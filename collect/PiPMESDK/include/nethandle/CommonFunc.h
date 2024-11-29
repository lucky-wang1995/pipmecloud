// CommonFunc.h : header file
//

#if !defined(AFX_COMMONFUNC_H__2ACE8CFD_786B_446E_A8B2_A5E5E09D19A0__INCLUDED_)
#define AFX_COMMONFUNC_H__2ACE8CFD_786B_446E_A8B2_A5E5E09D19A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdlib.h>
#include <tchar.h>

double DoubleRound(double fValue, int nSignificance, BOOL bRound);

BOOL GetModulePath(HMODULE hModule, TCHAR* pszPath, int nLen);

// Get file status, pdwFileSize and pdwFileAttr can be special NULL
BOOL GetFileStatus(const TCHAR* pszFileName, DWORD* pdwFileSize, DWORD* pdwFileAttr);

// Create config file according to lpFileName parameter
BOOL CreateConfigFile(const TCHAR *lpFileName);

// Get default paper size
BOOL GetDefaultPaperSize(void);


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMONFUNC_H__2ACE8CFD_786B_446E_A8B2_A5E5E09D19A0__INCLUDED_)