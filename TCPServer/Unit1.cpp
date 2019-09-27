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

	ChatServer->Active = False;
	StringGrid1->Cells[0][0]="No";
	StringGrid1->Cells[1][0]="�[������";
	StringGrid1->Cells[2][0]="�[���A�h���X";
	StringGrid1->Cells[3][0]="MAC";
	StringGrid1->Cells[4][0]="IP�A�h���X";
	StringGrid1->Cells[5][0]="�ڑ����|�[�g�ԍ�";

}
//---------------------------------------------------------------------------

void __fastcall TTCP_Server::ESendClick(TObject *Sender)
{
	if (ChatServer->Active == False) {

		ChatServer->DefaultPort = StrToInt(EPort->Text);
		TCP_Server->Caption = "TCP_Server�i�ڑ����j";
		ChatServer->Active = True;
		ESend->Caption = "��~";

	} else {

		ChatServer->Active = false;
		TCP_Server->Caption = "TCP_Serve";
		ESend->Caption = "�J�n";

	}




}
//---------------------------------------------------------------------------

void __fastcall TTCP_Server::ChatServerExcute(TIdContext *AContext)
{


	AnsiString rcvdStr;


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


	threads = ChatServer->Contexts->LockList();

	for(int idx=0; idx < threads->Count; idx++){
		ac = reinterpret_cast<TIdContext *>(threads->Items[idx]);

		if (AContext->Connection->Socket->Binding->PeerPort == ac->Connection->Socket->Binding->PeerPort) {
			ac->Connection->IOHandler->WriteLn(rcvdStr);
			LMessage->Items->Add(threads->Count);


			for (int i = 0; i < StringGrid1->RowCount; i++) {

				AnsiString test;
				test = IntToStr(AContext->Connection->Socket->Binding->PeerPort);

				if (test == StringGrid1->Cells[5][i]) {
					break;
				}


				if (i==StringGrid1->RowCount-1) {
					StringGrid1->RowCount += 1;
					StringGrid1->Cells[0][StringGrid1->RowCount-1] = StringGrid1->RowCount-1;
					StringGrid1->Cells[5][StringGrid1->RowCount-1] = AContext->Connection->Socket->Binding->PeerPort;
					StringGrid1->Cells[4][StringGrid1->RowCount-1] = AContext->Connection->Socket->Binding->PeerIP;
				}

			}
		}
	}

	ChatServer->Contexts->UnlockList();

}
//---------------------------------------------------------------------------




