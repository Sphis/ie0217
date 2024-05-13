#include "MainFrame.hpp"
#include <wx/wx.h>

// Ejemplo que pone en pantalla la tecla apretada o su valor en unicode

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
	wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

	//panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this); // No detecta
	//btn1->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this); // Solo detecta tecla en boton 1
	panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this); // Para que se detecte independiente
	// del elemento en el que se esta enfocado

	CreateStatusBar();
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
	wxChar keyChar = evt.GetUnicodeKey(); // Obtener valor de unicode de la tecla

	if (keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode();
		wxLogStatus("Key Event %d", keyCode);
	} else {
		wxLogStatus("Key Event %c", keyChar);
	}
}
	