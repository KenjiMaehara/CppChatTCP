//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::testButtonClick(TObject *Sender)
{
	vector<string> v;
	AnsiString filename = "testFile.txt";

	ifstream fin;
	fin.open(filename.c_str(), ios::in);

	if( !(fin.fail()) )
	{
		string line;

		while(getline(fin,line))
		{
			if(line.find("BKUK") != string::npos)
				v.push_back(line);

		}
	}
	else
	{
		//StatusBar1->Panels->Items[0]->Text = "Save file does not exist!";
	}
}
//---------------------------------------------------------------------------


