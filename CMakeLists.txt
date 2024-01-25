# Copyright (C) 2024 Devin Rockwell
# 
# This file is part of birch.
# 
# birch is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# birch is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with birch.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.16)

project(
    birch
    VERSION 0.1
    LANGUAGES C
)

add_executable(birch src/main.c src/window.h src/window.c vendor/glad/src/gl.c vendor/glad/include/glad/gl.h)

set_property(TARGET birch PROPERTY C_STANDARD 99)

target_include_directories(birch PRIVATE src)

target_include_directories(birch PUBLIC vendor/glad/include)

if(MSVC)
  target_compile_options(birch PRIVATE /W4)
else()
  target_compile_options(birch PRIVATE -Wall -Wextra -Wpedantic)
endif()

if (WIN32)
  target_sources(birch PRIVATE src/platform/win32/win32window.c vendor/glad/src/wgl.c vendor/glad/include/glad/wgl.h)
  target_link_libraries(birch PRIVATE opengl32)
endif()