//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "fstream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
AnsiString pathAS;
char* path;
const int Ma = 30;
char per1[Ma];
ofstream outfile;
ifstream infile;

//---------------------------------------------------------------------------
//--------------------АБК----------------------------------------------------
//---------------------------------------------------------------------------
class StroiTeh2
{
  protected:
    AnsiString   model,      // Модель
         marka,              // Марка
         tip_tr,             // Тип трансмиссии
         country;   // Страна производитель
    int  moschnost,      // Мощность
         dlina,
         shirina,
         visota,
         massa;    // Масштаб изображения
  public:
   //Конструктор по умолчанию//
    StroiTeh2(){}
   //Инициирующий конструктор//
   StroiTeh2(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos,int mas)
       : model(mod),
         marka(mar),
         country(coun),
         tip_tr(tt),
         dlina(dli),
         shirina(shi),
         visota(vis),
         moschnost(mos),
         massa(mas)
    {}
    //Конструктор копирования//
    Plotters(const StroiTeh2&);
    void operator = (const StroiTeh2&);  //Оператор присваивания
    bool operator == (const StroiTeh2&); //Оператор "Равно"
    bool operator != (const StroiTeh2&); //Оператор "Не равно"
    virtual void print(TMemo*)=0;           //Функция вывода на дисплей
    virtual void Get_vals(AnsiString*)=0;   //Функция для возврата массива со значениями полей класса
    virtual void Write_to_file() = 0;       //Функция записи в файл
    virtual void Read_from_file() = 0;      //Функция чтения из файла
    ~StroiTeh2(){}                       //Деструктор
};

class StroiTeh : public StroiTeh2
{
  protected:
   // AnsiString  vid_pribora;  // Вид прибора
   // int optich_sila;  // Оптическая сила
  public:
    StroiTeh(){}
    StroiTeh(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas)
     : StroiTeh2(mod,mar,coun,tt,dli,shi,vis,mos,mas)
       //vid_pribora(v_p),
       //optich_sila(o_s)
    {}
    void print(TMemo* Memo)
    {
      Memo->Lines->Add("Модель                               "+model);
      Memo->Lines->Add("Марка                                "+marka);
      Memo->Lines->Add("Страна производитель                 "+country);
      Memo->Lines->Add("Тип трансмиссии                      "+tip_tr);
      Memo->Lines->Add("Длина                                "+IntToStr(dlina));
      Memo->Lines->Add("Ширина                               "+IntToStr(shirina));
      Memo->Lines->Add("Высота                               "+IntToStr(visota));
      Memo->Lines->Add("Мощность                             "+IntToStr(moschnost));
      Memo->Lines->Add("Масса                                "+IntToStr(massa));
    }
    void Get_vals(AnsiString* ptrd)
     {}
    ~StroiTeh(){}
};



//--------------------Экскаваторы----------------------------------------------
class Ekskavator  : public StroiTeh
{
  protected:
        int kovsh,   // Ковш, м3
         glubina_kopaniya; // глубина копания, мм
  public:
    Ekskavator(){}
    Ekskavator(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, int kov, int g_k)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       kovsh(kov),
       glubina_kopaniya(g_k)

    {}
        Ekskavator(const Ekskavator& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;      kovsh = obj.kovsh;
         glubina_kopaniya = obj.glubina_kopaniya;
        }
        void operator = (const Ekskavator& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         kovsh = obj.kovsh; glubina_kopaniya = obj.glubina_kopaniya;
        }
        bool operator == (const Ekskavator& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa) &&
            (kovsh == obj.kovsh)&&(glubina_kopaniya == obj.glubina_kopaniya)) return true;
          else return false;
        }
        bool operator != (const Ekskavator& obj)
        {if(*(this)==obj) return false; else return true;};


    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("==============Класс ЭКСКАВАТОРЫ==============");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Ковш, м3                                    "+IntToStr(kovsh));
      Memo->Lines->Add("Глубина копания, м                          "+IntToStr(glubina_kopaniya));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = IntToStr(kovsh);
              ptrd[10] = IntToStr(glubina_kopaniya);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<kovsh<<endl
              <<glubina_kopaniya<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              kovsh = StrToInt(per1);
              infile.getline(per1,Ma);
              glubina_kopaniya = StrToInt(per1);
             }

    ~Ekskavator(){}
};

//--------------------Бульдозеры----------------------------------------------
class Buldozer  : public StroiTeh
{
  protected:
    AnsiString  tip_otvala;         // Тип лупы
        int obiem_otvala;   // Характер увеличения
  public:
    Buldozer(){}
    Buldozer(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, AnsiString t_otv,int o_otv)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       tip_otvala(t_otv),
       obiem_otvala(o_otv)

    {}
        Buldozer(const Buldozer& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         tip_otvala = obj.tip_otvala; obiem_otvala = obj.obiem_otvala;
        }
        void operator = (const Buldozer& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;    moschnost = obj.moschnost;
         massa = obj.massa;
         tip_otvala = obj.tip_otvala; obiem_otvala = obj.obiem_otvala;
        }
        bool operator == (const Buldozer& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            ( massa == obj.massa ) &&
            (tip_otvala == obj.tip_otvala)&&(obiem_otvala == obj.obiem_otvala)) return true;
          else return false;
        }
        bool operator != (const Buldozer& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("==============Класс БУЛЬДОЗЕРЫ===============");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Тип отвала                                   "+tip_otvala);
      Memo->Lines->Add("Объем отвала (м3)                            "+IntToStr(obiem_otvala));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = tip_otvala;
              ptrd[10] = IntToStr(obiem_otvala);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<tip_otvala.c_str()<<endl
              <<obiem_otvala<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              tip_otvala = per1;
              infile.getline(per1,Ma);
              obiem_otvala = StrToInt(per1);
             }

    ~Buldozer(){}
};

//---------------------------КАТКИ-----------------------------------
class Katki  : public StroiTeh
{
  protected:
        int Shirina_vala,
             Diametr_vala,  // Тип ходового устройства
             Chastota; // Вместимость бункера, м3
  public:
    Katki(){}
    Katki(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, int s_v, int d_v, int chas)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos, mas),
       Shirina_vala(s_v),
       Diametr_vala(d_v),
       Chastota(chas)

    {}
        Katki(const Katki& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         Shirina_vala = obj.Shirina_vala; Diametr_vala = obj.Diametr_vala;
         Chastota = obj.Chastota;
        }
        void operator = (const Katki& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         Shirina_vala = obj.Shirina_vala; Diametr_vala = obj.Diametr_vala;
         Chastota = obj.Chastota;
        }
        bool operator == (const Katki& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa) &&
            (Shirina_vala == obj.Shirina_vala)&&(Diametr_vala == obj.Diametr_vala)
            &&(Chastota == obj.Chastota))return true;
          else return false;
        }
        bool operator != (const Katki& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("================Класс Катки==================");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Ширина вала (мм)                             "+IntToStr(Shirina_vala));
      Memo->Lines->Add("Димаетр вала (мм)                            "+IntToStr(Diametr_vala));
      Memo->Lines->Add("Частота колебаний (Гц)                       "+IntToStr(Chastota));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = IntToStr(Shirina_vala);
              ptrd[10] = IntToStr(Diametr_vala);
              ptrd[11] = IntToStr(Chastota);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<Shirina_vala<<endl
              <<Diametr_vala<<endl
              <<Chastota<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              Shirina_vala = StrToInt(per1);
              infile.getline(per1,Ma);
              Diametr_vala = StrToInt(per1);
              infile.getline(per1,Ma);
              Chastota = StrToInt(per1);
             }

    ~Katki(){}
};


//--------------------АСФАЛЬТОУКЛАДЧИКИ---------------------------
class Asphalt  : public StroiTeh
{
  protected:
        AnsiString tip_hod_ustroistva;   // Тип ходового устройства
        int     vmestimost; // Вместимость бункера, м3
         int       proizvoditelnost;
  public:
    Asphalt(){}
    Asphalt(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, AnsiString t_h_p, int proizv, int vmes)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       tip_hod_ustroistva(t_h_p),
       proizvoditelnost(proizv),
       vmestimost(vmes)

