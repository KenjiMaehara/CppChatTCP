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
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TLabel *Label1;
	TEdit *EHost;
	TListBox *LMessage;
	TEdit *EMassage;
	TButton *ESend;
	TIdTCPClient *ChatClient;
	void __fastcall ESendClick(TObject *Sender);
	//void __fastcall ChatServerExcute(TIdContext *AContext);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
