#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

	//button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	//panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked");
}