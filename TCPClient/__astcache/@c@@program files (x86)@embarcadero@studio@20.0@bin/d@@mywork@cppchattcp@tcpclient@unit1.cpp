//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

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
	//ChatClient->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TTCP_Client::ESendClick(TObject *Sender)
{

    ChatClient->Host = EHost->Text;
    ChatClient->Connect();

    // ChatClient->Socket->Write(EMassage->Text.Length());
	ChatClient->Socket->Write(IntToStr(EMassage->Text.Length()));  // IntToStr()を用いてString型にすること
																   // String型にしないと文字化けになってLMessageに表示されません
    //ChatClient->Socket->Write(EMassage->Text);
    ChatClient->Socket->WriteLn(EMassage->Text); // ChatServerExcute()ではReadLn()でLn付きで受信するため、送信側もWriteLn()を使う
        // WriteLn()でないとReadLn()で処理が止まってしまう

    // ChatClient->Disconnect();

    // Note:
    // ChatClientのConnect(), Disconnect()はSendClickイベントで実施すると、応答受信までDisconnect()できません。
	// TCP通信のソフトでは「接続」「切断」ボタンを別途用意して、Connect(), Disconnect()をそれらのボタン押下で処理する例はあります。

}
//---------------------------------------------------------------------------


