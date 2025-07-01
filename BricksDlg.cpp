// BricksDlg.cpp : implementation file
//

#include "stdafx.h"
#include <afxext.h> 
#include "Bricks.h"
#include "BricksDlg.h"
#include "Random.h"
#include "Scores.h"
#include "EnterNameDlg.h"
#include "mmsystem.h"

#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>

//#include "Resource.h"
#include <stdlib.h>

int gamesnumber;
int cellsize;
int GameTime;
bool TimerOn;
bool firstclick;
bool timercount;
bool hour;
char name[21] = "                    ";
char ScoreName[20][21] = {"MASTER-MASON        ",
"STONEMASON          ",
"WALLER              ",
"BRICKLAYER          ",
"PADDY               ",
"BRICKY              ",
"HODMAN              ",
"COWAN               ",
"LAPICIDE            ",
"HEWER               ",
"CHIPPER             ",
"SAVAGE              ",
"BARBARIAN           ",
"PREHISTORIC         ",
"                    ",
"                    ",
"                    ",
"                    ",
"                    ",
"                    "};
int ScoreValue[20] = {15000, 10000, 9500, 9000, 8500, 
						8000, 7500, 7000, 6500, 6000, 
						5000, 4000, 3000, 1000, 0, 
						0, 0, 0, 0, 0};

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBricksDlg dialog

CBricksDlg::CBricksDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBricksDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBricksDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hAccell = LoadAccelerators( AfxGetResourceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1) );
}

void CBricksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBricksDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBricksDlg, CDialog)
	//{{AFX_MSG_MAP(CBricksDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_GAME_EXIT, OnGameExit)
	ON_COMMAND(ID_GAME_NEW, OnGameNew)
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_VIEW_SOUND, OnViewSound)
	ON_COMMAND(ID_VIEW_HIGHESTSCORES, OnViewHighestscores)
	ON_COMMAND(ID_OPTIONS_FASTMOVE, OnOptionsFastmove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBricksDlg message handlers

BOOL CBricksDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			//pSysMenu->AppendMenu(MF_STRING, IDC_MENU, strAboutMenu);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	///////////// registry ////////////////////////////////////////////////////////////////////////////
	/*SetRegistryKey("RI");
        WriteProfileString("Bricks", "Date" , "Hi");

	SetRegistryKey(("RI"));
	AfxMessageBox(GetProfileString("Step39", "TestApp", "None :-("));
	dlg.DoModal();*/
	///////////////////////////////////////////////////////////////////////////////////////////////////

	cellsize = 64;
	firstclick = false;
	timercount = true;
	SetTimer(ID_TIMER_1,50,NULL);
	//CFont 
	//m_Edit1.SetFont();
	GameTime = 0;
	soundon = true;
	fastmove = true;
	TimerOn = true;
	gamesnumber = 0;
	LoadNewGame();
	if(!ReadScores())
	{
		SaveScores();
		//
	}
	//Redraw();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBricksDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBricksDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		Redraw();
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBricksDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBricksDlg::OnGameExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}

