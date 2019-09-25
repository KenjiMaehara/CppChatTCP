//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ESendClick(TObject *Sender)
{

	ChatClient->Host = EHost->Text;
	ChatClient->Connect();

	ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(EMassage->Text);
	//ChatClient->Disconnect();



}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChatServerExcute(TIdContext *AContext)
{
	//int length = AContext->Connection->Socket->ReadLongInt();
	//UnicodeString Message = AContext->Connection->Socket->ReadString(length);
	//AContext->Connection->Disconnect();
	//LMessage->Items->Add(Message);

	AnsiString rcvdStr;

	//
	rcvdStr = AContext->Connection->IOHandler->ReadLn(IndyTextEncoding(932));

	TList *threads;
	TIdContext *ac;

	threads = ChatServer->Contexts->LockList();

	for(int idx=0; idx < threads->Count; idx++){
		ac = reinterpret_cast<TIdContext *>(threads->Items[idx]);
		ac->Connection->IOHandler->WriteLn(rcvdStr);

		int length = ac->Connection->Socket->ReadLongInt();
		UnicodeString Message = ac->Connection->Socket->ReadString(length);
		LMessage->Items->Add(Message);

	}


	ChatServer->Contexts->UnlockList();

}
//---------------------------------------------------------------------------


