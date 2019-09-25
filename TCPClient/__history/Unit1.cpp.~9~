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
	//ChatClient->Host = EHost->Text;
	//ChatClient->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ESendClick(TObject *Sender)
{


	ChatClient->Host = EHost->Text;
	ChatClient->Connect();
	ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(EMassage->Text);
	ChatClient->Disconnect();

	String buffer;
	buffer = ChatClient->IOHandler->ReadLn();

	LMessage->Items->Add(buffer);

}
//---------------------------------------------------------------------------