BOOL CBricksDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	m_wndMenu.LoadMenu(IDC_MENU);
	SetMenu(&m_wndMenu);
	return CDialog::Create(IDD, pParentWnd);
}
//---------------------------------------------------------------------------
void CBricksDlg::SetSize()
{
    int boardslider = 11;
	switch(GetDisplayResolution())
    {
    case 640:
        if(boardslider > 3) boardslider = 3;
        break;
    case 800:
        if(boardslider > 4) boardslider = 4;
        break;
    case 1024:
        if(boardslider > 7) boardslider = 7;
        break;
    case 1152:
        if(boardslider > 9) boardslider = 9;
        break;
    case 1280:
        if(boardslider > 11) boardslider = 11;
        break;
    case 1600:
    default:
        if(boardslider > 14) boardslider = 14;
    }
    CMenu* cm=GetMenu();
    if(boardslider < 1)
    {
        //smallboard = true;
        
        //cm->EnableMenuItem(ID_VIEW_NUMERA, MF_GRAYED);

    }
    else
    {
        //smallboard = false;
        
        //cm->EnableMenuItem(ID_VIEW_NUMERA, MF_ENABLED);
    
    }
    //SetFontSize();
    //cellsize = 4*(boardslider + 4);
    //halfcell = cellsize/2;
  /*  int btnsizey = 30;
	int btnsizex = 80;
    int btnleft = FWIDTH + cellsize * GAMEBOARDSIZE;
    int btnright = FWIDTH + cellsize * GAMEBOARDSIZE + btnsizex;
    formwidth = btnright + 14;
    formhight = FHIGHT + cellsize * GAMEBOARDSIZE;
        
    m_Edit1.SetWindowPos(this, 0, formhight - 70, formwidth - 124, formhight, SWP_NOZORDER);
    m_Edit2.SetWindowPos(this, formwidth - 124, formhight-70, formwidth, formhight, SWP_NOZORDER);
    m_btn1.SetWindowPos(this, btnleft, 10, btnsizex, btnsizey, SWP_NOZORDER);
    m_btn2.SetWindowPos(this, btnleft, 50, btnsizex, btnsizey, SWP_NOZORDER);
    m_btn3.SetWindowPos(this, btnleft, 90, btnsizex, btnsizey, SWP_NOZORDER);
    m_btn4.SetWindowPos(this, btnleft, 130, btnsizex, btnsizey, SWP_NOZORDER);
    m_btn5.SetWindowPos(this, btnleft, 170, btnsizex, btnsizey, SWP_NOZORDER);
    m_btn6.SetWindowPos(this, btnleft, 210, btnsizex, btnsizey, SWP_NOZORDER);
	m_btn7.SetWindowPos(this, btnleft, 250, btnsizex, btnsizey, SWP_NOZORDER);
	m_btn8.SetWindowPos(this, btnleft, 290, btnsizex, btnsizey, SWP_NOZORDER);

    SetWindowPos(this, 0, 0, formwidth, formhight, SWP_NOZORDER|SWP_NOMOVE);
    
    RedrawWindow(); //Important for window size decreasing */
    //m_btn1.SetFocus();
}
//---------------------------------------------------------------------------
int CBricksDlg::GetDisplayResolution()
{
    CRect Rect;
    CWnd* Desk;
    Desk = GetDesktopWindow();
    Desk->GetWindowRect( &Rect);
    return Rect.right;
}
//---------------------------------------------------------------------------
void CBricksDlg::Redraw()
{
    int i, j;
    for(i=0; i<GAMEBOARDSIZE; i++)
    {
        for(j=0; j<GAMEBOARDSIZE; j++)
        {
			DrawField(i, j, Field[i][j]);
        }
    }
}
//---------------------------------------------------------------------------
void CBricksDlg::DrawField(int x, int y, int number)
{
    int i;
	int X0 = cellsize * x + BOARDLEFT;
	int Y0 = cellsize * y + BOARDTOP;
    CClientDC dc(this);
    CPen Pen;
    CBrush Brush;
    CPen* pOldPen;
    CBrush* pOldBrush;
    pOldPen=dc.SelectObject(&Pen);
    pOldBrush=dc.SelectObject(&Brush);
    
    
	CRect RectField;
    RectField.top = Y0;
    RectField.bottom = Y0 + cellsize;
    RectField.left= X0;
    RectField.right= X0 + cellsize;
    
    
	dc.FillSolidRect(&RectField, BOARDCOLORGRID);// fill with boardcolor a cell
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	Brush.CreateSolidBrush(LINECOLORGRID);
	Pen.CreatePen(PS_SOLID, 2, LINECOLORGRID);
	pOldPen=dc.SelectObject(&Pen);
	pOldBrush=dc.SelectObject(&Brush);

    dc.MoveTo(X0, Y0);
   	dc.LineTo(X0+cellsize, Y0);
    dc.LineTo(X0+cellsize, Y0+cellsize);
    dc.LineTo(X0, Y0+cellsize);
    dc.LineTo(X0, Y0);

	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

    
    if(number != 0)
    {
        DrawChecker(x, y, number);
    }
}

