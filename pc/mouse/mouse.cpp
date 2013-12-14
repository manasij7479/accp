#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdexcept>
#include "mouse.hpp"
namespace mm
{
	void Mouse::move(int x,int y)
	{

		Display *displayMain = XOpenDisplay(NULL);

		if(!displayMain)
			return;

		XWarpPointer(displayMain, None, None, 0, 0, 0, 0, x, y);

		XCloseDisplay(displayMain);

	}
}