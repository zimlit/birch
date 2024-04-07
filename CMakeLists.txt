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

cmake_minimum_required(VERSION 3.29)

include(cmake/FileEmbed.cmake)

project(
    birch
    VERSION 0.1
    LANGUAGES C
)

add_library(birch include/birch/init.h include/birch/window.h src/window.c)
target_include_directories(birch PRIVATE vendor/glad/include include/birch)
target_include_directories(birch INTERFACE include)
set_property(TARGET birch PROPERTY C_STANDARD 99)

add_subdirectory(sandbox)

if (WIN32)
  target_link_libraries(birch PRIVATE opengl32)
  target_sources(birch PRIVATE src/platform/win32/win32window.c src/platform/win32/win32init.c)
elseif(APPLE)
  target_sources(birch PRIVATE src/platform/macos/macosWindow.m src/platform/macos/macosInit.m)
  target_link_libraries(birch PRIVATE "-framework Cocoa -framework MetalKit -framework Metal")

  add_custom_command(
    OUTPUT "${CMAKE_BINARY_DIR}/shaders.metallib"
    COMMAND xcrun -sdk macosx metal -c "${CMAKE_SOURCE_DIR}/src/platform/macos/shaders.metal" -o "${CMAKE_BINARY_DIR}/shaders.air"
    COMMAND xcrun -sdk macosx metallib "${CMAKE_BINARY_DIR}/shaders.air" -o "${CMAKE_BINARY_DIR}/shaders.metallib"
    DEPENDS "${CMAKE_SOURCE_DIR}/src/platform/macos/shaders.metal"
  )

  add_custom_target(
    shaders ALL
    DEPENDS "${CMAKE_BINARY_DIR}/shaders.metallib"
  )

  FileEmbedSetup()
  FileEmbedAdd("${CMAKE_BINARY_DIR}/shaders.metallib")
  target_link_libraries(birch PRIVATE file_embed)
endif()
