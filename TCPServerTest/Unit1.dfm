object TCP_Server: TTCP_Server
  Left = 0
  Top = 0
  Caption = 'TCP_Server'
  ClientHeight = 678
  ClientWidth = 728
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Port: TLabel
    Left = 24
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object LMessage: TListBox
    Left = 24
    Top = 398
    Width = 673
    Height = 169
    ItemHeight = 13
    TabOrder = 0
  end
  object EMassage: TEdit
    Left = 24
    Top = 583
    Width = 497
    Height = 21
    TabOrder = 1
  end
  object ESend: TButton
    Left = 118
    Top = 25
    Width = 75
    Height = 25
    Caption = #38283#22987
    TabOrder = 2
    OnClick = ESendClick
  end
  object EPort: TEdit
    Left = 24
    Top = 27
    Width = 73
    Height = 21
    TabOrder = 3
    Text = '5000'
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 72
    Width = 673
    Height = 297
    ColCount = 10
    RowCount = 1
    FixedRows = 0
    TabOrder = 4
  end
  object ChatClient: TIdTCPClient
    ConnectTimeout = 0
    IPVersion = Id_IPv4
    Port = 12000
    ReadTimeout = -1
    Left = 512
    Top = 24
  end
  object ChatServer: TIdTCPServer
    Bindings = <>
    DefaultPort = 12000
    OnExecute = ChatServerExcute
    Left = 576
    Top = 24
  end
end
