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

#include "init.h"
#include <Cocoa/Cocoa.h>

@interface AppMenu : NSMenu
@end

@implementation AppMenu
- (instancetype)initWithTitle:(NSString *)title
{
    self = [super initWithTitle:title];

    @autoreleasepool
    {
        NSMenuItem *quit = [NSMenuItem alloc];
        quit.submenu = [[NSMenu alloc] initWithTitle:@"quit"];
        [quit.submenu
            addItem:[[NSMenuItem alloc]
                        initWithTitle:[NSString
                                          stringWithFormat:@"Quit %@", title]
                               action:@selector(terminate:)
                        keyEquivalent:@"q"]];
        [self addItem:quit];
    }

    return self;
}
@end

void birchInit(const char *name)
{
    [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];

    AppMenu *menu =
        [[AppMenu alloc] initWithTitle:[NSString stringWithUTF8String:name]];
    NSApp.mainMenu = menu;

    [NSApp finishLaunching];
}

void birchTerminate()
{
    [NSApp terminate:nil];
    [NSApp release];
}