void CBricksDlg::DrawChecker(int x, int y, int number)
{
    CClientDC dc(this);
    CPen Pen;
    CBrush Brush;
    CPen* pOldPen;
    CBrush* pOldBrush;
	
	CRect RectField(cellsize * x + BOARDLEFT + 2,
			cellsize * y + BOARDTOP + 2,
			cellsize * (x+1) + BOARDLEFT -2,
			cellsize * (y+1) + BOARDTOP-2);

	Pen.CreatePen(PS_SOLID, 1, RGB(0,0,0));
	Brush.CreateSolidBrush(RGB(255,128,64));
	
	pOldPen=dc.SelectObject(&Pen);
	pOldBrush=dc.SelectObject(&Brush);
	dc.Rectangle(RectField);
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	DrawCheckerNumber(RectField, number);     
}

void CBricksDlg::DrawCheckerNumber(CRect RectField, int number)
{
    CClientDC dc(this);
    COLORREF oldColor;
    int oldBkMode;
    CFont Font;
    CFont* oldFont;

    Font.CreateFont(
    45, 0, 0, 0, FW_BOLD, 
    0, 0, 0, ANSI_CHARSET, OUT_DEVICE_PRECIS,
    CLIP_MASK, DEFAULT_QUALITY, DEFAULT_PITCH,
    "Times New Roman");
    RectField.top += 8;
    
    oldFont = dc.SelectObject(&Font);
    char buffer[4];
    RectField.bottom -=2;
    RectField.left +=2;
    RectField.right -=2;

    oldColor = SetTextColor(dc, RGB(0,255,255));
        
    
    oldBkMode = SetBkMode(dc, TRANSPARENT);
    _itoa(number, buffer,10);
    dc.DrawText(buffer, RectField, DT_CENTER | DT_VCENTER);
    SetBkMode(dc, oldBkMode);
    SetTextColor(dc, oldColor);
    dc.SelectObject(oldFont);
    
}

void CBricksDlg::OnGameNew() 
{
	LoadNewGame();
	GameTime = 0;
	timercount = true;
	firstclick = false;
	TimerOn = true;
	gamesnumber++;
	/*if(gamesnumber>2)
	{
		AfxMessageBox("Sorry. It's beta version with restriction (no more 3 games)");
		OnOK();
	}*/
	Redraw();	
}

void CBricksDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int x = (point.x - BOARDLEFT + cellsize)/ cellsize;
    int y = (point.y - BOARDTOP + cellsize)/ cellsize;
	if(timercount)
	{
		if( x>=1 && x<=GAMEBOARDSIZE && y>=1 && y<=GAMEBOARDSIZE) //&& gamefield[board][y-1][x-1]==EMPTYFIELD)
		{ 
			x--;
			y--;
			if(!fastmove)
			{
				if((x>0)&(Field[x-1][y]==0))
				{
					//swap
					Field[x-1][y] = Field[x][y];
					Field[x][y] = 0;
					firstclick = true;
					SoundVgick();
					Redraw();
				}
				if((x<3)&(Field[x+1][y]==0))
				{
					//swap
					Field[x+1][y] = Field[x][y];
					Field[x][y] = 0;
					firstclick = true;
					SoundVgick();
					Redraw();
				}
				if((y>0)&(Field[x][y-1]==0))
				{
					//swap
					Field[x][y-1] = Field[x][y];
					Field[x][y] = 0;
					firstclick = true;
					SoundVgick();
					Redraw();
				}
				if((y<3)&(Field[x][y+1]==0))
				{
					//swap
					Field[x][y+1] = Field[x][y];
					Field[x][y] = 0;
					firstclick = true;
					SoundVgick();
					Redraw();
				}
			}
			else
			{
				if(x>0)
				{
					if(Field[x-1][y]==0)
					{
						Field[x-1][y] = Field[x][y];
						Field[x][y] = 0;
						firstclick = true;
						SoundVgick();
						Redraw();
					}
					else
					{
						if((x>1))
						{
							if(Field[x-2][y]==0)
							{
								Field[x-2][y] = Field[x-1][y];
								Field[x-1][y] = Field[x][y];
								Field[x][y] = 0;
								firstclick = true;
								SoundVgick();
								Redraw();
							}
							else
							{
								if((x>2))
								{
									if(Field[x-3][y]==0)
									{
										Field[x-3][y] = Field[x-2][y];
										Field[x-2][y] = Field[x-1][y];
										Field[x-1][y] = Field[x][y];
										Field[x][y] = 0;
										firstclick = true;
										SoundVgick();
										Redraw();
									}
								}
							}
						}
					}
				}
				if(x<3)
				{
					if(Field[x+1][y]==0)
					{
						Field[x+1][y] = Field[x][y];
						Field[x][y] = 0;
						firstclick = true;
						SoundVgick();
						Redraw();
					}
					else
					{
						if((x<2))
						{
							if(Field[x+2][y]==0)
							{
								Field[x+2][y] = Field[x+1][y];
								Field[x+1][y] = Field[x][y];
								Field[x][y] = 0;
								firstclick = true;
								SoundVgick();
								Redraw();
							}
							else
							{
								if((x<1))
								{
									if(Field[x+3][y]==0)
									{
										Field[x+3][y] = Field[x+2][y];
										Field[x+2][y] = Field[x+1][y];
										Field[x+1][y] = Field[x][y];
										Field[x][y] = 0;
										firstclick = true;
										SoundVgick();
										Redraw();
									}
								}
							}
						}
					}//swap
				}
				if(y>0)
				{
					if(Field[x][y-1]==0)
					{
						Field[x][y-1] = Field[x][y];
						Field[x][y] = 0;
						firstclick = true;
						SoundVgick();
						Redraw();
					}
					else
					{
						if((y>1))
						{
							if(Field[x][y-2]==0)
							{
								Field[x][y-2] = Field[x][y-1];
								Field[x][y-1] = Field[x][y];
								Field[x][y] = 0;
								firstclick = true;
								SoundVgick();
								Redraw();
							}
							else
							{
								if((y>2))
								{
									if(Field[x][y-3]==0)
									{
										Field[x][y-3] = Field[x][y-2];
										Field[x][y-2] = Field[x][y-1];
										Field[x][y-1] = Field[x][y];
										Field[x][y] = 0;
										firstclick = true;
										SoundVgick();
										Redraw();
									}
								}
							}
						}
					}
					//swap
				}
				if(y<3)
				{
					if(Field[x][y+1]==0)
					{
						Field[x][y+1] = Field[x][y];
						Field[x][y] = 0;
						firstclick = true;
						SoundVgick();
						Redraw();
					}
					else
					{
						if((y<2))
						{
							if(Field[x][y+2]==0)
							{
								Field[x][y+2] = Field[x][y+1];
								Field[x][y+1] = Field[x][y];
								Field[x][y] = 0;
								firstclick = true;
								SoundVgick();
								Redraw();
							}
							else
							{
								if((y<1))
								{
									if(Field[x][y+3]==0)
									{
										Field[x][y+3] = Field[x][y+2];
										Field[x][y+2] = Field[x][y+1];
										Field[x][y+1] = Field[x][y];
										Field[x][y] = 0;
										firstclick = true;
										SoundVgick();
										Redraw();
									}
								}
							}
						}
					}
				}	
			}
		}
		//Redraw();
		//Compare for finish
		if(Finish())
		{
			timercount = false;
			//AfxMessageBox("Congratulation!!!");
			//Sound
			SoundTata();
			//end sound
			/*CString plname;
			CEnterNameDlg cd(this);
			if (cd.DoModal()==IDOK)
			{
				plname = cd.m_PlayerName;
				///FindText(cd.m_Search,FALSE);
			}
			CScores cd2(this);
			if (cd2.DoModal()==IDOK)
			{
				///FindText(cd.m_Search,FALSE);
			}*/
			int x = 11800 - GameTime;
			if(x<0) x=0;
			if(x>10600) x +=4400;
			if(x>15600) x +=4400;
			if(hour)
			{
				x = 0;
			}
			CString strMessage;
			strMessage = "You result is ";
			char ch[10];
			_itoa( x, ch, 10 );
			strMessage += ch;
			AfxMessageBox(strMessage);
			if(x >= ScoreValue[19])
			{
				CString plname;
				CEnterNameDlg cd(this);
				if (cd.DoModal()==IDOK)
				{
					plname = cd.m_PlayerName;
					///FindText(cd.m_Search,FALSE);
					//AfxMessageBox(name);
					RangeScore(x, plname);
					//AfxMessageBox(name);
					SaveScores();
				}
			}
			CScores cd2(this);
			if (cd2.DoModal()==IDOK)
			{
				///FindText(cd.m_Search,FALSE);
			}
		}
	}
	CDialog::OnLButtonUp(nFlags, point);

}
void CBricksDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i;
    if(TimerOn)
    {
		if(firstclick)
		{
			if(timercount)
			{
				if(GameTime>72000)
				{
					hour = true;
					GameTime -=72000;
				}
				if(GameTime%2 == 0)
				{
					int t = GameTime/20;
					char ch[14];
					ch[0] = ' ';
					ch[1] = (char)(t/600 + 48);
					ch[2] = (char)(t/60 - 10*((int)(t/600)) + 48);
					ch[3] = ' ';
					ch[4] = ':';
					ch[5] = ' ';
					ch[6] = (char)(t/10 - 6*((int)(t/60)) + 48);
					ch[7] = (char)(t%10 + 48);
					ch[8] = ' ';
					ch[9] = ':';
					ch[10] = ' ';
					ch[11] = (char)(((int)(GameTime/2))%10 + 48);
					ch[12] = ' ';
					ch[13] = '\0';
					

					m_Edit1.SetWindowText(ch);
					m_Edit1.RedrawWindow();
				}
				GameTime++;
			}
		}
		else
		{
			GameTime = 0;
			m_Edit1.SetWindowText(" 00 : 00 : 0 ");
			m_Edit1.RedrawWindow();
		}
    }
	else
	{
		GameTime = 0;
		m_Edit1.SetWindowText(" 00 : 00 : 0 ");
        m_Edit1.RedrawWindow();
	}

	CDialog::OnTimer(nIDEvent);
}

