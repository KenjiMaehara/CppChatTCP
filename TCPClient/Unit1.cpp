//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <string>
#include <fstream>

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

	#if 0
	if(FileExists("c:/SaveFile.xml"))
		ADODataSet1->LoadFromFile("c:/SaveFile.xml");
	else
		StatusBar1->Panels->Items[0]->Text = "Save file does not exist!";
	#endif

	AnsiString filename = "c:/SaveFile.txt";

	//filename += ".csv";

	ifstream fin;
	fin.open(filename.c_str(), ios::in);

	if( !(fin.fail()) )
	{
		string line;
		getline(fin, line);
        AnsiString str(line.c_str());
        ShowMessage(str);
	}

}
//---------------------------------------------------------------------------