    {}
        Asphalt(const Asphalt& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         tip_hod_ustroistva = obj.tip_hod_ustroistva; proizvoditelnost = obj.proizvoditelnost;
         vmestimost = obj.vmestimost;
        }
        void operator = (const Asphalt& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         tip_hod_ustroistva = obj.tip_hod_ustroistva; proizvoditelnost = obj.proizvoditelnost;
         vmestimost = obj.vmestimost;
        }
        bool operator == (const Asphalt& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa) &&
            (tip_hod_ustroistva == obj.tip_hod_ustroistva)&&(proizvoditelnost == obj.proizvoditelnost)
            &&(vmestimost == obj.vmestimost))return true;
          else return false;
        }
        bool operator != (const Asphalt& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("=========Класс АСФАЛЬТОУКЛАДЧИКИ=============");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Тип ходового устройства                      "+tip_hod_ustroistva);
      Memo->Lines->Add("Производительность (т/ч)                     "+IntToStr(proizvoditelnost));
      Memo->Lines->Add("Вместимость бункера (м3)                     "+IntToStr(vmestimost));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = tip_hod_ustroistva;
              ptrd[10] = IntToStr(proizvoditelnost);
              ptrd[11] = IntToStr(vmestimost);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<tip_hod_ustroistva.c_str()<<endl
              <<proizvoditelnost<<endl
              <<vmestimost<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              tip_hod_ustroistva = per1;
              infile.getline(per1,Ma);
              proizvoditelnost = StrToInt(per1);
              infile.getline(per1,Ma);
              vmestimost = StrToInt(per1);
             }

    ~Asphalt(){}
};



//---------------------------АВТОБЕТОНОСМЕСИТЕЛИ-----------------------------------
class Smesiteli  : public StroiTeh
{
  protected:
        int vmest_baraban;
        int chastota_vrash;  // Тип ходового устройства
        int  bak; // Вместимость бункера, м3
  public:
    Smesiteli(){}
    Smesiteli(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, int v_b, int ch_v, int bk)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       vmest_baraban(v_b),
       chastota_vrash(ch_v),
       bak(bk)

    {}
        Smesiteli(const Smesiteli& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         vmest_baraban = obj.vmest_baraban; chastota_vrash = obj.chastota_vrash;
         bak = obj.bak;
        }
        void operator = (const Smesiteli& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         vmest_baraban = obj.vmest_baraban; chastota_vrash = obj.chastota_vrash;
         bak = obj.bak;
        }
        bool operator == (const Smesiteli& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa) &&
            (vmest_baraban == obj.vmest_baraban)&&(chastota_vrash == obj.chastota_vrash)
            &&(bak == obj.bak))return true;
          else return false;
        }
        bool operator != (const Smesiteli& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("==========Класс АВТОБЕТОНОСМЕСИТЕЛИ==========");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Вместимость смесительного барабана (м3)      "+IntToStr(vmest_baraban));
      Memo->Lines->Add("Частота вращения барабана (Гц)               "+IntToStr(chastota_vrash));
      Memo->Lines->Add("Объем водяного бака (л)                      "+IntToStr(bak));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = IntToStr(vmest_baraban);
              ptrd[10] = IntToStr(chastota_vrash);
              ptrd[11] = IntToStr(bak);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<vmest_baraban<<endl
              <<chastota_vrash<<endl
              <<bak<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              vmest_baraban = StrToInt(per1);
              infile.getline(per1,Ma);
              chastota_vrash = StrToInt(per1);
              infile.getline(per1,Ma);
              bak = StrToInt(per1);
             }

    ~Smesiteli(){}
};


//---------------------------Краны-----------------------------------
class Krani  : public StroiTeh
{
  protected:
        int gruz; // Грузоподъемность
        int  dlina_streli; // Длина стрелы
        int vilet_streli;  // Максимальный вылет стрелы
        int  visota_podiema; //Максимальная высота подъема
  public:
    Krani(){}
    Krani(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, int gr, int dl_str, int vil_s, int vis_pod)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       gruz(gr),
       dlina_streli(dl_str),
       vilet_streli(vil_s),
       visota_podiema(vis_pod)

    {}
        Krani(const Krani& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         gruz = obj.gruz; dlina_streli = obj.dlina_streli;
         vilet_streli = obj.vilet_streli;   visota_podiema = obj.visota_podiema;
        }
        void operator = (const Krani& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         gruz = obj.gruz; dlina_streli = obj.dlina_streli;
         vilet_streli = obj.vilet_streli;  visota_podiema = obj.visota_podiema;
        }
        bool operator == (const Krani& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa) &&
            (gruz == obj.gruz)&&(dlina_streli == obj.dlina_streli)
            &&(vilet_streli == obj.vilet_streli) && (visota_podiema == obj.visota_podiema))return true;
          else return false;
        }
        bool operator != (const Krani& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("=================Класс КРАНЫ=================");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Грузоподъемность (т)                         "+IntToStr(gruz));
      Memo->Lines->Add("Длина грузовой стрелы (м)                    "+IntToStr(dlina_streli));
      Memo->Lines->Add("Максимальный вылет стрелы (м)                "+IntToStr(vilet_streli));
      Memo->Lines->Add("Максимальная высота подъема стрелы (м)       "+IntToStr(visota_podiema));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = IntToStr(gruz);
              ptrd[10] = IntToStr(dlina_streli);
              ptrd[11] = IntToStr(vilet_streli);
              ptrd[12] = IntToStr(visota_podiema);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<gruz<<endl
              <<dlina_streli<<endl
              <<vilet_streli<<endl
              <<visota_podiema<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              gruz = StrToInt(per1);
              infile.getline(per1,Ma);
              dlina_streli = StrToInt(per1);
              infile.getline(per1,Ma);
              vilet_streli = StrToInt(per1);
              infile.getline(per1,Ma);
              visota_podiema = StrToInt(per1);

             }

    ~Krani(){}
};


//---------------------------САМОСВАЛЫ-----------------------------------
class Samosvali  : public StroiTeh
{
  protected:
        int obiem_plat; // Объем самосвальной платформы
        int gruz;  // Грузоподъемность
        int  ugol_oprok; // Угол опрокидывания
  public:
    Samosvali(){}
    Samosvali(AnsiString mod,AnsiString mar,AnsiString coun,AnsiString tt,int dli,int shi, int vis, int mos, int mas, int ob_plat, int gr, int ug_op)
     : StroiTeh(mod,mar,coun,tt,dli,shi,vis,mos,mas),
       obiem_plat(ob_plat),
       gruz(gr),
       ugol_oprok(ug_op)

    {}
        Samosvali(const Samosvali& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         obiem_plat = obj.obiem_plat; gruz = obj.gruz;
         ugol_oprok = obj.ugol_oprok;
        }
        void operator = (const Samosvali& obj)
        {
         model = obj.model;      marka = obj.marka;
         country = obj.country;  tip_tr = obj.tip_tr;
         dlina = obj.dlina;      shirina = obj.shirina;
         visota = obj.visota;     moschnost = obj.moschnost;
         massa = obj.massa;
         obiem_plat = obj.obiem_plat; gruz = obj.gruz;
         ugol_oprok = obj.ugol_oprok;
        }
        bool operator == (const Samosvali& obj)
        {
         if((model == obj.model)&&(marka == obj.marka)&&
            (country == obj.country)&&(tip_tr == obj.tip_tr)&&
            (dlina == obj.dlina)&&(shirina == obj.shirina )&&
            (visota == obj.visota)&&(moschnost == obj.moschnost)&&
            (massa == obj.massa ) &&
            (obiem_plat == obj.obiem_plat)&&(gruz == obj.gruz)
            &&(ugol_oprok == obj.ugol_oprok))return true;
          else return false;
        }
        bool operator != (const Samosvali& obj)
        {if(*(this)==obj) return false; else return true;};

    void print(TMemo* Memo)
    {
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("===============Класс САМОСВАЛЫ===============");
      Memo->Lines->Add("=============================================");
      StroiTeh::print(Memo);
      Memo->Lines->Add("Объем самосвальной платформы (м3)            "+IntToStr(obiem_plat));
      Memo->Lines->Add("Грузподъемность (т)                          "+IntToStr(gruz));
      Memo->Lines->Add("Угол опрокидывания платформы (град)          "+IntToStr(ugol_oprok));
      Memo->Lines->Add("=============================================");
      Memo->Lines->Add("");
      Memo->Lines->Add("");
    }
        void Get_vals(AnsiString* ptrd)
             {
              ptrd[0] = model;
              ptrd[1] = marka;
              ptrd[2] = country;
              ptrd[3] = tip_tr;
              ptrd[4] = IntToStr(dlina);
              ptrd[5] = IntToStr(shirina);
              ptrd[6] = IntToStr(visota);
              ptrd[7] = IntToStr(moschnost);
              ptrd[8] = IntToStr(massa);
              ptrd[9] = IntToStr(obiem_plat);
              ptrd[10] = IntToStr(gruz);
              ptrd[11] = IntToStr(ugol_oprok);
             }
        void Write_to_file()
             {
              outfile
              <<model.c_str()<<endl
              <<marka.c_str()<<endl
              <<country.c_str()<<endl
              <<tip_tr.c_str()<<endl
              <<dlina<<endl
              <<shirina<<endl
              <<visota<<endl
              <<moschnost<<endl
              <<massa<<endl
              <<obiem_plat<<endl
              <<gruz<<endl
              <<ugol_oprok<<endl;
             }

