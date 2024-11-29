#pragma once

#include "wininet.h"

#define CONTENT_TYPE_APPLICATION_URLENCODED	_T("Content-Type: application/x-www-form-urlencoded")
#define CONTENT_TYPE_MULTIPART				_T("Content-Type: multipart/form-data; boundary=")
#define BOUNDARY                            "---------------------------7e131f530984"

class CHttpClient
{
public:
	CHttpClient();
	virtual ~CHttpClient();

	void ClearData();
	void AddParams(CStringA strName, CStringA strValue);

	DWORD doGet(CString href, CStringA& strContext, CString strAuthorization=_T(""));

	DWORD doPost(CString href, CStringA& strContext, 
		CString strContentType=CONTENT_TYPE_APPLICATION_URLENCODED, 
		CString strAuthorization=_T(""), 
		DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_NO_AUTO_REDIRECT);
	DWORD doPost(CString href, CStringA& strContext, CStringA strOptions, 
		CString strContentType=CONTENT_TYPE_APPLICATION_URLENCODED, 
		CString strAuthorization=_T(""), 
		DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_NO_AUTO_REDIRECT);

private:
	CString CONTENT;
	int CL;
	CArray<CStringA> m_arrName;
	CArray<CStringA> m_arrValue;
};
