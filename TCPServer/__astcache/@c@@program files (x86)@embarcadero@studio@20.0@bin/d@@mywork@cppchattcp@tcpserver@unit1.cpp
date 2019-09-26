//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTCP_Server *TCP_Server;
//---------------------------------------------------------------------------
__fastcall TTCP_Server::TTCP_Server(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TTCP_Server::ESendClick(TObject *Sender)
{

	ChatClient->Host = EHost->Text;
	ChatClient->Connect();

	ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(EMassage->Text);
	//ChatClient->Disconnect();



}
//---------------------------------------------------------------------------

void __fastcall TTCP_Server::ChatServerExcute(TIdContext *AContext)
{
	//int length = AContext->Connection->Socket->ReadLongInt();
	//UnicodeString Message = AContext->Connection->Socket->ReadString(length);
	//AContext->Connection->Disconnect();
	//LMessage->Items->Add(Message);

	AnsiString rcvdStr;

	//
	//rcvdStr = L"";
	rcvdStr = AContext->Connection->IOHandler->ReadLn(IndyTextEncoding(932));

	TList *threads;
	TIdContext *ac;


	// 受信元情報の表示
	String msg;
	msg = L"source IP:" + AContext->Connection->Socket->Binding->PeerIP;
	LMessage->Items->Add(msg);
    msg = L"\r\nsource port:" + IntToStr(AContext->Connection->Socket->Binding->PeerPort);
	LMessage->Items->Add(msg);
	LMessage->Items->Add(rcvdStr);  // 受信済の[rcvdStr]を使用

	threads = ChatServer->Contexts->LockList();

	for(int idx=0; idx < threads->Count; idx++){
		ac = reinterpret_cast<TIdContext *>(threads->Items[idx]);
        ac->Connection->IOHandler->WriteLn(rcvdStr);

        // 受信文字列はすでにrcvdStrにて取得しているため、下記の受信処理は過剰で処理が止まります
        //int length = ac->Connection->Socket->ReadLongInt();
        //UnicodeString Message = ac->Connection->Socket->ReadString(length);
        //LMessage->Items->Add(Message);
		//LMessage->Items->Add(rcvdStr);  // 受信済の[rcvdStr]を使用
	}

	ChatServer->Contexts->UnlockList();

}
//---------------------------------------------------------------------------