        void Read_from_file()
             {
              infile.getline(per1,Ma);
              model = per1;
              infile.getline(per1,Ma);
              marka = per1;
              infile.getline(per1,Ma);
              country = per1;
              infile.getline(per1,Ma);
              tip_tr = per1;
              infile.getline(per1,Ma);
              dlina = StrToInt(per1);
              infile.getline(per1,Ma);
              shirina = StrToInt(per1);
              infile.getline(per1,Ma);
              visota = StrToInt(per1);
              infile.getline(per1,Ma);
              moschnost = StrToInt(per1);
              infile.getline(per1,Ma);
              massa = StrToInt(per1);
              infile.getline(per1,Ma);
              obiem_plat = StrToInt(per1);
              infile.getline(per1,Ma);
              gruz = StrToInt(per1);
              infile.getline(per1,Ma);
              ugol_oprok = StrToInt(per1);
             }

    ~Samosvali(){}
};


/*========================================================*/
/*============Обобщенный контейнерный класс===============*/
/*========================================================*/
class Stack1
{
        private:
                void* data;
                AnsiString name;
                Stack1 *head, *next;
        public:
                Stack1()
                {
                   head  = next = NULL;
                }
                void Add_elem_head(void* x, AnsiString n)
                {
                  Stack1 *el;
                  el = new Stack1;
                  el->data = x;
                  el->name = n;
                  if (head == NULL)
                   {
                    el->next = NULL;
                    head = el;
                   } else
                     {
                      el->next = head;
                      head = el;
                     }
                 }


                void Delete_elem_head()
                 {
                  if(head!=NULL)
                    head = head->next;
                 }

                void Set_data(void* x, AnsiString nname)
                  {
                   bool flag = true;
                   Stack1 *hhead;
                   hhead = head;
                   if (head ==NULL) Add_elem_head(x,nname);
                     else
                        while (hhead !=NULL)
                          {
                            if(hhead->name == nname)
                             {
                               hhead->data = x;
                               flag = false;
                              }
                            hhead = hhead->next;
                           }
                        if (flag) Add_elem_head(x,nname);
                  }

                void* Get_data(AnsiString nname)
                  {
                   Stack1 *hhead;
                   hhead = head;
                   while (hhead !=NULL)
                    {
                     if(hhead->name == nname)
                       {
                        return hhead->data;
                       }
                     hhead = hhead->next;
                    }
                    return NULL;
                  }

                ~Stack1(){};
};

/*========================================================*/
/*========Шаблон для хранения указателей на АБК===========*/
/*========================================================*/

template <class T>
class Stack :private Stack1
{
        public:

                Stack()
                {Stack1::Stack1();}
                void Add_elem_head(T x, AnsiString n)
                {Stack1::Add_elem_head(reinterpret_cast<void*>(x),n);}

                void Delete_elem_head()
                 {Stack1::Delete_elem_head();}

                void Set_data(T x, AnsiString n)
                 {Stack1::Set_data(reinterpret_cast<void*>(x),n);}

                T Get_data(AnsiString nname)
                 {
                  if (Stack1::Get_data(nname) != NULL)
                   return reinterpret_cast<T>(Stack1::Get_data(nname));
                  else
                   { dyn_vect* obj=new dyn_vect;
                     return reinterpret_cast<T>(obj);
                   }
                 }

                ~Stack(){};
};

//--------------------------------------------
//-----------Динамический вектор--------------
//--------------------------------------------
const MAX = 100;

class dyn_vect
{
 private:
   long size;
   StroiTeh2** arr;
 public:
  dyn_vect(long s = MAX): size(s)
   {
    arr = new StroiTeh2*[size];
     if(!arr) ShowMessage("Ошибка при создании массива!");
   }

  void Set_one(StroiTeh2* x, int num)
   {
    arr[num] = x;
   }

  long length () const {return size;}

  dyn_vect(const dyn_vect& arrr)
   {
       size = arrr.size;
       arr = new StroiTeh2*[size];
       for(int i = 0; i<size; i++)
         arr[i] = arrr.arr[i];
   }

  dyn_vect& operator=(const dyn_vect& arrr)
   {
     if (this != &arrr)
      {
       size = arrr.size;
       if (arr) delete[] arr;
       arr = new StroiTeh2*[size];
       for(int i = 0; i<size; i++)
         arr[i] = arrr.arr[i];
      }
     return *this;
   }

  void orderVoz(int k, int l, int num, char typ)
   {
    AnsiString mas1[11];
    AnsiString mas2[11];
    this->arr[k]->Get_vals(mas1);
    this->arr[l]->Get_vals(mas2);
    switch(typ)
      {
        case 'i':
          {
           if (StrToInt(mas1[num])>StrToInt(mas2[num]))
             {
              StroiTeh2* temp;
              temp = this->arr[k];
              this->arr[k] = this->arr[l];
              this->arr[l] = temp;
             }
          } break;
        case 'a':
          {
           if (mas1[num]>mas2[num])
             {
              StroiTeh2* temp;
              temp = this->arr[k];
              this->arr[k] = this->arr[l];
              this->arr[l] = temp;
             }
          } break;
      }
   }

  void orderUb(int k, int l, int num, char typ)
   {
    AnsiString mas1[15];
    AnsiString mas2[15];
    this->arr[k]->Get_vals(mas1);
    this->arr[l]->Get_vals(mas2);
    switch(typ)
      {
        case 'i':
          {
           if (StrToInt(mas1[num])<StrToInt(mas2[num]))
             {
              StroiTeh2* temp;
              temp = this->arr[k];
              this->arr[k] = this->arr[l];
              this->arr[l] = temp;
             }
          } break;
        case 'a':
          {
           if (mas1[num]<mas2[num])
             {
              StroiTeh2* temp;
              temp = this->arr[k];
              this->arr[k] = this->arr[l];
              this->arr[l] = temp;
             }
          } break;
      }
   }

  void bsortUb(int razm, int numm, char typp)
   {
      for(int i=0; i<razm-1; i++)
        for(int j=i+1; j<razm; j++)
          orderUb(i,j,numm,typp);
   }

  void bsort(int razm, int numm, char typp)
   {
      for(int i=0; i<razm-1; i++)
        for(int j=i+1; j<razm; j++)
          orderVoz(i,j,numm,typp);
   }

  void find(AnsiString findd, TMemo* Memo, int razm, int num, char typ)
   {
    AnsiString mas1[15];
    for(int k=0; k<razm; k++)
     {
      this->arr[k]->Get_vals(mas1);
      switch(typ)
        {
          case 'i':
            {
             if (StrToInt(mas1[num])==StrToInt(findd))
               {this->arr[k]->print(Memo);}
            } break;
          case 'a':
            {
             if (mas1[num]==findd)
               {this->arr[k]->print(Memo);}
            } break;
        }
     }
   }

  void find_Diap(AnsiString find_from, AnsiString find_to, TMemo* Memo, int razm, int num, char typ)
   {
    AnsiString mas1[15];
    for(int k=0; k<razm; k++)
     {
      this->arr[k]->Get_vals(mas1);
      switch(typ)
        {
          case 'i':
            {
             if ((StrToInt(find_from)<=StrToInt(mas1[num]))&&
                 (StrToInt(mas1[num])<=StrToInt(find_to)))
               {this->arr[k]->print(Memo);}
            } break;
          case 'a':
            {
             if ((find_from<=mas1[num])&&(mas1[num]<=find_to))
               {this->arr[k]->print(Memo);}
            } break;
        }
     }
   }


  StroiTeh2* operator[](long n) const
   {
    if(n<0||n>MAX) exit(0);
    return arr[n];
   }
  ~dyn_vect(){};
};

