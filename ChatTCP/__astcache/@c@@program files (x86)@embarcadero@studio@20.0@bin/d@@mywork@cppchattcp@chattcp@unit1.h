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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TIdTCPClient *ChatClient;
	TIdTCPServer *ChatServer;
	TLabel *Label1;
	TEdit *EHost;
	TListBox *ListBox1;
	TEdit *Edit2;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
