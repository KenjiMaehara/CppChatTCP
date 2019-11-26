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
		string line02;

		while(getline(fin,line))
		{

			line = "[" + line;
			line = line + "]\r\n";
			line02 = line02 + line;

			int number = line.find("id:");
			int number02 = line.find("]");

			if(number != string::npos)
			{
				string line03 = line.substr(number+3,number02-(number+3));

				AnsiString str02(line03.c_str());
				//Edit1->Text = str02;

			}



		}
	}
	else
	{
		//StatusBar1->Panels->Items[0]->Text = "Save file does not exist!";
	}
}
//---------------------------------------------------------------------------