dyn_vect  dyn_vect_eks,dyn_vect_bul,dyn_vect_kat,dyn_vect_asp,dyn_vect_sme, dyn_vect_kra,dyn_vect_sam;
int  kol_eks,kol_bul,kol_kat,kol_asp,kol_sme,kol_kra,kol_sam;
Stack<dyn_vect*> MyStack;


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
  switch (ListBox1->ItemIndex)
   {
    case 0:{
             GroupBox1->Visible = true;
             //GroupBox2->Visible = false;
             //GroupBox3->Visible = false;
             GroupBox4->Visible = true;
             GroupBox5->Visible = false;
             GroupBox6->Visible = false;
             GroupBox7->Visible = false;
             GroupBox8->Visible = false;
             GroupBox11->Visible = false;
             GroupBox12->Visible = false;
            } break;
    case 1:{
             GroupBox1->Visible = true;
           //  GroupBox2->Visible = false;
             //GroupBox3->Visible = false;
             GroupBox4->Visible = false;
             GroupBox5->Visible = true;
             GroupBox6->Visible = false;
             GroupBox7->Visible = false;
             GroupBox8->Visible = false;
             GroupBox11->Visible = false;
             GroupBox12->Visible = false;
           } break;
    case 2:{
             GroupBox1->Visible = true;
            // GroupBox2->Visible = false;
            // GroupBox3->Visible = false;
             GroupBox4->Visible = false;
             GroupBox5->Visible = false;
             GroupBox6->Visible = false;
             GroupBox7->Visible = true;
             GroupBox8->Visible = false;
             GroupBox11->Visible = false;
             GroupBox12->Visible = false;
           } break;
    case 3:{
             GroupBox1->Visible = true;
             //GroupBox2->Visible = false;
            // GroupBox3->Visible = false;
             GroupBox4->Visible = false;
             GroupBox5->Visible = false;
             GroupBox6->Visible = false;
             GroupBox7->Visible = false;
             GroupBox8->Visible = true;
             GroupBox11->Visible = false;
             GroupBox12->Visible = false;
           } break;
    case 4:{
             GroupBox1->Visible = true;
           //  GroupBox2->Visible = false;
          //   GroupBox3->Visible = true;
             GroupBox4->Visible = false;
             GroupBox5->Visible = false;
             GroupBox6->Visible = false;
             GroupBox7->Visible = false;
             GroupBox8->Visible = false;
             GroupBox11->Visible = true;
             GroupBox12->Visible = false;
           } break;
    case 5:{
             GroupBox1->Visible = true;
           //  GroupBox2->Visible = false;
          //   GroupBox3->Visible = true;
             GroupBox4->Visible = false;
             GroupBox5->Visible = false;
             GroupBox6->Visible = true;
             GroupBox7->Visible = false;
             GroupBox8->Visible = false;
             GroupBox11->Visible = false;
             GroupBox12->Visible = false;
           } break;
    case 6:{
             GroupBox1->Visible = true;
           //  GroupBox2->Visible = false;
           //  GroupBox3->Visible = true;
             GroupBox4->Visible = false;
             GroupBox5->Visible = false;
             GroupBox6->Visible = false;
             GroupBox7->Visible = false;
             GroupBox8->Visible = false;
             GroupBox11->Visible = false;
             GroupBox12->Visible = true;
           } break;
   };
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "")&&(Edit21->Text != "")&&
      (Edit22->Text != "")&&(Edit10->Text != "")&&
      (Edit26->Text != ""))
       {
        Ekskavator* ob1=new Ekskavator(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),StrToInt(Edit10->Text),
                             StrToInt(Edit26->Text));
        dyn_vect_eks.Set_one(ob1,kol_eks);
        MyStack.Set_data(&dyn_vect_eks,"Ekskavator");
        kol_eks++;
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "")&&(Edit21->Text != "")&&
      (Edit22->Text != "") && (Edit12->Text != "" )&&
      (Edit27->Text != ""))
       {
        Buldozer* ob1=new Buldozer(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),Edit12->Text,
                             StrToInt(Edit27->Text));
        dyn_vect_bul.Set_one(ob1,kol_bul);
        MyStack.Set_data(&dyn_vect_bul,"Buldozer");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
        kol_bul++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "")&&(Edit21->Text != "")&&
      (Edit22->Text != "") && (Edit13->Text != "") &&
      (Edit24->Text != "") &&  (Edit23->Text != "") &&
      (Edit25->Text != ""))
       {
        Krani* ob1=new Krani(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),StrToInt(Edit13->Text),
                             StrToInt(Edit24->Text), StrToInt(Edit23->Text),
                             StrToInt(Edit25->Text));
        dyn_vect_kra.Set_one(ob1,kol_kra);
        MyStack.Set_data(&dyn_vect_kra,"Krani");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);   
        kol_kra++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "") && (Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "") && (Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "") && (Edit21->Text != "")&&
      (Edit22->Text != "")&& (Edit14->Text != "")
      && (Edit28->Text != "") && (Edit29->Text != ""))
       {
        Katki* ob1=new Katki(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),StrToInt(Edit14->Text),
                             StrToInt(Edit28->Text),StrToInt(Edit29->Text));
        dyn_vect_kat.Set_one(ob1,kol_kat);
        MyStack.Set_data(&dyn_vect_kat,"Katki");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
        kol_kat++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "")&&(Edit21->Text != "")&&
      (Edit22->Text != "")&&(Edit15->Text != "")&&
      (Edit30->Text != "") && (Edit31->Text != ""))
       {
        Asphalt* ob1=new Asphalt(Edit1->Text,Edit2->Text,Edit3->Text,
                                        Edit4->Text,
                                        StrToInt(Edit19->Text),
                                         StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                                         StrToInt(Edit5->Text),
                                         StrToInt(Edit22->Text),Edit31->Text,
                                        StrToInt(Edit15->Text),
                                        StrToInt(Edit30->Text));
        dyn_vect_asp.Set_one(ob1,kol_asp);
        MyStack.Set_data(&dyn_vect_asp,"Asphalt");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
        kol_asp++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ListBox2->ItemIndex=0;
 Form1->ListBox2Click(Form1);
 kol_eks = 0;
 kol_bul = 0;
 kol_kat = 0;
 kol_asp = 0;
 kol_sme = 0;
 kol_kra = 0;
 kol_sam = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox2Click(TObject *Sender)
{
  switch (ListBox2->ItemIndex)
   {
    case 0:{
             ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
              ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Глубина копания");
             ComboBox2->Items->Add("Объем ковша");
            } break;

    case 1:{
             ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
              ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Объем отвала");
             ComboBox2->Items->Add("Тип отвала");
           } break;
    case 2:{
             ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
             ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Ширина вала");
             ComboBox2->Items->Add("Диаметр вала");
             ComboBox2->Items->Add("Частота колебаний");
           } break;
    case 3:{
            ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
              ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Производительность");
             ComboBox2->Items->Add("Тип ходового устройства");
             ComboBox2->Items->Add("Вместимость бункера");
           } break;
    case 4:{
             ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
              ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Вместимость барабана");
             ComboBox2->Items->Add("Частота вращения барабана");
             ComboBox2->Items->Add("Объем бака");
           } break;
    case 5:{
            ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
              ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Грузоподъемность");
             ComboBox2->Items->Add("Длина стрелы");
             ComboBox2->Items->Add("Вылет стрелы");
             ComboBox2->Items->Add("Высота подъема стрелы");
           } break;
    case 6:{
             ComboBox2->Items->Clear();
             ComboBox2->Items->Add("Модель");
             ComboBox2->Items->Add("Марка");
             ComboBox2->Items->Add("Страна производитель");
             ComboBox2->Items->Add("Тип трансмисии");
             ComboBox2->Items->Add("Длина");
             ComboBox2->Items->Add("Ширина");
             ComboBox2->Items->Add("Высота");
             ComboBox2->Items->Add("Мощность двигателя");
             ComboBox2->Items->Add("Масса");
             ComboBox2->Items->Add("Грузоподъемность");
             ComboBox2->Items->Add("Объем платформы");
             ComboBox2->Items->Add("Угол опрокидывания");
           } break;
   };
ComboBox2->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
 if (RadioGroup1->ItemIndex == 0)
  switch (ListBox2->ItemIndex)
   {
    case 0:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_eks.bsort(kol_eks,0,'a'); break;
            case 1: dyn_vect_eks.bsort(kol_eks,2,'a'); break;
            case 2: dyn_vect_eks.bsort(kol_eks,1,'a'); break;
            case 3: dyn_vect_eks.bsort(kol_eks,3,'a'); break;
            case 4: dyn_vect_eks.bsort(kol_eks,4,'i'); break;
            case 5: dyn_vect_eks.bsort(kol_eks,5,'i'); break;
            case 6: dyn_vect_eks.bsort(kol_eks,6,'i'); break;
            case 7: dyn_vect_eks.bsort(kol_eks,7,'i'); break;
            case 8: dyn_vect_eks.bsort(kol_eks,8,'i'); break;
            case 9: dyn_vect_eks.bsort(kol_eks,9,'i'); break;
            case 10: dyn_vect_eks.bsort(kol_eks,10,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_eks = *MyStack.Get_data("Ekskavator");
            for(int i = 0; i<kol_eks; i++)
              dyn_vect_eks[i]->print(Memo2);
            } break;
    case 1:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_bul.bsort(kol_bul,0,'a'); break;
            case 1: dyn_vect_bul.bsort(kol_bul,1,'a'); break;
            case 2: dyn_vect_bul.bsort(kol_bul,2,'a'); break;
            case 3: dyn_vect_bul.bsort(kol_bul,3,'a'); break;
            case 4: dyn_vect_bul.bsort(kol_bul,4,'i'); break;
            case 5: dyn_vect_bul.bsort(kol_bul,5,'i'); break;
            case 6: dyn_vect_bul.bsort(kol_bul,6,'i'); break;
            case 7: dyn_vect_bul.bsort(kol_bul,7,'i'); break;
            case 8: dyn_vect_bul.bsort(kol_bul,8,'i'); break;
            case 9: dyn_vect_bul.bsort(kol_bul,9,'a'); break;
           };
            Memo2->Clear();
            dyn_vect_bul = *MyStack.Get_data("Buldozer");
            for(int i = 0; i<kol_bul; i++)
             dyn_vect_bul[i]->print(Memo2);
           } break;
    case 2:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_kat.bsort(kol_kat,0,'a'); break;
            case 1: dyn_vect_kat.bsort(kol_kat,1,'a'); break;
            case 2: dyn_vect_kat.bsort(kol_kat,2,'a'); break;
            case 3: dyn_vect_kat.bsort(kol_kat,3,'a'); break;
            case 4: dyn_vect_kat.bsort(kol_kat,4,'i'); break;
            case 5: dyn_vect_kat.bsort(kol_kat,5,'i'); break;
            case 6: dyn_vect_kat.bsort(kol_kat,6,'i'); break;
            case 7: dyn_vect_kat.bsort(kol_kat,7,'i'); break;
            case 8: dyn_vect_kat.bsort(kol_kat,8,'i'); break;
            case 9: dyn_vect_bul.bsort(kol_kat,9,'i'); break;
            case 10: dyn_vect_bul.bsort(kol_kat,10,'i'); break;
            case 11: dyn_vect_bul.bsort(kol_kat,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_kat = *MyStack.Get_data("Katki");
            for(int i = 0; i<kol_kat; i++)
             dyn_vect_kat[i]->print(Memo2);
           } break;
    case 3:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_asp.bsort(kol_asp,0,'a'); break;
            case 1: dyn_vect_asp.bsort(kol_asp,2,'a'); break;
            case 2: dyn_vect_asp.bsort(kol_asp,3,'a'); break;
            case 3: dyn_vect_asp.bsort(kol_asp,0,'a'); break;
            case 4: dyn_vect_asp.bsort(kol_asp,4,'i'); break;
            case 5: dyn_vect_asp.bsort(kol_asp,5,'i'); break;
            case 6: dyn_vect_asp.bsort(kol_asp,6,'i'); break;
            case 7: dyn_vect_asp.bsort(kol_asp,7,'i'); break;
            case 8: dyn_vect_asp.bsort(kol_asp,8,'i'); break;
            case 9: dyn_vect_asp.bsort(kol_asp,8,'i'); break;
            case 10: dyn_vect_asp.bsort(kol_asp,9,'a'); break;
            case 11: dyn_vect_asp.bsort(kol_asp,10,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_asp = *MyStack.Get_data("Asphalt");
            for(int i = 0; i<kol_asp; i++)
             dyn_vect_asp[i]->print(Memo2);
           } break;
    case 4:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_sme.bsort(kol_sme,1,'a'); break;
            case 1: dyn_vect_sme.bsort(kol_sme,2,'a'); break;
            case 2: dyn_vect_sme.bsort(kol_sme,3,'a'); break;
            case 3: dyn_vect_sme.bsort(kol_sme,4,'a'); break;
            case 4: dyn_vect_sme.bsort(kol_sme,0,'i'); break;
            case 5: dyn_vect_sme.bsort(kol_sme,5,'i'); break;
            case 6: dyn_vect_sme.bsort(kol_sme,6,'i'); break;
            case 7: dyn_vect_sme.bsort(kol_sme,7,'i'); break;
            case 8: dyn_vect_sme.bsort(kol_sme,8,'i'); break;
            case 9: dyn_vect_sme.bsort(kol_sme,9,'i'); break;
            case 10: dyn_vect_sme.bsort(kol_sme,10,'i'); break;
            case 11: dyn_vect_sme.bsort(kol_sme,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_sme = *MyStack.Get_data("Smesiteli");
            for(int i = 0; i<kol_sme; i++)
             dyn_vect_sme[i]->print(Memo2);
           } break;
    case 5:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_kra.bsort(kol_kra,1,'a'); break;
            case 1: dyn_vect_kra.bsort(kol_kra,2,'a'); break;
            case 2: dyn_vect_kra.bsort(kol_kra,3,'a'); break;
            case 3: dyn_vect_kra.bsort(kol_kra,4,'a'); break;
            case 4: dyn_vect_kra.bsort(kol_kra,5,'i'); break;
            case 5: dyn_vect_kra.bsort(kol_kra,0,'i'); break;
            case 6: dyn_vect_kra.bsort(kol_kra,6,'i'); break;
            case 7: dyn_vect_kra.bsort(kol_kra,7,'i'); break;
            case 8: dyn_vect_kra.bsort(kol_kra,8,'i'); break;
            case 9: dyn_vect_kra.bsort(kol_kra,9,'i'); break;
            case 10: dyn_vect_kra.bsort(kol_kra,10,'i'); break;
            case 11: dyn_vect_kra.bsort(kol_kra,11,'i'); break;
            case 12: dyn_vect_kra.bsort(kol_kra,12,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_kra = *MyStack.Get_data("Krani");
            for(int i = 0; i<kol_kra; i++)
             dyn_vect_kra[i]->print(Memo2);
           } break;
    case 6:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_sam.bsort(kol_sam,1,'a'); break;
            case 1: dyn_vect_sam.bsort(kol_sam,2,'a'); break;
            case 2: dyn_vect_sam.bsort(kol_sam,3,'a'); break;
            case 3: dyn_vect_sam.bsort(kol_sam,4,'a'); break;
            case 4: dyn_vect_sam.bsort(kol_sam,5,'i'); break;
            case 5: dyn_vect_sam.bsort(kol_sam,6,'i'); break;
            case 6: dyn_vect_sam.bsort(kol_sam,0,'i'); break;
            case 7: dyn_vect_sam.bsort(kol_sam,7,'i'); break;
            case 8: dyn_vect_sam.bsort(kol_sam,8,'i'); break;
            case 9: dyn_vect_sam.bsort(kol_sam,9,'i'); break;
            case 10: dyn_vect_sam.bsort(kol_sam,10,'i'); break;
            case 11: dyn_vect_sam.bsort(kol_sam,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_sam = *MyStack.Get_data("Samosvali");
            for(int i = 0; i<kol_sam; i++)
             dyn_vect_sam[i]->print(Memo2);
           } break;
   };

 if (RadioGroup1->ItemIndex == 1)
  switch (ListBox2->ItemIndex)
   {
    case 0:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_eks.bsortUb(kol_eks,0,'a'); break;
            case 1: dyn_vect_eks.bsortUb(kol_eks,2,'a'); break;
            case 2: dyn_vect_eks.bsortUb(kol_eks,1,'a'); break;
            case 3: dyn_vect_eks.bsortUb(kol_eks,4,'a'); break;
            case 4: dyn_vect_eks.bsortUb(kol_eks,5,'i'); break;
            case 5: dyn_vect_eks.bsortUb(kol_eks,3,'i'); break;
            case 6: dyn_vect_eks.bsortUb(kol_eks,6,'i'); break;
            case 7: dyn_vect_eks.bsortUb(kol_eks,7,'i'); break;
            case 8: dyn_vect_eks.bsortUb(kol_eks,8,'i'); break;
            case 9: dyn_vect_eks.bsortUb(kol_eks,9,'i'); break;
            case 10: dyn_vect_eks.bsortUb(kol_eks,10,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_eks = *MyStack.Get_data("Ekskavator");
            for(int i = 0; i<kol_eks; i++)
              dyn_vect_eks[i]->print(Memo2);
            } break;
    case 1:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_bul.bsortUb(kol_bul,0,'a'); break;
            case 1: dyn_vect_bul.bsortUb(kol_bul,2,'a'); break;
            case 2: dyn_vect_bul.bsortUb(kol_bul,1,'a'); break;
            case 3: dyn_vect_bul.bsortUb(kol_bul,4,'a'); break;
            case 4: dyn_vect_bul.bsortUb(kol_bul,5,'i'); break;
            case 5: dyn_vect_bul.bsortUb(kol_bul,3,'i'); break;
            case 6: dyn_vect_bul.bsortUb(kol_bul,6,'i'); break;
            case 7: dyn_vect_bul.bsortUb(kol_bul,7,'i'); break;
            case 8: dyn_vect_bul.bsortUb(kol_bul,8,'i'); break;
            case 9: dyn_vect_bul.bsortUb(kol_bul,9,'i'); break;
            case 10: dyn_vect_bul.bsortUb(kol_bul,10,'a'); break;
           };
            Memo2->Clear();
            dyn_vect_bul = *MyStack.Get_data("Buldozer");
            for(int i = 0; i<kol_bul; i++)
             dyn_vect_bul[i]->print(Memo2);
           } break;
    case 2:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_kat.bsortUb(kol_kat,0,'a'); break;
            case 1: dyn_vect_kat.bsortUb(kol_kat,2,'a'); break;
            case 2: dyn_vect_kat.bsortUb(kol_kat,1,'a'); break;
            case 3: dyn_vect_kat.bsortUb(kol_kat,4,'a'); break;
            case 4: dyn_vect_kat.bsortUb(kol_kat,5,'i'); break;
            case 5: dyn_vect_kat.bsortUb(kol_kat,3,'i'); break;
            case 6: dyn_vect_kat.bsortUb(kol_kat,6,'i'); break;
            case 7: dyn_vect_kat.bsortUb(kol_kat,7,'i'); break;
            case 8: dyn_vect_kat.bsortUb(kol_kat,8,'i'); break;
            case 9: dyn_vect_kat.bsortUb(kol_kat,9,'i'); break;
            case 10: dyn_vect_kat.bsortUb(kol_kat,10,'i'); break;
            case 11: dyn_vect_kat.bsortUb(kol_kat,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_kat = *MyStack.Get_data("Katki");
            for(int i = 0; i<kol_kat; i++)
             dyn_vect_kat[i]->print(Memo2);
           } break;
    case 3:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_asp.bsortUb(kol_asp,0,'a'); break;
            case 1: dyn_vect_asp.bsortUb(kol_asp,2,'a'); break;
            case 2: dyn_vect_asp.bsortUb(kol_asp,1,'a'); break;
            case 3: dyn_vect_asp.bsortUb(kol_asp,4,'a'); break;
            case 4: dyn_vect_asp.bsortUb(kol_asp,5,'i'); break;
            case 5: dyn_vect_asp.bsortUb(kol_asp,3,'i'); break;
            case 6: dyn_vect_asp.bsortUb(kol_asp,6,'i'); break;
            case 7: dyn_vect_asp.bsortUb(kol_asp,7,'i'); break;
            case 8: dyn_vect_asp.bsortUb(kol_asp,8,'i'); break;
            case 9: dyn_vect_asp.bsortUb(kol_asp,9,'i'); break;
            case 10: dyn_vect_asp.bsortUb(kol_asp,10,'a'); break;
            case 11: dyn_vect_asp.bsortUb(kol_asp,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_asp = *MyStack.Get_data("Asphalt");
            for(int i = 0; i<kol_asp; i++)
             dyn_vect_asp[i]->print(Memo2);
           } break;
    case 4:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_sme.bsortUb(kol_sme,0,'a'); break;
            case 1: dyn_vect_sme.bsortUb(kol_sme,2,'a'); break;
            case 2: dyn_vect_sme.bsortUb(kol_sme,1,'a'); break;
            case 3: dyn_vect_sme.bsortUb(kol_sme,4,'a'); break;
            case 4: dyn_vect_sme.bsortUb(kol_sme,5,'i'); break;
            case 5: dyn_vect_sme.bsortUb(kol_sme,3,'i'); break;
            case 6: dyn_vect_sme.bsortUb(kol_sme,6,'i'); break;
            case 7: dyn_vect_sme.bsortUb(kol_sme,7,'i'); break;
            case 8: dyn_vect_sme.bsortUb(kol_sme,8,'i'); break;
            case 9: dyn_vect_sme.bsortUb(kol_sme,9,'i'); break;
            case 10: dyn_vect_sme.bsortUb(kol_sme,10,'i'); break;
            case 11: dyn_vect_sme.bsortUb(kol_sme,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_sme = *MyStack.Get_data("Smesiteli");
            for(int i = 0; i<kol_sme; i++)
             dyn_vect_sme[i]->print(Memo2);
           } break;
    case 5:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_kra.bsortUb(kol_kra,0,'a'); break;
            case 1: dyn_vect_kra.bsortUb(kol_kra,2,'a'); break;
            case 2: dyn_vect_kra.bsortUb(kol_kra,1,'a'); break;
            case 3: dyn_vect_kra.bsortUb(kol_kra,4,'a'); break;
            case 4: dyn_vect_kra.bsortUb(kol_kra,5,'i'); break;
            case 5: dyn_vect_kra.bsortUb(kol_kra,3,'i'); break;
            case 6: dyn_vect_kra.bsortUb(kol_kra,6,'i'); break;
            case 7: dyn_vect_kra.bsortUb(kol_kra,7,'i'); break;
            case 8: dyn_vect_kra.bsortUb(kol_kra,8,'i'); break;
            case 9: dyn_vect_kra.bsortUb(kol_kra,9,'i'); break;
            case 10: dyn_vect_kra.bsortUb(kol_kra,10,'i'); break;
            case 11: dyn_vect_kra.bsortUb(kol_kra,11,'i'); break;
            case 12: dyn_vect_kra.bsortUb(kol_kra,12,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_kra = *MyStack.Get_data("Krani");
            for(int i = 0; i<kol_kra; i++)
             dyn_vect_kra[i]->print(Memo2);
           } break;
    case 6:{
           switch (ComboBox2->ItemIndex)
           {
            case 0: dyn_vect_sam.bsortUb(kol_sam,0,'a'); break;
            case 1: dyn_vect_sam.bsortUb(kol_sam,2,'a'); break;
            case 2: dyn_vect_sam.bsortUb(kol_sam,1,'a'); break;
            case 3: dyn_vect_sam.bsortUb(kol_sam,4,'a'); break;
            case 4: dyn_vect_sam.bsortUb(kol_sam,5,'i'); break;
            case 5: dyn_vect_sam.bsortUb(kol_sam,3,'i'); break;
            case 6: dyn_vect_sam.bsortUb(kol_sam,6,'i'); break;
            case 7: dyn_vect_sam.bsortUb(kol_sam,7,'i'); break;
            case 8: dyn_vect_sam.bsortUb(kol_sam,8,'i'); break;
            case 9: dyn_vect_sam.bsortUb(kol_sam,9,'i'); break;
            case 10: dyn_vect_sam.bsortUb(kol_sam,10,'i'); break;
            case 11: dyn_vect_sam.bsortUb(kol_sam,11,'i'); break;
           };
            Memo2->Clear();
            dyn_vect_sam = *MyStack.Get_data("Samosvali");
            for(int i = 0; i<kol_sam; i++)
             dyn_vect_sam[i]->print(Memo2);
           } break;

   };

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
Memo1->Clear();
dyn_vect_eks = *MyStack.Get_data("Ekskavator");
for(int i = 0; i<kol_eks; i++)
 dyn_vect_eks[i]->print(Memo1);

