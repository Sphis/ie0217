#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	CreateStatusBar();

	panel->Bind(wxEVT_LEFT_DOWN, &MainFrame:: OnMouseEvent, this);
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	wxPoint mousePos = evt.GetPosition();
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}
