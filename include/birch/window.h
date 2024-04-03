// Copyright (C) 2024 Devin Rockwell
//
// This file is part of birch.
//
// birch is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// birch is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with birch.  If not, see <http://www.gnu.org/licenses/>.

#ifndef BIRCH_WINDOW_H
#define BIRCH_WINDOW_H

#include <stdbool.h>

/* The unknown key */
#define BIRCH_KEY_UNKNOWN -1

/* Printable keys */
#define BIRCH_KEY_SPACE 32
#define BIRCH_KEY_APOSTROPHE 39 /* ' */
#define BIRCH_KEY_COMMA 44 /* , */
#define BIRCH_KEY_MINUS 45 /* - */
#define BIRCH_KEY_PERIOD 46 /* . */
#define BIRCH_KEY_SLASH 47 /* / */
#define BIRCH_KEY_0 48
#define BIRCH_KEY_1 49
#define BIRCH_KEY_2 50
#define BIRCH_KEY_3 51
#define BIRCH_KEY_4 52
#define BIRCH_KEY_5 53
#define BIRCH_KEY_6 54
#define BIRCH_KEY_7 55
#define BIRCH_KEY_8 56
#define BIRCH_KEY_9 57
#define BIRCH_KEY_SEMICOLON 59 /* ; */
#define BIRCH_KEY_EQUAL 61 /* = */
#define BIRCH_KEY_A 65
#define BIRCH_KEY_B 66
#define BIRCH_KEY_C 67
#define BIRCH_KEY_D 68
#define BIRCH_KEY_E 69
#define BIRCH_KEY_F 70
#define BIRCH_KEY_G 71
#define BIRCH_KEY_H 72
#define BIRCH_KEY_I 73
#define BIRCH_KEY_J 74
#define BIRCH_KEY_K 75
#define BIRCH_KEY_L 76
#define BIRCH_KEY_M 77
#define BIRCH_KEY_N 78
#define BIRCH_KEY_O 79
#define BIRCH_KEY_P 80
#define BIRCH_KEY_Q 81
#define BIRCH_KEY_R 82
#define BIRCH_KEY_S 83
#define BIRCH_KEY_T 84
#define BIRCH_KEY_U 85
#define BIRCH_KEY_V 86
#define BIRCH_KEY_W 87
#define BIRCH_KEY_X 88
#define BIRCH_KEY_Y 89
#define BIRCH_KEY_Z 90
#define BIRCH_KEY_LEFT_BRACKET 91 /* [ */
#define BIRCH_KEY_BACKSLASH 92 /* \ */
#define BIRCH_KEY_RIGHT_BRACKET 93 /* ] */
#define BIRCH_KEY_GRAVE_ACCENT 96 /* ` */
// #define BIRCH_KEY_WORLD_1            161 /* non-US #1 */
// #define BIRCH_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define BIRCH_KEY_ESCAPE 256
#define BIRCH_KEY_ENTER 257
#define BIRCH_KEY_TAB 258
#define BIRCH_KEY_BACKSPACE 259
#define BIRCH_KEY_INSERT 260
#define BIRCH_KEY_DELETE 261
#define BIRCH_KEY_RIGHT 262
#define BIRCH_KEY_LEFT 263
#define BIRCH_KEY_DOWN 264
#define BIRCH_KEY_UP 265
#define BIRCH_KEY_PAGE_UP 266
#define BIRCH_KEY_PAGE_DOWN 267
#define BIRCH_KEY_HOME 268
#define BIRCH_KEY_END 269
#define BIRCH_KEY_CAPS_LOCK 280
#define BIRCH_KEY_SCROLL_LOCK 281
#define BIRCH_KEY_NUM_LOCK 282
#define BIRCH_KEY_PRINT_SCREEN 283
#define BIRCH_KEY_PAUSE 284
#define BIRCH_KEY_F1 290
#define BIRCH_KEY_F2 291
#define BIRCH_KEY_F3 292
#define BIRCH_KEY_F4 293
#define BIRCH_KEY_F5 294
#define BIRCH_KEY_F6 295
#define BIRCH_KEY_F7 296
#define BIRCH_KEY_F8 297
#define BIRCH_KEY_F9 298
#define BIRCH_KEY_F10 299
#define BIRCH_KEY_F11 300
#define BIRCH_KEY_F12 301
#define BIRCH_KEY_F13 302
#define BIRCH_KEY_F14 303
#define BIRCH_KEY_F15 304
#define BIRCH_KEY_F16 305
#define BIRCH_KEY_F17 306
#define BIRCH_KEY_F18 307
#define BIRCH_KEY_F19 308
#define BIRCH_KEY_F20 309
#define BIRCH_KEY_F21 310
#define BIRCH_KEY_F22 311
#define BIRCH_KEY_F23 312
#define BIRCH_KEY_F24 313
#define BIRCH_KEY_F25 314
#define BIRCH_KEY_KP_0 320
#define BIRCH_KEY_KP_1 321
#define BIRCH_KEY_KP_2 322
#define BIRCH_KEY_KP_3 323
#define BIRCH_KEY_KP_4 324
#define BIRCH_KEY_KP_5 325
#define BIRCH_KEY_KP_6 326
#define BIRCH_KEY_KP_7 327
#define BIRCH_KEY_KP_8 328
#define BIRCH_KEY_KP_9 329
#define BIRCH_KEY_KP_DECIMAL 330
#define BIRCH_KEY_KP_DIVIDE 331
#define BIRCH_KEY_KP_MULTIPLY 332
#define BIRCH_KEY_KP_SUBTRACT 333
#define BIRCH_KEY_KP_ADD 334
#define BIRCH_KEY_KP_ENTER 335
#define BIRCH_KEY_KP_EQUAL 336
#define BIRCH_KEY_LEFT_SHIFT 340
#define BIRCH_KEY_LEFT_CONTROL 341
#define BIRCH_KEY_LEFT_ALT 342
#define BIRCH_KEY_LEFT_SUPER 343
#define BIRCH_KEY_RIGHT_SHIFT 344
#define BIRCH_KEY_RIGHT_CONTROL 345
#define BIRCH_KEY_RIGHT_ALT 346
#define BIRCH_KEY_RIGHT_SUPER 347
#define BIRCH_KEY_MENU 348

