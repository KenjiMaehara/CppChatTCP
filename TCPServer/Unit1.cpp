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


	// ��M�����̕\��
	String msg;
	msg = L"source IP:" + AContext->Connection->Socket->Binding->PeerIP;
	LMessage->Items->Add(msg);
	msg = L"\r\nsource port:" + IntToStr(AContext->Connection->Socket->Binding->PeerPort);
	LMessage->Items->Add(msg);
	LMessage->Items->Add(rcvdStr);  // ��M�ς�[rcvdStr]���g�p

	//AContext->Connection->IOHandler->WriteLn(rcvdStr);

	threads = ChatServer->Contexts->LockList();

	for(int idx=0; idx < threads->Count; idx++){
		ac = reinterpret_cast<TIdContext *>(threads->Items[idx]);

		if (AContext->Connection->Socket->Binding->PeerPort == ac->Connection->Socket->Binding->PeerPort) {
			ac->Connection->IOHandler->WriteLn(rcvdStr);
			LMessage->Items->Add(threads->Count);
		}

		//ac->Connection->IOHandler->WriteLn(rcvdStr);

		// ��M������͂��ł�rcvdStr�ɂĎ擾���Ă��邽�߁A���L�̎�M�����͉ߏ�ŏ������~�܂�܂�
        //int length = ac->Connection->Socket->ReadLongInt();
        //UnicodeString Message = ac->Connection->Socket->ReadString(length);
        //LMessage->Items->Add(Message);
		//LMessage->Items->Add(rcvdStr);  // ��M�ς�[rcvdStr]���g�p
	}

	ChatServer->Contexts->UnlockList();

}
//---------------------------------------------------------------------------


