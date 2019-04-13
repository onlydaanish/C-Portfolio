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

#include "OverlayRectangle.h"
#include <atlbase.h>
#include <memory>
#include <string>

namespace Overlay
{
	extern Rectangle DefaultRectangle;

	/*
	These formats are listed in order of preference. The overlay manager will attempt
	to create a surface with each of them until it succeeds, or it runs out of formats.
	*/
	enum PixelFormat
	{
		PIXEL_FORMAT_32BPP,
		PIXEL_FORMAT_16BPP_R5G6B5,
		PIXEL_FORMAT_16BPP_R5G5B5,
		PIXEL_FORMAT_UYVY,
		PIXEL_FORMAT_YUY2,

		PIXEL_FORMAT_FIRST = PIXEL_FORMAT_32BPP,
		PIXEL_FORMAT_LAST = PIXEL_FORMAT_YUY2
	};

	std::string PixelFormatToString(PixelFormat f);

	class OverlayManager
	{
	public:
		typedef void (*RenderingFunction)(
			IDirectDrawSurface7* overlayBackSurface,
			PixelFormat format,
			void* userData);

	public:
		/*
		Performs the first step in the initialization of the DirectDraw overlay renderer. 
		The second step must be performed explicitly by the client.

		See also:
		<Reset>
		*/
		OverlayManager();

		// Checks whether the hardware supports overlays or not.
		bool SupportAvailable() const;

		/*
		Checks whether the manager was initialized, i.e. an overlay surface has been 
		created
		*/
		bool IsInitialized() const;

		/*
		Performs the 2nd and final initialization step. This was not implemented in the
		constructor in order to give the client the chance to check for hardware support 
		using <SupportAvailable>.

		Note that after initialization, the overlay is hidden. To show the overlay, call
		<ShowOverlay>.
		*/
		void Reset(
			int width,
			int height);

		// Shows or hides the overlay surface.
		void ShowOverlay(bool show = true);

		const Rectangle& SetSourceRectangle(const Rectangle& r);
		const Rectangle& SetDestinationRectangle(const Rectangle& r);

		/*
		Updates the overlay contents
		
		Returns false if the surfaces are lost and cannot be restored right now.
		No action is required by the user to restore the surfaces, they will be 
		automatically restored in subsequent calls to Update when it's possible to do so
		*/
		bool Update(
			RenderingFunction renderingCallback,
			void* userData);

		PixelFormat GetPixelFormat() const;
		int Width() const;
		int Height() const;

	private:
		void AssureIsInitialized(const char* function) const;
		void DisableDesktopWindowManager() const;
		void InitializeSurfaces(
			int overlayWidth,
			int overlayHeight);
		
		void CreatePrimarySurface();
		void CreateOverlaySurface(
			int overlayWidth, 
			int overlayHeight);

		void CleanUp();
		DDPIXELFORMAT PixelFormatToDdPixelFormat(PixelFormat format);

	private:
		CComPtr<IDirectDraw7> directDraw_;
		DDCAPS caps_;

		CComPtr<IDirectDrawSurface7> primarySurface_, overlaySurface_;
		// NOT a CComPtr, because we don't control (release) it
		IDirectDrawSurface7* overlayBackSurface_;

		int 
			width_, 
			height_;

		std::auto_ptr<Rectangle>
			sourceRectangle_,
			destinationRectangle_;

		/*
		Set to true whenever a condition causes our surfaces to be lost. I do not know the 
		full set of conditions that can cause this, I only know one. When an application goes 
		full-screen TestCooperativeLevel returns DDERR_EXCLUSIVEMODEALREADYSET. We check for 
		that in <Update>, and when it happens we set this flag to true, sleep for a second 
		and cancel the Update.

		We keep doing this until TestCooperativeLevel succeeds; then we clear the flag, 
		restore our surfaces and resume normal operation.
		*/
		bool surfacesLost_;

		PixelFormat pixelFormat_;
	};
}