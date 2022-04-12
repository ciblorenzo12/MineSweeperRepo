#pragma once
#include "wx/wx.h"
	class Main:public wxFrame
{
public:
		Main();
		~Main();



		int cellWidh=20;
		int cellHight=20;
		wxButton** Buttsafe;	
		int* clkfield= nullptr;
		bool firstClick=true;
		//buttons and boxes 
		
		void  OnButtonClicked(wxCommandEvent& evt);
		wxDECLARE_EVENT_TABLE();
};

