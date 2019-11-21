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
	ChatClient->Socket->Write(IntToStr(EMassage->Text.Length()));  // IntToStr()を用いてString型にすること
																   // String型にしないと文字化けになってLMessageに表示されません
	//ChatClient->Socket->Write(EMassage->Text);
	ChatClient->Socket->WriteLn(EMassage->Text); // ChatServerExcute()ではReadLn()でLn付きで受信するため、送信側もWriteLn()を使う


	AnsiString buffer;
	buffer = ChatClient->IOHandler->ReadLn(IndyTextEncoding(932));
	LMessage->Items->Add(buffer);
        // WriteLn()でないとReadLn()で処理が止まってしまう

	// ChatClient->Disconnect();

	// Note:
	// ChatClientのConnect(), Disconnect()はSendClickイベントで実施すると、応答受信までDisconnect()できません。
	// TCP通信のソフトでは「接続」「切断」ボタンを別途用意して、Connect(), Disconnect()をそれらのボタン押下で処理する例はあります。

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
		EConnect->Caption = "接続中";

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

