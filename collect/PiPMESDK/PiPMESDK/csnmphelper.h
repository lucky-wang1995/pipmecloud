#pragma once
#include "QString"
#include "qsettings.h"
#include "qcoreapplication.h"
#include "QStringList"
#include "datatype.h"
#include "cdbhelper.h"
#include "libsnmp.h"
#include "snmp_pp/snmp_pp.h"
#include "SNMPSession.h"
#include "pipmesdk.h"
//#pragma comment(lib,"../lib/SNMP++.lib")
using namespace Snmp_pp;


enum class PrinterErrorClass
{

};


enum class PrinterError
{
	noError,
	fatalError,
	shellOpen,
	tonerEroor,
	noPaper,
	paperJam,
	paperUnmatch
};

class CSnmpHelper
{
public:
	CSnmpHelper();
	~CSnmpHelper();

	QueryResult getPrinterBaseInfo(QString strIPAdress, PrinterBaseInfo& info, int nOvertime, bool bSnmpv3Status, SnmpArg params);
	QueryResult getPrinterDetailInfo(QString strIPAdress, PrinterDetailInfo &info, bool bSnmpv3Status, SnmpArg params);
	QueryResult scanPrintersInNet(QStringList strIPAddress, QStringList &IPList, bool bSnmpv3Status, SnmpArg params);
    void loadV3Config(SnmpArg params);
    void loadSnmpv3Status(bool status);

private:
	QueryResult getPrinterBrand(QString strIPAddress, PrinterBaseInfo &info);
	QueryResult getPrinterModel(QString strIPAddress, QString strQueryOID, QString &strModel, int nMethod, int nOvertime);
	QueryResult getPrinterSN(QString strIPAddress, QString strQueryOID, QString &strSN, int nMethod, int nOvertime);



	void sessionCallback(int reason, Snmp* session, Pdu& pdu, SnmpTarget& target, void* data);
	QueryResult getBrandOID(QString strIPAddress, QString& strBrandOID, int nOvertime);
	QueryResult queryMibDataV2(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime = 1);
	QueryResult queryMibDataV1(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime);
	QueryResult queryMibDataV3(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime = 1);

	QList<QString> m_PrinterIP;
	SNMPSession* snmpsession;

    QString m_strPrivPwd;
    QString m_strAuthPwd;
    QString m_strSecuName;
    QString m_strContextName;
    QString m_strContextEngineID;
	QString m_strCommunityName;

    int m_nSecuLevel;
    long m_nAuthProtocol;
    long m_nPrivProtocol;

    bool m_bSnmpv3;
};
