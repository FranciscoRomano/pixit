// -------------------------------------------------------------------------------------------------------------------------- //
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Francisco Romano
// -------------------------------------------------------------------------------------------------------------------------- //
#include "module.h"
// -------------------------------------------------------------------------------------------------------------------------- //

struct _Module_x11 _x11 = { NULL };

bool _FreeModule_x11()
{
    // check if module is unloaded
    if (!_x11.OK) return false;

    // check if windows have been closed
    ASSERT(_x11.window_count == 0, false, "uninitialized X11 windows")

    // close the connection to the X server
    if (_libX11.XCloseDisplay(_x11.display) != 0)
    {
        printf("ERROR: failed to close X11 display\n");
        return false;
    }

    _free_libX11_so();
    _x11.OK = false;
    return true;
}

bool _LoadModule_x11()
{
    // check if module is loaded
    if (_x11.OK) return true;

    // load the "libX11.so" library
    if (!_load_libX11_so())
    {
        printf("ERROR: failed to load library 'libX11.so'\n");
        return false;
    }

    // open a connection to the X server
    _x11.display = _libX11.XOpenDisplay(NULL);
    assert(_x11.display, "failed to open X11 display")

    // get a unique or the default context
    _x11.context = (XContext)_libX11.XrmUniqueQuark();
    assert(_x11.context, "failed to fetch X11 context")

    // get the display's default root window
    _x11.root_window = _libX11.XDefaultRootWindow(_x11.display);
    assert(_x11.root_window, "failed to get X11 root window")

    // get the internal atom 'WM_DELETE_WINDOW'
    _x11.WM_DELETE_WINDOW = _libX11.XInternAtom(_x11.display, "WM_DELETE_WINDOW", 0);
    assert(_x11.WM_DELETE_WINDOW, "failed to get X11 'WM_DELETE_WINDOW' atom")

    _x11.OK = true;
    return true;
}

// -------------------------------------------------------------------------------------------------------------------------- //