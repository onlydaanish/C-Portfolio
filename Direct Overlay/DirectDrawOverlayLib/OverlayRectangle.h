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
#pragma once

#include <ddraw.h>

namespace Overlay
{
	// An immutable rectangle
	class Rectangle
	{
	public:
		Rectangle(
			int x, int y,
			int width, int height)
			: x_(x), y_(y), width_(width), height_(height)
		{
		}

		int Left() const { return x_; }
		int Top() const { return y_; }
		int Width() const { return width_; }
		int Height() const { return height_; }

		RECT ToRECT() const
		{
			const RECT result = { x_, y_, x_ + width_, y_ + height_ };
			return result;
		}

		bool operator==(const Rectangle& rhs) const
		{
			return 
				x_ == rhs.x_ && 
				y_ == rhs.y_ && 
				width_ == rhs.width_ && 
				height_ == rhs.height_;
		}

		bool operator!=(const Rectangle& rhs) const
		{
			return !operator==(rhs);
		}

	private:
		int 
			x_,
			y_,
			width_,
			height_;
	};

	Rectangle CreateSourceRectangle(
		const DDCAPS& caps,
		int x,
		int y,
		int width,
		int height);

	Rectangle CreateDestinationRectangle(
		const DDCAPS& caps,
		const Rectangle& sourceRectangle,
		int x,
		int y,
		int width,
		int height);

	int Align(int value, int alignment);
}