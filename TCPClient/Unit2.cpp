//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <sstream>
#include <istream>



using namespace std;

int vectorStringFinder(vector<string> vec, string number);

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
	vector<string> reciveData;
	AnsiString filename = "testFile.txt";

	string buf;

	ifstream fin;
	fin.open(filename.c_str(), ios::in);


	v[5].push_back("test");



	if( !(fin.fail()) )
	{
		string line;

		while(getline(fin,line))
		{
			stringstream ss{line};


			while (std::getline(ss, buf, ','))
			{
				reciveData.push_back(buf);
			}


			//if(line.find("BKUK") != string::npos)
			if(reciveData.at(0) == "BKUK")
			{
				for(int i=0;i<v.size();i++)
				{
					if(reciveData.at(i).at(1) != reciveData.at(0).at(1))
					{
						int num = v.size() + 1;
						int j=0;

						while(getline(ss, buf, ','))
						{
							//v.at(num).push_back(buf);
						}
					}
				}
			}
		}
	}
	else
	{
		//StatusBar1->Panels->Items[0]->Text = "Save file does not exist!";
	}
}
//---------------------------------------------------------------------------


int vectorStringFinder(vector<string> vec, string number)
{
	auto itr = find(vec.begin(), vec.end(), number);
	size_t index = distance( vec.begin(), itr );
	if (index != vec.size())
	{ // ”­Œ©‚Å‚«‚½‚Æ‚«
		return 1;
	}
	else
	{ // ”­Œ©‚Å‚«‚È‚©‚Á‚½‚Æ‚«
		return 0;
	}
}

