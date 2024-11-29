#pragma once

#include <QCoreApplication>
#include <QSettings>

#include "QString"
#include "datatype.h"
#include "cdbhelper.h"
#include "libsnmp.h"
#include "snmp_pp/snmp_pp.h"
#include "cdbhelper.h"
#include "QMap"
#include "QThread"
#include "writelog.h"
#include "pipmesdk.h"
#include "SNMPSession.h"
//#pragma comment(lib,"../lib/SNMP++.lib")
using namespace Snmp_pp;

#if defined (WIN32)
    #define newLine   "\r\n"
#else   //linux系统
    #define newLine   "\n"
#endif


class QueryPrinterDetailInfo
{
public:
	QueryPrinterDetailInfo();
	~QueryPrinterDetailInfo();

	PrinterDetailInfo getPantumPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantumPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getLexMarkPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getLexMarkPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getLexMarkBeaglePrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getLexMarkBeaglePrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getLexMarkWilburPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getLexMarkWilburPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getHPPrinterDetailInfo(QString strIPAddress);
	PrinterDetailInfo getHPPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPrinterDetailInfo(QString strIPAddress, PrinterBaseInfo baseInfo);
    PrinterDetailInfo getPrinterDetailInfoV3(QString strIPAddress, PrinterBaseInfo baseInfo);

	PrinterDetailInfo getCanonPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getCanonPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getBrotherPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getBrotherPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getFujiXeroxPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getFujiXeroxPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getLenovoPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getLenovoPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getKyoceraPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getKyoceraPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getKonicaMinoltaPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getKonicaMinoltaPrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPantum1820PrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantum1820PrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPantum4020PrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantum4020PrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPantum2013PrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantum2013PrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPantum3320PrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantum3320PrinterDetailInfoV3(QString strIPAddress);

	PrinterDetailInfo getPantum5103PrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantum5103PrinterDetailInfoV3(QString strIPAddress);

    PrinterDetailInfo getPantumKanasPrinterDetailInfo(QString strIPAddress);
    PrinterDetailInfo getPantumKanasPrinterDetailInfoV3(QString strIPAddress);
	
	PrinterDetailInfo getPantumOld5103PrinterDetailInfo(QString strIPAddress);
	PrinterDetailInfo getPantumOld5103PrinterDetailInfoV3(QString strIPAddress);

    void loadV3Config(bool bSnmpStatus, SnmpArg params);

//    void loadSnmpv3Status(bool status);


private:

	QueryResult queryMibDataV1(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value);

	QueryResult queryMibDataV2(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value);

	QueryResult queryMibDataV3(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value);

	QueryResult WalkMib(QString strIPAdress, QString OID, QList<MibValue>& List_Value);

	QMap<QString, QString> m_LemarkError;

	void initLemarkError();

    QString m_strPrivPwd;
    QString m_strAuthPwd;
	QString m_strSecuName;
    QString m_strContextName;
    QString m_strContextEngineID;
	QString m_strCommunityName;

    int m_nSecuLevel;
    int m_nAuthProtocol;
    int m_nPrivProtocol;

    bool m_bSnmpv3;

	//void writeLog(QString txt);
};

