// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "window.h"
#define INVOKE_WINDOW_IMPL(Name, ...)\
if (window->pfn##Name) return window->pfn##Name(window,##__VA_ARGS__); return false;
// -------------------------------------------------------------------------------------------------------------------------- //
bool _CloseWindow(Window window)                                 { INVOKE_WINDOW_IMPL(CloseWindow)               }
bool _DestroyWindow(Window window)                               { INVOKE_WINDOW_IMPL(DestroyWindow)             }
bool _FocusWindow(Window window, bool focus)                     { INVOKE_WINDOW_IMPL(FocusWindow, focus)        }
bool _HideWindow(Window window)                                  { INVOKE_WINDOW_IMPL(HideWindow)                }
bool _MaximizeWindow(Window window)                              { INVOKE_WINDOW_IMPL(MaximizeWindow)            }
bool _MinimizeWindow(Window window)                              { INVOKE_WINDOW_IMPL(MinimizeWindow)            }
bool _MoveWindow(Window window, int32_t left, int32_t top)       { INVOKE_WINDOW_IMPL(MoveWindow, left, top)     }
bool _RestoreWindow(Window window)                               { INVOKE_WINDOW_IMPL(RestoreWindow)             }
bool _ShowWindow(Window window)                                  { INVOKE_WINDOW_IMPL(ShowWindow)                }
bool _SizeWindow(Window window, uint32_t width, uint32_t height) { INVOKE_WINDOW_IMPL(SizeWindow, width, height) }
// -------------------------------------------------------------------------------------------------------------------------- //
bool _CreateWindow(const WindowCreateInfo* pCreateInfo, Window* pWindow)
{
    Window window = (Window)malloc(sizeof(Window_t));
    memset(window, 0, sizeof(Window_t));
    if (pWindow) (*pWindow) = window;

    #if IS_PLATFORM_LINUX
    if (_CreateWindow_X11(pCreateInfo, window)) return true;
    #elif IS_PLATFORM_WINDOWS
    if (_CreateWindow_Win32(pCreateInfo, window)) return true;
    #endif

    free(window);
    return false;
}
// -------------------------------------------------------------------------------------------------------------------------- //
bool _ReadWindowEvents()
{
    bool result = false;
    #if IS_PLATFORM_LINUX
    result |= _ReadWindowEvents_X11();
    #elif IS_PLATFORM_WINDOWS
    result |= _ReadWindowEvents_Win32();
    #endif
    return result;
}
// -------------------------------------------------------------------------------------------------------------------------- //