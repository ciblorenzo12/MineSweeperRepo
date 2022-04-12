#pragma once
#include "wx/wx.h"

class Main ;
class MinApp: public wxApp		
{
private :
	Main* mw =  nullptr;
public :
	MinApp();
	~MinApp();

	virtual bool OnInit();	
};

