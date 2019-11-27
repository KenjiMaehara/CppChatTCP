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
	//vector<string> v[6];
	vector<vector<string> > v(6, vector<string>(5));

	vector<vector<string> > reciveData(1, vector<string>(5));
	//vector<string> reciveData;
	AnsiString filename = "testFile.txt";

	string buf;

	ifstream fin;
	fin.open(filename.c_str(), ios::in);


	//v.resize(5);
	//v[5][0]="test";
	//v[5].push_back("test02");
	//v[5][2]="test03";
	//v[5].push_back("test02");
	//v.at(5).at(0) = "test02";
	//v.at(5).push_back("test02");






	if( !(fin.fail()) )
	{
		string line;

		while(getline(fin,line))
		{
			stringstream ss{line};

			int j=0;

			while (std::getline(ss, buf, ','))
			{
				reciveData.at(0).at(j++) = buf;
			}


			//if(line.find("BKUK") != string::npos)
			if(reciveData.at(0).at(0) == "BKUK")
			{
				for(int i=0;i<v.size();i++)
				{
					if(v.at(i).at(1) != reciveData.at(0).at(1) && i == v.size())
					{
						int num = v.size() + 1;

						while(getline(ss, buf, ','))
						{
							v.at(num).push_back(buf);
						}
					}
					else
					{

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