dyn_vect_bul = *MyStack.Get_data("Buldozer");
for(int i = 0; i<kol_bul; i++)
 dyn_vect_bul[i]->print(Memo1);

dyn_vect_kat = *MyStack.Get_data("Katki");
for(int i = 0; i<kol_kat; i++)
 dyn_vect_kat[i]->print(Memo1);

dyn_vect_asp = *MyStack.Get_data("Asphalt");
for(int i = 0; i<kol_asp; i++)
 dyn_vect_asp[i]->print(Memo1);

dyn_vect_sme = *MyStack.Get_data("Smesiteli");
for(int i = 0; i<kol_sme; i++)
 dyn_vect_sme[i]->print(Memo1);

dyn_vect_kra = *MyStack.Get_data("Krani");
for(int i = 0; i<kol_kra; i++)
 dyn_vect_kra[i]->print(Memo1);

dyn_vect_sam = *MyStack.Get_data("Samosvali");
for(int i = 0; i<kol_sam; i++)
 dyn_vect_sam[i]->print(Memo1);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
if (RadioGroup2->ItemIndex == 0)
 if (Edit16->Text == "") ShowMessage("Необходимо ввести значение для поиска!");

  //if (Edit16->Text !="")
  else
   switch (ListBox2->ItemIndex)
    {
     case 0:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,0,'a'); break;
                case 1: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,2,'a'); break;
                case 2: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,1,'a'); break;
                case 3: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,4,'a'); break;
                case 4: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,5,'i'); break;
                case 5: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,3,'i'); break;
                case 6: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,6,'i'); break;
                case 7: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,7,'i'); break;
                case 8: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,8,'i'); break;
                case 9: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,9,'i'); break;
                case 10: dyn_vect_eks.find(Edit16->Text,Memo2,kol_eks,10,'i'); break;
               };
            } break;
     case 1:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,0,'a'); break;
                case 1: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,2,'a'); break;
                case 2: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,1,'a'); break;
                case 3: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,4,'a'); break;
                case 4: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,5,'i'); break;
                case 5: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,3,'i'); break;
                case 6: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,6,'i'); break;
                case 7: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,7,'i'); break;
                case 8: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,8,'i'); break;
                case 9: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,9,'i'); break;
                case 10: dyn_vect_bul.find(Edit16->Text,Memo2,kol_bul,10,'a'); break;

               };
            } break;
     case 2:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,0,'a'); break;
                case 1: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,2,'a'); break;
                case 2: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,1,'a'); break;
                case 3: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,4,'a'); break;
                case 4: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,5,'i'); break;
                case 5: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,3,'i'); break;
                case 6: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,6,'i'); break;
                case 7: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,7,'i'); break;
                case 8: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,8,'i'); break;
                case 9: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,9,'i'); break;
                case 10: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,10,'i'); break;
                case 11: dyn_vect_kat.find(Edit16->Text,Memo2,kol_kat,11,'i'); break;
               };
            } break;
     case 3:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,0,'a'); break;
                case 1: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,2,'a'); break;
                case 2: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,1,'a'); break;
                case 3: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,4,'a'); break;
                case 4: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,5,'i'); break;
                case 5: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,3,'i'); break;
                case 6: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,6,'i'); break;
                case 7: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,7,'i'); break;
                case 8: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,8,'i'); break;
                case 9: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,9,'i'); break;
                case 10: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,10,'a'); break;
                case 11: dyn_vect_asp.find(Edit16->Text,Memo2,kol_asp,11,'i'); break;
               };
            } break;
     case 4:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,0,'a'); break;
                case 1: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,2,'a'); break;
                case 2: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,1,'a'); break;
                case 3: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,4,'a'); break;
                case 4: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,5,'i'); break;
                case 5: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,3,'i'); break;
                case 6: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,6,'i'); break;
                case 7: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,7,'i'); break;
                case 8: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,8,'i'); break;
                case 9: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,9,'i'); break;
                case 10: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,10,'i'); break;
                case 11: dyn_vect_sme.find(Edit16->Text,Memo2,kol_sme,11,'i'); break;
               };
            } break;
      case 5:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,0,'a'); break;
                case 1: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,2,'a'); break;
                case 2: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,1,'a'); break;
                case 3: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,4,'a'); break;
                case 4: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,5,'i'); break;
                case 5: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,3,'i'); break;
                case 6: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,6,'i'); break;
                case 7: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,7,'i'); break;
                case 8: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,8,'i'); break;
                case 9: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,9,'i'); break;
                case 10: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,10,'i'); break;
                case 11: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,11,'i'); break;
                case 12: dyn_vect_kra.find(Edit16->Text,Memo2,kol_kra,12,'i'); break;
               };
            } break;
       case 6:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,0,'a'); break;
                case 1: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,2,'a'); break;
                case 2: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,1,'a'); break;
                case 3: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,4,'a'); break;
                case 4: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,5,'i'); break;
                case 5: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,3,'i'); break;
                case 6: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,6,'i'); break;
                case 7: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,7,'i'); break;
                case 8: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,8,'i'); break;
                case 9: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,9,'i'); break;
                case 10: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,10,'i'); break;
                case 11: dyn_vect_sam.find(Edit16->Text,Memo2,kol_sam,11,'i'); break;               };
            } break;
        };

