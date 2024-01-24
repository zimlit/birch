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
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static int32_t keyMap[] = {
  [VK_SPACE]            = BIRCH_KEY_SPACE,
  [VK_OEM_7]            = BIRCH_KEY_APOSTROPHE,
  [VK_OEM_COMMA]        = BIRCH_KEY_COMMA,
  [VK_OEM_MINUS]        = BIRCH_KEY_MINUS,
  [VK_OEM_PERIOD]       = BIRCH_KEY_PERIOD,
  [VK_OEM_2]            = BIRCH_KEY_SLASH,
  ['0']                 = BIRCH_KEY_0,
  ['1']                 = BIRCH_KEY_1,
  ['2']                 = BIRCH_KEY_2,
  ['3']                 = BIRCH_KEY_3,
  ['4']                 = BIRCH_KEY_4,
  ['5']                 = BIRCH_KEY_5,
  ['6']                 = BIRCH_KEY_6,
  ['7']                 = BIRCH_KEY_7,
  ['8']                 = BIRCH_KEY_8,
  ['9']                 = BIRCH_KEY_9,
  [VK_OEM_1]            = BIRCH_KEY_SEMICOLON,
  [VK_OEM_PLUS]         = BIRCH_KEY_EQUAL,
  ['A']                 = BIRCH_KEY_A,
  ['B']                 = BIRCH_KEY_B,
  ['C']                 = BIRCH_KEY_C,
  ['D']                 = BIRCH_KEY_D,
  ['E']                 = BIRCH_KEY_E,
  ['F']                 = BIRCH_KEY_F,
  ['G']                 = BIRCH_KEY_G,
  ['H']                 = BIRCH_KEY_H,
  ['I']                 = BIRCH_KEY_I,
  ['J']                 = BIRCH_KEY_J,
  ['K']                 = BIRCH_KEY_K,
  ['L']                 = BIRCH_KEY_L,
  ['M']                 = BIRCH_KEY_M,
  ['N']                 = BIRCH_KEY_N,
  ['O']                 = BIRCH_KEY_O,
  ['P']                 = BIRCH_KEY_P,
  ['Q']                 = BIRCH_KEY_Q,
  ['R']                 = BIRCH_KEY_R,
  ['S']                 = BIRCH_KEY_S,
  ['T']                 = BIRCH_KEY_T,
  ['U']                 = BIRCH_KEY_U,
  ['V']                 = BIRCH_KEY_V,
  ['W']                 = BIRCH_KEY_W,
  ['X']                 = BIRCH_KEY_X,
  ['Y']                 = BIRCH_KEY_Y,
  ['Z']                 = BIRCH_KEY_Z,
  [VK_OEM_4]            = BIRCH_KEY_LEFT_BRACKET,
  [VK_OEM_5]            = BIRCH_KEY_BACKSLASH,
  [VK_OEM_6]            = BIRCH_KEY_RIGHT_BRACKET,
  [VK_OEM_3]            = BIRCH_KEY_GRAVE_ACCENT,
  [VK_ESCAPE]           = BIRCH_KEY_ESCAPE,
  [VK_RETURN]           = BIRCH_KEY_ENTER,
  [VK_TAB]              = BIRCH_KEY_TAB,
  [VK_BACK]             = BIRCH_KEY_BACKSPACE,
  [VK_INSERT]           = BIRCH_KEY_INSERT,
  [VK_DELETE]           = BIRCH_KEY_DELETE,
  [VK_RIGHT]            = BIRCH_KEY_RIGHT,
  [VK_LEFT]             = BIRCH_KEY_LEFT,
  [VK_DOWN]             = BIRCH_KEY_DOWN,
  [VK_UP]               = BIRCH_KEY_UP,
  [VK_PRIOR]            = BIRCH_KEY_PAGE_UP,
  [VK_NEXT]             = BIRCH_KEY_PAGE_DOWN,
  [VK_HOME]             = BIRCH_KEY_HOME,
  [VK_END]              = BIRCH_KEY_END,
  [VK_CAPITAL]          = BIRCH_KEY_CAPS_LOCK,
  [VK_SCROLL]           = BIRCH_KEY_SCROLL_LOCK,
  [VK_NUMLOCK]          = BIRCH_KEY_NUM_LOCK,
  [VK_PRINT]            = BIRCH_KEY_PRINT_SCREEN,
  [VK_MEDIA_PLAY_PAUSE] = BIRCH_KEY_PAUSE,
  [VK_F1]               = BIRCH_KEY_F1,
  [VK_F2]               = BIRCH_KEY_F2,
  [VK_F3]               = BIRCH_KEY_F3,
  [VK_F4]               = BIRCH_KEY_F4,
  [VK_F5]               = BIRCH_KEY_F5,
  [VK_F6]               = BIRCH_KEY_F6,
  [VK_F7]               = BIRCH_KEY_F7,
  [VK_F8]               = BIRCH_KEY_F8,
  [VK_F9]               = BIRCH_KEY_F9,
  [VK_F10]              = BIRCH_KEY_F10,
  [VK_F11]              = BIRCH_KEY_F11,
  [VK_F12]              = BIRCH_KEY_F12,
  [VK_F13]              = BIRCH_KEY_F13,
  [VK_F14]              = BIRCH_KEY_F14,
  [VK_F15]              = BIRCH_KEY_F15,
  [VK_F16]              = BIRCH_KEY_F16,
  [VK_F17]              = BIRCH_KEY_F17,
  [VK_F18]              = BIRCH_KEY_F18,
  [VK_F19]              = BIRCH_KEY_F19,
  [VK_F20]              = BIRCH_KEY_F20,
  [VK_F21]              = BIRCH_KEY_F21,
  [VK_F22]              = BIRCH_KEY_F22,
  [VK_F23]              = BIRCH_KEY_F23,
  [VK_F24]              = BIRCH_KEY_F24,
  [0]                   = BIRCH_KEY_F25,
  [VK_NUMPAD0]          = BIRCH_KEY_KP_0,
  [VK_NUMPAD1]          = BIRCH_KEY_KP_1,
  [VK_NUMPAD2]          = BIRCH_KEY_KP_2,
  [VK_NUMPAD3]          = BIRCH_KEY_KP_3,
  [VK_NUMPAD4]          = BIRCH_KEY_KP_4,
  [VK_NUMPAD5]          = BIRCH_KEY_KP_5,
  [VK_NUMPAD6]          = BIRCH_KEY_KP_6,
  [VK_NUMPAD7]          = BIRCH_KEY_KP_7,
  [VK_NUMPAD8]          = BIRCH_KEY_KP_8,
  [VK_NUMPAD9]          = BIRCH_KEY_KP_9,
  [VK_DECIMAL]          = BIRCH_KEY_KP_DECIMAL,
  [VK_DIVIDE]           = BIRCH_KEY_KP_DIVIDE,
  [VK_MULTIPLY]         = BIRCH_KEY_KP_MULTIPLY,
  [VK_SUBTRACT]         = BIRCH_KEY_KP_SUBTRACT,
  [VK_ADD]              = BIRCH_KEY_KP_ADD,
  [VK_RETURN]           = BIRCH_KEY_KP_ENTER,
  [VK_OEM_PLUS]         = BIRCH_KEY_KP_EQUAL,
  [VK_SHIFT]            = BIRCH_KEY_LEFT_SHIFT,
  [VK_CONTROL]          = BIRCH_KEY_LEFT_CONTROL,
  [VK_LMENU]            = BIRCH_KEY_LEFT_ALT,
  [VK_LWIN]             = BIRCH_KEY_LEFT_SUPER,
  [VK_SHIFT]            = BIRCH_KEY_RIGHT_SHIFT,
  [VK_CONTROL]          = BIRCH_KEY_RIGHT_CONTROL,
  [VK_RMENU]            = BIRCH_KEY_RIGHT_ALT,
  [VK_RWIN]             = BIRCH_KEY_RIGHT_SUPER,
  [VK_MENU]             = BIRCH_KEY_MENU,
  [VK_OEM_102]          = BIRCH_KEY_UNKNOWN,
};

