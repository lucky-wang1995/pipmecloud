#include "pipmesdk.h"
#include "csnmphelper.h"
#include "cdbhelper.h"
#include "USBHelper.h"
#include "writelog.h"


PiPMESDK::PiPMESDK()
{
	//CDBHelper::init();
	m_nVersion = 2;
	m_nPort = 161;
    m_strCommunityString = new char[7];
    strcpy(m_strCommunityString,"public");
}

//void PiPMESDK::mps_api_snmpv3Status(bool bSnmpv3)
//{
//    m_bSnmpv3 = bSnmpv3;
//}
int PiPMESDK::mps_api_set(int nVersion, int nPort, char* strCommunityString)
{
	m_nVersion = nVersion;
	m_nPort = nPort;
	m_strCommunityString = strCommunityString;
	return (int)QueryResult::Successed;
}

int PiPMESDK::mps_api_getPrinterBaseInfo(const char* strIpaddress, char* buffPrinterInfo, int& len, int nOverTime, bool bSnmpv3Status, SnmpArg params)
{
	CSnmpHelper snmp;
	QString IP = QString::fromLocal8Bit(strIpaddress);
	PrinterBaseInfo info;
	QueryResult nRet = snmp.getPrinterBaseInfo(IP, info, nOverTime, bSnmpv3Status, params);
	QString result = info.toJson();

	if (nRet != QueryResult::Successed)
	{
		return (int)nRet;
	}
	if (len <= result.length())
	{
		len = result.length();
		return (int)QueryResult::InsufficientBuffer;
	}
	QByteArray rArray = result.toUtf8();
	char* json = rArray.data();
	memcpy(buffPrinterInfo, json, result.length());
	return (int)QueryResult::Successed;
}
int PiPMESDK::mps_api_getPrinterDetailInfo(const char* strIpaddress, char* buffPrinterInfo, int& len,int ntype, const char* UUID, bool bSnmpv3Status, SnmpArg params)
{
	if (ntype == 1)
	{
		QString IP = QString::fromLocal8Bit(strIpaddress);
		QByteArray rArray;
		USBHelper usbReader;
		QueryResult nRet = usbReader.getUSBPrinterInfo(IP, rArray);
		if (nRet == QueryResult::Successed)
		{
			char* json = rArray.data();
			memcpy(buffPrinterInfo, json, rArray.length());
		}
		return (int)nRet;
	}
	CSnmpHelper snmp;
	QString IP = QString::fromLocal8Bit(strIpaddress);
	PrinterDetailInfo dtInfo;
	QueryResult nRet = snmp.getPrinterDetailInfo(IP, dtInfo, bSnmpv3Status, params);
	if (nRet!= QueryResult::Successed)
	{
		return (int)nRet;
	}
	QString QUUID = QString::fromLocal8Bit(UUID);
	dtInfo.UUID = QUUID;
	QString result = dtInfo.toJson();
	QByteArray rArray = result.toUtf8();
	if (len <= rArray.length())
	{
		len = rArray.length();
		return (int)QueryResult::InsufficientBuffer;
	}
	memcpy(buffPrinterInfo, rArray.constData(), rArray.length());
	for (int i = 0;i<rArray.length();i++)
	{
		if (buffPrinterInfo[i] == '\0')
		{
			buffPrinterInfo[i] = ' ';
		}
	}
	return (int)QueryResult::Successed;
}
int PiPMESDK::mps_api_getSupportPrinters(char* buffer, int& len)
{
	QList<QString> listPrinterModels;
	QueryResult ret = CDBHelper::getSupportPrinterModel(listPrinterModels);
	if (ret != QueryResult::Successed)
	{
		return (int)ret;
	}
	QString json;
	json.append("{");
	json.append("\"models\":[");
	for (auto item : listPrinterModels)
	{
		json.append("\"");
		json.append(item);
		json.append("\",");
	}
	json = json.left(json.length() - 1);
	json.append("]}");
	QByteArray rArray = json.toUtf8();
	if (len <= rArray.length())
	{
		len = rArray.length();
		return (int)QueryResult::InsufficientBuffer;
	}
	char* cjson = rArray.data();
	memcpy(buffer, cjson, rArray.length());
	return (int)QueryResult::Successed;
}
int PiPMESDK::mps_api_getSDKVersion(char* buffer, int& len)
{
	QString version;

	version = "{\"version\":\"0.2.6.4\"}";
	QByteArray rArray = version.toUtf8();
	if (len <= rArray.length())
	{
		len = rArray.length();
		return (int)QueryResult::InsufficientBuffer;
	}
	char* json = rArray.data();
	memcpy(buffer, json, rArray.length());
	return (int)QueryResult::Successed;
}

int PiPMESDK::mps_api_seekPrinter(const char* ipList, int listSize,char* p, int& nSize, bool bSnmpv3Status, SnmpArg params)
{
	QStringList sourcelist = QString::fromLatin1(ipList).split(",",QString::SkipEmptyParts);
	QStringList albeList;
	CSnmpHelper snmp;
	snmp.scanPrintersInNet(sourcelist, albeList, bSnmpv3Status, params);
	memset(p, 0, nSize);	
	QString ip;
	for (auto item : albeList)
	{
		ip.append(item);
		ip.append(",");
	}
	ip.remove(ip.length()-1, 1);
	QByteArray array = ip.toLatin1();
	char* buff = array.data();
	
	memcpy(p, buff, array.length());
	return (int)QueryResult::Successed;
}