if (RadioGroup2->ItemIndex == 1)
 if ((Edit17->Text == "")||(Edit18->Text == "")) ShowMessage("Необходимо ввести все значения для поиска!");
   //if ((Edit17->Text != "")&&(Edit18->Text != ""))
   else
   switch (ListBox2->ItemIndex)
    {
     case 0:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,0,'a'); break;
                case 1: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,2,'a'); break;
                case 2: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,1,'a'); break;
                case 3: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,4,'a'); break;
                case 4: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,5,'i'); break;
                case 5: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,3,'i'); break;
                case 6: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,6,'i'); break;
                case 7: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,7,'i'); break;
                case 8: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,8,'i'); break;
                case 9: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,9,'i'); break;
                case 10: dyn_vect_eks.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_eks,10,'i'); break;
              };
            } break;
     case 1:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,0,'a'); break;
                case 1: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,2,'a'); break;
                case 2: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,1,'a'); break;
                case 3: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,4,'a'); break;
                case 4: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,5,'i'); break;
                case 5: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,3,'i'); break;
                case 6: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,6,'i'); break;
                case 7: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,7,'i'); break;
                case 8: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,8,'i'); break;
                case 9: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,9,'i'); break;
                case 10: dyn_vect_bul.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_bul,10,'a'); break;
               };
            } break;
     case 2:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,0,'a'); break;
                case 1: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,2,'a'); break;
                case 2: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,1,'a'); break;
                case 3: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,4,'a'); break;
                case 4: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,5,'i'); break;
                case 5: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,3,'i'); break;
                case 6: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,6,'i'); break;
                case 7: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,7,'i'); break;
                case 8: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,8,'i'); break;
                case 9: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,9,'i'); break;
                case 10: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,10,'i'); break;
                case 11: dyn_vect_kat.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kat,11,'i'); break;
               };
            } break;
     case 3:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,0,'a'); break;
                case 1: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,2,'a'); break;
                case 2: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,1,'a'); break;
                case 3: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,4,'a'); break;
                case 4: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,5,'i'); break;
                case 5: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,3,'i'); break;
                case 6: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,6,'i'); break;
                case 7: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,7,'i'); break;
                case 8: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,8,'i'); break;
                case 9: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,9,'i'); break;
                case 10: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,10,'a'); break;
                case 11: dyn_vect_asp.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_asp,11,'i'); break;
               };
            } break;
     case 4:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,0,'a'); break;
                case 1: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,2,'a'); break;
                case 2: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,1,'a'); break;
                case 3: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,4,'a'); break;
                case 4: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,5,'i'); break;
                case 5: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,3,'i'); break;
                case 6: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,6,'i'); break;
                case 7: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,7,'i'); break;
                case 8: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,8,'i'); break;
                case 9: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,9,'i'); break;
                case 10: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,10,'i'); break;
                case 11: dyn_vect_sme.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sme,11,'i'); break;
               };
            } break;
     case 5:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,0,'a'); break;
                case 1: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,2,'a'); break;
                case 2: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,1,'a'); break;
                case 3: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,4,'a'); break;
                case 4: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,5,'i'); break;
                case 5: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,3,'i'); break;
                case 6: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,6,'i'); break;
                case 7: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,7,'i'); break;
                case 8: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,8,'i'); break;
                case 9: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,9,'i'); break;
                case 10: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,10,'i'); break;
                case 11: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,11,'i'); break;
                case 12: dyn_vect_kra.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_kra,12,'i'); break;
               };
            } break;
     case 6:{
              switch (ComboBox2->ItemIndex)
               {
                case 0: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,0,'a'); break;
                case 1: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,2,'a'); break;
                case 2: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,1,'a'); break;
                case 3: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,4,'a'); break;
                case 4: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,5,'i'); break;
                case 5: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,3,'i'); break;
                case 6: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,6,'i'); break;
                case 7: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,7,'i'); break;
                case 8: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,8,'i'); break;
                case 9: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,9,'i'); break;
                case 10: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,10,'i'); break;
                case 11: dyn_vect_sam.find_Diap(Edit17->Text, Edit18->Text,Memo2,kol_sam,11,'i'); break;
               };
            } break;
  };
}
//---------------------------------------------------------------------------

