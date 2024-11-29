#pragma once
#include "datatype.h"
#include "QString"
#include "QStringList"
#include "cdbhelper.h"
#include "libsnmp.h"
#include "snmp_pp/snmp_pp.h"
#include "pipmesdk.h"
//#pragma comment(lib,"../lib/SNMP++.lib")
using namespace Snmp_pp;

class SNMPSession : public QObject
{
	Q_OBJECT

signals:
	void PrinterFinded(QStringList);

public:

	SNMPSession();
	~SNMPSession();

	bool get(QStringList strIPAdress,const QString& oid, int nonReps, int maxReps, int nOverTime, QStringList& ipList, SnmpArg params);
	bool getV3(QStringList strIPAdress, const QString& oid, int nonReps, int maxReps, int nOverTime, QStringList& ipList, SnmpArg params);

	static void sessionCallback(int reason, Snmp* session, Pdu& pdu, SnmpTarget& target, void* data);
	static void sessionV3Callback(int reason, Snmp* session, Pdu& pdu, SnmpTarget& target, void* data);

	static QStringList m_IPList;

	static void writeLog(QString log);

	static v3MP *v3_MP;
private:

	Snmp* m_snmp;
	int m_status;
};

