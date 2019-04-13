#pragma once

#include <OverlayManager.h>

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();

private:
	void LoadFromResources();
	void OnVisibleRadio(wxCommandEvent& event);
	void OnHiddenRadio(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnTimer(wxTimerEvent& event);

	static void RenderingCallback(
		IDirectDrawSurface7* overlayBackSurface,
		Overlay::PixelFormat format,
		void* userData);

private:
	wxTextCtrl* widthText;
	wxTextCtrl* heightText;	

	wxImage snapshot_;
		
	std::auto_ptr<Overlay::OverlayManager> overlayManager_;
	wxTimer m_timer;

	DECLARE_EVENT_TABLE();
};