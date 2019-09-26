//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
//---------------------------------------------------------------------------
class TTCP_Server : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	TIdTCPServer *ChatServer;
	TEdit *EPort;
	TLabel *Port;
	void __fastcall ESendClick(TObject *Sender);
	void __fastcall ChatServerExcute(TIdContext *AContext);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TTCP_Server(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTCP_Server *TCP_Server;
//---------------------------------------------------------------------------
#endif
