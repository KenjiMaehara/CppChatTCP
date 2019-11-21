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
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTCP_Client : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TLabel *Label1;
	TEdit *EHost;
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	TEdit *EPort;
	TLabel *Label2;
	TButton *EConnect;
	TEdit *Edit1;
	TLabel *Label3;
	TADODataSet *ADODataSet1;
	TStatusBar *StatusBar1;
	void __fastcall ESendClick(TObject *Sender);
	void __fastcall EConnectClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	//void __fastcall ChatServerExcute(TIdContext *AContext);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TTCP_Client(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTCP_Client *TCP_Client;
//---------------------------------------------------------------------------
#endif
