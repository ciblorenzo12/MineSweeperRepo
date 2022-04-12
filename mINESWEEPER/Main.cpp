#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

EVT_BUTTON(10001,OnButtonClicked)	

wxEND_EVENT_TABLE()


Main::Main():wxFrame(nullptr,wxID_ANY,"Minesweeper",wxPoint(50,50),wxSize(1000,1000))
	{
	Buttsafe = new wxButton*[cellWidh* cellHight];
	clkfield = new int[cellWidh * cellHight];
	wxGridSizer* grid = new wxGridSizer(cellWidh, cellHight, 0, 0);
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false);
	for (int i   = 0; i < cellWidh; i++)
	{
		for (int j = 0; j < cellHight; j++)
		{
			Buttsafe[j * cellWidh + i] = new wxButton(this, 10001 + (j * cellWidh + i));
			grid->Add(Buttsafe[j * cellWidh + i], 1, wxEXPAND | wxALL);


			Buttsafe[j * cellWidh + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
			Buttsafe[j * cellWidh + i]->SetFont(font);
			clkfield[j * cellWidh + i] = 0;
		}
	}
	this->SetSizer(grid);	
	grid->Layout();
}	
Main::~Main()
{
	delete[]Buttsafe;
}
void  Main::OnButtonClicked(wxCommandEvent& evt) {
	int Xx = (evt.GetId() - 10001) % cellWidh;
	int Yy = (evt.GetId() - 10001) / cellWidh;
	if (firstClick)
	{
		int mine = 24;
		while (mine) {
			int randX = rand() % cellWidh;

			int RandY = rand() % cellHight;

	
		if (clkfield[RandY * cellWidh + randX] == 0 && randX != Xx && RandY != Yy) {
			clkfield[RandY * cellWidh + randX] = -1;
			mine--;

		}
		}
		firstClick = false;

	}
	Buttsafe[Yy * cellWidh + Xx]->Enable(false);	
	if (clkfield[Yy * cellWidh + Xx] == -1) {

		wxMessageBox(" Boom,You Have explode!!!!!!!!  ");
		//reset 
		firstClick = true;
		for (int x = 0; x < cellWidh; x++)
		{
			for (int y = 0; y < cellHight; y++)
			{

				clkfield[y * cellWidh + x] = 0;
				Buttsafe[y * cellWidh + x]->SetLabel(" ");
				Buttsafe[y * cellWidh + x]->Enable(true);
			}
			}
	}
	else 
	{
		int mine_count = 0;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				
				if (Xx + i >= 0 && Xx + i < cellWidh && Yy + j >= 0 && Yy + j < cellHight) {
					
					if (clkfield[(Yy + j) * cellWidh+ (Xx + i)] == -1) {
						mine_count++;
					}
				}
				if (mine_count > 0) {
					Buttsafe[Yy * cellWidh + Xx]->SetLabel(std::to_string(mine_count));
				}
			}
			}
		}
	
	

	
	evt.Skip();

		
}