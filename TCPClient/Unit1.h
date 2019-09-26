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
class TTCP_Client : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TLabel *Label1;
	TEdit *EHost;
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	TEdit *EPort;
	TLabel *Label2;
	TButton *EConnect;
	void __fastcall ESendClick(TObject *Sender);
	void __fastcall EConnectClick(TObject *Sender);
	//void __fastcall ChatServerExcute(TIdContext *AContext);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TTCP_Client(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTCP_Client *TCP_Client;
//---------------------------------------------------------------------------
#endif
