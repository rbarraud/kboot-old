/*
 * Copyright (C) 2011 Alex Smith
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
 * @brief		TAR filesystem handler.
 *
 * @note		Here be dragons. I hacked this together really quickly,
 *			it's probably buggy.
 */

#include <lib/string.h>
#include <lib/utility.h>

#include <fs.h>
#include <memory.h>
#include <system.h>
#include <tar.h>

/** Callback type for tar_iterate(). */
typedef bool (*iterate_cb_t)(tar_header_t *header, mount_t *mount, void *a1, void *a2, void *a3);

/** Iterate over a TAR file.
 * @param mount		Mount to iterate.
 * @param cb		Callback for each entry.
 * @param a1		Data to pass to callback.
 * @param a2		Data to pass to callback.
 * @param a3		Data to pass to callback. */
static void iterate_tar_file(mount_t *mount, iterate_cb_t cb, void *a1, void *a2, void *a3) {
	tar_header_t *header;
	offset_t offset = 0;
	unsigned long size;

	while(true) {
		header = (tar_header_t *)(mount->data + offset);

		/* Two NULL bytes in the name field indicates EOF. */
		if(!header->name[0] && !header->name[1]) {
			break;
		}

		/* Check validity of the header. */
		if(strncmp(header->magic, "ustar", 5) != 0) {
			boot_error("Boot image is corrupted");
		}

		if(!cb(header, mount, a1, a2, a3)) {
			break;
		}

		/* 512 for the header, plus the file size if necessary. */
		size = strtoul(header->size, NULL, 8);
		offset += 512;
		if(size) {
			offset += ROUND_UP(size, 512);
		}
	}
}

/** Iteration callback for tar_open(). */
static bool tar_open_cb(tar_header_t *header, mount_t *mount, void *a1, void *a2, void *a3) {
	const char *path = a1, *name;
	file_handle_t **handlep = a2;
	size_t len;

	name = header->name;
	while(name[0] == '/') {
		name++;
	}

	len = strlen(path);
	if(strncmp(name, path, len) == 0 && (name[len] == 0 || (name[len] == '/' && !name[len + 1]))) {
		*handlep = file_handle_create(mount, header->typeflag == DIRTYPE, header);
		return false;
	}

	return true;
}

/** Open a file/directory on the filesystem.
 * @param mount		Mount to open from.
 * @param path		Path to file/directory to open.
 * @return		Pointer to handle on success, NULL on failure. */
static file_handle_t *tar_open(mount_t *mount, const char *path) {
	file_handle_t *ret = NULL;

	while(path[0] == '/') {
		path++;
	}

	if(!path[0]) {
		return file_handle_create(mount, true, NULL);
	}

	iterate_tar_file(mount, tar_open_cb, (void *)path, &ret, NULL);
	return ret;
}

/** Read from a file.
 * @param handle	Handle to the file.
 * @param buf		Buffer to read into.
 * @param count		Number of bytes to read.
 * @param offset	Offset into the file.
 * @return		Whether read successfully. */
static bool tar_read(file_handle_t *handle, void *buf, size_t count, offset_t offset) {
	tar_header_t *header = handle->data;
	unsigned long size;

	size = strtoul(header->size, NULL, 8);
	if(offset >= (offset_t)size) {
		return false;
	} else if((offset + count) > (offset_t)size) {
		return false;
	}

	memcpy(buf, handle->data + 512 + offset, count);
	return true;
}

/** Get the size of a file.
 * @param handle	Handle to the file.
 * @return		Size of the file. */
static offset_t tar_size(file_handle_t *handle) {
	tar_header_t *header = handle->data;
	return strtoul(header->size, NULL, 8);
}

/** Iteration callback for tar_iterate(). */
static bool tar_iterate_cb(tar_header_t *header, mount_t *mount, void *a1, void *a2, void *a3) {
	tar_header_t *parent = ((file_handle_t *)a1)->data;
	dir_iterate_cb_t cb = a2;
	void *arg = a3;
	file_handle_t *child;
	const char *name;
	char *pos, *dup;
	size_t len;

	if(parent) {
		len = strlen(parent->name);
		if(strncmp(header->name, parent->name, len) == 0 && header->name[len]) {
			name = &header->name[len];
			goto found;
		}
	} else {
		name = header->name;
		while(name[0] == '/') {
			name++;
		}
		goto found;
	}

	return true;
found:
	dup = kstrdup(name);
	pos = strchr(dup, '/');
	if(pos != dup && (!pos || !pos[1])) {
		*pos = 0;
		child = file_handle_create(mount, header->typeflag == DIRTYPE, header);
		if(!cb(dup, child, arg)) {
			file_close(child);
			kfree(dup);
			return false;
		}
	}

	kfree(dup);
	return true;
}

/** Read directory entries.
 * @param handle	Handle to directory.
 * @param cb		Callback to call on each entry.
 * @param arg		Data to pass to callback.
 * @return		Whether read successfully. */
static bool tar_iterate(file_handle_t *handle, dir_iterate_cb_t cb, void *arg) {
	iterate_tar_file(handle->mount, tar_iterate_cb, handle, cb, arg);
	return true;
}

/** TAR filesystem type. */
static fs_type_t tar_fs_type = {
	.open = tar_open,
	.read = tar_read,
	.size = tar_size,
	.iterate = tar_iterate,
};

/** Mount a TAR file as the boot device.
 * @param addr		Address of the TAR file data.
 * @param size		Size of the TAR file data. */
void tar_mount(void *addr, size_t size) {
	tar_header_t *header = addr;
	mount_t *mount;
	device_t *device;

	if(strncmp(header->magic, "ustar", 5) != 0) {
		boot_error("Loaded boot image is invalid");
	}

	mount = kmalloc(sizeof(mount_t));
	memset(mount, 0, sizeof(mount_t));
	mount->type = &tar_fs_type;
	mount->data = addr;
	mount->label = kstrdup("TAR");
	mount->uuid = NULL;
	device = device_add("pxe", NULL);
	device->fs = mount;

	/* This is the boot device. */
	current_device = device;
}
