#pragma once
#ifdef WIN32
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else //linux
#include <QtCore/QtGlobal>
#ifdef SO_EXPORTS
#define DLL_API Q_DECL_EXPORT
#else
#define DLL_API Q_DECL_IMPORT
#endif
#endif
#include "string"
#include <list>
using namespace std;

typedef struct SnmpArg
{
	SnmpArg()
	{
		nSecuLevel = 0;
		nAuthProtocol = 0;
		nPrivProtocol = 0;
		strPrivPwd = "";
		strAuthPwd = "";
		strSecuName = "";
		strContextName = "";
		strCommunityName = "";
		strContextEngineID = "";
	}
	string strPrivPwd;
	string strAuthPwd;
	string strSecuName;
	string strContextName;
	string strContextEngineID;
	string strCommunityName;
	int nSecuLevel;
	long nAuthProtocol;
	long nPrivProtocol;
}SNMPARG;



class DLL_API PiPMESDK
{
public:
    PiPMESDK();


    int mps_api_getPrinterBaseInfo(const char* strIpaddress,char* buffPrinterInfo,int& len,int nOverTime, bool bSnmpv3Status, SNMPARG params);
    int mps_api_getPrinterDetailInfo(const char* strIpaddress, char* buffPrinterInfo, int& len,int ntype, const char* UUID, bool bSnmpv3Status, SNMPARG params);
    int mps_api_set(int nVersion,int m_nPort,char* strCommunityString);
    int mps_api_getSDKVersion(char* buffer,int& len);
    int mps_api_getSupportPrinters(char* buffer, int& len);
    int mps_api_seekPrinter(const char* ipList,int listSize,char* p,int& nSize, bool bSnmpv3Status, SNMPARG params);
    //void mps_api_snmpv3Status(bool bSnmpv3);

private:

    bool m_bSnmpv3;
    int m_nVersion;
    int m_nPort;
    char* m_strCommunityString;
};
