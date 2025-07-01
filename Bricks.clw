; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBricksDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Bricks.h"

ClassCount=5
Class1=CBricksApp
Class2=CBricksDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDC_MENU
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG2
Resource4=IDD_DIALOG1
Resource5=IDD_BRICKS_DIALOG
Class4=CScores
Resource6=IDD_ABOUTBOX
Class5=CEnterNameDlg
Resource7=IDR_ACCELERATOR1

[CLS:CBricksApp]
Type=0
HeaderFile=Bricks.h
ImplementationFile=Bricks.cpp
Filter=N

[CLS:CBricksDlg]
Type=0
HeaderFile=BricksDlg.h
ImplementationFile=BricksDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_OPTIONS_FASTMOVE

[CLS:CAboutDlg]
Type=0
HeaderFile=BricksDlg.h
ImplementationFile=BricksDlg.cpp
Filter=D
LastObject=ID_HELP_ABOUT

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_BRICKS_DIALOG]
Type=1
Class=CBricksDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350633601
Control2=IDC_STATIC,static,1342177294

[MNU:IDC_MENU]
Type=1
Class=CBricksDlg
Command1=ID_GAME_NEW
Command2=ID_GAME_EXIT
Command3=ID_VIEW_BOARDSIZE_3X3
Command4=ID_VIEW_BOARDSIZE_4X4
Command5=ID_VIEW_BOARDSIZE_5X5
Command6=ID_VIEW_BOARDSIZE_6X6
Command7=ID_VIEW_BOARDSIZE_7X7
Command8=ID_VIEW_BOARDSTYLE_STYLE1
Command9=ID_VIEW_BOARDSTYLE_STYLE2
Command10=ID_VIEW_BOARDSTYLE_STYLE3
Command11=ID_VIEW_HIGHESTSCORES
Command12=ID_VIEW_SOUND
Command13=ID_OPTIONS_FASTMOVE
Command14=ID_HELP_ABOUT
Command15=ID_HELP_RULES
Command16=ID_HELP_REGISTRATION
CommandCount=16

[ACL:IDR_ACCELERATOR1]
Type=1
Class=?
Command1=ID_GAME_EXIT
CommandCount=1

[DLG:IDD_DIALOG1]
Type=1
Class=CScores
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,listbox,1353728257

[CLS:CScores]
Type=0
HeaderFile=Scores.h
ImplementationFile=Scores.cpp
BaseClass=CDialog
Filter=D
LastObject=CScores
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CEnterNameDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631560

[CLS:CEnterNameDlg]
Type=0
HeaderFile=EnterNameDlg.h
ImplementationFile=EnterNameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

