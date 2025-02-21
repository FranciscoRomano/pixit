// ┌───────────────────────────────────────────────────────────────────────────────────────────┐
// │ Copyright (c) 2025 Francisco Romano                                                       │
// │                                                                                           │
// │ THIS FILE IS A MODIFIED VERSION OF THE ORIGINAL X WINDOWING SYSTEM (AKA: X11, X) LIBRARY. │
// │ MODIFICATIONS ARE DISTRIBUTED UNDER THE SAME ORIGINAL FILE LICENSE, WHICH IS SHOWN BELOW: │
// └───────────────────────────────────────────────────────────────────────────────────────────┘
// 
// Copyright 1987, 1998  The Open Group
// 
// Permission to use, copy, modify, distribute, and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appear in all copies and that both that
// copyright notice and this permission notice appear in supporting
// documentation.
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
// AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// Except as contained in this notice, the name of The Open Group shall not be
// used in advertising or otherwise to promote the sale, use or other dealings
// in this Software without prior written authorization from The Open Group.
// 
// 
// Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts.
// 
//                         All Rights Reserved
// 
// Permission to use, copy, modify, and distribute this software and its
// documentation for any purpose and without fee is hereby granted,
// provided that the above copyright notice appear in all copies and that
// both that copyright notice and this permission notice appear in
// supporting documentation, and that the name of Digital not be
// used in advertising or publicity pertaining to distribution of the
// software without specific, written prior permission.
// 
// DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
// ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
// DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
// ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
// ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
// SOFTWARE.

#ifndef _X11_Xutil_h_
#define _X11_Xutil_h_

// You must include <X11/Xlib.h> before including this file
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdint.h>

// The Xlib structs are full of implicit padding to properly align members
// We can't clean that up without breaking ABI, so tell clang not to bother complaining about it
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

#define AllValues                  0x000F      // Bitmask returned by XParseGeometry()
#define BitmapFileInvalid          2           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapNoMemory             3           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapOpenFailed           1           // Return code for XReadBitmapFile and XWriteBitmapFile
#define BitmapSuccess              0           // Return code for XReadBitmapFile and XWriteBitmapFile
#define HeightValue                0x0008      // Bitmask returned by XParseGeometry()
#define IconicState                3           // application wants to start as an icon
#define IconMaskHint               (1L << 5)   // definition for flags of XWMHints
#define IconPixmapHint             (1L << 2)   // definition for flags of XWMHints
#define IconPositionHint           (1L << 4)   // definition for flags of XWMHints
#define IconWindowHint             (1L << 3)   // definition for flags of XWMHints
#define InputHint                  (1L << 0)   // definition for flags of XWMHints
#define NormalState                1           // most applications want to start this way
#define NoValue                    0x0000      // Bitmask returned by XParseGeometry()
#define PAspect                    (1L << 7)   // program specified min and max aspect ratios
#define PBaseSize                  (1L << 8)   // program specified base for incrementing
#define PMaxSize                   (1L << 5)   // program specified maximum size
#define PMinSize                   (1L << 4)   // program specified minimum size
#define PPosition                  (1L << 2)   // program specified position
#define PResizeInc                 (1L << 6)   // program specified resize increments
#define PSize                      (1L << 3)   // program specified size
#define PWinGravity                (1L << 9)   // program specified window gravity
#define RectangleIn                1           // Return value from XRectInRegion()
#define RectangleOut               0           // Return value from XRectInRegion()
#define RectanglePart              2           // Return value from XRectInRegion()
#define ReleaseByFreeingColormap   ((XID) 1L)  // for killid field
#define StateHint                  (1L << 1)   // definition for flags of XWMHints
#define USPosition                 (1L << 0)   // user specified x, y
#define USSize                     (1L << 1)   // user specified width, height
#define VisualAllMask              0x1FF       // ???
#define VisualBitsPerRGBMask       0x100       // ???
#define VisualBlueMaskMask         0x40        // ???
#define VisualClassMask            0x8         // ???
#define VisualColormapSizeMask     0x80        // ???
#define VisualDepthMask            0x4         // ???
#define VisualGreenMaskMask        0x20        // ???
#define VisualIDMask               0x1         // ???
#define VisualNoMask               0x0         // ???
#define VisualRedMaskMask          0x10        // ???
#define VisualScreenMask           0x2         // ???
#define WidthValue                 0x0004      // Bitmask returned by XParseGeometry()
#define WindowGroupHint            (1L << 6)   // definition for flags of XWMHints
#define WithdrawnState             0           // for windows that are not mapped
#define XCNOENT                    2           // Context management associative lookup table return codes - No entry in table
#define XCNOMEM                    1           // Context management associative lookup table return codes - Out of memory
#define XConverterNotFound         -3          // ???
#define XCSUCCESS                  0           // Context management associative lookup table return codes - No error
#define XLocaleNotSupported        -2          // ???
#define XNegative                  0x0010      // Bitmask returned by XParseGeometry()
#define XNoMemory                  -1          // ???
#define XUrgencyHint               (1L << 8)   // definition for flags of XWMHints
#define XValue                     0x0001      // Bitmask returned by XParseGeometry()
#define YNegative                  0x0020      // Bitmask returned by XParseGeometry()
#define YValue                     0x0002      // Bitmask returned by XParseGeometry()
#define IsCursorKey(keysym)        (((XKeySym)(keysym) >= XK_Home)     && ((XKeySym)(keysym) <  XK_Select))
#define IsFunctionKey(keysym)      (((XKeySym)(keysym) >= XK_F1)       && ((XKeySym)(keysym) <= XK_F35))
#define IsKeypadKey(keysym)        (((XKeySym)(keysym) >= XK_KP_Space) && ((XKeySym)(keysym) <= XK_KP_Equal))
#define IsMiscFunctionKey(keysym)  (((XKeySym)(keysym) >= XK_Select)   && ((XKeySym)(keysym) <= XK_Break))
#define IsModifierKey(keysym)      ((((XKeySym)(keysym) >= XK_Shift_L) && ((XKeySym)(keysym) <= XK_Hyper_R)) || (((XKeySym)(keysym) >= XK_ISO_Lock) && ((XKeySym)(keysym) <= XK_ISO_Level5_Lock)) || ((XKeySym)(keysym) == XK_Mode_switch) || ((XKeySym)(keysym) == XK_Num_Lock))
#define IsPFKey(keysym)            (((XKeySym)(keysym) >= XK_KP_F1)    && ((XKeySym)(keysym) <= XK_KP_F4))
#define IsPrivateKeypadKey(keysym) (((XKeySym)(keysym) >= 0x11000000)  && ((XKeySym)(keysym) <= 0x1100FFFF))
#define XStringToContext(string)   ((XContext)XrmStringToQuark(string))
#define XUniqueContext()           ((XContext)XrmUniqueQuark())

