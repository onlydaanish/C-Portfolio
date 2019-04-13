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
	class ImageRgb
	{
	public:
		ImageRgb()
			:
		data_(0), pitch_(0), width_(0), height_(0), bytesPerPixel_(0), redMask_(0), 
		greenMask_(0), blueMask_(0), redShift_(0), greenShift_(0), blueShift_(0)
		{
		}
		
		BYTE* Data() const { return data_; }
		ImageRgb& Data(BYTE* val) { data_ = val; return *this; }

		int Pitch() const { return pitch_; }
		ImageRgb& Pitch(int val) { pitch_ = val; return *this; }

		int Height() const { return height_; }
		ImageRgb& Height(int val) { height_ = val; return *this; }

		int Width() const { return width_; }
		ImageRgb& Width(int val) { width_ = val; return *this; }

		int BytesPerPixel() const { return bytesPerPixel_; }
		ImageRgb& BytesPerPixel(int val) { bytesPerPixel_ = val; return *this; }

		int BlueMask() const { return blueMask_; }
		ImageRgb& BlueMask(int val) { blueMask_ = val; return *this; }

		int GreenMask() const { return greenMask_; }
		ImageRgb& GreenMask(int val) { greenMask_ = val; return *this; }

		int RedMask() const { return redMask_; }
		ImageRgb& RedMask(int val) { redMask_ = val; return *this; }

		int BlueShift() const { return blueShift_; }
		ImageRgb& BlueShift(int val) { blueShift_ = val; return *this; }

		int GreenShift() const { return greenShift_; }
		ImageRgb& GreenShift(int val) { greenShift_ = val; return *this; }

		int RedShift() const { return redShift_; }
		ImageRgb& RedShift(int val) { redShift_ = val; return *this; }

		int MaxRed() const { return redMask_ >> redShift_; }
		int MaxGreen() const { return greenMask_ >> greenShift_; }
		int MaxBlue() const { return blueMask_ >> blueShift_; }

		bool IsValid() const
		{
			return 
				data_ &&
				pitch_ > 0 &&
				width_ > 0 &&
				height_ > 0 &&
				bytesPerPixel_ > 0 && bytesPerPixel_ <= 4 &&
				redMask_ &&
				greenMask_ &&
				blueMask_ &&
				(redShift_ != greenShift_ &&
				greenShift_ != blueShift_ &&
				redShift_ != blueShift_);
		}

	private:
		BYTE* data_;
		int pitch_;
		int width_, height_;
		int bytesPerPixel_;
		int redMask_, greenMask_, blueMask_;
		int redShift_, greenShift_, blueShift_;
	};

	void Blit(
		IDirectDrawSurface7* destinationSurface,
		int xDest, int yDest,
		const ImageRgb& image,
		int xSrc, int ySrc);
}