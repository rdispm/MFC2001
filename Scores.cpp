// Scores.cpp : implementation file
//

#include "stdafx.h"
#include "Bricks.h"
#include "Scores.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScores dialog


CScores::CScores(CWnd* pParent /*=NULL*/)
	: CDialog(CScores::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScores)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CScores::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScores)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScores, CDialog)
	//{{AFX_MSG_MAP(CScores)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScores message handlers

BOOL CScores::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//m_List.AddString("Hello");
	//m_List.AddString("kuku");
	int i;
	FILE *fp;
    
    if((fp = fopen("scores.txt", "r")) == NULL)
    {
		//AfxMessageBox("file not found");
    }
    else
    {
		//read file
		char line[34];
		int i;
		m_List.AddString("                    ");
		for(i=0;i<20;i++) //read toplines to lines
		{
			fgets(line,32,fp);
			line[30] = ' ';
			line[31] = ' ';
			line[32] = '\0';
			line[33] = '\0';
			m_List.AddString(line);
		}
		fclose(fp);
	}   
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
