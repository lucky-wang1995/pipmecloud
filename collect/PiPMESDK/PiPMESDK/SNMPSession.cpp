#include "SNMPSession.h"
#include <QDateTime> 

v3MP* SNMPSession::v3_MP = nullptr;

SNMPSession::SNMPSession()
{
	char strEngineId[256];

	strcpy(strEngineId, "snmpGet");

	unsigned int snmpEngineBoots = 0;

	int construct_status;
	if (v3_MP == nullptr)
		v3_MP = new v3MP((const char*)strEngineId, snmpEngineBoots, construct_status);

	m_status = 0;
	Snmp::socket_startup();
	m_snmp = new Snmp(m_status, 0, Address::version_ipv4);
	m_snmp->start_poll_thread(5);
}

QStringList SNMPSession::m_IPList;

SNMPSession::~SNMPSession()
{
	m_snmp->stop_poll_thread();
	delete m_snmp;
}

void SNMPSession::writeLog(QString log)
{
	//QFile outFile("d:\\connectionlog.txt");
	//outFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
	//QTextStream ts(&outFile);
	//ts << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + ": " + "SDKLog" + log << endl;
	//outFile.close();
}

bool SNMPSession::get(QStringList strIPAdress, const QString& oid, int nonReps, int maxReps, int nOverTime, QStringList &ipList, SnmpArg params)
{
	Pdu pdu;
	QByteArray array = oid.toLocal8Bit();
	pdu += Vb(Oid(array.data()));
	snmp_version version = version1;          // default is v1
	int retries = 1;                          // default retries is 1
	int timeout = nOverTime * 100;                        // default is 1 second (100unit)
	u_short port = 161;                       // default snmp port is 161
    OctetStr community;  // community name
    if (!params.strCommunityName.empty())
    {
        community = OctetStr(params.strCommunityName.c_str());          // community name
    }
    else
    {
        community = OctetStr("public");           // community name
    }

	int non_reps = 0;                         // non repeaters default is 0
	int max_reps = 10;                        // maximum repetitions default is 10

	CTarget ctarget;             // make a target using the address
	ctarget.set_version(version);         // set the SNMP version SNMPV1 or V2
	ctarget.set_retry(retries);           // set the number of auto retries
	ctarget.set_timeout(timeout);         // set timeout
	ctarget.set_readcommunity(community); // set the read community name
	SnmpTarget* target;
	target = &ctarget;
	if (m_status != SNMP_CLASS_SUCCESS)
	{
		Snmp::socket_cleanup();
		return false;//snmp初始化失败
	}
	m_IPList.clear();
	//	writeLog("start Query Printers");
	for (auto item : strIPAdress)
	{
		if (strIPAdress.contains("255"))
		{
			continue;
		}
		//	writeLog("Printers:" + item);
		QByteArray addressarray = item.toLatin1();
		UdpAddress address(addressarray.data());
		ctarget.set_address(address);
		qDebug() << "m_snmp->get start";
		int ret = m_snmp->get(pdu, *target, &SNMPSession::sessionCallback, &ipList);
		qDebug() << "m_snmp->get end";
		if (ret != SNMP_CLASS_SUCCESS) {
			Sleep(5);
			continue;
		}
		Sleep(5);
	}

	Sleep(nOverTime * 1000 + 1000);
	ipList = m_IPList;
	//	writeLog("End Query Printers total:"+QString::number(ipList.size()));
	return true;
}


