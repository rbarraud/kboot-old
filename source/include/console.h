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
 * @brief		Console functions.
 */

#ifndef __CONSOLE_H
#define __CONSOLE_H

#include <stdarg.h>
#include <types.h>

/** Structure describing a draw region. */
typedef struct draw_region {
	int x;			/**< X position. */
	int y;			/**< Y position. */
	int width;		/**< Width of region. */
	int height;		/**< Height of region. */
	bool scrollable;	/**< Whether to scroll when cursor reaches the end. */
} draw_region_t;

/** Structure describing a console. */
typedef struct console {
	int width;		/**< Width of the console (columns). */
	int height;		/**< Height of the console (rows). */

	/** Reset and clear the console. */
	void (*reset)(void);

	/** Set the draw region.
	 * @note		Positions the cursor at 0, 0 in the new region.
	 * @param region	Structure describing the region. */
	void (*set_region)(draw_region_t *region);

	/** Get the draw region.
	 * @param region	Draw region structure to fill in. */
	void (*get_region)(draw_region_t *region);

	/** Write a character to the console.
	 * @param ch		Character to write. */
	void (*putch)(char ch);

	/** Change the highlight on a portion of the console.
	 * @note		This reverses whatever the current state of
	 *			each character is, e.g. if something is already
	 *			highlighted, it will become unhighlighted.
	 * @note		Position is relative to the draw region.
	 * @param x		Start X position.
	 * @param y		Start Y position.
	 * @param width		Width of the highlight.
	 * @param height	Height of the highlight. */
	void (*highlight)(int x, int y, int width, int height);

	/** Clear a portion of the console.
	 * @note		Position is relative to the draw region.
	 * @param x		Start X position.
	 * @param y		Start Y position.
	 * @param width		Width of the highlight.
	 * @param height	Height of the highlight. */
	void (*clear)(int x, int y, int width, int height);

	/** Move the cursor.
	 * @note		Position is relative to the draw region.
	 * @param x		New X position.
	 * @param y		New Y position. */
	void (*move_cursor)(int x, int y);

	/** Set whether the cursor is visible.
	 * @param visible	Whether the cursor is visible. */
	void (*show_cursor)(bool visible);

	/** Scroll the draw region up (move contents down). */
	void (*scroll_up)(void);

	/** Scroll the draw region down (move contents up). */
	void (*scroll_down)(void);

	/** Read a keypress from the console.
	 * @return		Key read from the console. */
	uint16_t (*get_key)(void);

	/** Check if input is available.
	 * @return		Whether input is available. */
	bool (*check_key)(void);
} console_t;

/** Special key codes. */
#define CONSOLE_KEY_UP		0x100
#define CONSOLE_KEY_DOWN	0x101
#define CONSOLE_KEY_LEFT	0x102
#define CONSOLE_KEY_RIGHT	0x103
#define CONSOLE_KEY_HOME	0x104
#define CONSOLE_KEY_END		0x105
#define CONSOLE_KEY_DELETE	0x106
#define CONSOLE_KEY_F1		0x107
#define CONSOLE_KEY_F2		0x108
#define CONSOLE_KEY_F3		0x109
#define CONSOLE_KEY_F4		0x10A
#define CONSOLE_KEY_F5		0x10B
#define CONSOLE_KEY_F6		0x10C
#define CONSOLE_KEY_F7		0x10D
#define CONSOLE_KEY_F8		0x10E
#define CONSOLE_KEY_F9		0x10F
#define CONSOLE_KEY_F10		0x110

/** Debug log size. */
#define DEBUG_LOG_SIZE		8192

extern char debug_log[DEBUG_LOG_SIZE];
extern size_t debug_log_start;
extern size_t debug_log_length;

extern console_t *main_console;
extern console_t *debug_console;

#endif /* __CONSOLE_H */
