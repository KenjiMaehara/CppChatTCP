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
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TTCP_Server : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	TIdTCPServer *ChatServer;
	TEdit *EPort;
	TLabel *Port;
	TStringGrid *StringGrid1;
	void __fastcall ESendClick(TObject *Sender);
	void __fastcall ChatServerExcute(TIdContext *AContext);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TTCP_Server(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTCP_Server *TCP_Server;
//---------------------------------------------------------------------------
#endif
