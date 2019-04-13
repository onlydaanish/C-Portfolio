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
#include "OverlayManager.h"
#include "Exception.h"
#include <boost/format.hpp>

#ifdef DEBUG
#define DEBUG_MESSAGE(x) OutputDebugString(x)
#else
#define DEBUG_MESSAGE(x)
#endif

namespace Overlay
{
	Rectangle DefaultRectangle(0, 0, 0, 0);

	std::string PixelFormatToString(PixelFormat f)
	{
		switch(f)
		{
		case PIXEL_FORMAT_32BPP:
			return "RGB 32bpp";

		case PIXEL_FORMAT_16BPP_R5G6B5:
			return "RGB 16bpp R5G6B5";

		case PIXEL_FORMAT_16BPP_R5G5B5:
			return "RGB 16bpp R5G5B5";

		case PIXEL_FORMAT_UYVY:
			return "UYVY";

		case PIXEL_FORMAT_YUY2:
			return "YUY2";

		default:
			throw std::out_of_range(__FUNCTION__ ": PixelFormat out of range");
		}
	}

	OverlayManager::OverlayManager()
		: 
	width_(0),
	height_(0),
	surfacesLost_(false)
	{
		/*
		This is necessary for Vista. DWM expects applications to draw on a surface, not
		directly to the screen. We have to disable it.
		*/
		DisableDesktopWindowManager();

		HRE(DirectDrawCreateEx(0, (void**)&directDraw_, IID_IDirectDraw7, 0));

		ZeroMemory(&caps_, sizeof(caps_));
		caps_.dwSize = sizeof(caps_);
		HRE(directDraw_->GetCaps(&caps_, 0));
	}

	bool OverlayManager::SupportAvailable() const
	{
		/*
		If we've created and shown an overlay surface, don't take it into consideration when
		checking the number of visible overlays.
		*/
		int numVisibleOverlays = overlaySurface_? caps_.dwCurrVisibleOverlays - 1 : 0;

		/*
		If the overlay surface was created but not shown, numVisibleOverlays would be -1
		*/
		if(numVisibleOverlays < 0)
			numVisibleOverlays = 0;

		return
			(caps_.dwMaxVisibleOverlays > static_cast<DWORD>(numVisibleOverlays)) && 
			(caps_.dwCaps & DDCAPS_OVERLAY);
	}

	bool OverlayManager::IsInitialized() const
	{
		return overlaySurface_ && overlayBackSurface_;
	}

	void OverlayManager::Reset(
		int width,
		int height)
	{
		if(IsInitialized())
			CleanUp();

		// Request normal cooperative level to put us in windowed mode
		HRE(directDraw_->SetCooperativeLevel(0, DDSCL_NORMAL));

		InitializeSurfaces(width, height);
		// Update caps after surfaces have been created
		directDraw_->GetCaps(&caps_, 0);
	}

	bool OverlayManager::Update(
		RenderingFunction renderingCallback,
		void* userData)
	{
		AssureIsInitialized(__FUNCTION__);

		HRESULT hr;

		// Check the cooperative level before rendering
		if(FAILED(hr = directDraw_->TestCooperativeLevel()))
		{
			DEBUG_MESSAGE(boost::str(boost::wformat(
				L"TestCooperativeLevel failed with hr = 0x%X\n") % hr).c_str());

			switch(hr)
			{
			case DDERR_EXCLUSIVEMODEALREADYSET:
				// Do nothing because some other app has exclusive mode
				surfacesLost_ = true;
				return false;

			case DDERR_WRONGMODE:
				// The display mode changed on us. Update the surfaces accordingly
				CleanUp();
				Reset(width_, height_);
				ShowOverlay();
				break;

			default:
				// If we reached this point, then we haven't handled the failure.
				HRE(hr);
			}
		}

		if(surfacesLost_ || FAILED(primarySurface_->IsLost()))
		{
			DEBUG_MESSAGE(L"Surfaces lost. Attempting recovery...\n");
			
			if(FAILED(directDraw_->RestoreAllSurfaces()))
			{
				DEBUG_MESSAGE(L"Failed to restore surfaces. Attempting reset...\n");
				try
				{
					Reset(width_, height_);
				}
				catch(...)
				{
					DEBUG_MESSAGE(L"Reset failed.\n");
					return false;
				}
			}

			ShowOverlay();
			surfacesLost_ = false;
		}

		renderingCallback(overlayBackSurface_, pixelFormat_, userData);

		HRE(overlaySurface_->Flip(0, DDFLIP_WAIT));
		return true;
	}

