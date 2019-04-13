#include "stdafx.h"
#include "MainFrame.h"
#include <OverlayDraw.h>

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_RADIOBUTTON(XRCID("VisibleRadio"), OnVisibleRadio)
EVT_RADIOBUTTON(XRCID("HiddenRadio"), OnHiddenRadio)
EVT_BUTTON(XRCID("ExitButton"), OnExit)
EVT_TIMER(wxID_ANY, OnTimer)
END_EVENT_TABLE()

MainFrame::MainFrame() : m_timer(this)
{
	LoadFromResources();
	m_timer.Start(500);
}

MainFrame::~MainFrame()
{
}

void MainFrame::LoadFromResources()
{
	wxXmlResource* res = wxXmlResource::Get();
	if(!res->LoadFrame(this, 0, wxT("MainFrame")))
		throw std::exception("Could not load MainFrame from the XRC resource file.");

	widthText = XRCCTRL(*this, "WidthText", wxTextCtrl);
	heightText = XRCCTRL(*this, "HeightText", wxTextCtrl);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	Destroy();
}

void MainFrame::OnVisibleRadio(wxCommandEvent& event)
{
	const int width = GetSize().GetWidth();
	const int height = GetSize().GetHeight();

	if(!overlayManager_.get())
		overlayManager_.reset(new Overlay::OverlayManager);
	
	if(!overlayManager_->IsInitialized())
	{
		try
		{
			overlayManager_->Reset(width, height);
			const Overlay::PixelFormat format = overlayManager_->GetPixelFormat();
			const wxString formatString(Overlay::PixelFormatToString(format).c_str(),
				wxConvLibc);

			wxTextCtrl* formatText = XRCCTRL(*this, "FormatText", wxTextCtrl);
			formatText->SetValue(formatString);

			widthText->SetValue(wxString() << width);
			heightText->SetValue(wxString() << height);
		}
		catch(...)
		{
			wxRadioButton* visibleRadio = XRCCTRL(*this, "VisibleRadio", wxRadioButton);
			visibleRadio->SetValue(0);
			wxRadioButton* hiddenRadio = XRCCTRL(*this, "HiddenRadio", wxRadioButton);
			hiddenRadio->SetValue(1);

			throw;	// re-throw
		}
	}

	if(event.IsChecked())
		overlayManager_->ShowOverlay();
}

void MainFrame::OnHiddenRadio(wxCommandEvent& event)
{
	if(overlayManager_.get() && event.IsChecked())
		overlayManager_->ShowOverlay(false);
}

void MainFrame::RenderingCallback(IDirectDrawSurface7* overlayBackSurface,
								  Overlay::PixelFormat format,
								  void* userData)
{
	MainFrame* me = reinterpret_cast<MainFrame*>(userData);

	if(me->IsActive())
	{
		const int width = me->GetSize().GetWidth();
		const int height = me->GetSize().GetHeight();

		wxBitmap snapshotBmp(width, height);
		wxMemoryDC bmpDc;
		wxWindowDC dc(me);
		bmpDc.SelectObject(snapshotBmp);
		bmpDc.Blit(0, 0, width, height, &dc, 0, 0);
		bmpDc.SelectObject(wxNullBitmap);
		me->snapshot_ = snapshotBmp.ConvertToImage();
	}	

	if(me->snapshot_.IsOk())
	{
		const Overlay::ImageRgb image = Overlay::ImageRgb()
			.Data(me->snapshot_.GetData())
			.Width(me->snapshot_.GetWidth())
			.Height(me->snapshot_.GetHeight())
			.Pitch(me->snapshot_.GetWidth() * 3)
			.BytesPerPixel(3)
			.RedMask(0x0000ff)
			.GreenMask(0x00ff00)
			.BlueMask(0xff0000)
			.GreenShift(8)
			.BlueShift(16);

		Overlay::Blit(overlayBackSurface, 0, 0, image, 0, 0);
	}
}

void MainFrame::OnTimer(wxTimerEvent& event)
{
	if(overlayManager_.get() && overlayManager_->IsInitialized())
		overlayManager_->Update(RenderingCallback, this);
}