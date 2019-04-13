/*
Copyright (c) 2007 Muhammad Haggag

This software is provided 'as-is', without any express or implied warranty. In no event 
will the author(s) be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including 
commercial applications, and to alter it and redistribute it freely, subject to 
the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you 
wrote the original software. If you use this software in a product, an acknowledgment in 
the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented 
as being the original software.

3. This notice may not be removed or altered from any source distribution.
*/
#include "stdafx.h"
#include "OverlayRectangle.h"
#include "Exception.h"

namespace Overlay
{
	Rectangle CreateSourceRectangle(
		const DDCAPS& caps, 
		int x, 
		int y, 
		int width, 
		int height)
	{
		if(caps.dwCaps & DDCAPS_ALIGNBOUNDARYSRC && caps.dwAlignBoundarySrc != 0)
			x = Align(x, caps.dwAlignBoundarySrc);

		if(caps.dwCaps & DDCAPS_ALIGNSIZESRC && caps.dwAlignSizeSrc != 0)
			width = Align(width, caps.dwAlignSizeSrc);

		return Rectangle(x, y, width, height);
	}

	Rectangle CreateDestinationRectangle(
		const DDCAPS& caps,
		const Rectangle& sourceRectangle,
		int x, 
		int y, 
		int width, 
		int height)
	{
		if(caps.dwCaps & DDCAPS_ALIGNBOUNDARYDEST && caps.dwAlignBoundaryDest != 0)
			x = Align(x, caps.dwAlignBoundaryDest);

		if(caps.dwCaps & DDCAPS_OVERLAYSTRETCH)
		{
			/*
			We check whether: MinStretch <= width/sourceWidth <= MaxStretch
			However, MinStretch and MaxStretch are both stored multiplied by 1000, so
			we scale width as well
			*/			
			const DWORD minStretch = caps.dwMinOverlayStretch;
			const DWORD maxStretch = caps.dwMaxOverlayStretch;
			const DWORD scaledWidth = 1000 * width;
			const DWORD sourceWidth = sourceRectangle.Width();
			const bool minStretchSatisifed = (sourceWidth * minStretch <= scaledWidth);
			const bool maxStretchSatisfied = (sourceWidth * maxStretch >= scaledWidth);

			if(!minStretchSatisifed)
				width = (sourceWidth * minStretch) / 1000;
			else if(!maxStretchSatisfied)
				width = sourceWidth * (maxStretch / 1000);
		}

		if(caps.dwCaps & DDCAPS_ALIGNSIZEDEST && caps.dwAlignSizeDest != 0)
			width = Align(width, caps.dwAlignSizeDest);

		return Rectangle(x, y, width, height);
	}

	int Align(int value, int alignment)
	{
		const int remainder = value % alignment;
		if(remainder)
			return value - remainder + alignment;

		return value;
	}
}