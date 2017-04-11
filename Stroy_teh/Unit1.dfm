object Form1: TForm1
  Left = 234
  Top = 174
  Width = 701
  Height = 673
  Caption = #1048#1077#1088#1072#1088#1093#1080#1103' '#1089#1090#1088#1086#1080#1090#1077#1083#1100#1085#1099#1093' '#1084#1072#1096#1080#1085
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1001
    Height = 689
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1076#1072#1085#1085#1099#1093
      ParentShowHint = False
      ShowHint = False
      object Label27: TLabel
        Left = 528
        Top = 16
        Width = 104
        Height = 13
        Caption = #1050#1083#1072#1089#1089' '#1089#1090#1088#1086#1080#1090#1077#1083#1100#1085#1086#1081
      end
      object Label28: TLabel
        Left = 528
        Top = 32
        Width = 43
        Height = 13
        Caption = #1090#1077#1093#1085#1080#1082#1080':'
      end
      object ListBox1: TListBox
        Left = 520
        Top = 48
        Width = 129
        Height = 113
        ItemHeight = 13
        Items.Strings = (
          #1069#1082#1089#1082#1072#1074#1072#1090#1086#1088#1099
          #1041#1091#1083#1100#1076#1086#1079#1077#1088#1099
          #1050#1072#1090#1082#1080
          #1040#1089#1092#1072#1083#1100#1090#1086#1091#1082#1083#1072#1076#1095#1080#1082#1080
          #1040#1074#1090#1086#1073#1077#1090#1086#1085#1086#1089#1084#1077#1089#1080#1090#1077#1083#1080
          #1050#1088#1072#1085#1099
          #1057#1072#1084#1086#1089#1074#1072#1083#1099)
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object GroupBox7: TGroupBox
        Left = 152
        Top = 263
        Width = 345
        Height = 186
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103':'
        TabOrder = 1
        Visible = False
        object Label12: TLabel
          Left = 8
          Top = 24
          Width = 94
          Height = 13
          Caption = #1064#1080#1088#1080#1085#1072' '#1074#1072#1083#1072' ('#1084#1084'):'
          WordWrap = True
        end
        object Label15: TLabel
          Left = 144
          Top = 24
          Width = 101
          Height = 13
          Caption = #1044#1080#1072#1084#1077#1090#1088' '#1074#1072#1083#1072' ('#1084#1084'):'
          WordWrap = True
        end
        object Label35: TLabel
          Left = 8
          Top = 88
          Width = 94
          Height = 13
          Caption = #1064#1080#1088#1080#1085#1072' '#1074#1072#1083#1072' ('#1084#1084'):'
          WordWrap = True
        end
        object Edit14: TEdit
          Left = 8
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object Button4: TButton
          Left = 136
          Top = 144
          Width = 75
          Height = 25
          Caption = #1054#1050
          TabOrder = 1
          OnClick = Button4Click
        end
        object Edit28: TEdit
          Left = 144
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 2
        end
        object Edit29: TEdit
          Left = 8
          Top = 112
          Width = 121
          Height = 21
          TabOrder = 3
        end
      end
      object GroupBox8: TGroupBox
        Left = 144
        Top = 296
        Width = 345
        Height = 185
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103
        TabOrder = 2
        Visible = False
        object Label11: TLabel
          Left = 8
          Top = 32
          Width = 131
          Height = 13
          Caption = #1058#1080#1087' '#1093#1086#1076#1086#1074#1086#1075#1086' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072':'
        end
        object Label37: TLabel
          Left = 184
          Top = 24
          Width = 108
          Height = 13
          Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
        end
        object Label38: TLabel
          Left = 184
          Top = 40
          Width = 98
          Height = 13
          Caption = #1073#1091#1085#1082#1077#1088#1072' ('#1090#1086#1085#1085'/'#1095#1072#1089'):'
        end
        object Label39: TLabel
          Left = 8
          Top = 88
          Width = 139
          Height = 13
          Caption = #1042#1084#1077#1089#1090#1080#1084#1086#1089#1090#1100' '#1073#1091#1085#1082#1077#1088#1072' ('#1084'3):'
        end
        object Edit15: TEdit
          Left = 8
          Top = 104
          Width = 129
          Height = 21
          TabOrder = 0
        end
        object Button5: TButton
          Left = 136
          Top = 136
          Width = 75
          Height = 25
          Caption = 'OK'
          TabOrder = 1
          OnClick = Button5Click
        end
        object Edit30: TEdit
          Left = 184
          Top = 56
          Width = 121
          Height = 21
          TabOrder = 2
        end
        object Edit31: TEdit
          Left = 8
          Top = 56
          Width = 129
          Height = 21
          TabOrder = 3
        end
      end
      object GroupBox4: TGroupBox
        Left = 103
        Top = 279
        Width = 346
        Height = 226
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103':'
        TabOrder = 3
        Visible = False
        object Label16: TLabel
          Left = 8
          Top = 24
          Width = 53
          Height = 13
          Caption = #1050#1086#1074#1096' ('#1084'3):'
        end
        object Label33: TLabel
          Left = 168
          Top = 24
          Width = 106
          Height = 13
          Caption = #1043#1083#1091#1073#1080#1085#1072' '#1082#1086#1087#1072#1085#1080#1103' ('#1084'):'
        end
        object Button1: TButton
          Left = 118
          Top = 112
          Width = 75
          Height = 25
          Caption = #1054#1050
          TabOrder = 0
          OnClick = Button1Click
        end
        object Edit10: TEdit
          Left = 8
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 1
        end
        object Edit26: TEdit
          Left = 168
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 2
        end
      end
      object GroupBox5: TGroupBox
        Left = 104
        Top = 368
        Width = 345
        Height = 169
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103
        TabOrder = 4
        Visible = False
        object Label14: TLabel
          Left = 16
          Top = 32
          Width = 60
          Height = 13
          Caption = #1058#1080#1087' '#1086#1090#1074#1072#1083#1072':'
        end
        object Label34: TLabel
          Left = 184
          Top = 32
          Width = 99
          Height = 13
          Caption = #1054#1073#1098#1077#1084' '#1086#1090#1074#1072#1083#1072' ('#1084'3):'
        end
        object Edit12: TEdit
          Left = 16
          Top = 56
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object Button2: TButton
          Left = 128
          Top = 120
          Width = 75
          Height = 25
          Caption = #1054#1050
          TabOrder = 1
          OnClick = Button2Click
        end
        object Edit27: TEdit
          Left = 184
          Top = 56
          Width = 121
          Height = 21
          TabOrder = 2
        end
      end
      object GroupBox6: TGroupBox
        Left = 103
        Top = 304
        Width = 346
        Height = 249
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103':'
        TabOrder = 5
        Visible = False
        object Label13: TLabel
          Left = 16
          Top = 32
          Width = 114
          Height = 13
          Caption = #1043#1088#1091#1079#1086#1087#1086#1076#1098#1077#1084#1085#1086#1089#1090#1100' ('#1090'):'
        end
        object Label6: TLabel
          Left = 184
          Top = 32
          Width = 142
          Height = 13
          Caption = #1044#1083#1080#1085#1072' '#1075#1088#1091#1079#1086#1074#1086#1081' '#1089#1090#1088#1077#1083#1099' ('#1084'):'
        end
        object Label29: TLabel
          Left = 16
          Top = 96
          Width = 116
          Height = 13
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1081' '#1074#1099#1083#1077#1090' '
        end
        object Label30: TLabel
          Left = 16
          Top = 112
          Width = 57
          Height = 13
          Caption = #1089#1090#1088#1077#1083#1099' ('#1084'):'
        end
        object Label31: TLabel
          Left = 176
          Top = 96
          Width = 120
          Height = 13
          Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1072#1103' '#1074#1099#1089#1086#1090#1072':'
        end
        object Label32: TLabel
          Left = 176
          Top = 112
          Width = 105
          Height = 13
          Caption = #1087#1086#1076#1098#1077#1084#1072' '#1089#1090#1088#1077#1083#1099' ('#1084'):'
        end
        object Button3: TButton
          Left = 128
          Top = 200
          Width = 83
          Height = 25
          Caption = #1054#1050
          TabOrder = 0
          OnClick = Button3Click
        end
        object Edit13: TEdit
          Left = 16
          Top = 56
          Width = 121
          Height = 21
          TabOrder = 1
        end
        object Edit24: TEdit
          Left = 184
          Top = 56
          Width = 137
          Height = 21
          TabOrder = 2
        end
        object Edit23: TEdit
          Left = 16
          Top = 136
          Width = 121
          Height = 21
          TabOrder = 3
        end
        object Edit25: TEdit
          Left = 176
          Top = 136
          Width = 145
          Height = 21
          TabOrder = 4
        end
      end
      object GroupBox1: TGroupBox
        Left = 152
        Top = 8
        Width = 345
        Height = 257
        Caption = #1054#1073#1097#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103' '#1086' '#1090#1077#1093#1085#1080#1082#1077':'
        TabOrder = 6
        object Label1: TLabel
          Left = 16
          Top = 24
          Width = 42
          Height = 13
          Caption = #1052#1086#1076#1077#1083#1100':'
        end
        object Label2: TLabel
          Left = 16
          Top = 104
          Width = 119
          Height = 13
          Caption = #1057#1090#1088#1072#1085#1072' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
        end
        object Label3: TLabel
          Left = 16
          Top = 64
          Width = 36
          Height = 13
          Caption = #1052#1072#1088#1082#1072':'
        end
        object Label4: TLabel
          Left = 16
          Top = 144
          Width = 92
          Height = 13
          Caption = #1058#1080#1087' '#1090#1088#1072#1085#1089#1084#1080#1089#1089#1080#1080':'
        end
        object Label5: TLabel
          Left = 184
          Top = 144
          Width = 138
          Height = 13
          Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1076#1074#1080#1075#1072#1090#1077#1083#1103' ('#1083'.'#1089'.):'
        end
        object Label22: TLabel
          Left = 184
          Top = 24
          Width = 61
          Height = 13
          Caption = #1044#1083#1080#1085#1072' ('#1084#1084'):'
        end
        object Label23: TLabel
          Left = 184
          Top = 64
          Width = 67
          Height = 13
          Caption = #1064#1080#1088#1080#1085#1072' ('#1084#1084'):'
        end
        object Label25: TLabel
          Left = 184
          Top = 104
          Width = 66
          Height = 13
          Caption = #1042#1099#1089#1086#1090#1072' ('#1084#1084'):'
        end
        object Label26: TLabel
          Left = 184
          Top = 192
          Width = 50
          Height = 13
          Caption = #1052#1072#1089#1089#1072' ('#1090'):'
        end
        object Edit1: TEdit
          Left = 16
          Top = 40
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object Edit2: TEdit
          Left = 16
          Top = 80
          Width = 121
          Height = 21
          TabOrder = 1
        end
        object Edit3: TEdit
          Left = 16
          Top = 120
          Width = 121
          Height = 21
          TabOrder = 2
        end
        object Edit4: TEdit
          Left = 16
          Top = 160
          Width = 121
          Height = 21
          TabOrder = 3
        end
        object Edit5: TEdit
          Left = 184
          Top = 160
          Width = 121
          Height = 21
          TabOrder = 4
        end
        object Edit19: TEdit
          Left = 184
          Top = 40
          Width = 121
          Height = 21
          TabOrder = 5
        end
        object Edit20: TEdit
          Left = 184
          Top = 80
          Width = 121
          Height = 21
          TabOrder = 6
        end
        object Edit21: TEdit
          Left = 184
          Top = 120
          Width = 121
          Height = 21
          TabOrder = 7
        end
        object Edit22: TEdit
          Left = 184
          Top = 208
          Width = 121
          Height = 21
          TabOrder = 8
        end
      end
      object Button9: TButton
        Left = 520
        Top = 188
        Width = 129
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
        TabOrder = 7
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 520
        Top = 236
        Width = 129
        Height = 25
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1072#1081#1083
        TabOrder = 8
        OnClick = Button10Click
      end
      object GroupBox11: TGroupBox
        Left = 255
        Top = 328
        Width = 346
        Height = 249
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103':'
        TabOrder = 9
        Visible = False
        object Label40: TLabel
          Left = 16
          Top = 32
          Width = 150
          Height = 13
          Caption = #1042#1084#1077#1089#1090#1080#1084#1086#1089#1090#1100' '#1089#1084#1077#1089#1080#1090#1077#1083#1100#1085#1086#1075#1086
        end
        object Label41: TLabel
          Left = 184
          Top = 32
          Width = 96
          Height = 13
          Caption = #1063#1072#1089#1090#1086#1090#1072' '#1074#1088#1072#1097#1077#1085#1080#1103
        end
        object Label42: TLabel
          Left = 16
          Top = 96
          Width = 85
          Height = 13
          Caption = #1054#1073#1098#1077#1084' '#1074#1086#1076#1103#1085#1086#1075#1086
        end
        object Label43: TLabel
          Left = 16
          Top = 112
          Width = 50
          Height = 13
          Caption = #1073#1072#1082#1072' ('#1084'3):'
        end
        object Label46: TLabel
          Left = 16
          Top = 48
          Width = 51
          Height = 13
          Caption = #1073#1072#1088#1072#1073#1072#1085#1072':'
        end
        object Label47: TLabel
          Left = 184
          Top = 48
          Width = 74
          Height = 13
          Caption = #1073#1072#1088#1072#1073#1072#1085#1072' ('#1043#1062'):'
        end
        object Edit32: TEdit
          Left = 16
          Top = 64
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object Edit33: TEdit
          Left = 184
          Top = 64
          Width = 137
          Height = 21
          TabOrder = 1
        end
        object Edit34: TEdit
          Left = 16
          Top = 136
          Width = 121
          Height = 21
          TabOrder = 2
        end
        object Button11: TButton
          Left = 152
          Top = 200
          Width = 89
          Height = 25
          Caption = 'OK'
          TabOrder = 3
          OnClick = Button11Click
        end
      end
      object GroupBox12: TGroupBox
        Left = 175
        Top = 272
        Width = 346
        Height = 249
        Caption = #1044#1088#1091#1075#1080#1077' '#1089#1074#1077#1076#1077#1085#1080#1103':'
        TabOrder = 10
        Visible = False
        object Label44: TLabel
          Left = 16
          Top = 32
          Width = 115
          Height = 13
          Caption = #1054#1073#1098#1077#1084' '#1089#1072#1084#1086#1089#1074#1072#1083#1100#1085#1086#1081' '
        end
        object Label45: TLabel
          Left = 184
          Top = 40
          Width = 114
          Height = 13
          Caption = #1043#1088#1091#1079#1086#1087#1086#1076#1098#1077#1084#1085#1086#1089#1090#1100' ('#1090'):'
        end
        object Label48: TLabel
          Left = 16
          Top = 96
          Width = 108
          Height = 13
          Caption = #1059#1075#1086#1083' '#1086#1087#1088#1086#1082#1080#1076#1099#1074#1072#1085#1080#1103
        end
        object Label49: TLabel
          Left = 16
          Top = 112
          Width = 94
          Height = 13
          Caption = #1087#1083#1072#1090#1092#1086#1088#1084#1099' ('#1075#1088#1072#1076'):'
        end
        object Label50: TLabel
          Left = 16
          Top = 48
          Width = 85
          Height = 13
          Caption = #1087#1083#1072#1090#1092#1086#1088#1084#1099' ('#1084'3):'
        end
        object Edit35: TEdit
          Left = 16
          Top = 64
          Width = 121
          Height = 21
          TabOrder = 0
        end
        object Edit36: TEdit
          Left = 184
          Top = 64
          Width = 137
          Height = 21
          TabOrder = 1
        end
        object Edit37: TEdit
          Left = 16
          Top = 136
          Width = 121
          Height = 21
          TabOrder = 2
        end
        object Button12: TButton
          Left = 136
          Top = 192
          Width = 81
          Height = 25
          Caption = 'OK'
          TabOrder = 3
          OnClick = Button12Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1076#1072#1085#1085#1099#1093
      ImageIndex = 1
      object Memo1: TMemo
        Left = 144
        Top = 8
        Width = 449
        Height = 425
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Button8: TButton
        Left = 312
        Top = 464
        Width = 75
        Height = 25
        Caption = #1042#1099#1074#1086#1076
        TabOrder = 1
        OnClick = Button8Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072' '#1076#1072#1085#1085#1099#1093
      ImageIndex = 2
      object Label7: TLabel
        Left = 8
        Top = 208
        Width = 144
        Height = 13
        Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1072#1088#1072#1084#1077#1090#1088' '#1087#1086#1080#1089#1082#1072':'
      end
      object GroupBox9: TGroupBox
        Left = -72
        Top = 564
        Width = 193
        Height = 109
        Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
        TabOrder = 0
        object RadioGroup1: TRadioGroup
          Left = 8
          Top = 16
          Width = 169
          Height = 49
          Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
          ItemIndex = 0
          Items.Strings = (
            #1087#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
            #1087#1086' '#1091#1073#1099#1074#1072#1085#1080#1102)
          TabOrder = 0
        end
        object Button6: TButton
          Left = 104
          Top = 72
          Width = 75
          Height = 25
          Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
          TabOrder = 1
          OnClick = Button6Click
        end
      end
      object ListBox2: TListBox
        Left = 8
        Top = 40
        Width = 145
        Height = 153
        ItemHeight = 13
        Items.Strings = (
          #1069#1082#1089#1082#1072#1074#1072#1090#1086#1088#1099
          #1041#1091#1083#1100#1076#1086#1079#1077#1088#1099
          #1050#1072#1090#1082#1080
          #1040#1089#1092#1072#1083#1100#1090#1086#1091#1082#1083#1072#1076#1095#1080#1082#1080
          #1040#1074#1090#1086#1073#1077#1090#1086#1085#1086#1089#1084#1077#1089#1080#1090#1077#1083#1080
          #1050#1088#1072#1085#1099
          #1057#1072#1084#1086#1089#1074#1072#1083#1099)
        TabOrder = 1
        OnClick = ListBox2Click
      end
      object ComboBox2: TComboBox
        Left = 8
        Top = 232
        Width = 129
        Height = 21
        ItemHeight = 13
        TabOrder = 2
      end
      object GroupBox10: TGroupBox
        Left = 8
        Top = 264
        Width = 193
        Height = 161
        Caption = #1055#1086#1080#1089#1082
        TabOrder = 3
        object Panel1: TPanel
          Left = 8
          Top = 72
          Width = 177
          Height = 41
          TabOrder = 2
          Visible = False
          object Label19: TLabel
            Left = 8
            Top = 16
            Width = 11
            Height = 13
            Caption = #1086#1090
          end
          object Label20: TLabel
            Left = 88
            Top = 16
            Width = 12
            Height = 13
            Caption = #1076#1086
          end
          object Edit17: TEdit
            Left = 24
            Top = 12
            Width = 49
            Height = 21
            TabOrder = 0
          end
          object Edit18: TEdit
            Left = 112
            Top = 12
            Width = 41
            Height = 21
            TabOrder = 1
          end
        end
        object Panel2: TPanel
          Left = 8
          Top = 72
          Width = 177
          Height = 49
          TabOrder = 3
          object Label21: TLabel
            Left = 8
            Top = 8
            Width = 48
            Height = 13
            Caption = #1047#1085#1072#1095#1077#1085#1080#1077
          end
          object Edit16: TEdit
            Left = 8
            Top = 20
            Width = 121
            Height = 21
            TabOrder = 0
          end
        end
        object RadioGroup2: TRadioGroup
          Left = 8
          Top = 16
          Width = 177
          Height = 57
          Caption = #1057#1087#1086#1089#1086#1073' '#1087#1086#1080#1089#1082#1072
          ItemIndex = 0
          Items.Strings = (
            #1090#1086#1095#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
            #1076#1080#1072#1087#1072#1079#1086#1085)
          TabOrder = 0
          OnClick = RadioGroup2Click
        end
        object Button7: TButton
          Left = 110
          Top = 128
          Width = 75
          Height = 25
          Caption = #1053#1072#1081#1090#1080
          TabOrder = 1
          OnClick = Button7Click
        end
      end
      object Memo2: TMemo
        Left = 216
        Top = 24
        Width = 409
        Height = 481
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 4
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 376
  end
  object SaveDialog1: TSaveDialog
    Left = 352
  end
  object MainMenu1: TMainMenu
    Left = 400
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object N5: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N5Click
      end
    end
    object N6: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N7: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        object N8: TMenuItem
          Caption = #1069#1082#1089#1082#1072#1074#1072#1090#1086#1088
          OnClick = N8Click
        end
        object N9: TMenuItem
          Caption = #1041#1091#1083#1100#1076#1086#1079#1077#1088#1099
          OnClick = N9Click
        end
        object N10: TMenuItem
          Caption = #1050#1072#1090#1082#1080
          OnClick = N10Click
        end
        object N11: TMenuItem
          Caption = #1040#1089#1092#1072#1083#1100#1090#1086#1091#1082#1083#1072#1076#1095#1080#1082#1080
          OnClick = N11Click
        end
        object N12: TMenuItem
          Caption = #1040#1074#1090#1086#1073#1077#1090#1086#1085#1086#1089#1084#1077#1089#1080#1090#1077#1083#1080
          OnClick = N12Click
        end
        object N18: TMenuItem
          Caption = #1050#1088#1072#1085#1099
        end
        object N19: TMenuItem
          Caption = #1057#1072#1084#1086#1089#1074#1072#1083#1099
        end
      end
      object N13: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077
        OnClick = N13Click
      end
    end
    object N14: TMenuItem
      Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072
      object N15: TMenuItem
        Caption = #1055#1086#1080#1089#1082
        OnClick = N15Click
      end
      object N16: TMenuItem
        Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
        OnClick = N16Click
      end
      object N17: TMenuItem
        Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1076#1072#1085#1085#1099#1093
        OnClick = N17Click
      end
    end
    object N20: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
    end
  end
end
