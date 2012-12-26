/*
 * Copyright (C) 2011-2012 Alex Smith
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * @file
 * @brief		x86 KBoot kernel loader.
 *
 * @todo		Only use large pages if supported.
 */

#include <x86/cpu.h>
#include <x86/mmu.h>

#include <loaders/kboot.h>

#include <elf.h>
#include <loader.h>
#include <mmu.h>

/** Entry arguments for the kernel. */
typedef struct entry_args {
	target_ptr_t transition_cr3;	/**< Transition address space CR3. */
	target_ptr_t virt;		/**< Virtual location of trampoline. */
	target_ptr_t kernel_cr3;	/**< Kernel address space CR3. */
	target_ptr_t sp;		/**< Stack pointer for the kernel. */
	target_ptr_t entry;		/**< Entry point for kernel. */
	target_ptr_t tags;		/**< Tag list virtual address. */

	char trampoline[];
} entry_args_t;

extern void kboot_arch_enter64(entry_args_t *args) __noreturn;
extern void kboot_arch_enter32(entry_args_t *args) __noreturn;

extern char kboot_trampoline64[], kboot_trampoline32[];
extern size_t kboot_trampoline64_size, kboot_trampoline32_size;

/** Check for long mode support.
 * @return		Whether long mode is supported. */
static inline bool have_long_mode(void) {
	uint32_t eax, ebx, ecx, edx;

	/* Check whether long mode is supported. */
	x86_cpuid(X86_CPUID_EXT_MAX, &eax, &ebx, &ecx, &edx);
	if(eax & (1<<31)) {
		x86_cpuid(X86_CPUID_EXT_FEATURE, &eax, &ebx, &ecx, &edx);
		if(edx & (1<<29))
			return true;
	}

	return false;
}

/** Check a kernel image and determine the target type.
 * @param loader	KBoot loader data structure. */
void kboot_arch_check(kboot_loader_t *loader) {
	unsigned long flags;

	/* Check if CPUID is supported - if we can change EFLAGS.ID, it is. */
	flags = x86_read_flags();
	x86_write_flags(flags ^ X86_FLAGS_ID);
	if((x86_read_flags() & X86_FLAGS_ID) == (flags & X86_FLAGS_ID))
		boot_error("CPU does not support CPUID");

	if(elf_check(loader->kernel, ELFCLASS64, ELFDATA2LSB, ELF_EM_X86_64)) {
		loader->target = TARGET_TYPE_64BIT;

		/* Check for 64-bit support. */
		if(!have_long_mode())
			boot_error("64-bit kernel requires 64-bit CPU");
	} else if(elf_check(loader->kernel, ELFCLASS32, ELFDATA2LSB, ELF_EM_386)) {
		loader->target = TARGET_TYPE_32BIT;
	} else {
		boot_error("Kernel image is not for this architecture");
	}
}

/** Check whether an address is canonical.
 * @param addr		Address to check.
 * @return		Result of check. */
static inline bool is_canonical_addr(target_ptr_t addr) {
	return ((uint64_t)((int64_t)addr >> 47) + 1) <= 1;
}

/** Check whether an address range is canonical.
 * @param start		Start of range to check.
 * @param size		Size of address range.
 * @return		Result of check. */
static inline bool is_canonical_range(target_ptr_t start, target_size_t size) {
	target_ptr_t end = start + size - 1;
	return (is_canonical_addr(start) && is_canonical_addr(end)
		&& (start & (1ULL<<47)) == (end & (1ULL<<47)));
}

/** Validate kernel load parameters.
 * @param loader	KBoot loader data structure.
 * @param load		Load image tag. */
void kboot_arch_load_params(kboot_loader_t *loader, kboot_itag_load_t *load) {
	if(!(load->flags & KBOOT_LOAD_FIXED) && !load->alignment) {
		/* Set default alignment parameters. Try to align to the large
		 * page size so we can map using large pages, but fall back to
		 * 1MB if we're tight on memory. */
		load->alignment = (loader->target == TARGET_TYPE_64BIT)
			? 0x200000 : 0x400000;
		load->min_alignment = 0x100000;
	}

	if(load->virt_map_base || load->virt_map_size) {
		if(loader->target == TARGET_TYPE_64BIT
			&& !is_canonical_range(load->virt_map_base,
				load->virt_map_size)) {
			boot_error("Kernel specifies invalid virtual map range");
		}
	} else {
		/* On 64-bit we can't default to the whole 64-bit address space
		 * so just use the bottom half. */
		if(loader->target == TARGET_TYPE_64BIT) {
			load->virt_map_base = 0;
			load->virt_map_size = 0x800000000000ULL;
		}
	}
}

/** Perform architecture-specific setup tasks.
 * @param loader	KBoot loader data structure. */
void kboot_arch_setup(kboot_loader_t *loader) {
	kboot_tag_pagetables_t *tag;
	target_ptr_t addr, i;
	uint64_t *pml4;
	uint32_t *pdir;

	/* Find a location to recursively map the pagetables at. */
	if(loader->target == TARGET_TYPE_64BIT) {
		/* Search backward from the end of the address space for a free
		 * PML4 entry. */
		pml4 = (uint64_t *)loader->mmu->cr3;
		i = 512;
		while(i-- > 1) {
			if(!(pml4[i] & X86_PTE_PRESENT)) {
				addr = i * 0x8000000000LL
					| ((i >= 256) ? 0xFFFF000000000000 : 0);
				allocator_reserve(&loader->alloc, addr, 0x8000000000LL);
				pml4[i] = loader->mmu->cr3 | X86_PTE_PRESENT | X86_PTE_WRITE;
				break;
			}
		}

		if(i == 0)
			boot_error("Unable to allocate page table mapping space");
	} else {
		/* Allocate a 4MB address region to recursively map the page
		 * directory at. */
		if(!allocator_alloc(&loader->alloc, 0x400000, 0x400000, &addr))
			boot_error("Unable to allocate page table mapping space");

		pdir = (uint32_t *)loader->mmu->cr3;
		pdir[addr / 0x400000] = loader->mmu->cr3 | X86_PTE_PRESENT | X86_PTE_WRITE;
	}

	/* Add the pagetables tag. */
	tag = kboot_allocate_tag(loader, KBOOT_TAG_PAGETABLES, sizeof(*tag));
	tag->page_dir = loader->mmu->cr3;
	tag->mapping = addr;
}

/** Enter a loaded KBoot kernel.
 * @param loader	KBoot loader data structure. */
__noreturn void kboot_arch_enter(kboot_loader_t *loader) {
	entry_args_t *args;

	/* Enter with interrupts disabled. */
	__asm__ volatile("cli");

	/* Flush cached data to memory. This is needed to ensure, for example,
	 * that the log buffer set up is written to memory and can be detected
	 * again after a reset. */
	__asm__ volatile("wbinvd");

	/* Store information for the entry code. */
	args = (void *)((ptr_t)loader->trampoline_phys);
	args->transition_cr3 = loader->transition->cr3;
	args->virt = loader->trampoline_virt;
	args->kernel_cr3 = loader->mmu->cr3;
	args->sp = loader->stack_virt + loader->stack_size;
	args->entry = loader->entry;
	args->tags = loader->tags_virt;

	/* Copy the trampoline and call the entry code. */
	if(loader->target == TARGET_TYPE_64BIT) {
		memcpy(args->trampoline, kboot_trampoline64, kboot_trampoline64_size);
		kboot_arch_enter64(args);
	} else {
		memcpy(args->trampoline, kboot_trampoline32, kboot_trampoline32_size);
		kboot_arch_enter32(args);
	}
}
