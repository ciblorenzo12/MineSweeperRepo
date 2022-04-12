#include "MinApp.h"
#include "Main.h"


wxIMPLEMENT_APP(MinApp);


MinApp::MinApp() {





}
MinApp::~MinApp() {

}

bool MinApp::OnInit() {
	mw = new Main();
	mw->Show();
	return true;

}