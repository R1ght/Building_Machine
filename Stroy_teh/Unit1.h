//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TListBox *ListBox1;
        TGroupBox *GroupBox7;
        TLabel *Label12;
        TEdit *Edit14;
        TButton *Button4;
        TGroupBox *GroupBox8;
        TLabel *Label11;
        TEdit *Edit15;
        TButton *Button5;
        TGroupBox *GroupBox4;
        TLabel *Label16;
        TButton *Button1;
        TEdit *Edit10;
        TGroupBox *GroupBox5;
        TLabel *Label14;
        TEdit *Edit12;
        TButton *Button2;
        TGroupBox *GroupBox6;
        TLabel *Label13;
        TButton *Button3;
        TEdit *Edit13;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TMemo *Memo1;
        TGroupBox *GroupBox9;
        TRadioGroup *RadioGroup1;
        TButton *Button6;
        TListBox *ListBox2;
        TComboBox *ComboBox2;
        TGroupBox *GroupBox10;
        TRadioGroup *RadioGroup2;
        TButton *Button7;
        TPanel *Panel1;
        TLabel *Label19;
        TEdit *Edit17;
        TEdit *Edit18;
        TLabel *Label20;
        TPanel *Panel2;
        TLabel *Label21;
        TEdit *Edit16;
        TMemo *Memo2;
        TButton *Button8;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TButton *Button9;
        TButton *Button10;
        TLabel *Label22;
        TEdit *Edit19;
        TLabel *Label23;
        TEdit *Edit20;
        TLabel *Label25;
        TEdit *Edit21;
        TEdit *Edit22;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TEdit *Edit24;
        TLabel *Label6;
        TLabel *Label29;
        TEdit *Edit23;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TEdit *Edit25;
        TLabel *Label33;
        TEdit *Edit26;
        TLabel *Label34;
        TEdit *Edit27;
        TLabel *Label15;
        TLabel *Label35;
        TEdit *Edit28;
        TLabel *Label37;
        TLabel *Label38;
        TEdit *Edit30;
        TLabel *Label39;
        TEdit *Edit31;
        TGroupBox *GroupBox11;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TEdit *Edit32;
        TEdit *Edit33;
        TEdit *Edit34;
        TLabel *Label46;
        TLabel *Label47;
        TGroupBox *GroupBox12;
        TLabel *Label44;
        TLabel *Label45;
        TLabel *Label48;
        TLabel *Label49;
        TLabel *Label50;
        TEdit *Edit35;
        TEdit *Edit36;
        TEdit *Edit37;
        TEdit *Edit29;
        TButton *Button11;
        TButton *Button12;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TLabel *Label7;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
