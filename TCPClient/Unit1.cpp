//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTCP_Client *TCP_Client;
//---------------------------------------------------------------------------
__fastcall TTCP_Client::TTCP_Client(TComponent* Owner)
	: TForm(Owner)
{
	//ChatClient->Host = EHost->Text;
	//ChatClient->Port = 5000;
	//ChatClient->Connect();
	ESend->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TTCP_Client::ESendClick(TObject *Sender)
{

	//rcvdStr = AContext->Connection->IOHandler->ReadLn(IndyTextEncoding(932));
	//ChatClient->Host = EHost->Text;
	//ChatClient->Connect();

    // ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(IntToStr(EMassage->Text.Length()));  // IntToStr()��p����String�^�ɂ��邱��
																   // String�^�ɂ��Ȃ��ƕ��������ɂȂ���LMessage�ɕ\������܂���
	//ChatClient->Socket->Write(EMassage->Text);
	ChatClient->Socket->WriteLn(EMassage->Text); // ChatServerExcute()�ł�ReadLn()��Ln�t���Ŏ�M���邽�߁A���M����WriteLn()���g��


	AnsiString buffer;
	buffer = ChatClient->IOHandler->ReadLn(IndyTextEncoding(932));
	LMessage->Items->Add(buffer);
        // WriteLn()�łȂ���ReadLn()�ŏ������~�܂��Ă��܂�

	// ChatClient->Disconnect();

	// Note:
	// ChatClient��Connect(), Disconnect()��SendClick�C�x���g�Ŏ��{����ƁA������M�܂�Disconnect()�ł��܂���B
	// TCP�ʐM�̃\�t�g�ł́u�ڑ��v�u�ؒf�v�{�^����ʓr�p�ӂ��āAConnect(), Disconnect()�������̃{�^�������ŏ��������͂���܂��B

}
//---------------------------------------------------------------------------




void __fastcall TTCP_Client::EConnectClick(TObject *Sender)
{
	ChatClient->Host = EHost->Text;
	ChatClient->Port = 5000;
	ChatClient->Connect();


	AnsiString buffer;
	buffer = "123456789";
	//ChatClient->Socket->Write(IntToStr(buffer));
	ChatClient->Socket->WriteLn(buffer);

	AnsiString buffer02;
	buffer02 = ChatClient->IOHandler->ReadLn(IndyTextEncoding(932));

	if (buffer == buffer02) {
		EConnect->Enabled = false;
		ESend->Enabled = true;
		EConnect->Caption = "�ڑ���";

	}


}
//---------------------------------------------------------------------------

using namespace std;

void __fastcall TTCP_Client::FormCreate(TObject *Sender)
{

	AnsiString filename = "SaveFile.txt";

	ifstream fin;
	fin.open(filename.c_str(), ios::in);

	if( !(fin.fail()) )
	{
		string line;
		string line02;

		while(getline(fin,line))
		{
			//cout << "[" << line << "]" << endl;
			//line02 << "[" << line << "]" << endl;
			line = "[" + line;
			line = line + "]\r\n";
			line02 = line02 + line;

			int number = line.find("id:");
			int number02 = line.find("]");

			if(number != string::npos)
			{
				string line03 = line.substr(number+3,number02-(number+3));

				AnsiString str02(line03.c_str());
				Edit1->Text = str02;

			}



		}

		AnsiString str(line02.c_str());
		ShowMessage(str);
	}
	else
	{
		StatusBar1->Panels->Items[0]->Text = "Save file does not exist!";
		//StatusBar1->Panels[0]-> = "Save file does not exist!";
	}

}
//---------------------------------------------------------------------------