void CBricksDlg::LoadNewGame()
{
	int i, j, k;
	srand( (unsigned)time( NULL ) );
	k = rand()%11;
   
	//k = m_Edit2;
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			Field[j][i] = RandBoard[k][i][j];
		}
	}
	hour = false;
}


bool CBricksDlg::Finish()
{ 
	int i, j;
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			if((j==3)&(i==3))
			{
				return true;
			}
			if(Field[i][j] != i+1+j*4)
			{
				return false;
			}
		}
	}

}

int CBricksDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	//m_PlayerNameCtrl.SetFocus;
	return CDialog::DoModal();
}

void CBricksDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg cd;
	if (cd.DoModal()==IDOK)
	{
		//plname = cd.m_PlayerName;
		///FindText(cd.m_Search,FALSE);
	}
}
UINT sound1(LPVOID Param)
{
	HRSRC hWav;
	hWav=FindResource(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_WAVE2),"WAVE");
	if (hWav!=NULL)
	{
		   HGLOBAL hPtrDataWav;
	   hPtrDataWav=LoadResource(AfxGetResourceHandle(), hWav);
	   if (hPtrDataWav!=NULL)
	   {
	   LockResource(hPtrDataWav);
		   sndPlaySound((LPCTSTR)hPtrDataWav,SND_MEMORY|SND_ASYNC );
		   FreeResource(hPtrDataWav);
	   }
	   else AfxMessageBox(" Error #1");
	}
	else AfxMessageBox("Error #2");
	return 0;
}
UINT sound2(LPVOID Param)
{
	HRSRC hWav;
	hWav=FindResource(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_WAVE1),"WAVE");
	if (hWav!=NULL)
	{
		   HGLOBAL hPtrDataWav;
	   hPtrDataWav=LoadResource(AfxGetResourceHandle(), hWav);
	   if (hPtrDataWav!=NULL)
	   {
	   LockResource(hPtrDataWav);
		   sndPlaySound((LPCTSTR)hPtrDataWav,SND_MEMORY|SND_ASYNC );
		   FreeResource(hPtrDataWav);
	   }
	   else AfxMessageBox(" Error #1");
	}
	else AfxMessageBox("Error #2");
	return 0;
}
void CBricksDlg::SoundVgick()
{
	if(soundon) AfxBeginThread(sound1,this);	
}



