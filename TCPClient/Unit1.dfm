object TCP_Client: TTCP_Client
  Left = 0
  Top = 0
  Caption = 'TCP_Client'
  ClientHeight = 362
  ClientWidth = 639
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 22
    Height = 13
    Caption = 'Host'
  end
  object Label2: TLabel
    Left = 160
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object Label3: TLabel
    Left = 24
    Top = 73
    Width = 58
    Height = 13
    Caption = 'Host name :'
  end
  object EHost: TEdit
    Left = 24
    Top = 27
    Width = 113
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object LMessage: TListBox
    Left = 24
    Top = 144
    Width = 561
    Height = 113
    ItemHeight = 13
    TabOrder = 1
  end
  object EMassage: TEdit
    Left = 24
    Top = 273
    Width = 497
    Height = 21
    TabOrder = 2
  end
  object ESend: TButton
    Left = 527
    Top = 271
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 3
    OnClick = ESendClick
  end
  object EPort: TEdit
    Left = 160
    Top = 27
    Width = 57
    Height = 21
    TabOrder = 4
    Text = '5000'
  end
  object EConnect: TButton
    Left = 272
    Top = 24
    Width = 75
    Height = 25
    Caption = #25509#32154#38283#22987
    TabOrder = 5
    OnClick = EConnectClick
  end
  object Edit1: TEdit
    Left = 88
    Top = 70
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 343
    Width = 639
    Height = 19
    Panels = <>
  end
  object ChatClient: TIdTCPClient
    ConnectTimeout = 0
    IPVersion = Id_IPv4
    Port = 12000
    ReadTimeout = -1
    Left = 408
    Top = 24
  end
  object ADODataSet1: TADODataSet
    Parameters = <>
    Left = 496
    Top = 24
  end
end