typedef enum XICCEncodingStyle {
    XStringStyle,       // STRING
    XCompoundTextStyle, // COMPOUND_TEXT
    XTextStyle,         // text in owner's encoding (current locale)
    XStdICCTextStyle,   // STRING, else COMPOUND_TEXT
    XUTF8StringStyle    // UTF8_STRING
} XICCEncodingStyle;

typedef struct XSizeHints {
    int64_t                   flags;         // marks which fields in this structure are defined
    int32_t                   x;             // obsolete for new window mgrs, but clients
    int32_t                   y;             // obsolete for new window mgrs, but clients
    int32_t                   width;         // should set so old wm's don't mess up
    int32_t                   height;        // should set so old wm's don't mess up
    int32_t                   min_width;     // ??
    int32_t                   min_height;    // ??
    int32_t                   max_width;     // ??
    int32_t                   max_height;    // ??
    int32_t                   width_inc;     // ??
    int32_t                   height_inc;    // ??
    struct { int32_t x,  y; } min_aspect;    // x: numerator, y: denominator
    struct { int32_t x,  y; } max_aspect;    // x: numerator, y: denominator
    int32_t                   base_width;    // added by ICCCM version 1
    int32_t                   base_height;   // added by ICCCM version 1
    int32_t                   win_gravity;   // added by ICCCM version 1
} XSizeHints;

typedef struct XWMHints {
    int64_t                   flags;         // marks which fields in this structure are defined
    int                       input;         // does this application rely on the window manager to get keyboard input?
    int32_t                   initial_state; // see below
    XPixmap                   icon_pixmap;   // pixmap to be used as icon
    XWindow                   icon_window;   // window to be used as icon
    int32_t                   icon_x;        // initial position of icon
    int32_t                   icon_y;        // initial position of icon
    XPixmap                   icon_mask;     // icon mask bitmap
    XID                       window_group;  // id of related window group
} XWMHints;


