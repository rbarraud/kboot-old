/*
 * Copyright (C) 2010-2012 Alex Smith
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
 * @brief		Disk device layer.
 */

#include <lib/string.h>
#include <lib/utility.h>

#include <disk.h>
#include <fs.h>
#include <loader.h>
#include <memory.h>

/** Type of a partition disk device. */
typedef struct partition {
	disk_t disk;			/**< Disk structure header. */
	offset_t offset;		/**< Offset of the partition on the disk. */
} partition_t;

static void probe_disk(disk_t *disk);

/** Read from a disk.
 * @param disk		Disk to read from.
 * @param buf		Buffer to read into.
 * @param count		Number of bytes to read.
 * @param offset	Offset in the disk to read from.
 * @return		Whether the read was successful. */
bool disk_read(disk_t *disk, void *buf, size_t count, offset_t offset) {
	size_t blksize = disk->block_size;
	uint64_t start, end, size;
	void *block = NULL;

	if(!disk->ops || !disk->ops->read) {
		return false;
	} else if(!count) {
		return true;
	}

	if((offset + count) > (disk->blocks * blksize))
		internal_error("Reading beyond end of disk");

	/* Allocate a temporary buffer for partial transfers if required. */
	if(offset % blksize || count % blksize)
		block = kmalloc(blksize);

	/* Now work out the start block and the end block. Subtract one from
	 * count to prevent end from going onto the next block when the offset
	 * plus the count is an exact multiple of the block size. */
	start = offset / blksize;
	end = (offset + (count - 1)) / blksize;

	/* If we're not starting on a block boundary, we need to do a partial
	 * transfer on the initial block to get up to a block boundary. 
	 * If the transfer only goes across one block, this will handle it. */
	if(offset % blksize) {
		/* Read the block into the temporary buffer. */
		if(!disk->ops->read(disk, block, start, 1)) {
			kfree(block);
			return false;
		}

		size = (start == end) ? count : blksize - (size_t)(offset % blksize);
		memcpy(buf, block + (offset % blksize), size);
		buf += size; count -= size; start++;
	}

	/* Handle any full blocks. */
	size = count / blksize;
	if(size) {
		if(!disk->ops->read(disk, buf, start, size)) {
			kfree(block);
			return false;
		}

		buf += (size * blksize);
		count -= (size * blksize);
		start += size;
	}

	/* Handle anything that's left. */
	if(count > 0) {
		if(!disk->ops->read(disk, block, start, 1)) {
			kfree(block);
			return false;
		}

		memcpy(buf, block, count);
	}

	kfree(block);
	return true;
}

/** Read blocks from a partition.
 * @param disk		Disk being read from.
 * @param buf		Buffer to read into.
 * @param lba		Starting block number.
 * @param count		Number of blocks to read.
 * @return		Whether reading succeeded. */
static bool partition_disk_read(disk_t *disk, void *buf, uint64_t lba, size_t count) {
	partition_t *partition = (partition_t *)disk;
	return disk->parent->ops->read(disk->parent, buf, lba + partition->offset, count);
}

/** Operations for a partition disk. */
static disk_ops_t partition_disk_ops = {
	.read = partition_disk_read,
};

/** Determine whether a disk is a partition.
 * @param disk		Disk to check.
 * @return		Whether the disk is a partition. */
static bool is_partition(disk_t *disk) {
	return (disk->ops == &partition_disk_ops);
}

/** Add a partition to a disk device.
 * @param parent	Parent of the partition.
 * @param id		ID of the partition.
 * @param lba		Start LBA.
 * @param blocks	Size in blocks. */
static void add_partition(disk_t *parent, uint8_t id, uint64_t lba, uint64_t blocks) {
	partition_t *partition = kmalloc(sizeof(partition_t));
	char name[32];

	sprintf(name, "%s,%u", parent->device.name, id);

	partition->disk.id = id;
	partition->disk.block_size = parent->block_size;
	partition->disk.blocks = blocks;
	partition->disk.ops = &partition_disk_ops;
	partition->disk.parent = parent;
	partition->offset = lba;

	/* Add the device. */
	device_add(&partition->disk.device, name, DEVICE_TYPE_DISK);

	/* Set as the boot device if it is the boot partition. */
	if(boot_device == &parent->device && parent->ops->is_boot_partition) {
		if(parent->ops->is_boot_partition(parent, id, lba))
			boot_device = &partition->disk.device;
	}

	/* Probe for filesystems/partitions. */
	probe_disk(&partition->disk);
}

/** Probe a disk for filesystems/partitions.
 * @param disk		Disk to probe. */
static void probe_disk(disk_t *disk) {
	if(!(disk->device.fs = fs_probe(disk)) && !is_partition(disk)) {
		/* Check for a partition table on the device if it is not
		 * itself a partition. */
		BUILTIN_ITERATE(BUILTIN_TYPE_PARTITION_MAP, partition_map_ops_t, type) {
			if(type->iterate(disk, add_partition))
				return;
		}
	}
}

/** Register a disk device.
 * @param disk		Disk device structure.
 * @param name		Name of the disk (will be duplicated).
 * @param id		ID of the device (this is not used anywhere by the
 *			disk code, but it is what gets passed to the OS
 *			kernel).
 * @param block_size	Size of a block on the device.
 * @param blocks	Number of blocks on the device.
 * @param ops		Operations structure. Can be NULL.
 * @param boot		Whether the disk is the boot disk. */
void disk_add(disk_t *disk, const char *name, uint8_t id, size_t block_size,
	uint64_t blocks, disk_ops_t *ops, bool boot)
{
	disk->id = id;
	disk->block_size = block_size;
	disk->blocks = blocks;
	disk->ops = ops;
	disk->parent = NULL;

	/* Add the device. */
	device_add(&disk->device, name, DEVICE_TYPE_DISK);

	/* Set as the boot device if it is the boot disk. */
	if(boot && !boot_device)
		boot_device = &disk->device;

	/* Probe for filesystems/partitions. */
	probe_disk(disk);
}

/** Get the top level parent disk of a partition.
 * @param disk		Disk to get parent of.
 * @return		Parent disk (if disk is already the top level, it will
 *			be returned). */
disk_t *disk_parent(disk_t *disk) {
	while(is_partition(disk))
		disk = disk->parent;

	return disk;
}

/** Detect all disk devices. */
void disk_init(void) {
	platform_disk_detect();
}
