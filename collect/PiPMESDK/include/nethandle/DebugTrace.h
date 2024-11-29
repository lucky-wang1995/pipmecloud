#pragma once
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <wchar.h>
#include <tchar.h>
#include "CommonFunc.h"

#define OUTPUT_LOG_TO_FILE
#define LOGFILENAME		TEXT("Log.txt")
//#define OutputFileNameAndLineNo

#define DEBUG_BUF_SIZE 2048

#define DEBUG_LEVEL1	1	// High level debug message
#define DEBUG_LEVEL2	2
#define DEBUG_LEVEL3	3	// Low level debug message

#if defined(_DEBUG) || defined(DBG)
#define Trace DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__)
#define Trace1 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL1)
#define Trace2 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL2)
#define Trace3 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL3)
#define	FUNCTION_START(s) DebugSpace::CFunctionEntryExitTrace _FunctionEntryExitTrace(__FILE__, __LINE__, s)
#else
//#define Trace
//#define	FUNCTION_START(s)
#define Trace DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__)
#define Trace1 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL1)
#define Trace2 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL2)
#define Trace3 DebugSpace::CTraceFileAndLineInfo(__FILE__, __LINE__, DEBUG_LEVEL3)
#define	FUNCTION_START(s) DebugSpace::CFunctionEntryExitTrace _FunctionEntryExitTrace(__FILE__, __LINE__, s)
#endif

typedef void (*PLOGFUNC)(TCHAR* pMsg, int nDebugLevel);

namespace DebugSpace
{

class CDebugTrace
{
public:
	CDebugTrace()
		: m_nOutputType(DebugNone)
	{}
	~CDebugTrace()
	{}

public:
	void __cdecl TraceFile(const char *pszFileName, int nLineNo,
		LPCTSTR pszFmt, va_list args) const;

	void __cdecl TraceDebugView(const char *pszFileName, int nLineNo, int nDebugLevel, 
		LPCTSTR pszFmt, va_list args) const;

	void __cdecl DebugTrace(const char *pszFileName, int nLineNo, int nDebugLevel, LPCTSTR pszFmt, ...) const;

	void SetDebugMode(int nOutputType)
	{
		m_nOutputType = nOutputType;
		if (m_nOutputType == DebugFile)
		{
			size_t nLen = 0;
			//GetWindowsDirectory(szPath, sizeof(szPath)/sizeof(TCHAR));
			//StringCchCat(szPath, sizeof(szPath)/sizeof(TCHAR), TEXT("\\temp\\"));
			//StringCchCat(szPath, sizeof(szPath)/sizeof(TCHAR), LOGFILENAME);
			//GetTempPath(sizeof(m_szLogPath)/sizeof(TCHAR), m_szLogPath);
			GetModulePath(NULL, m_szLogPath, sizeof(m_szLogPath)/sizeof(TCHAR));
			if (_tcslen(m_szLogPath) > 0)
			{
				if (m_szLogPath[_tcslen(m_szLogPath)-1] != _T('\\'))
					_tcscat_s(m_szLogPath, sizeof(m_szLogPath)/sizeof(TCHAR), _T("\\"));
			}
			_tcscat_s(m_szLogPath, sizeof(m_szLogPath)/sizeof(TCHAR), LOGFILENAME);
		}
	};

	int GetDebugMode()
	{
		return m_nOutputType;
	};

	void SetLogCallback(PLOGFUNC func)	// 第一个参数为函数的指针
	{
		m_pLogFunc = func;
	}

public:
	static CDebugTrace s_trace;

	enum OutputMode {
		DebugNone =   (int) 0x00000,
		DebugView =   (int) 0x00001,
		DebugFile =   (int) 0x00002,
		DebugEdit =   (int) 0x00003,
	};

private:
	int m_nOutputType;
	TCHAR m_szLogPath[MAX_PATH];
	PLOGFUNC m_pLogFunc;
};

inline void __cdecl CDebugTrace::TraceFile(const char *pszFileName, int nLineNo,
										   LPCTSTR pszFmt, va_list args) const
{
	TCHAR szLogMsg[DEBUG_BUF_SIZE] = { 0x0 };
	TCHAR szOutput[DEBUG_BUF_SIZE] = { 0x0 };

	_vstprintf_s(szLogMsg, sizeof(szLogMsg)/sizeof(TCHAR), pszFmt, args);

	HANDLE hFile = CreateFile(m_szLogPath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwNumOfBytesWritten;
		if (GetFileSize(hFile, NULL) == 0)
		{
			WriteFile(hFile, "\xFF\xFE", 2, &dwNumOfBytesWritten, NULL);
		}

		SetFilePointer(hFile, NULL, NULL, FILE_END);
		size_t dwLen;

#ifdef OutputFileNameAndLineNo
#ifdef UNICODE
		WCHAR szPath[MAX_PATH] = { 0x0 };
		MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, szPath, sizeof(szPath)/sizeof(WCHAR));
		_stprintf_s(szOutput, sizeof(szLogMsg)/sizeof(TCHAR), TEXT("%s(%d) : %s"), szPath, nLineNo, szLogMsg);

		dwLen = _tcslen(szOutput) * sizeof(TCHAR);
		WriteFile(hFile, szOutput, dwLen, &dwNumOfBytesWritten, NULL);
#else
		_stprintf_s(szOutput, sizeof(szLogMsg)/sizeof(TCHAR), TEXT("%s(%d) : %s"), pszFileName, nLineNo, szLogMsg);
		WCHAR szwLogMsg[DEBUG_BUF_SIZE] = { 0x0 };
		MultiByteToWideChar(CP_ACP, 0, szOutput, -1, szwLogMsg, sizeof(szwLogMsg)/sizeof(WCHAR));
		dwLen = wcslen(szwLogMsg) * sizeof(WCHAR);
		WriteFile(hFile, szwLogMsg, dwLen, &dwNumOfBytesWritten, NULL);

#endif	// UNICODE
#else
#ifdef UNICODE
		dwLen = _tcslen(szLogMsg) * sizeof(TCHAR);
		WriteFile(hFile, szLogMsg, dwLen, &dwNumOfBytesWritten, NULL);
#else
		WCHAR szwLogMsg[DEBUG_BUF_SIZE] = { 0x0 };
		MultiByteToWideChar(CP_ACP, 0, szLogMsg, -1, szwLogMsg, sizeof(szwLogMsg)/sizeof(WCHAR));
		dwLen = wcslen(szwLogMsg) * sizeof(WCHAR);
		WriteFile(hFile, szwLogMsg, dwLen, &dwNumOfBytesWritten, NULL);
#endif	// UNICODE
#endif	// OutputFileNameAndLineNo

		CloseHandle(hFile);
	}
}

