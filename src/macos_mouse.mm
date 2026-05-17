#include "mouse.h"
#include <Cocoa/Cocoa.h>

MousePos getGlobalMousePos()
{
	NSPoint mouseLocation = [NSEvent mouseLocation];
	return { (int)mouseLocation.x , (int)mouseLocation.y };

}


ScreenDimensions getScreenDimensions()
{
	NSRect visibleRect = [[NSScreen mainScreen] visibleFrame];
	CGFloat visibleWidth = visibleRect.size.width;
	CGFloat visibleHeight = visibleRect.size.height;
	return { (int)visibleWidth, (int)visibleHeight };
}
