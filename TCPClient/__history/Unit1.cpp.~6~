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
	ChatClient->Host = EHost->Text;
	ChatClient->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ESendClick(TObject *Sender)
{



	ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(EMassage->Text);
	//ChatClient->Disconnect();



}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChatServerExcute(TIdContext *AContext)
{
	int length = AContext->Connection->Socket->ReadLongInt();
	UnicodeString Message = AContext->Connection->Socket->ReadString(length);
	AContext->Connection->Disconnect();
	LMessage->Items->Add(Message);

}
//---------------------------------------------------------------------------

