#include "MainFrame.hpp"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox",
		wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "statictext - not editable",
		wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);
	
	wxTextCtrl* textctrl = new wxTextCtrl(panel, wxID_ANY, "textctrl - editable",
		wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxGA_VERTICAL);

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetValue(50);

	wxArrayString choices;
	choices.Add("Item C");
	choices.Add("Item A");
	choices.Add("Item B");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	choice->Select(0);

	wxSpinCtrl* spinctrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

	wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	wxRadioBox* radiobox = new wxRadioBox(panel, wxID_ANY, "Radiobox",
		wxPoint(555, 450), wxDefaultSize, choices, 3, wxRA_SPECIFY_ROWS);
}