#define BIRCH_KEY_LAST BIRCH_KEY_MENU

#define BIRCH_MOUSE_BUTTON_1 0
#define BIRCH_MOUSE_BUTTON_2 1
#define BIRCH_MOUSE_BUTTON_3 2
#define BIRCH_MOUSE_BUTTON_4 3
#define BIRCH_MOUSE_BUTTON_5 4
#define BIRCH_MOUSE_BUTTON_6 5
#define BIRCH_MOUSE_BUTTON_7 6
#define BIRCH_MOUSE_BUTTON_8 7
#define BIRCH_MOUSE_BUTTON_9 8
#define BIRCH_MOUSE_BUTTON_10 9
#define BIRCH_MOUSE_BUTTON_LAST BIRCH_MOUSE_BUTTON_8
#define BIRCH_MOUSE_BUTTON_LEFT BIRCH_MOUSE_BUTTON_1
#define BIRCH_MOUSE_BUTTON_RIGHT BIRCH_MOUSE_BUTTON_2
#define BIRCH_MOUSE_BUTTON_MIDDLE BIRCH_MOUSE_BUTTON_3

typedef struct
{
    unsigned int width;
    unsigned int height;
    const char *title;
    void (*mouseMovedCallback)(int x, int y);
    void (*resizeCallback)(int width, int height);
    void (*keyPressedCallback)(int key);
    void (*keyReleasedCallback)(int key);
    void (*mouseButtonPressedCallback)(int button);
    void (*mouseButtonReleasedCallback)(int button);
} BirchWindow;

BirchWindow *
birchWindowNew(unsigned int width, unsigned int height, const char *title);
void birchWindowFree(BirchWindow *window);
void birchWindowUpdate(BirchWindow *window);
bool birchWindowShouldClose(BirchWindow *window);

void birchWindowSetMouseMovedCallback(
    BirchWindow *window,
    void (*mouseMovedCallback)(int x, int y)
);

void birchWindowSetResizeCallback(
    BirchWindow *window,
    void (*resizeCallback)(int width, int height)
);

void birchWindowSetKeyPressedCallback(
    BirchWindow *window,
    void (*keyPressedCallback)(int key)
);

void birchWindowSetKeyReleasedCallback(
    BirchWindow *window,
    void (*keyReleasedCallback)(int key)
);

void birchWindowSetMouseButtonPressedCallback(
    BirchWindow *window,
    void (*mouseButtonPressedCallback)(int button)
);

void birchWindowSetMouseButtonReleasedCallback(
    BirchWindow *window,
    void (*mouseButtonReleasedCallback)(int button)
);

#endif