void CBricksDlg::SoundTata()
{
	//if(soundon) AfxBeginThread(sound2,this);
	AfxBeginThread(sound2,this);
}

void CBricksDlg::OnViewSound() 
{
	// TODO: Add your command handler code here
	CMenu* cm=GetMenu();
	if(soundon)
    {
        soundon = false;
        cm->CheckMenuItem(ID_VIEW_SOUND, MF_UNCHECKED);
    }
    else
    {
        soundon = true;
        cm->CheckMenuItem(ID_VIEW_SOUND, MF_CHECKED);
    }
}

bool CBricksDlg::ReadScores()
{
	FILE *fp;
    
    if((fp = fopen("scores.txt", "r")) == NULL)
    {
		//AfxMessageBox("file not found");
		return false;
    }
    else
    {
		//read file
		// restriction
		//return false;
		////////
		char line[32];
		int i, j, score;
		for(i=0;i<20;i++) //read toplines to lines
		{
			fgets(line,32,fp);
			score = 0;
			for(j=0;j<20;j++)
			{
				ScoreName[i][j] = line[j];
			}
			for(j=25;j<30;j++)
			{
				if(line[j] == ' ')
				{
				}
				else
				{
					if((line[j] == '0')||(line[j] == '1')||(line[j] == '2')
					||(line[j] == '3')||(line[j] == '4')||(line[j] == '5')||(line[j] == '6')
					||(line[j] == '7')||(line[j] == '8')||(line[j] == '9'))
					{
						score = 10*score + ((int)(line[j]) - 48);
					}
					else
					{
						return false;
					}
				}
			}
			ScoreValue[i] = score;
			 
			
		}
		fclose(fp);
		return true;
	}   
}

void CBricksDlg::SaveScores()
{
	FILE *fp;
    int i, j, k;
	char ch[8];
    if((fp = fopen("scores.txt", "w")) != NULL)
    {
        for(i=0; i<20; i++)
    	{
			fprintf(fp, ScoreName[i]);
			fprintf(fp, "     ");
			k = 10000;
			for(j=0; j<5; j++)
			{
				if(ScoreValue[i]<k)
				{
					fprintf(fp, " ");
				}
				else
				{
					itoa(ScoreValue[i], ch, 10);
					fprintf(fp, ch);
					//fprintf(fp, "\n");
					break;

				}
				k = k/10;

			}
			fprintf(fp, "\n");
        }
		fclose(fp);
    }
    	
}


void CBricksDlg::RangeScore(int x, CString plname)
{
	int i, j;
	int length = plname.GetLength();
	for(i=0; i< length; i++)
	{
		name[i] = plname[i];
	}
	//AfxMessageBox(name);
	if(length<20)
	{
		for(i=length; i< 20; i++)
		{
			name[i] = ' ';
		}
	}
	name[20] = '\0';
	//AfxMessageBox(name);
	for(i=19; i>=0; i--)
	{
		if(i==0)
		{
			for(j=0; j<20; j++)
			{
				ScoreName[i][j] = name[j];
			}
			ScoreValue[i] = x;
			break;
		}
		if(x>ScoreValue[i-1])
		{
			ScoreValue[i] = ScoreValue[i-1];
			for(j=0; j<20; j++)
			{
				ScoreName[i][j] = ScoreName[i-1][j];
			}
		}
		else
		{
			for(j=0; j<20; j++)
			{
				ScoreName[i][j] = name[j];
			}
			ScoreValue[i] = x;
			break;
		}
	}
}

void CBricksDlg::OnViewHighestscores() 
{
	// TODO: Add your command handler code here
	CScores cd2(this);
	//AfxMessageBox(name);
	if (cd2.DoModal()==IDOK)
	{
		///FindText(cd.m_Search,FALSE);
	}
}

void CBricksDlg::OnOptionsFastmove() 
{
	// TODO: Add your command handler code here
	CMenu* cm=GetMenu();
	if(fastmove)
    {
        fastmove = false;
        cm->CheckMenuItem(ID_OPTIONS_FASTMOVE, MF_UNCHECKED);
    }
    else
    {
        fastmove = true;
        cm->CheckMenuItem(ID_OPTIONS_FASTMOVE, MF_CHECKED);
    }
}