void write_file()
{
//----сохранение в файла-------
 outfile.open(path);

dyn_vect_eks = *MyStack.Get_data("Ekskavator");
for(int i = 0; i<kol_eks; i++)
 dyn_vect_eks[i]->Write_to_file();

dyn_vect_bul = *MyStack.Get_data("Buldozer");
for(int i = 0; i<kol_bul; i++)
 dyn_vect_bul[i]->Write_to_file();

dyn_vect_kat = *MyStack.Get_data("Katki");
for(int i = 0; i<kol_kat; i++)
 dyn_vect_kat[i]->Write_to_file();

dyn_vect_asp = *MyStack.Get_data("Asphalt");
for(int i = 0; i<kol_asp; i++)
 dyn_vect_asp[i]->Write_to_file();

dyn_vect_sme = *MyStack.Get_data("Smesiteli");
for(int i = 0; i<kol_sme; i++)
 dyn_vect_sme[i]->Write_to_file();

dyn_vect_kra = *MyStack.Get_data("Krani");
for(int i = 0; i<kol_kra; i++)
 dyn_vect_kra[i]->Write_to_file();

dyn_vect_sam = *MyStack.Get_data("Samosvali");
for(int i = 0; i<kol_sam; i++)
 dyn_vect_sam[i]->Write_to_file();


 outfile.close();

 ofstream outfile1("C:\\fdat.dat");
 outfile1
  <<kol_eks<<' '
  <<kol_bul<<' '
  <<kol_kat<<' '
  <<kol_asp<<' '
  <<kol_sme<<' '
  <<kol_kra<<' '
  <<kol_sam<<' ';
}

