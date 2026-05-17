#include "mouse.h"
#include <Cocoa/Cocoa.h>

MousePos getGlobalMousePos()
{
	NSPoint mouseLocation = [NSEvent mouseLocation];
	ScreenDimensions screen = getScreenDimensions();
	int flippedY = screen.height - (int)mouseLocation.y;

	return { (int)mouseLocation.x , flippedY };

}


ScreenDimensions getScreenDimensions()
{
	NSRect visibleRect = [[NSScreen mainScreen] visibleFrame];
	CGFloat visibleWidth = visibleRect.size.width;
	CGFloat visibleHeight = visibleRect.size.height;
	return { (int)visibleWidth, (int)visibleHeight };
}
