object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Maze.07362415'
  ClientHeight = 572
  ClientWidth = 788
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 352
    Top = 312
    Width = 105
    Height = 105
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 202
    Height = 569
    Color = 15136253
    ParentBackground = False
    TabOrder = 0
    object Label3: TLabel
      Left = 8
      Top = 226
      Width = 47
      Height = 13
      Caption = 'Grid_size:'
      Color = 15136509
      ParentColor = False
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 32
      Width = 177
      Height = 113
      Caption = 'Size'
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentBackground = False
      ParentColor = False
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 32
        Width = 46
        Height = 19
        Caption = 'Height'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 16
        Top = 73
        Width = 41
        Height = 19
        Caption = 'Width'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 68
        Top = 26
        Width = 97
        Height = 31
        TabOrder = 0
        Text = '7'
      end
      object Edit2: TEdit
        Left = 68
        Top = 63
        Width = 97
        Height = 31
        TabOrder = 1
        Text = '7'
      end
    end
    object Button1: TButton
      Left = 72
      Top = 151
      Width = 113
      Height = 42
      Caption = 'Generate Maze'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 8
      Top = 376
      Width = 105
      Height = 41
      Caption = 'Save Maze'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 288
      Width = 105
      Height = 41
      Caption = 'Load Maze'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 8
      Top = 464
      Width = 105
      Height = 41
      Caption = 'Find a tour'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button4Click
    end
    object Edit3: TEdit
      Left = 72
      Top = 223
      Width = 36
      Height = 21
      TabOrder = 5
      Text = '40'
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 250
      Width = 121
      Height = 15
      Caption = 'Show the number '
      Color = 15136509
      ParentColor = False
      TabOrder = 6
    end
  end
  object Panel2: TPanel
    Left = 208
    Top = 0
    Width = 579
    Height = 569
    Color = 16443110
    ParentBackground = False
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 8
      Top = 8
      Width = 569
      Height = 553
      ActivePage = TabSheet3
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Memo'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 558
          Height = 521
          ScrollBars = ssVertical
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = #36855#23470
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object StringGrid1: TStringGrid
          Left = 3
          Top = 0
          Width = 555
          Height = 521
          DefaultColWidth = 40
          DefaultRowHeight = 40
          DefaultDrawing = False
          ParentShowHint = False
          ScrollBars = ssHorizontal
          ShowHint = False
          TabOrder = 0
          OnDrawCell = StringGrid1DrawCell
        end
      end
      object TabSheet3: TTabSheet
        Caption = #36855#23470#21205#30059
        ImageIndex = 2
        object StringGrid2: TStringGrid
          Left = 3
          Top = 3
          Width = 555
          Height = 518
          DefaultColWidth = 40
          DefaultRowHeight = 40
          DefaultDrawing = False
          TabOrder = 0
          OnDrawCell = StringGrid2DrawCell
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 136
    Top = 304
  end
  object SaveDialog1: TSaveDialog
    Left = 144
    Top = 392
  end
end