	void OverlayManager::InitializeSurfaces(
		int overlayWidth,
		int overlayHeight)
	{
		CreatePrimarySurface();
		CreateOverlaySurface(overlayWidth, overlayHeight);
	}

	void OverlayManager::CreatePrimarySurface()
	{
		DDSURFACEDESC2 ddsd;

		// Create the primary surface
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		ddsd.dwFlags = DDSD_CAPS;
		ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
		HRE(directDraw_->CreateSurface(&ddsd, &primarySurface_, 0));
	}

	void OverlayManager::CreateOverlaySurface(
		int overlayWidth, 
		int overlayHeight)
	{
		// Overlay surface
		DDSURFACEDESC2 ddsd;
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize = sizeof(ddsd);
		ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_BACKBUFFERCOUNT | 
			DDSD_PIXELFORMAT;
		ddsd.ddsCaps.dwCaps = DDSCAPS_OVERLAY | DDSCAPS_FLIP | DDSCAPS_COMPLEX | 
			DDSCAPS_VIDEOMEMORY;
		ddsd.dwBackBufferCount = 1;
		ddsd.dwWidth = overlayWidth;
		ddsd.dwHeight = overlayHeight;

		HRESULT overlayResult = S_OK;
		for(int format = PIXEL_FORMAT_FIRST; format <= PIXEL_FORMAT_LAST; format++)
		{
			// Attempt to create the surface with this pixel format
			ddsd.ddpfPixelFormat = PixelFormatToDdPixelFormat(static_cast<PixelFormat>(format));
			overlayResult = directDraw_->CreateSurface(&ddsd, &overlaySurface_, 0);
			if(SUCCEEDED(overlayResult))
			{
				pixelFormat_ = static_cast<PixelFormat>(format);
				break;
			}
		}	

		HRE(overlayResult);

		// Store width and height
		width_ = overlayWidth;
		height_ = overlayHeight;

		// Retrieve the back-buffer
		DDSCAPS2 ddscaps;
		ZeroMemory(&ddscaps, sizeof(ddscaps));
		ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
		HRE(overlaySurface_->GetAttachedSurface(&ddscaps, &overlayBackSurface_));
	}

	void OverlayManager::CleanUp()
	{
		overlaySurface_ = 0;
		primarySurface_ = 0;

		surfacesLost_ = false;
	}

	DDPIXELFORMAT OverlayManager::PixelFormatToDdPixelFormat(PixelFormat format)
	{
		const DDPIXELFORMAT formats[] = 
		{
			// PIXEL_FORMAT_32BPP
			{ sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 32, 0xFF0000, 0x0000FF00, 0x000000FF, 0},
			// PIXEL_FORMAT_16BPP_R5G6B5
			{ sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 16, 0xF800, 0x07E0, 0x001F, 0},
			// PIXEL_FORMAT_16BPP_R5G5B5		
			{ sizeof(DDPIXELFORMAT), DDPF_RGB, 0, 16, 0x7C00, 0x03e0, 0x001F, 0},
			// PIXEL_FORMAT_UYVY
			{ sizeof(DDPIXELFORMAT), DDPF_FOURCC, MAKEFOURCC('U', 'Y', 'V', 'Y'), 0, 0, 0, 0, 0},
			// PIXEL_FORMAT_YUY2
			{ sizeof(DDPIXELFORMAT), DDPF_FOURCC, MAKEFOURCC('Y', 'U', 'Y', '2'), 0, 0, 0, 0, 0}
		};

		switch(format)
		{
		case PIXEL_FORMAT_32BPP:
			return formats[0];

		case PIXEL_FORMAT_16BPP_R5G6B5:
			return formats[1];

		case PIXEL_FORMAT_16BPP_R5G5B5:
			return formats[2];

		case PIXEL_FORMAT_UYVY:
			return formats[3];

		case PIXEL_FORMAT_YUY2:
			return formats[4];
		}
		
		throw std::out_of_range(boost::str(boost::format(
			"%1%: Argument 'format' is out of range. Value = %2%")
			% __FUNCTION__ % format));
	}