inline void __cdecl CDebugTrace::TraceDebugView(const char *pszFileName, int nLineNo, int nDebugLevel,
												LPCTSTR pszFmt, va_list args) const
{
	TCHAR szLogMsg[DEBUG_BUF_SIZE] = { 0x0 };
	TCHAR szOutput[DEBUG_BUF_SIZE] = { 0x0 };

	_vstprintf_s(szLogMsg, sizeof(szLogMsg)/sizeof(TCHAR), pszFmt, args);

#ifdef OutputFileNameAndLineNo
	TCHAR szPath[MAX_PATH] = { 0x0 };
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, pszFileName, -1, szPath, sizeof(szPath)/sizeof(TCHAR));
#else
	_tcscpy_s(szPath, pszFileName);
#endif
	_stprintf_s(szOutput, sizeof(szLogMsg)/sizeof(TCHAR), TEXT("%s(%d) : %s"), szPath, nLineNo, szLogMsg);
	OutputDebugString(szOutput);
#else
	if (m_nOutputType == DebugView)
	{
		OutputDebugString(szLogMsg);
	}
	else
	{
		OutputDebugString(szLogMsg);
		if (m_pLogFunc != NULL)
			m_pLogFunc(szLogMsg, nDebugLevel);
	}
#endif
}

inline void __cdecl CDebugTrace::DebugTrace(const char *pszFileName, int nLineNo, int nDebugLevel, LPCTSTR pszFmt, ...) const
{
	if (m_nOutputType != CDebugTrace::DebugNone)
	{
		va_list arglist;
		va_start(arglist, pszFmt);

		if ((m_nOutputType == CDebugTrace::DebugView) || (m_nOutputType == CDebugTrace::DebugEdit))
		{
			CDebugTrace::s_trace.TraceDebugView(pszFileName, nLineNo, nDebugLevel, pszFmt, arglist);
		}
		else if (m_nOutputType == CDebugTrace::DebugFile)
		{
			CDebugTrace::s_trace.TraceFile(pszFileName, nLineNo, pszFmt, arglist);
		}

		va_end(arglist);
	}
}

class CTraceFileAndLineInfo
{
public:
	CTraceFileAndLineInfo(const char *pszFileName, int nLineNo)
		: m_pszFileName(pszFileName), m_nLineNo(nLineNo), m_nDebugLevel(3)
	{}
	CTraceFileAndLineInfo(const char *pszFileName, int nLineNo, int nDebugLevel)
		: m_pszFileName(pszFileName), m_nLineNo(nLineNo), m_nDebugLevel(nDebugLevel)
	{}

	void __cdecl operator()(const TCHAR *pszFmt, ...) const
	{
		if (CDebugTrace::s_trace.GetDebugMode() != CDebugTrace::DebugNone)
		{
			va_list arglist;
			va_start(arglist, pszFmt);

			if ((CDebugTrace::s_trace.GetDebugMode() == CDebugTrace::DebugView) || (CDebugTrace::s_trace.GetDebugMode() == CDebugTrace::DebugEdit))
				CDebugTrace::s_trace.TraceDebugView(m_pszFileName, m_nLineNo, m_nDebugLevel, pszFmt, arglist);
			else if (CDebugTrace::s_trace.GetDebugMode() == CDebugTrace::DebugFile)
				CDebugTrace::s_trace.TraceFile(m_pszFileName, m_nLineNo, pszFmt, arglist);

			va_end(arglist);
		}
	}

private:
	const char *const m_pszFileName;
	const int m_nLineNo;
	int m_nDebugLevel;
};

#define kErrMsgEnter	TEXT("Enter: %s\r\n")
#define kErrMsgExit		TEXT("Exit : %s\r\n")

class CFunctionEntryExitTrace
{
public:
	CFunctionEntryExitTrace(const char *pszFileName, int nLineNo, TCHAR* pszMsg)
		: m_pszFileName(pszFileName), m_nLineNo(nLineNo), m_pszMsg(pszMsg)
	{
		CDebugTrace::s_trace.DebugTrace(m_pszFileName, m_nLineNo, DEBUG_LEVEL3, kErrMsgEnter, m_pszMsg);
	}
	~CFunctionEntryExitTrace()
	{
		CDebugTrace::s_trace.DebugTrace(m_pszFileName, m_nLineNo, DEBUG_LEVEL3, kErrMsgExit, m_pszMsg);
	}

private:
	const char *const m_pszFileName;
	const int m_nLineNo;
	TCHAR*	m_pszMsg;
};

};	// namespace DebugSpace

void SaveFile(LPCTSTR lpFileName, void* pBuffer, DWORD dwSize, BOOL bAppend = TRUE);
void ReadRawData(LPCTSTR lpFileName, void* lpBuffer, DWORD dwSize, DWORD *lpdwReturn);










