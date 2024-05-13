#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI");
	mainFrame->Show();
	return true;
}