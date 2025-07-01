#if !defined(AFX_ENTERNAMEDLG_H__1873DB93_FDBF_4001_9694_04CDF1718E32__INCLUDED_)
#define AFX_ENTERNAMEDLG_H__1873DB93_FDBF_4001_9694_04CDF1718E32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnterNameDlg dialog

class CEnterNameDlg : public CDialog
{
// Construction
public:
	CString GetEditStr();
	CEnterNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnterNameDlg)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_PlayerNameCtrl;
	CString	m_PlayerName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnterNameDlg)
	public:
	virtual int DoModal();
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnterNameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERNAMEDLG_H__1873DB93_FDBF_4001_9694_04CDF1718E32__INCLUDED_)
