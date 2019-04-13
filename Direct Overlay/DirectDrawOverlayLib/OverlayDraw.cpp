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
#include "OverlayDraw.h"
#include "Exception.h"

namespace
{
	int Clamp(int value, int low, int high)
	{
		if(value < low)
			return low;
		else if(value > high)
			return high;

		return value;
	}
}

namespace Overlay
{
	struct RgbColor
	{
		BYTE red, green, blue;

		static RgbColor FromImage(
			const ImageRgb& image,
			int x, int y)
		{
			assert(x >= 0 && x < image.Width() && y >= 0 && y < image.Height());
			
			const int index = image.BytesPerPixel() * x + y * image.Pitch();
			UINT32 rgb = 0;
			for(int i = 0; i < image.BytesPerPixel(); i++)
				rgb |= image.Data()[index + i] << (i * 8);

			const int red = (rgb & image.RedMask()) >> image.RedShift();
			const int green = (rgb & image.GreenMask()) >> image.GreenShift();
			const int blue = (rgb & image.BlueMask()) >> image.BlueShift();
			
			const RgbColor result =
			{
				red * 255 / image.MaxRed(),
				green * 255 / image.MaxGreen(),
				blue * 255 / image.MaxBlue()
			};
			
			return result;
		}
	};

	struct YuvColor
	{
		BYTE y, u, v;

		static YuvColor FromRgb(const RgbColor& color)
		{
			YuvColor result =
			{
				Clamp(        0.29 * color.red + 0.59 * color.green + 0.14 * color.blue, 0, 235),
				Clamp(128.0 - 0.14 * color.red - 0.29 * color.green + 0.43 * color.blue, 0,240),
				Clamp(128.0 + 0.36 * color.red - 0.29 * color.green - 0.07 * color.blue, 0,240)
			};

			return result;
		}
	};

	typedef void (*BlitFunction)(
		const DDSURFACEDESC2& ddsd,
		int xDest, int yDest, 
		const ImageRgb& image,
		int xSrc, int ySrc);

	// Refer to: http://www.fourcc.org/yuv.php#YUY2 for a specification of the YUY2 format
	void BlitYuy2(
		const DDSURFACEDESC2& ddsd,
		int xDest, int yDest, 
		const ImageRgb& image,
		int xSrc, int ySrc)
	{
		const int width = ddsd.dwWidth;
		const int height = ddsd.dwHeight;
		const int pitch = ddsd.lPitch;
		BYTE* surface = static_cast<BYTE*>(ddsd.lpSurface);

		for(int dy = yDest, sy = ySrc;
			dy < height && sy < image.Height();
			dy++, sy++)
		{
			UINT16* const line = reinterpret_cast<UINT16*>(surface + dy * pitch);
			for(int dx = xDest, sx = xSrc;
				dx < width && sx + 1 < image.Width();
				dx += 2, sx += 2)
			{
				const RgbColor rgb0 = RgbColor::FromImage(image, sx, sy);
				const YuvColor yuv0 = YuvColor::FromRgb(rgb0);

				RgbColor rgb1 = RgbColor::FromImage(image, sx + 1, sy);				
				const YuvColor yuv1 = YuvColor::FromRgb(rgb1);

				BYTE* macroPixel = reinterpret_cast<BYTE*>(line + dx);
				*macroPixel++ = yuv0.y;
				*macroPixel++ = (yuv0.u + yuv1.u) / 2;
				*macroPixel++ = yuv1.y;
				*macroPixel++ = (yuv0.v + yuv1.v) / 2;
			}
		}
	}

	// Refer to: http://www.fourcc.org/yuv.php#UYVY for a specification of the UYVY format
	void BlitUyvy(
		const DDSURFACEDESC2& ddsd,
		int xDest, int yDest, 
		const ImageRgb& image,
		int xSrc, int ySrc)
	{
		const int width = ddsd.dwWidth;
		const int height = ddsd.dwHeight;
		const int pitch = ddsd.lPitch;
		BYTE* surface = static_cast<BYTE*>(ddsd.lpSurface);

		for(int dy = yDest, sy = ySrc;
			dy < height && sy < image.Height();
			dy++, sy++)
		{
			UINT16* const line = reinterpret_cast<UINT16*>(surface + dy * pitch);
			for(int dx = xDest, sx = xSrc;
				dx < width && sx + 1 < image.Width();
				dx += 2, sx += 2)
			{
				const RgbColor rgb0 = RgbColor::FromImage(image, sx, sy);
				const YuvColor yuv0 = YuvColor::FromRgb(rgb0);

				const RgbColor rgb1 = RgbColor::FromImage(image, sx + 1, sy);				
				const YuvColor yuv1 = YuvColor::FromRgb(rgb1);

				BYTE* macroPixel = reinterpret_cast<BYTE*>(line + dx);
				*macroPixel++ = (yuv0.u + yuv1.u) / 2;
				*macroPixel++ = yuv0.y;
				*macroPixel++ = (yuv0.v + yuv1.v) / 2;
				*macroPixel++ = yuv1.y;
			}
		}
	}

