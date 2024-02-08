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

#include "window.h"
#include <Cocoa/Cocoa.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MacosWindow MacosWindow;

@interface MacosWindowDelegate : NSObject <NSWindowDelegate>
{
  MacosWindow *window;
}

- (instancetype)initWithWindow:(MacosWindow *)window;
@end

struct MacosWindow
{
  BirchWindow base;
  NSWindow *window;
  NSView *view;
  NSRect rect;
  bool shouldClose;
  MacosWindowDelegate *delegate;
};

@implementation MacosWindowDelegate
- (instancetype)initWithWindow:(MacosWindow *)initWindow
{
  self = [super init];
  if (self != nil)
    window = initWindow;
  return self;
}

- (BOOL)windowShouldClose:(NSWindow *)sender
{
  window->shouldClose = true;
  return YES;
}

- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize
{
  window->base.width  = frameSize.width;
  window->base.height = frameSize.height;

  if (window->base.resizeCallback)
    {
      window->base.resizeCallback(frameSize.width, frameSize.height);
    }
  return frameSize;
}
@end

@interface MacosView : NSView
{
  MacosWindow *window;
}

- (instancetype)initWithFrame:(NSRect)frameRect window:(MacosWindow *)window;

@end

@implementation MacosView
- (instancetype)initWithFrame:(NSRect)frameRect
                       window:(MacosWindow *)initWindow
{
  self = [super initWithFrame:frameRect];
  if (self != nil)
    window = initWindow;
  return self;
}

- (void)mouseMoved:(NSEvent *)event
{
  if (window->base.mouseMovedCallback)
    {
      window->base.mouseMovedCallback(event.locationInWindow.x,
                                      event.locationInWindow.y);
    }
}
@end

BirchWindow *
birchWindowNew(unsigned int width, unsigned int height, const char *title)
{
  MacosWindow *window = malloc(sizeof(MacosWindow));
  if (!window)
    {
      return NULL;
    }

  window->base.width                       = width;
  window->base.height                      = height;
  window->base.title                       = title;
  window->base.mouseMovedCallback          = NULL;
  window->base.resizeCallback              = NULL;
  window->base.keyPressedCallback          = NULL;
  window->base.keyReleasedCallback         = NULL;
  window->base.mouseButtonPressedCallback  = NULL;
  window->base.mouseButtonReleasedCallback = NULL;
  window->shouldClose                      = false;

  window->rect   = NSMakeRect(0, 0, width, height);
  window->window = [[NSWindow alloc]
      initWithContentRect:window->rect
                styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable
                          | NSWindowStyleMaskResizable
                  backing:NSBackingStoreBuffered
                    defer:NO];

  [window->window setTitle:[NSString stringWithUTF8String:title]];
  window->view = [[MacosView alloc] initWithFrame:window->rect window:window];
  [window->window setContentView:window->view];
  window->delegate = [[MacosWindowDelegate alloc] initWithWindow:window];
  [window->window setDelegate:window->delegate];
  [window->window
      setCollectionBehavior:NSWindowCollectionBehaviorFullScreenPrimary];
  [window->window setAcceptsMouseMovedEvents:YES];
  [window->window makeFirstResponder:window->view];
  [window->window makeKeyAndOrderFront:nil];

  return (BirchWindow *)window;
}

void
birchWindowFree(BirchWindow *window)
{
  MacosWindow *macosWindow = (MacosWindow *)window;
  [macosWindow->window release];
  [macosWindow->view release];
  [macosWindow->delegate release];
  free(macosWindow);
  macosWindow = NULL;
}

void
birchWindowUpdate(BirchWindow *window)
{
  MacosWindow *macosWindow = (MacosWindow *)window;
  @autoreleasepool
  {
    for (;;)
      {
        NSEvent *event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                               inMode:NSDefaultRunLoopMode
                                              dequeue:YES];
        if (event == nil)
          {
            break;
          }
        [NSApp sendEvent:event];
        [NSApp updateWindows];
      }
  }
}

bool
birchWindowShouldClose(BirchWindow *window)
{
  MacosWindow *macosWindow = (MacosWindow *)window;
  return macosWindow->shouldClose;
}
