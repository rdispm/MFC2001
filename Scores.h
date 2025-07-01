#if !defined(AFX_SCORES_H__067FCE27_C259_43BD_8695_71C17BE74827__INCLUDED_)
#define AFX_SCORES_H__067FCE27_C259_43BD_8695_71C17BE74827__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Scores.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScores dialog

class CScores : public CDialog
{
// Construction
public:
	CScores(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScores)
	enum { IDD = IDD_DIALOG1 };
	CListBox	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScores)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScores)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCORES_H__067FCE27_C259_43BD_8695_71C17BE74827__INCLUDED_)
