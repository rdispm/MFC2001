// EnterNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bricks.h"
#include "EnterNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern char name[21];
/////////////////////////////////////////////////////////////////////////////
// CEnterNameDlg dialog


CEnterNameDlg::CEnterNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnterNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnterNameDlg)
	m_PlayerName = _T("");
	//}}AFX_DATA_INIT
//	m_PlayerNameCtrl.SetFocus;
}


void CEnterNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnterNameDlg)
	DDX_Control(pDX, IDC_EDIT1, m_PlayerNameCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_PlayerName);
	DDV_MaxChars(pDX, m_PlayerName, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnterNameDlg, CDialog)
	//{{AFX_MSG_MAP(CEnterNameDlg)
	ON_WM_KEYDOWN()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnterNameDlg message handlers

BOOL CEnterNameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//m_PlayerNameCtrl.SetFocus;
	if(name[0]!=' ')
	{
		m_PlayerNameCtrl.SetWindowText(name);
		m_PlayerNameCtrl.RedrawWindow();
	}
	else
	{
		m_PlayerNameCtrl.SetFocus();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	//return FALSE;  // EXCEPTION: OCX Property Pages should return FALSE
}

void CEnterNameDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//m_PlayerNameCtrl.SetFocus;
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEnterNameDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	m_PlayerNameCtrl.SetFocus();	
}

int CEnterNameDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	//m_PlayerNameCtrl.SetFocus;
	return CDialog::DoModal();
}

CString CEnterNameDlg::GetEditStr()
{
	return m_PlayerName;

}

BOOL CEnterNameDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	//ReadScoreList();
	//SaveScoreList();
	return CDialog::DestroyWindow();
}
