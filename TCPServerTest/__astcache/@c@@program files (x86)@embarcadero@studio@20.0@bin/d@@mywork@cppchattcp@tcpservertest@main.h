//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
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
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TTCP_Server : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	TIdTCPServer *TIdTCPServer;
	TEdit *EPort;
	TLabel *Port;
	TStringGrid *StringGrid1;
	TAdvDockPanel *AdvDockPanel1;
	void __fastcall ESendClick(TObject *Sender);
	void __fastcall ServerExecute(TIdContext *AContext);
	void __fastcall ServerDisconnect(TIdContext *AContext);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TTCP_Server(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTCP_Server *TCP_Server;
//---------------------------------------------------------------------------
#endif
