// Bricks.h : main header file for the BRICKS application
//

#if !defined(AFX_BRICKS_H__35E298D2_EBC3_4BDD_B3E0_FA9A97D0A2AD__INCLUDED_)
#define AFX_BRICKS_H__35E298D2_EBC3_4BDD_B3E0_FA9A97D0A2AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBricksApp:
// See Bricks.cpp for the implementation of this class
//

class CBricksApp : public CWinApp
{
public:
	CBricksApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBricksApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBricksApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRICKS_H__35E298D2_EBC3_4BDD_B3E0_FA9A97D0A2AD__INCLUDED_)