	void OverlayManager::ShowOverlay(bool show)
	{
		AssureIsInitialized(__FUNCTION__);

		if(show)
		{
			std::auto_ptr<RECT> sr;
			if(sourceRectangle_.get())
				sr.reset(new RECT(sourceRectangle_->ToRECT()));

			std::auto_ptr<RECT> dr;
			if(destinationRectangle_.get())
				dr.reset(new RECT(destinationRectangle_->ToRECT()));
			else
			{
				const RECT defaultRect = { 0, 0, width_, height_ };
				dr.reset(new RECT(defaultRect));
			}

			HRE(overlaySurface_->UpdateOverlay(sr.get(), primarySurface_, dr.get(),
				DDOVER_SHOW, 0));
			HRE(overlaySurface_->UpdateOverlayZOrder(DDOVERZ_SENDTOFRONT, 0));
		}
		else
		{
			HRE(overlaySurface_->UpdateOverlay(0, primarySurface_, 0, DDOVER_HIDE, 0));
		}
	}

	const Rectangle& OverlayManager::SetSourceRectangle(const Rectangle& r)
	{
		if(r == DefaultRectangle)
		{
			sourceRectangle_.reset();
			return r;
		}

		sourceRectangle_.reset(new Rectangle(
			CreateSourceRectangle(caps_, r.Left(), r.Top(), r.Width(), r.Height())));
		return *sourceRectangle_.get();
	}

	const Rectangle& OverlayManager::SetDestinationRectangle(const Rectangle& r)
	{
		if(r == DefaultRectangle)
		{
			destinationRectangle_.reset();
			return r;
		}

		if(!sourceRectangle_.get())
			throw std::logic_error(__FUNCTION__ ": Cannot set destination rectangle "
				"without setting source rectangle first");

		destinationRectangle_.reset(new Rectangle(
			CreateDestinationRectangle(caps_, *sourceRectangle_.get(), r.Left(), r.Top(),
				r.Width(), r.Height())));
		return *destinationRectangle_.get();
	}

	PixelFormat OverlayManager::GetPixelFormat() const
	{
		AssureIsInitialized(__FUNCTION__);
		return pixelFormat_;
	}
	
	int OverlayManager::Width() const
	{
		AssureIsInitialized(__FUNCTION__);
		return width_;
	}

	int OverlayManager::Height() const
	{
		AssureIsInitialized(__FUNCTION__);
		return height_;
	}

	void OverlayManager::DisableDesktopWindowManager() const
	{
		HMODULE dwmModule = LoadLibrary(L"dwmapi.dll");
		if(dwmModule)
		{
			typedef HRESULT (STDAPICALLTYPE *DwmIsCompositionEnabledFunc)(BOOL* enabled);
			typedef HRESULT (STDAPICALLTYPE *DwmEnableCompositionFunc)(UINT action);

			DwmIsCompositionEnabledFunc IsCompositionEnabled =
				reinterpret_cast<DwmIsCompositionEnabledFunc>(
				GetProcAddress(dwmModule, "DwmIsCompositionEnabled"));
			
			BOOL enabled;
			IsCompositionEnabled(&enabled);
			if(enabled)
			{
				DwmEnableCompositionFunc EnableComposition = 
					reinterpret_cast<DwmEnableCompositionFunc>(
					GetProcAddress(dwmModule, "DwmEnableComposition"));
				EnableComposition(0);
			}

			FreeLibrary(dwmModule);
		}
	}

	void OverlayManager::AssureIsInitialized(const char* function) const
	{
		if(!IsInitialized())
		{
			throw std::logic_error(boost::str(boost::format(
				"The function %1% was called on an uninitialized OverlayManager. Call "
				"OverlayManager::Reset first.") % function));
		}
	}
}