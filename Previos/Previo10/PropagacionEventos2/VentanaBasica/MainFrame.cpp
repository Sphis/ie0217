#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked");
}