bool SNMPSession::getV3(QStringList strIPAdress, const QString& oid, int nonReps, int maxReps, int nOverTime, QStringList &ipList, SnmpArg params)
{
	Pdu pdu;
	int status;
	QByteArray array = oid.toLocal8Bit();
	pdu += Vb(Oid(array.data()));
	snmp_version version;
	Snmp::socket_startup();

	version = version3;

	int retries = 1;                          // default retries is 1
	int timeout = nOverTime * 100;                        // default is 1 second (100unit)
	u_short port = 161;                       // default snmp port is 161
	OctetStr community;
	if (!params.strCommunityName.empty())
	{
		community = OctetStr(params.strCommunityName.c_str());          // community name
	}
	else
	{
		community = OctetStr("public");           // community name
	}

	int non_reps = 0;                         // non repeaters default is 0
	int max_reps = 10;                        // maximum repetitions default is 10

	SnmpTarget* target;
	UTarget utarget;            //snmpv3

		//--------- [ parameters of SNMP V3 ]--------------------------------------
	OctetStr privPassword(params.strPrivPwd.c_str());
	OctetStr authPassword(params.strAuthPwd.c_str());
	OctetStr securityName(params.strSecuName.c_str());
	int securityModel = SNMP_SECURITY_MODEL_USM;
	int securityLevel = params.nSecuLevel;
	OctetStr contextName(params.strContextName.c_str());
	OctetStr contextEngineID(params.strContextEngineID.c_str());
	long authProtocol = params.nAuthProtocol;
	long privProtocol = params.nPrivProtocol;
	//v3MP *v3_MP;

	//---------[ init SnmpV3 ]--------------------------------------------
	//QString strEngineId;

	//char strEngineId[256];

	//strcpy(strEngineId, "snmpGet");

	//const char* strFileName = "snmpv3_boot_counter";
	//unsigned int snmpEngineBoots = 0;

	//status = getBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
	//if ((status != SNMPv3_OK) && (status < SNMPv3_FILEOPEN_ERROR))
	//{
	//	Snmp::socket_cleanup();
	//	return false;
	//}
	//snmpEngineBoots++;
	//status = saveBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
	//if (status != SNMPv3_OK)
	//{
	//	Snmp::socket_cleanup();
	//	return false;
	//}

	//int construct_status;
	////v3_MP = new v3MP((const char*)strEngineId, snmpEngineBoots, construct_status);
	//v3MP v3_MP((const char*)strEngineId, snmpEngineBoots, construct_status);
	//if (construct_status != SNMPv3_MP_OK)
	//{
	//	//delete v3_MP;
	//	Snmp::socket_cleanup();
	//	return false;
	//}

	//USM *usm = v3_MP.get_usm();
	USM *usm = SNMPSession::v3_MP->get_usm();
	usm->add_usm_user(securityName,
		authProtocol, privProtocol,
		authPassword, privPassword);

	utarget.set_version(version);          // set the SNMP version SNMPV1 or V2 or V3
	utarget.set_retry(retries);            // set the number of auto retries
	utarget.set_timeout(timeout);          // set timeout
	utarget.set_security_model(securityModel);
	utarget.set_security_name(securityName);
	pdu.set_security_level(securityLevel);
	pdu.set_context_name(contextName);
	pdu.set_context_engine_id(contextEngineID);
	target = &utarget;


	if (m_status != SNMP_CLASS_SUCCESS)
	{
		//delete v3_MP;
		Snmp::socket_cleanup();
		return false;//snmp初始化失败
	}
	m_IPList.clear();
	//	writeLog("start Query Printers");
	for (auto item : strIPAdress)
	{
		if (strIPAdress.contains("255"))
		{
			continue;
		}
		//	writeLog("Printers:" + item);
		QByteArray addressarray = item.toLatin1();
		UdpAddress address(addressarray.data());
		utarget.set_address(address);

		qDebug() << "m_snmp->get start";
		int ret = m_snmp->get(pdu, *target, &SNMPSession::sessionV3Callback, &ipList);
		qDebug() << "m_snmp->get end";
		if (ret != SNMP_CLASS_SUCCESS) {
			Sleep(5);
			continue;
		}
		Sleep(5);
	}

	//delete v3_MP;
	Snmp::socket_cleanup();
	Sleep(nOverTime * 1000 + 1000);
	ipList = m_IPList;
	//	writeLog("End Query Printers total:"+QString::number(ipList.size()));
	return true;
}

void SNMPSession::sessionCallback(int reason, Snmp_pp::Snmp* session, Pdu& pdu, SnmpTarget& target, void* data)
{
	//	writeLog("sessionCallback");
	Q_UNUSED(session)
		Q_UNUSED(target)

		if (SNMP_CLASS_TIMEOUT == reason)
		{
			qDebug() << target.get_address().get_printable() << "\n";
			return;
		}
	if (SNMP_CLASS_ASYNC_RESPONSE == reason)
	{
		Vb vb;
		QString m_ret;
		QString OID;
		QString strValue;
		QList<QString>* ipList = static_cast<QList<QString>*>(data);

		for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
		{
			pdu.get_vb(vb, vbi);
			/*if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
			&& (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
			;//continue;//只显示要求OID的内容*/
			m_ret += ("Oid = ");
			m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
			m_ret += ("\r\n");
			if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
			{
				m_ret += ("Value = ");
				m_ret += QString::fromLocal8Bit(vb.get_printable_value());
				strValue = QString::fromLocal8Bit(vb.get_printable_value());
				QString strEntry = strValue.right(1);
				if (strEntry.toInt() == 5)
				{
					UdpAddress address;
					GenAddress strAddress = target.get_address();
					QString strIP = strAddress.get_printable();
					m_IPList.push_back(strIP.left(strIP.indexOf("/")));
				}
				m_ret += ("\r\n");
			}
			else
			{
				m_ret += ("End of MIB view.\r\n");
			}
		}
	}
}


void SNMPSession::sessionV3Callback(int reason, Snmp_pp::Snmp* session, Pdu& pdu, SnmpTarget& target, void* data)
{
	//	writeLog("sessionCallback");
	Q_UNUSED(session)
		Q_UNUSED(target)

		if (SNMP_CLASS_TIMEOUT == reason)
		{
			qDebug() << target.get_address().get_printable() << "\n";
			return;
		}
	if (SNMP_CLASS_ASYNC_RESPONSE == reason)
	{
		Vb vb;
		QString m_ret;
		QString OID;
		QString strValue;
		QList<QString>* ipList = static_cast<QList<QString>*>(data);

		for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
		{
			pdu.get_vb(vb, vbi);
			/*if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
			&& (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
			;//continue;//只显示要求OID的内容*/
			m_ret += ("Oid = ");
			m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
			m_ret += ("\r\n");
			if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
			{
				m_ret += ("Value = ");
				m_ret += QString::fromLocal8Bit(vb.get_printable_value());
				strValue = QString::fromLocal8Bit(vb.get_printable_value());
				QString strEntry = strValue.right(1);

				UdpAddress address;
				GenAddress strAddress = target.get_address();
				QString strIP = strAddress.get_printable();
				m_IPList.push_back(strIP.left(strIP.indexOf("/")));

				m_ret += ("\r\n");
			}
			else
			{
				m_ret += ("End of MIB view.\r\n");
			}
		}
	}
}

