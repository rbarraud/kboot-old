/*
 * Copyright (C) 2010-2011 Alex Smith
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
 * @brief		PC platform startup code.
 */

#include <arch/io.h>

#include <x86/descriptor.h>

#include <lib/string.h>

#include <pc/console.h>
#include <pc/memory.h>
#include <pc/multiboot.h>
#include <pc/vbe.h>

#include <config.h>
#include <loader.h>
#include <memory.h>
#include <tar.h>
#include <time.h>

/** Main function of the PC loader. */
void platform_init(void) {
	/* Set up console output. */
	console_init();

	/* Initialize the architecture. */
	arch_init();

	/* Initialize hardware. */
	memory_probe();
	disk_init();
	vbe_init();

	/* Parse information from Multiboot. */
	multiboot_init();

	/* Call the main function. */
	loader_main();
}

/** Reboot the system. */
void platform_reboot(void) {
	uint8_t val;

	/* Try the keyboard controller. */
	do {
		val = in8(0x64);
		if(val & (1<<0)) {
			in8(0x60);
		}
	} while(val & (1<<1));
	out8(0x64, 0xfe);
	spin(5000);

	/* Fall back on a triple fault. */
	lidt(0, 0);
	__asm__ volatile("ud2");
}
