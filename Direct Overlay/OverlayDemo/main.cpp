#include "stdafx.h"
#include "MainFrame.h"
#include <Exception.h>

class OverlayDemo : public wxApp
{
public:
	bool OnInit();
	bool OnExceptionInMainLoop();
};

IMPLEMENT_APP(OverlayDemo)

bool OverlayDemo::OnInit()
{
	try
	{
		::wxHandleFatalExceptions();
		::wxInitAllImageHandlers();
		wxXmlResource::Get()->InitAllHandlers();
		if(!wxXmlResource::Get()->Load(wxT("OverlayDemo.xrc")))
		{
			wxMessageBox(wxT("Failed to find the resource file: OverlayDemo.xrc"), 
				wxT("Error"), wxOK | wxICON_ERROR);
			return false;
		}

		MainFrame* mainFrame = new MainFrame;
		SetTopWindow(mainFrame);
		mainFrame->Show();

		return true;
	}
	catch(const std::exception& e)
	{
		wxMessageBox(wxString(e.what(), wxConvLibc), wxT("Error"), wxOK | wxICON_ERROR);
		return false;
	}
}

bool OverlayDemo::OnExceptionInMainLoop()
{
	try
	{
		throw;	// Re-throw
	}
	catch(const DirectX::Exception& e)
	{
		wxMessageBox(wxString(e.ToString().c_str(), wxConvLibc), wxT("DirectX Error"),
			wxCENTER | wxOK | wxICON_ERROR);
		return true;
	}
	catch(const std::exception& e)
	{
		wxMessageBox(wxString(e.what(), wxConvLibc), wxT("Error"), wxOK | wxICON_ERROR);
		return true;
	}

	return false;
}