typedef struct XTextProperty {
    u_char*                   value;         // same as Property routines
    XAtom                     encoding;      // prop type
    int32_t                   format;        // prop data format: 8, 16, or 32
    uint64_t                  nitems;        // number of data items in value
} XTextProperty;

typedef struct XIconSize {
    int32_t                   min_width;     // ???
    int32_t                   min_height;    // ???
    int32_t                   max_width;     // ???
    int32_t                   max_height;    // ???
    int32_t                   width_inc;     // ???
    int32_t                   height_inc;    // ???
} XIconSize;

typedef struct XClassHint {
    char*                     res_name;      // ???
    char*                     res_class;     // ???
} XClassHint;

typedef struct XComposeStatus {
    void*                     compose_ptr;   // state table pointer
    int32_t                   chars_matched; // match state
} XComposeStatus;

typedef struct XRegion_t* XRegion;

typedef struct XVisualInfo {
  XVisual*                    visual;        // ???
  XVisualID                   visualid;      // ???
  int32_t                     screen;        // ???
  int32_t                     depth;         // ???
  int32_t                     c_class;       // ???
  uint64_t                    red_mask;      // ???
  uint64_t                    green_mask;    // ???
  uint64_t                    blue_mask;     // ???
  int32_t                     colormap_size; // ???
  int32_t                     bits_per_rgb;  // ???
} XVisualInfo;

typedef struct XStandardColormap {
    XColormap                 colormap;      // ???
    uint64_t                  red_max;       // ???
    uint64_t                  red_mult;      // ???
    uint64_t                  green_max;     // ???
    uint64_t                  green_mult;    // ???
    uint64_t                  blue_max;      // ???
    uint64_t                  blue_mult;     // ???
    uint64_t                  base_pixel;    // ???
    XVisualID                 visualid;      // added by ICCCM version 1
    XID                       killid;        // added by ICCCM version 1
} XStandardColormap;

typedef int32_t XContext;