	void BlitRgb32(
		const DDSURFACEDESC2& ddsd,
		int xDest, int yDest, 
		const ImageRgb& image,
		int xSrc, int ySrc)
	{
		const int width = ddsd.dwWidth;
		const int height = ddsd.dwHeight;
		const int pitch = ddsd.lPitch;
		BYTE* surface = static_cast<BYTE*>(ddsd.lpSurface);

		for(int dy = yDest, sy = ySrc;
			dy < height && sy < image.Height();
			dy++, sy++)
		{
			UINT32* const line = reinterpret_cast<UINT32*>(surface + dy * pitch);
			for(int dx = xDest, sx = xSrc;
				dx < width && sx < image.Width();
				dx++, sx++)
			{
				const RgbColor rgb = RgbColor::FromImage(image, sx, sy);
				line[dx] = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
			}
		}
	}
	
	void BlitRgb16(
		const DDSURFACEDESC2& ddsd,
		int xDest, int yDest, 
		const ImageRgb& image,
		int xSrc, int ySrc)
	{
		const int width = ddsd.dwWidth;
		const int height = ddsd.dwHeight;
		const int pitch = ddsd.lPitch;
		const bool isR5G6B5 = (ddsd.ddpfPixelFormat.dwGBitMask == 0x07E0);
		BYTE* surface = static_cast<BYTE*>(ddsd.lpSurface);

		for(int dy = yDest, sy = ySrc;
			dy < height && sy < image.Height();
			dy++, sy++)
		{
			UINT16* const line = reinterpret_cast<UINT16*>(surface + dy * pitch);
			for(int dx = xDest, sx = xSrc;
				dx < width && sx < image.Width();
				dx++, sx++)
			{
				const RgbColor rgb = RgbColor::FromImage(image, sx, sy);

				if(isR5G6B5)
				{
					line[dx] = ((rgb.red >> 3) << 11) | ((rgb.green >> 2) << 5) | 
						(rgb.blue >> 3);
				}
				else
				{
					line[dx] = ((rgb.red >> 3) << 10) | ((rgb.green >> 3) << 5) | 
						(rgb.blue >> 3);
				}
			}
		}
	}	

	void Blit(
		IDirectDrawSurface7* destinationSurface,
		int xDest, int yDest,
		const ImageRgb& image,
		int xSrc, int ySrc)
	{
		if(!destinationSurface)
			throw std::invalid_argument("Destination surface cannot be null");

		if(!image.IsValid())
			throw std::invalid_argument("Invalid input image");

		if(xSrc < 0 || xSrc >= image.Width() || ySrc < 0 || ySrc >= image.Height())
			throw std::out_of_range("Source X and/or Y out of range");

		// Local class to handle locking/unlocking the given surface
		class Locker
		{
		public:
			Locker(IDirectDrawSurface7* surface, DDSURFACEDESC2& ddsd) : surface_(surface)
			{
				HRE(surface->Lock(0, &ddsd, DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT, 0));
			}

			~Locker()
			{
				surface_->Unlock(0);
			}

		private:
			IDirectDrawSurface7* surface_;
		};
		
		DDSURFACEDESC2 ddsd;
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		Locker lock(destinationSurface, ddsd);
		
		if(xDest < 0 || yDest < 0 || xDest >= ddsd.dwWidth || yDest >= ddsd.dwHeight)
			throw std::out_of_range("Destination X and/or Y out of range");

		BlitFunction blitter = 0;
		if(ddsd.ddpfPixelFormat.dwFlags == DDPF_FOURCC)
		{
			const DWORD fourCC = ddsd.ddpfPixelFormat.dwFourCC;
			if(fourCC == MAKEFOURCC('Y', 'U', 'Y', '2'))
				blitter = &BlitYuy2;
			else if(fourCC == MAKEFOURCC('U', 'Y', 'V', 'Y'))
				blitter = &BlitUyvy;
		}
		else if(ddsd.ddpfPixelFormat.dwFlags == DDPF_RGB)
		{
			const DWORD bpp = ddsd.ddpfPixelFormat.dwRGBBitCount;
			if(bpp == 32)
				blitter = &BlitRgb32;
			else if(bpp == 16)
				blitter = &BlitRgb16;
		}

		if(!blitter)
			throw std::logic_error(__FUNCTION__ ": Unsupported pixel format");
		
		blitter(ddsd, xDest, yDest, image, xSrc, ySrc);
	}
}