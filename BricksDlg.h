// BricksDlg.h : header file
//

#if !defined(AFX_BRICKSDLG_H__3A671B73_A043_42C7_B737_CCAB523511D5__INCLUDED_)
#define AFX_BRICKSDLG_H__3A671B73_A043_42C7_B737_CCAB523511D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "Resource.h"
#include "Globals.h"
/////////////////////////////////////////////////////////////////////////////
// CBricksDlg dialog

class CBricksDlg : public CDialog
{
// Construction
public:
	void RangeScore(int x, CString plname);
	void SaveScores();
	bool ReadScores();
	bool soundon;
	bool fastmove;
	void SoundTata();
	void SoundVgick();
	bool Finish();
	void LoadNewGame();
	CBricksDlg(CWnd* pParent = NULL);	// standard constructor
	CMenu m_wndMenu;
	int Field[4][4];
// Dialog Data
	//{{AFX_DATA(CBricksDlg)
	enum { IDD = IDD_BRICKS_DIALOG };
	CEdit	m_Edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBricksDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	void SetSize();
	int GetDisplayResolution();
	void Redraw();
	void DrawField(int x, int y, int number);
	void DrawChecker(int x, int y, int number);
	void DrawCheckerNumber(CRect RectField, int number);

protected:
	HICON m_hIcon;
	HACCEL hAccell;
	// Generated message map functions
	//{{AFX_MSG(CBricksDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGameExit();
	afx_msg void OnGameNew();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHelpAbout();
	afx_msg void OnViewSound();
	afx_msg void OnViewHighestscores();
	afx_msg void OnOptionsFastmove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRICKSDLG_H__3A671B73_A043_42C7_B737_CCAB523511D5__INCLUDED_)