void read_file()
{
try
{
//----загрузка из файла-------
 ifstream infile1("C:\\fdat.dat");
 infile1
  >>kol_eks
  >>kol_bul
  >>kol_kat
  >>kol_asp
  >>kol_sme
  >>kol_kra
  >>kol_sam;

 infile.open(path);
 infile.seekg(0);

 Stack<dyn_vect*> MyStack1;

 for(int i = 0; i<kol_eks; i++)
   {
    Ekskavator* eks_obj = new Ekskavator;
    eks_obj->Read_from_file();
    dyn_vect_eks.Set_one(eks_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_eks,"Ekskavator");

 for(int i = 0; i<kol_bul; i++)
   {
    Buldozer* bul_obj = new Buldozer;
    bul_obj->Read_from_file();
    dyn_vect_bul.Set_one(bul_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_bul,"Buldozer");

 for(int i = 0; i<kol_kat; i++)
   {
    Katki* kat_obj = new Katki;
    kat_obj->Read_from_file();
    dyn_vect_kat.Set_one(kat_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_kat,"Katki");

 for(int i = 0; i<kol_asp; i++)
   {
    Asphalt* asp_obj = new Asphalt;
    asp_obj->Read_from_file();
    dyn_vect_asp.Set_one(asp_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_asp,"Asphalt");

 for(int i = 0; i<kol_sme; i++)
   {
    Smesiteli* sme_obj = new Smesiteli;
    sme_obj->Read_from_file();
    dyn_vect_sme.Set_one(sme_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_sme,"Smesiteli");

 for(int i = 0; i<kol_kra; i++)
   {
    Krani* kra_obj = new Krani;
    kra_obj->Read_from_file();
    dyn_vect_kra.Set_one(kra_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_kra,"Krani");

  for(int i = 0; i<kol_sam; i++)
   {
    Samosvali* sam_obj = new Samosvali;
    sam_obj->Read_from_file();
    dyn_vect_sam.Set_one(sam_obj,i);
   }

 MyStack1.Add_elem_head(&dyn_vect_sam,"Samosvali");


 infile.close();
 MyStack = MyStack1;
}catch(...)
{Application->MessageBox("Файл содержит неправильные значения!","Ошибка!",MB_ICONHAND+MB_OK);}
}

void __fastcall TForm1::Button9Click(TObject *Sender)
{
 if(SaveDialog1->Execute())
  {
   pathAS = SaveDialog1->FileName;
   path = pathAS.c_str();
   write_file();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
 if(OpenDialog1->Execute())
  {
   pathAS = OpenDialog1->FileName;
   path = pathAS.c_str();
   read_file();
  }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::RadioGroup2Click(TObject *Sender)
{
switch (RadioGroup2->ItemIndex)
 {
  case 0: {Panel2->Visible=true; Panel1->Visible=false;}break;
  case 1: {Panel2->Visible=false; Panel1->Visible=true;}break;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
 Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
 Form1->Button10->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
 Form1->Button9->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
 kol_eks = 0;
 kol_bul = 0;
 kol_kat = 0;
 kol_asp = 0;
 kol_sme = 0;
 kol_kra = 0;
 kol_sam = 0;
 Memo1->Clear();
 Memo2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
 ListBox1->ItemIndex=0;
 Form1->ListBox1Click(N8);
 PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
 ListBox1->ItemIndex=1;
 Form1->ListBox1Click(N9);
 PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
 ListBox1->ItemIndex=2;
 Form1->ListBox1Click(N10);
 PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
 ListBox1->ItemIndex=3;
 Form1->ListBox1Click(N11);
 PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
 ListBox1->ItemIndex=4;
 Form1->ListBox1Click(N12);
 PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
 PageControl1->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
 PageControl1->ActivePageIndex = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N17Click(TObject *Sender)
{
 PageControl1->ActivePageIndex = 1;
 Button8->Click();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//--------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "")&&(Edit21->Text != "")&&
      (Edit22->Text != "") &&
      (Edit32->Text != "") && (Edit33->Text != "") &&
      (Edit34->Text != ""))
       {
        Smesiteli* ob1=new Smesiteli(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),StrToInt(Edit32->Text),
                                        StrToInt(Edit33->Text),StrToInt(Edit34->Text));
        dyn_vect_sme.Set_one(ob1,kol_sme);
        MyStack.Set_data(&dyn_vect_sme,"Smesiteli");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
        kol_sme++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 try
  {
   if ((Edit1->Text     != "")&&(Edit2->Text != "")&&(Edit3->Text != "")&&
      (Edit4->Text != "")&&(Edit5->Text     != "")&&
      (Edit19->Text != "")&&
      (Edit20->Text     != "") && (Edit21->Text != "")&&
      (Edit22->Text != "") && (Edit35->Text != "")
      &&(Edit36->Text != "") && (Edit37->Text != ""))
       {
        Samosvali* ob1=new Samosvali(Edit1->Text,Edit2->Text,Edit3->Text,
                             Edit4->Text,
                             StrToInt(Edit19->Text),
                             StrToInt(Edit20->Text),StrToInt(Edit21->Text),
                             StrToInt(Edit5->Text),
                             StrToInt(Edit22->Text),StrToInt(Edit35->Text),
                                        StrToInt(Edit36->Text),StrToInt(Edit37->Text));
        dyn_vect_sam.Set_one(ob1,kol_sam);
        MyStack.Set_data(&dyn_vect_sam,"Samosvali");
        Application->MessageBox("Добавление успешно.","Добавление",MB_OK);
        kol_sam++;
       } else Application->MessageBox("Необходимо заполнить все поля!","Ошибка ввода",MB_ICONHAND+MB_OK);
  }
  catch(EConvertError&)
   {Application->MessageBox("Проверьте правльность ввода данных!","Ошибка типов",MB_ICONHAND+MB_OK);}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

