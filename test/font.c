/*
 * Copyright (c) 2004, 2005 Tristan Grimmer
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/**
 * @file
 * @brief		Console font.
 *
 * This font is based on the Proggy Tiny font by Tristan Grimmer. It has been
 * modified slightly to add top and bottom padding (making it 6x12 instead of
 * 6x10).
 */

/** Console font. */
unsigned char console_font[] = {
	0x00, 0x00, 0x78, 0x84, 0xb4, 0xa4, 0xb4, 0x84, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x78, 0x84, 0x94, 0xa4, 0xa4, 0x84, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x20, 0x50, 0x70, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x70, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0x20, 0x50, 0x70, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x20, 0x50, 0x70, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x70, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x70, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x84, 0x78, 0x48, 0x48, 0x78, 0x84, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x20, 0x60, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x7c, 0xe8, 0xe8, 0x68, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00,
	0x00, 0x18, 0x20, 0x20, 0x70, 0x88, 0x88, 0x70, 0x20, 0x20, 0xc0, 0x00,
	0x00, 0x60, 0x10, 0x60, 0x10, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x88, 0x48, 0xd0, 0x50, 0xa4, 0x2c, 0x5c, 0x44, 0x80, 0x00, 0x00,
	0x00, 0x05, 0x52, 0x7f, 0xbf, 0xde, 0x3e, 0x5e, 0x84, 0x46, 0xb1, 0x00,
	0x00, 0x67, 0xfb, 0x79, 0x9e, 0x25, 0x88, 0xf8, 0xe2, 0x25, 0x55, 0x00,
	0x00, 0x05, 0x90, 0x72, 0xf9, 0x78, 0xfb, 0x3c, 0x7e, 0x12, 0x5e, 0x00,
	0x00, 0x5f, 0x50, 0x86, 0xc5, 0xde, 0xd7, 0xd7, 0x24, 0xc1, 0x35, 0x00,
	0x00, 0x6c, 0xf8, 0x2d, 0x94, 0x32, 0xe7, 0x61, 0x32, 0x84, 0xd2, 0x00,
	0x00, 0x72, 0x43, 0x0b, 0xaf, 0x95, 0x65, 0x2d, 0xfc, 0x1a, 0xb9, 0x00,
	0x00, 0x65, 0x6b, 0xaa, 0x36, 0x4a, 0x7b, 0xce, 0xfb, 0x5d, 0x99, 0x00,
	0x00, 0x71, 0xfd, 0xd6, 0x5a, 0x87, 0x17, 0x84, 0xb1, 0x49, 0x5e, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x50, 0xf8, 0x50, 0x50, 0xf8, 0x50, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x78, 0xa0, 0x70, 0x28, 0xf0, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x44, 0xa8, 0x50, 0x28, 0x54, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x60, 0x90, 0x90, 0x60, 0x94, 0x88, 0x74, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x10, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x10, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x40, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0xa8, 0x70, 0xa8, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x88, 0xa8, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x08, 0x30, 0x40, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x08, 0x30, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x10, 0x30, 0x50, 0x90, 0xf8, 0x10, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x80, 0x80, 0xf0, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x30, 0x40, 0x80, 0xf0, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0x60, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x20, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x08, 0x30, 0xc0, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x08, 0x10, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x78, 0x84, 0xb4, 0xb4, 0xbc, 0x80, 0x7c, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x50, 0x50, 0x70, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0x90, 0x88, 0x88, 0x88, 0x90, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x80, 0x98, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x38, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x90, 0xa0, 0xc0, 0xa0, 0x90, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0xd8, 0xd8, 0xa8, 0xa8, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc8, 0xc8, 0xa8, 0xa8, 0xa8, 0x98, 0x98, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x98, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0xa8, 0xa8, 0xa8, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x88, 0x70, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x70, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70, 0x00, 0x00,
	0x00, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x00, 0x00,
	0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x80, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x08, 0x08, 0x78, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x38, 0x40, 0x40, 0xf0, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70, 0x00,
	0x00, 0x80, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0xe0, 0x00,
	0x00, 0x40, 0x40, 0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x00, 0x00, 0x00,
	0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xd0, 0xa8, 0xa8, 0xa8, 0xa8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x78, 0x88, 0x88, 0x88, 0x78, 0x08, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xb0, 0xc8, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x70, 0x08, 0xf0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x40, 0x70, 0x40, 0x40, 0x40, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x88, 0xa8, 0xa8, 0x50, 0x50, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf8, 0x10, 0x20, 0x40, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x10, 0x20, 0x20, 0x20, 0x40, 0x20, 0x20, 0x20, 0x10, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x20, 0x20, 0x10, 0x20, 0x20, 0x20, 0x40, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xea, 0x1f, 0x37, 0x94, 0xbe, 0x38, 0x20, 0x0a, 0xce, 0x8d, 0x00,
	0x00, 0x00, 0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x20, 0x40, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x66, 0x71, 0xc6, 0xd3, 0x3f, 0x94, 0x59, 0x48, 0x66, 0x8b, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x78, 0x80, 0x80, 0x80, 0x78, 0x20, 0x40, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x1e, 0x3b, 0x36, 0xe9, 0xe9, 0xd1, 0x9a, 0x92, 0xcb, 0xfe, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x20, 0x50, 0x70, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0xcf, 0x1f, 0xb9, 0xf7, 0xfd, 0xa9, 0xe0, 0xf2, 0xce, 0x37, 0x00,
	0x00, 0x20, 0x40, 0x00, 0xf8, 0x80, 0xf0, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x68, 0x14, 0x78, 0x90, 0x6c, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x3c, 0x50, 0x50, 0x78, 0x90, 0x90, 0x9c, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x34, 0x75, 0x49, 0x2d, 0x38, 0x02, 0x27, 0x9b, 0x2d, 0x5f, 0x00,
	0x00, 0x20, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x40, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x08, 0x70, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x10, 0x38, 0x50, 0x50, 0x38, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x18, 0x20, 0x20, 0x78, 0x20, 0x40, 0x80, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x88, 0x88, 0x70, 0x20, 0xf8, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x04, 0x2b, 0x1a, 0x6d, 0x7f, 0x2a, 0x86, 0x75, 0x4b, 0x65, 0x00,
	0x00, 0xcc, 0xd8, 0xfa, 0xc9, 0xf4, 0xc8, 0x6f, 0x05, 0x3c, 0xba, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x40, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x28, 0x50, 0x00, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x28, 0x50, 0x00, 0xc8, 0xa8, 0xa8, 0x98, 0x98, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x10, 0x30, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x50, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x00, 0x20, 0x10, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00,
	0x00, 0xda, 0xab, 0x10, 0x1c, 0x4e, 0x69, 0xfc, 0x67, 0xfb, 0x9b, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x88, 0x90, 0x90, 0x2c, 0x24, 0x48, 0x4c, 0x80, 0x00, 0x00,
	0x00, 0x08, 0x88, 0x90, 0x90, 0x24, 0x2c, 0x5c, 0x44, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x90, 0x48, 0x24, 0x48, 0x90, 0x00, 0x00, 0x00,
	0x00, 0x9e, 0x76, 0xdc, 0xc5, 0xc1, 0xa5, 0xec, 0xd6, 0x8d, 0xb8, 0x00,
	0x00, 0x8b, 0xd2, 0x7f, 0x34, 0x5c, 0x5c, 0x9b, 0xc3, 0xfc, 0xed, 0x00,
	0x00, 0xfa, 0xc0, 0x8b, 0xbc, 0xd2, 0xb2, 0x11, 0xc3, 0x64, 0xc8, 0x00,
	0x00, 0xab, 0xde, 0x94, 0xd0, 0x5f, 0xd9, 0x24, 0xb2, 0x78, 0x8e, 0x00,
	0x00, 0xc9, 0x8e, 0x10, 0xea, 0x87, 0xe6, 0xc8, 0xf4, 0x26, 0x83, 0x00,
	0x00, 0x95, 0x80, 0x4c, 0xf0, 0x95, 0x90, 0x37, 0x91, 0xa2, 0xd9, 0x00,
	0x00, 0x94, 0xf4, 0xbe, 0xc4, 0x04, 0xa3, 0xe1, 0x94, 0xbb, 0x72, 0x00,
	0x00, 0xba, 0x71, 0xba, 0x2a, 0xfc, 0x71, 0xe0, 0x24, 0xbe, 0xa4, 0x00,
	0x00, 0x9a, 0x58, 0xea, 0xea, 0xec, 0x0f, 0xe4, 0xf1, 0xf5, 0x5d, 0x00,
	0x00, 0x0e, 0x42, 0xc2, 0x3f, 0x90, 0x8c, 0xab, 0x61, 0x1e, 0x29, 0x00,
	0x00, 0x3f, 0x78, 0xcd, 0xee, 0xc9, 0xb0, 0xec, 0x1c, 0x47, 0x21, 0x00,
	0x00, 0x1d, 0x58, 0x91, 0xb1, 0xc6, 0x13, 0xf3, 0x10, 0x33, 0x3f, 0x00,
	0x00, 0x14, 0x74, 0x98, 0x3c, 0x5c, 0x51, 0x0f, 0x60, 0x0d, 0x63, 0x00,
	0x00, 0xf9, 0x01, 0x1a, 0x20, 0x46, 0xf4, 0x5f, 0x69, 0xf9, 0xc6, 0x00,
	0x00, 0xcf, 0x32, 0x87, 0x26, 0xd4, 0x21, 0xe3, 0x5d, 0x85, 0x0c, 0x00,
	0x00, 0x11, 0xf1, 0x65, 0x09, 0x20, 0x81, 0xb5, 0xc6, 0x73, 0x15, 0x00,
	0x00, 0x44, 0x73, 0x16, 0x29, 0xef, 0x9c, 0xd7, 0xec, 0x64, 0xfd, 0x00,
	0x00, 0x24, 0x03, 0x32, 0x03, 0x0b, 0x9e, 0xf4, 0x92, 0xdc, 0xeb, 0x00,
	0x00, 0xd1, 0x78, 0xb6, 0x3c, 0xa3, 0x94, 0x35, 0xbe, 0x97, 0x1e, 0x00,
	0x00, 0x72, 0x25, 0x06, 0xb9, 0xbb, 0x8a, 0xb1, 0x69, 0x04, 0x1e, 0x00,
	0x00, 0x9e, 0x2c, 0xb0, 0xa2, 0x56, 0x66, 0x89, 0x8e, 0x68, 0x0b, 0x00,
	0x00, 0xa4, 0xee, 0xdf, 0x02, 0x3d, 0x45, 0xb9, 0xf7, 0x54, 0x3e, 0x00,
	0x00, 0x55, 0x80, 0x73, 0x60, 0x79, 0x86, 0x7f, 0x71, 0xd4, 0xbb, 0x00,
	0x00, 0x79, 0xe1, 0x7a, 0x84, 0xe7, 0x99, 0x81, 0x2a, 0x53, 0xc4, 0x00,
	0x00, 0xb1, 0xa1, 0x0a, 0x7c, 0xc4, 0xa8, 0xb7, 0x77, 0xa5, 0xea, 0x00,
	0x00, 0xd8, 0x32, 0xca, 0xcd, 0x40, 0xdd, 0x49, 0x85, 0x45, 0xd6, 0x00,
	0x00, 0x10, 0x57, 0x7f, 0x2d, 0xb6, 0x9c, 0xce, 0xd2, 0xca, 0x88, 0x00,
	0x00, 0x89, 0x45, 0x03, 0x06, 0xd0, 0x75, 0x99, 0x79, 0x9e, 0x6d, 0x00,
	0x00, 0x90, 0x23, 0x10, 0x2b, 0xd6, 0x81, 0xaf, 0x9c, 0x86, 0xc7, 0x00,
	0x00, 0x07, 0xf5, 0x39, 0x61, 0x08, 0xfe, 0x72, 0x53, 0x46, 0x6b, 0x00,
	0x00, 0x38, 0x9c, 0xb8, 0x81, 0xf6, 0x34, 0xc2, 0xe8, 0xd0, 0x8a, 0x00,
	0x00, 0x1e, 0xf4, 0x76, 0xc3, 0x06, 0x3c, 0xc6, 0xec, 0xcb, 0x64, 0x00,
	0x00, 0xbe, 0x33, 0xeb, 0xad, 0xb0, 0x98, 0xde, 0x19, 0x27, 0x87, 0x00,
	0x00, 0x17, 0xda, 0x1e, 0x78, 0x2b, 0xfb, 0xb2, 0xc2, 0x6d, 0x88, 0x00,
	0x00, 0x5e, 0x9b, 0xc7, 0xad, 0x07, 0x84, 0x76, 0x3e, 0x39, 0x34, 0x00,
	0x00, 0xff, 0x5a, 0xec, 0xdb, 0x25, 0x22, 0xe5, 0x81, 0x6d, 0xa4, 0x00,
	0x00, 0x01, 0xd5, 0x6e, 0x79, 0x23, 0x3c, 0x89, 0xec, 0x2e, 0x56, 0x00,
	0x00, 0xd1, 0xa9, 0x39, 0xef, 0x10, 0xbc, 0x21, 0x23, 0x6c, 0xc7, 0x00,
	0x00, 0xf6, 0xb0, 0xb4, 0xd3, 0x98, 0xa8, 0x2a, 0x35, 0x6d, 0x0b, 0x00,
	0x00, 0xa9, 0x15, 0x1d, 0xd7, 0x41, 0xfc, 0x85, 0xca, 0x1e, 0x65, 0x00,
	0x00, 0xec, 0xb1, 0xaa, 0x3f, 0xaa, 0xd4, 0x40, 0x1d, 0x72, 0x93, 0x00,
	0x00, 0x13, 0x41, 0x37, 0x0a, 0xf7, 0xda, 0xcf, 0xf2, 0xa8, 0x34, 0x00,
	0x00, 0x33, 0x1e, 0x8f, 0x03, 0x31, 0x61, 0x24, 0x53, 0x0f, 0x85, 0x00,
	0x00, 0x70, 0x5c, 0xb5, 0xea, 0xc4, 0x76, 0xf1, 0x58, 0x2c, 0x06, 0x00,
	0x00, 0xbf, 0x6b, 0x2f, 0xb2, 0xe9, 0xbe, 0x8f, 0xf8, 0x54, 0x70, 0x00,
	0x00, 0xd6, 0x66, 0x36, 0x9a, 0xcc, 0x45, 0x14, 0x45, 0x0b, 0x72, 0x00,
	0x00, 0x47, 0xa0, 0x8a, 0x44, 0xe7, 0x3e, 0xda, 0x3e, 0xc8, 0xb7, 0x00,
	0x00, 0x5b, 0xee, 0x51, 0x15, 0xc6, 0xa5, 0x65, 0x61, 0x1f, 0xa7, 0x00,
	0x00, 0x97, 0x11, 0x87, 0xce, 0x63, 0x49, 0xf4, 0xf4, 0xab, 0x13, 0x00,
	0x00, 0x00, 0x70, 0x48, 0x48, 0x70, 0x48, 0x48, 0x70, 0x80, 0x00, 0x00,
	0x00, 0x78, 0x80, 0x4a, 0x84, 0x81, 0x8f, 0xbf, 0x08, 0x88, 0x71, 0x00,
	0x00, 0x31, 0xf2, 0xfc, 0xa3, 0x06, 0x42, 0x73, 0xc2, 0x1a, 0x39, 0x00,
	0x00, 0xba, 0x0d, 0xfa, 0x2e, 0x90, 0xc5, 0xff, 0x45, 0xe1, 0xbe, 0x00,
	0x00, 0xc1, 0x57, 0x97, 0xf4, 0xe4, 0xc1, 0xbe, 0xad, 0x26, 0x54, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x48, 0x48, 0x48, 0x48, 0x74, 0x40, 0x80, 0x00,
	0x00, 0xbd, 0xfc, 0x1c, 0x1c, 0x47, 0xfe, 0x88, 0x1d, 0xea, 0x8e, 0x00,
	0x00, 0xa9, 0xae, 0x76, 0x66, 0xcc, 0xa4, 0xf7, 0xd4, 0x2c, 0x49, 0x00,
	0x00, 0xa8, 0x18, 0x3b, 0xe4, 0xc4, 0x18, 0x5a, 0x14, 0x81, 0x0c, 0x00,
	0x00, 0x8e, 0x9a, 0x4c, 0x8b, 0x64, 0xda, 0xab, 0xae, 0x27, 0xbc, 0x00,
	0x00, 0x24, 0xd0, 0x00, 0x05, 0x80, 0xa8, 0x9a, 0x48, 0x73, 0x5a, 0x00,
	0x00, 0xf8, 0x78, 0xb0, 0xc3, 0x38, 0x8f, 0x03, 0x74, 0x67, 0xfa, 0x00,
	0x00, 0x1d, 0x85, 0x45, 0x14, 0xf9, 0x4b, 0xa1, 0x88, 0x67, 0x9e, 0x00,
	0x00, 0xd9, 0x56, 0xbd, 0x26, 0xde, 0xec, 0x28, 0xe9, 0x37, 0x47, 0x00,
	0x00, 0xb7, 0x7f, 0x91, 0x12, 0x62, 0x32, 0x97, 0xfd, 0xe1, 0xa6, 0x00,
	0x00, 0xf7, 0x57, 0x79, 0xca, 0xdd, 0x39, 0xa1, 0x2a, 0x48, 0xa1, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0xf8, 0x20, 0x20, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0xf9, 0x74, 0xe0, 0xba, 0xfd, 0x3c, 0x58, 0x5b, 0x71, 0xf0, 0x00,
	0x00, 0x0f, 0xd8, 0x09, 0xe8, 0xfe, 0x9c, 0xf9, 0x3f, 0x56, 0xe3, 0x00,
	0x00, 0x43, 0x1f, 0x07, 0xb0, 0x49, 0x4c, 0x0b, 0xd8, 0xe2, 0x24, 0x00,
	0x00, 0xad, 0xc9, 0xe9, 0xa3, 0x95, 0x85, 0x0d, 0x2f, 0xc4, 0x40, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0xf8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x92, 0x8a, 0x42, 0xdc, 0xa6, 0xbc, 0xf6, 0xf8, 0xea, 0xc3, 0x00,
	0x00, 0x00, 0x20, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x69, 0x50, 0xa4, 0x4b, 0x4c, 0x70, 0x83, 0x15, 0x94, 0x51, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xdd, 0x19, 0x4e, 0x0e, 0x74, 0xa2, 0xd5, 0x98, 0xd8, 0x9c, 0x00,
	0x00, 0xad, 0x88, 0x04, 0x13, 0xfb, 0xd8, 0x78, 0x69, 0x4c, 0xeb, 0x00,
	0x00, 0x60, 0x10, 0x20, 0x40, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x74, 0x81, 0x64, 0x75, 0x3b, 0xa0, 0x00, 0xc3, 0x95, 0x20, 0x00,
	0x00, 0xba, 0x72, 0x78, 0xac, 0xf8, 0xdd, 0x96, 0xaf, 0x9a, 0x53, 0x00,
};
