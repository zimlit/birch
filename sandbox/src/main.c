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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PU/Users/devinr/projects/birch/sandbox/src/main.cRPOSE.  See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with birch.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <birch/init.h>
#include <birch/window.h>

int main()
{
    birchInit("Sandbox");

    BirchWindow *window = birchWindowNew(800, 600, "sandbox");

    while (!birchWindowShouldClose(window))
    {
        birchWindowUpdate(window);
    }

    birchTerminate();
}