typedef struct
{
  BirchWindow base;
  HWND hwnd;
  wchar_t *title_w;
  bool should_close;
  HINSTANCE hinstance;
} Win32Window;

LRESULT CALLBACK
birchWindowProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam)
{
  Win32Window *window = (Win32Window *)GetWindowLongPtrW(hwnd, GWLP_USERDATA);

  switch (uMsg)
    {
    case WM_DESTROY:
      window->should_close = true;
      return 0;
    }
  return DefWindowProcW(hwnd, uMsg, wparam, lparam);
}

BirchWindow *
birchWindowNew(unsigned int width, unsigned int height, const char *title)
{
  Win32Window *window = malloc(sizeof(Win32Window));
  if (!window)
    {
      return NULL;
    }

  char error_message[30];

  window->base.width                       = width;
  window->base.height                      = height;
  window->base.title                       = title;
  window->base.mouseMovedCallback          = NULL;
  window->base.resizeCallback              = NULL;
  window->base.keyPressedCallback          = NULL;
  window->base.keyReleasedCallback         = NULL;
  window->base.mouseButtonPressedCallback  = NULL;
  window->base.mouseButtonReleasedCallback = NULL;
  window->should_close                     = false;

  HINSTANCE hinstance = GetModuleHandle(NULL);
  window->hinstance   = hinstance;

  const wchar_t CLAS_NAME[] = L"birch";
  WNDCLASS wc               = { 0 };
  wc.lpfnWndProc            = birchWindowProc;
  wc.hInstance              = hinstance;
  wc.lpszClassName          = CLAS_NAME;
  wc.cbWndExtra             = sizeof(Win32Window *);

  if (!RegisterClassW((const WNDCLASS *)&wc))
    {
      snprintf(error_message, 30, "RegisterClassW() failed with code %d",
               GetLastError());
      MessageBoxW(NULL, L"RegisterClassW() failed", L"Error", MB_ICONERROR);

      return NULL;
    }

  size_t title_len = strlen(title) + 1;
  window->title_w  = malloc(title_len * sizeof(wchar_t));
  mbstowcs_s(NULL, window->title_w, title_len, title, title_len);

  window->hwnd = CreateWindowExW(
      0, CLAS_NAME, window->title_w, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
      CW_USEDEFAULT, width, height, NULL, NULL, hinstance, NULL);
  SetWindowLongPtrW(window->hwnd, GWLP_USERDATA, (LONG_PTR)window);

  if (!window->hwnd)
    {
      snprintf(error_message, 30, "CreateWindowExW() failed with code %d",
               GetLastError());
      MessageBoxW(NULL, L"CreateWindowExW() failed", L"Error", MB_ICONERROR);

      return NULL;
    }

  ShowWindow(window->hwnd, SW_SHOWDEFAULT);

  return (BirchWindow *)window;
}

void
birchWindowFree(BirchWindow *window)
{
  Win32Window *win32_window = (Win32Window *)window;

  DestroyWindow(win32_window->hwnd);
  UnregisterClassW(L"birch", win32_window->hinstance);
  free(win32_window->title_w);
  free(win32_window);
}

void
birchWindowUpdate(BirchWindow *window)
{
  Win32Window *win32_window = (Win32Window *)window;

  MSG msg;
  while (PeekMessageW(&msg, win32_window->hwnd, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessageW(&msg);
    }
}

bool
birchWindowShouldClose(BirchWindow *window)
{
  Win32Window *win32_window = (Win32Window *)window;

  return win32_window->should_close;
}