int32_t            XDestroyImage(XImage*);
uint64_t           XGetPixel(XImage*,int32_t,int32_t);
int32_t            XPutPixel(XImage*,int32_t,int32_t,uint64_t);
XImage*            XSubImage(XImage*,int32_t,int32_t,uint32_t,uint32_t);
int32_t            XAddPixel(XImage*,int64_t);
XClassHint*        XAllocClassHint();
XIconSize*         XAllocIconSize();
XSizeHints*        XAllocSizeHints();
XStandardColormap* XAllocStandardColormap();
XWMHints*          XAllocWMHints();
int32_t            XClipBox(XRegion,XRectangle*);
XRegion            XCreateRegion();
const char*        XDefaultString();
int32_t            XDeleteContext(XDisplay*,XID,XContext);
int32_t            XDestroyRegion(XRegion);
int                XEmptyRegion(XRegion);
int                XEqualRegion(XRegion,XRegion);
int32_t            XFindContext(XDisplay*,XID,XContext,void**);
int                XGetClassHint(XDisplay*,XWindow,XClassHint*);
int                XGetIconSizes(XDisplay*,XWindow,XIconSize**,int32_t*); 
int                XGetNormalHints(XDisplay*,XWindow,XSizeHints*); 
int                XGetRGBColormaps(XDisplay*,XWindow,XStandardColormap**,int32_t*,XAtom); 
int                XGetSizeHints(XDisplay*,XWindow,XSizeHints*,XAtom); 
int                XGetStandardColormap(XDisplay*,XWindow,XStandardColormap*,XAtom); 
int                XGetTextProperty(XDisplay*,XWindow,XTextProperty*,XAtom); 
XVisualInfo*       XGetVisualInfo(XDisplay*,int64_t,XVisualInfo*,int32_t*); 
int                XGetWMClientMachine(XDisplay*,XWindow,XTextProperty*); 
XWMHints*          XGetWMHints(XDisplay*,XWindow); 
int                XGetWMIconName(XDisplay*,XWindow,XTextProperty*); 
int                XGetWMName(XDisplay*,XWindow,XTextProperty*); 
int                XGetWMNormalHints(XDisplay*,XWindow,XSizeHints*,int64_t*); 
int                XGetWMSizeHints(XDisplay*,XWindow,XSizeHints*,int64_t*,XAtom); 
int                XGetZoomHints(XDisplay*,XWindow,XSizeHints*); 
int32_t            XIntersectRegion(XRegion,XRegion,XRegion); 
void               XConvertCase(XKeySym,XKeySym*,XKeySym*); 
int32_t            XLookupString(XKeyEvent*,char*,int32_t,XKeySym*,XComposeStatus*); 
int                XMatchVisualInfo(XDisplay*,int32_t,int32_t,int32_t,XVisualInfo*); 
int32_t            XOffsetRegion(XRegion,int32_t,int32_t); 
int                XPointInRegion(XRegion,int32_t,int32_t); 
XRegion            XPolygonRegion(XPoint*,int32_t,int32_t); 
int32_t            XRectInRegion(XRegion,int32_t,int32_t,uint32_t,uint32_t); 
int32_t            XSaveContext(XDisplay*,XID,XContext,const char*); 
int32_t            XSetClassHint(XDisplay*,XWindow,XClassHint*); 
int32_t            XSetIconSizes(XDisplay*,XWindow,XIconSize*,int32_t); 
int32_t            XSetNormalHints(XDisplay*,XWindow,XSizeHints*); 
void               XSetRGBColormaps(XDisplay*,XWindow,XStandardColormap*,int32_t,XAtom); 
int32_t            XSetSizeHints(XDisplay*,XWindow,XSizeHints*,XAtom); 
int32_t            XSetStandardProperties(XDisplay*,XWindow,const char*,const char*,XPixmap,char**,int32_t,XSizeHints*); 
void               XSetTextProperty(XDisplay*,XWindow,XTextProperty*,XAtom); 
void               XSetWMClientMachine(XDisplay*,XWindow,XTextProperty*); 
int32_t            XSetWMHints(XDisplay*,XWindow,XWMHints*); 
void               XSetWMIconName(XDisplay*,XWindow,XTextProperty*); 
void               XSetWMName(XDisplay*,XWindow,XTextProperty*); 
void               XSetWMNormalHints(XDisplay*,XWindow,XSizeHints*); 
void               XSetWMProperties(XDisplay*,XWindow,XTextProperty*,XTextProperty*,char**,int32_t,XSizeHints*,XWMHints*,XClassHint*); 
void               XmbSetWMProperties(XDisplay*,XWindow,const char*,const char*,char**,int32_t,XSizeHints*,XWMHints*,XClassHint*); 
void               Xutf8SetWMProperties(XDisplay*,XWindow,const char*,const char*,char**,int32_t,XSizeHints*,XWMHints*,XClassHint*); 
void               XSetWMSizeHints(XDisplay*,XWindow,XSizeHints*,XAtom); 
int32_t            XSetRegion(XDisplay*,XGC,XRegion); 
void               XSetStandardColormap(XDisplay*,XWindow,XStandardColormap*,XAtom); 
int32_t            XSetZoomHints(XDisplay*,XWindow,XSizeHints*); 
int32_t            XShrinkRegion(XRegion,int32_t,int32_t); 
int                XStringListToTextProperty(char**,int32_t,XTextProperty*); 
int32_t            XSubtractRegion(XRegion,XRegion,XRegion); 
int32_t            XmbTextListToTextProperty(XDisplay*,char**,int32_t,XICCEncodingStyle,XTextProperty*);
int32_t            XwcTextListToTextProperty(XDisplay*,wchar_t**,int32_t,XICCEncodingStyle,XTextProperty*);
int32_t            Xutf8TextListToTextProperty(XDisplay*,char**,int32_t,XICCEncodingStyle,XTextProperty*);
void               XwcFreeStringList(wchar_t**); 
int                XTextPropertyToStringList(XTextProperty*,char***,int32_t*); 
int32_t            XmbTextPropertyToTextList(XDisplay*,const XTextProperty*,char***,int32_t*); 
int32_t            XwcTextPropertyToTextList(XDisplay*,const XTextProperty*,wchar_t***,int32_t*); 
int32_t            Xutf8TextPropertyToTextList(XDisplay*,const XTextProperty*,char***,int32_t*); 
int32_t            XUnionRectWithRegion(XRectangle*,XRegion,XRegion); 
int32_t            XUnionRegion(XRegion,XRegion,XRegion); 
int32_t            XWMGeometry(XDisplay*,int32_t,const char*,const char*,uint32_t,XSizeHints*,int32_t*,int32_t*,int32_t*,int32_t*,int32_t*); 
int32_t            XXorRegion(XRegion,XRegion,XRegion);

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif// _X11_Xutil_h_