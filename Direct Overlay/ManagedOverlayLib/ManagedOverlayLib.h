#pragma once

#include <OverlayManager.h>
#include <memory>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Drawing;

namespace ManagedOverlayLib
{
	public enum class PixelFormat
	{
		R8G8B8,
		R5G6B5,
		R5G5B5,
		UYVY,
		YUY2		
	};

	[UnmanagedFunctionPointer(CallingConvention::Cdecl)]
	public delegate void RenderingDelegate(IntPtr overlaySurface, IntPtr userData);

	public ref class OverlayManager
	{
	public:
		/*
		Performs the first step in the initialization of the DirectDraw overlay renderer. 
		The second step must be performed explicitly by the client.

		See also:
		<Reset>
		*/
		OverlayManager();

		~OverlayManager();

		// Checks whether the hardware supports overlays or not.
		property bool SupportAvailable
		{
			bool get();
		}

		/*
		Checks whether the manager was initialized, i.e. an overlay surface has been 
		created
		*/
		property bool IsInitialized
		{
			bool get();
		}

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

		// Shows the overlay
		void ShowOverlay();

		// Shows or hides the overlay
		void ShowOverlay(bool show);

		Drawing::Rectangle^ SetSourceRectangle(Drawing::Rectangle^ r);
		Drawing::Rectangle^ SetDestinationRectangle(Drawing::Rectangle^ r);

		/*
		Updates the overlay contents

		Returns false if the surfaces are lost and cannot be restored right now.
		No action is required by the user to restore the surfaces, they will be 
		automatically restored in subsequent calls to Update when it's possible to do so
		*/
		bool Update();


		property PixelFormat^ PixelFormat
		{
			ManagedOverlayLib::PixelFormat^ get();
		}

		property int Width
		{
			int get();
		}

		property int Height
		{
			int get();
		}

		property RenderingDelegate^ RenderingCallback;
	private:
		Overlay::OverlayManager* impl_;		
	};

	public ref class Blitter
	{
	public:
		static void Blit(
			IntPtr overlaySurface,
			int xDest, int yDest,
			Bitmap^ image,
			int xSrc, int ySrc);
	};
}