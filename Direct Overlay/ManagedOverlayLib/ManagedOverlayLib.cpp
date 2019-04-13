#include "stdafx.h"
#include "ManagedOverlayLib.h"
#include <Exception.h>
#include <OverlayDraw.h>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedOverlayLib
{
	OverlayManager::OverlayManager() : impl_(new Overlay::OverlayManager)
	{
	}

	OverlayManager::~OverlayManager()
	{
		delete impl_;
		impl_ = 0;
	}

	bool OverlayManager::SupportAvailable::get()
	{
		return impl_->SupportAvailable();
	}

	bool OverlayManager::IsInitialized::get()
	{
		return impl_->IsInitialized();
	}

	void OverlayManager::Reset(
		int width,
		int height)
	{
		impl_->Reset(width, height);
	}

	void OverlayManager::ShowOverlay()
	{
		ShowOverlay(true);
	}

	void OverlayManager::ShowOverlay(bool show)
	{
		impl_->ShowOverlay(show);
	}

	Drawing::Rectangle^ OverlayManager::SetSourceRectangle(Drawing::Rectangle^ r)
	{
		const Overlay::Rectangle result = impl_->SetSourceRectangle(
			Overlay::Rectangle(r->Left, r->Top, r->Width, r->Height));

		return gcnew Drawing::Rectangle(result.Left(), result.Top(), result.Width(),
			result.Height());
	}

	Drawing::Rectangle^ OverlayManager::SetDestinationRectangle(Drawing::Rectangle^ r)
	{
		const Overlay::Rectangle result = impl_->SetDestinationRectangle(
			Overlay::Rectangle(r->Left, r->Top, r->Width, r->Height));

		return gcnew Drawing::Rectangle(result.Left(), result.Top(), result.Width(),
			result.Height());
	}

	bool OverlayManager::Update()
	{
		RenderingDelegate^ callback = RenderingCallback;
		pin_ptr<RenderingDelegate^> pinCallback = &callback;
		Overlay::OverlayManager::RenderingFunction func = 
			static_cast<Overlay::OverlayManager::RenderingFunction>(
			Marshal::GetFunctionPointerForDelegate(callback).ToPointer());
		
		return impl_->Update(func, 0);
	}

	ManagedOverlayLib::PixelFormat^ OverlayManager::PixelFormat::get()
	{
		switch(impl_->GetPixelFormat())
		{
		case Overlay::PIXEL_FORMAT_32BPP:
			return ManagedOverlayLib::PixelFormat::R8G8B8;

		case Overlay::PIXEL_FORMAT_16BPP_R5G5B5:
			return ManagedOverlayLib::PixelFormat::R5G5B5;

		case Overlay::PIXEL_FORMAT_16BPP_R5G6B5:
			return ManagedOverlayLib::PixelFormat::R5G6B5;

		case Overlay::PIXEL_FORMAT_YUY2:
			return ManagedOverlayLib::PixelFormat::YUY2;

		case Overlay::PIXEL_FORMAT_UYVY:
			return ManagedOverlayLib::PixelFormat::UYVY;
		}

		throw gcnew Exception("Unknown pixel format returned by native overlay manager");
	}

	int OverlayManager::Width::get()
	{
		return impl_->Width();
	}

	int OverlayManager::Height::get()
	{
		return impl_->Height();
	}

	void Blitter::Blit(
		IntPtr overlaySurface,
		int xDest, int yDest,
		Bitmap^ image,
		int xSrc, int ySrc)
	{
		if(image->PixelFormat != Imaging::PixelFormat::Format24bppRgb &&
			image->PixelFormat != Imaging::PixelFormat::Format16bppRgb555 &&
			image->PixelFormat != Imaging::PixelFormat::Format16bppRgb565 &&
			image->PixelFormat != Imaging::PixelFormat::Format32bppRgb)
		{
			throw gcnew ArgumentException(
				"Input image format must be Format32bppRgb, Format24bppRgb, "
				"Format16bppRgb555, or Format16bppRgb565", "image");
		}

		Drawing::Rectangle rect(0, 0, image->Width, image->Height);
		Imaging::BitmapData^ data = image->LockBits(rect, Imaging::ImageLockMode::ReadOnly, 
			image->PixelFormat);

		try
		{
			IDirectDrawSurface7* surface = reinterpret_cast<IDirectDrawSurface7*>(
				overlaySurface.ToPointer());

			Overlay::ImageRgb rawImage = Overlay::ImageRgb()
				.Data(static_cast<BYTE*>(data->Scan0.ToPointer()))
				.Width(data->Width)
				.Height(data->Height)
				.Pitch(data->Stride);

			if(image->PixelFormat == Imaging::PixelFormat::Format32bppRgb)
			{
				rawImage.BytesPerPixel(4)
					.RedMask(0xff0000)
					.GreenMask(0x00ff00)
					.BlueMask(0x0000ff)
					.RedShift(16)
					.GreenShift(8);
			}
			else if(image->PixelFormat == Imaging::PixelFormat::Format24bppRgb)
			{
				rawImage.BytesPerPixel(3)
					.RedMask(0xff0000)
					.GreenMask(0x00ff00)
					.BlueMask(0x0000ff)
					.RedShift(16)
					.GreenShift(8);
			}
			else if(image->PixelFormat == Imaging::PixelFormat::Format16bppRgb565)
			{
				rawImage.BytesPerPixel(2)
					.RedMask(0xF800)
					.GreenMask(0x07E0)
					.BlueMask(0x001F)
					.RedShift(11)
					.GreenShift(5);
			}
			else if(image->PixelFormat == Imaging::PixelFormat::Format16bppRgb555)
			{
				rawImage.BytesPerPixel(2)
					.RedMask(0x7C00)
					.GreenMask(0x03e0)
					.BlueMask(0x001F)
					.RedShift(10)
					.GreenShift(5);
			}

			Overlay::Blit(surface, xDest, yDest, rawImage, xSrc, ySrc);
		}
		catch(const DirectX::Exception& e)
		{
			throw gcnew Exception(Marshal::PtrToStringUni(
				IntPtr(const_cast<wchar_t*>(e.ToString().c_str()))));
		}
		catch(const std::exception& e)
		{
			throw gcnew Exception(Marshal::PtrToStringAnsi(
				IntPtr(const_cast<char*>(e.what()))));
		}
		catch(...)
		{
			throw gcnew Exception("An unknown exception occurred");
		}
		finally
		{
			image->UnlockBits(data);
		}
	}
}