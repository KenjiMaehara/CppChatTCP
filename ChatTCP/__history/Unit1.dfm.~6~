object TCPServer: TTCPServer
  Left = 0
  Top = 0
  Caption = 'TCPServer'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 22
    Height = 13
    Caption = 'Host'
  end
  object EHost: TEdit
    Left = 24
    Top = 27
    Width = 329
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object LMessage: TListBox
    Left = 24
    Top = 80
    Width = 585
    Height = 169
    ItemHeight = 13
    TabOrder = 1
  end
  object EMassage: TEdit
    Left = 24
    Top = 255
    Width = 497
    Height = 21
    TabOrder = 2
  end
  object ESend: TButton
    Left = 534
    Top = 255
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 3
    OnClick = ESendClick
  end
  object ChatClient: TIdTCPClient
    ConnectTimeout = 0
    IPVersion = Id_IPv4
    Port = 12000
    ReadTimeout = -1
    Left = 408
    Top = 24
  end
  object ChatServer: TIdTCPServer
    Active = True
    Bindings = <>
    DefaultPort = 12000
    OnExecute = ChatServerExcute
    Left = 496
    Top = 32
  end
end
