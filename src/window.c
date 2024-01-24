/**
 * Copyright (C) 2024 Devin Rockwell
 *
 * This file is part of birch.
 *
 * birch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * birch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with birch.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "window.h"
#include <stdlib.h>

void
birchWindowSetMouseMovedCallback(BirchWindow *window,
                                 void (*mouseMovedCallback)(int x, int y))
{
  window->mouseMovedCallback = mouseMovedCallback;
}

void
birchWindowSetResizeCallback(BirchWindow *window,
                             void (*resizeCallback)(int width, int height))
{
  window->resizeCallback = resizeCallback;
}

void
birchWindowSetKeyPressedCallback(BirchWindow *window,
                                 void (*keyPressedCallback)(int key))
{
  window->keyPressedCallback = keyPressedCallback;
}

void
birchWindowSetKeyReleasedCallback(BirchWindow *window,
                                  void (*keyReleasedCallback)(int key))
{
  window->keyReleasedCallback = keyReleasedCallback;
}

void
birchWindowSetMouseButtonPressedCallback(
    BirchWindow *window, void (*mouseButtonPressedCallback)(int button))
{
  window->mouseButtonPressedCallback = mouseButtonPressedCallback;
}

void
birchWindowSetMouseButtonReleasedCallback(
    BirchWindow *window, void (*mouseButtonReleasedCallback)(int button))
{
  window->mouseButtonReleasedCallback = mouseButtonReleasedCallback;
}