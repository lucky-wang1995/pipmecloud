#include "cdbhelper.h"
#include "QDebug"
#include "QSqlError"
#include "QStandardPaths"

CDBHelper::CDBHelper()
{
	
}

QSqlDatabase CDBHelper::m_dataBase;
CDBHelper::~CDBHelper()
{

}

QMap<QString, QMap<int, ErrorCodeMapping>> CDBHelper::m_mapErrorMapping;
QMap<QString, QMap<int, StatusCodeMapping>> CDBHelper::m_mapStatusMapping;


bool getSDKPath(QString ModuleName,QString& path)
{
#ifdef Q_OS_WIN
	const char* strModuleName = ModuleName.toLocal8Bit().constData();
	HANDLE hDllhandle = GetModuleHandleA("PiPMESDK.dll");//获取当前模块句柄
	if (hDllhandle == NULL)
	{
		return false;
	}
	char buff[MAX_PATH];
	memset(buff, 0, MAX_PATH);
	GetModuleFileNameA((HMODULE)hDllhandle, buff, MAX_PATH);//获取当前模块句柄路径

	for (INT i = strlen(buff) - 1; i > 0; i--)
	{
		if (buff[i] == '\\' || buff[i] == '/')
		{
			//最后一个'\\'或'/'消去
			buff[i] = '\0';
			break;
		}
		buff[i] = '\0';
	}

    path = QString::fromLocal8Bit(buff);
    return true;
#elif defined (Q_OS_LINUX)
    size_t size = 256;
    char *buf = (char*)malloc(size);
    char *end;
    memset(buf, 0, size);
    if(getcwd(buf, size) == NULL)
    {
        return false;
    }
    path = QString::fromStdString(buf);
    delete buf;
    return true;
#endif
}

bool CDBHelper::init()
{
    QString strPath;
#ifdef Q_OS_WIN
    bool bRet = getSDKPath("PiPMESDK.dll", strPath);
#elif defined (Q_OS_LINUX)
    bool bRet = getSDKPath("libpipmesdk.so", strPath);  //PiPMESDK.dll
#endif
    QString dbname = strPath + QString("/config.dll");
    m_dataBase = QSqlDatabase::addDatabase("QSQLITE");
    m_dataBase.setDatabaseName(dbname);

	QueryResult ret = loadErrorCodeMapping();
	if (ret != QueryResult::Successed)
	{
		return false;
	}
	ret = loadStatusCodeMapping();
	if (ret != QueryResult::Successed)
	{
		return false;
	}
	return true;
}

QueryResult CDBHelper::getBrandBaseInfoByBrandOID(QString strBrandOID, PrinterBaseInfo& baseinfo)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select a.PrinterModelOID,a.PrinterSNOID,a.method,b.strBrandName from tab_brand_oid a \
					left join \
					tab_brand b \
					on a.BrandID = b.autoid \
					where a.BrandOID = :BrandOID";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":BrandOID", strBrandOID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	if (query.next())
	{
		baseinfo.strBrand = query.value("strBrandName").toString();
		baseinfo.strModel = query.value("PrinterModelOID").toString();
		baseinfo.strPrinterSN = query.value("PrinterSNOID").toString();
		baseinfo.nMethod = query.value("method").toInt();
	}
	else
	{
		return QueryResult::querynodata;
	}
	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getBrandMib(QString strBrandOID, BrandMIB& bmib)
{
	return QueryResult::Successed;
}
QueryResult CDBHelper::getPrinterMib(QString strPModel, PrinterAdvancedInfo& adinfo)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select a.*,b.strBrandName from tab_printer_baseinfo a\
					left join\
					tab_brand b\
					on a.nBrand = b.autoid \
					where a.strPrinterModel = :PrinterModel";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":PrinterModel", strPModel);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	if (query.next())
	{
		adinfo.nPrinterID = query.value("autoid").toInt();
		adinfo.strModel = query.value("strPrinterModel").toString();
		adinfo.nPrinterSize = query.value("nPrintSizeType").toInt();
		adinfo.nPrinterColor = query.value("nPrintColorType").toInt();
		adinfo.nDrumCount = query.value("nDrumCount").toInt();
		adinfo.nTonerCount = query.value("nTonerCount").toInt();
		adinfo.nRollerCount = query.value("nRoller").toInt();
		adinfo.nFuserCount = query.value("nFuser").toInt();
	}
	else
	{
		m_dataBase.close();
		return QueryResult::querynodata;
	}
	m_dataBase.close();
	return QueryResult::Successed;
}


QueryResult CDBHelper::getPrinterBaseInfoByModel(QString strPModel, PrinterBaseInfo& baseinfo)
{
	return QueryResult::Successed;
}
QueryResult CDBHelper::getPrinterAdvancedInfo(int nPrinterID, PrinterAdvancedInfo& adInfo)
{
	return QueryResult::Successed;
}

QueryResult CDBHelper::getPrinterDrumInfo(int nPrinterID, QList<PrinterDrum>& listPrinterDrum)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select * from tab_printer_drum where printerID = :printerID";
					
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	while (query.next())
	{
		PrinterDrum drum;

		drum.nDrumID = query.value("DrumID").toInt();
		drum.nMax = query.value("DrumMax").toInt();
		drum.strDrumName = query.value("DrumNameEn").toString() + "|" + query.value("DrumNameCn").toString();
		drum.strQueryCurrentOID = query.value("qRestOID").toString();
		drum.DrumModel = query.value("DrumModel").toString();
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getPrinterFuserInfo(int nPrinterID, QList<PrinterFuser>& listPrinterFuser)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select * from tab_printer_fuser where printerID = :printerID";

	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	while (query.next())
	{
		PrinterFuser Fuser;

		Fuser.nFuserID = query.value("FuserID").toInt();
		Fuser.strFuserName = query.value("FuserNameEn").toString() + "|" + query.value("FuserNameCn").toString();
		Fuser.strQueryCurrentOID = query.value("qRestOID").toString();
		Fuser.strFuserModel = query.value("FuserModel").toString();
		Fuser.nMax = query.value("FuserMax").toInt();
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getPrinterPCountInfo(int nPrinterID, QList<PrinterPCount>& listPrinterPCount)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select * from tab_printer_pcount where printerID = :printerID";

	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	while (query.next())
	{
		PrinterPCount pCount;

		pCount.nColorType = query.value("colortype").toInt();
		pCount.nPaperType = query.value("papertype").toInt();
		pCount.strNameCn = query.value("pCountNameCn").toString();
		pCount.strNameEn = query.value("pCountNameEn").toString();
		pCount.strQueryOID = query.value("qQueryOID").toString();
		listPrinterPCount.push_back(pCount);
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getPrinterTonerInfo(int nPrinterID, QList<PrinterToner>& listPrinterToner)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select * from tab_printer_toner where printerID = :printerID";

	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	while (query.next())
	{
		PrinterToner pToner;

		pToner.nTonerID = query.value("TonerID").toInt();
		pToner.nColorType = query.value("ColorType").toInt();
		pToner.strTonerName = query.value("TonerNameCn").toString() + "|" + query.value("TonerNameEn").toString();
		pToner.nMax = query.value("TonerLife").toInt();
		pToner.TonerModel = query.value("TonerModel").toString();
		pToner.strQueryCurrentOID = query.value("qRestOID").toString();
		pToner.strQueryMaxOID = query.value("qMaxOID").toString();
		listPrinterToner.push_back(pToner);
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getPrinterWastTonerInfo(int nPrinterID, QList<PrinterWasteToner>& listPrinterToner)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}

	QString sql = "select * from tab_printer_wastetoner where printerID = :printerID";

	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	while (query.next())
	{
		PrinterWasteToner pToner;

		pToner.nWasteTonerID = query.value("TonerID").toInt();
		pToner.nColorType = query.value("ColorType").toInt();
		pToner.strWasteTonerName = query.value("TonerNameCn").toString() + "|" + query.value("TonerNameEn").toString();
		pToner.nMax = query.value("TonerLife").toInt();
		pToner.strWasteTonerModel = query.value("TonerModel").toString();
		pToner.strQueryCurrentOID = query.value("qRestOID").toString();
		pToner.strQueryMaxOID = query.value("qMaxOID").toString();
		listPrinterToner.push_back(pToner);
	}
}

QueryResult CDBHelper::getQueryErrorOID(int nPrinterID, PrinterErrorOID& ErrorOID)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select * from tab_error_oid where printerID = :printerID";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":printerID", nPrinterID);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	if (query.next())
	{
		ErrorOID.nPrinterID = query.value("printerid").toInt();
		ErrorOID.strStatusOID = query.value("qStatusOID").toString();
		ErrorOID.strErrorOID = query.value("qErrorOID").toString();
		ErrorOID.strShellOpenOID = query.value("qShellOpenOID").toString();
		ErrorOID.strTonerErrorOID = query.value("qTonerErrorOID").toString();
		ErrorOID.strNoPaperOID = query.value("qNoPaperOID").toString();
		ErrorOID.strPaperJamOID = query.value("qPaperJamOID").toString();
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getErrorString(int nErrorCode, QString strBrandOID, QString& strErrorString)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select * from tab_error where ErrorCode = :ErrorCode";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":ErrorCode", nErrorCode);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	if (query.next())
	{
		strErrorString = query.value("ErrorStringEn").toString() + "|" + query.value("ErrorStringCn").toString();
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getStatusString(int StatusCode, QString& strErrorString)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select * from tab_status where StatusCode = :StatusCode";
	QSqlQuery query;
	query.prepare(sql);
	query.bindValue(":StatusCode", StatusCode);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}

	if (query.next())
	{
		strErrorString = query.value("StatusStringEn").toString() + "|" + query.value("StatusStringCn").toString();
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

int CDBHelper::getMappingErrorCode(QString strBrandOID, int nErrorCode)
{
	QMap<QString, QMap<int, ErrorCodeMapping>>::iterator itor1 = m_mapErrorMapping.find(strBrandOID);
	if (itor1 == m_mapErrorMapping.end())
	{
		return -1;
	}
	QMap<int, ErrorCodeMapping>::iterator itor2 = itor1->find(nErrorCode);
	if (itor2 == itor1->end())
	{
		return -1;
	}
	return itor2->nMappingCode;
}
int CDBHelper::getMappingStatusCode(QString strBrandOID, int nStatusCode)
{
	QMap<QString, QMap<int, StatusCodeMapping>>::iterator itor1 = m_mapStatusMapping.find(strBrandOID);
	if (itor1 == m_mapStatusMapping.end())
	{
		return -1;
	}
	QMap<int, StatusCodeMapping>::iterator itor2 = itor1->find(nStatusCode);
	if (itor2 == itor1->end())
	{
		return -1;
	}
	return itor2->nMappingCode;
}

QueryResult CDBHelper::loadErrorCodeMapping()
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select * from tab_error_mapping";
	QSqlQuery query(m_dataBase);
	query.prepare(sql);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}


	while (query.next())
	{
		ErrorCodeMapping ecm;
		ecm.strBrandOID = query.value("BrandOID").toString();
		ecm.nErrorCode = query.value("ErrorCode").toInt();
		ecm.nMappingCode = query.value("MappingErrorCode").toInt();

		QMap<QString, QMap<int, ErrorCodeMapping>>::iterator itor1 = m_mapErrorMapping.find(ecm.strBrandOID);
		if (itor1 == m_mapErrorMapping.end())
		{
			QMap<int, ErrorCodeMapping> ecmMap;
			ecmMap.insert(ecm.nErrorCode, ecm);
			m_mapErrorMapping.insert(ecm.strBrandOID, ecmMap);
		}
		else
		{
			itor1->insert(ecm.nErrorCode, ecm);
		}
	}

	m_dataBase.close();
	return QueryResult::Successed;
}
QueryResult CDBHelper::loadStatusCodeMapping()
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select * from tab_status_mapping";
	QSqlQuery query;
	query.prepare(sql);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}


	while (query.next())
	{
		StatusCodeMapping scm;
		scm.strBrandOID = query.value("BrandOID").toString();
		scm.nStatusCode = query.value("StatusCode").toInt();
		scm.nMappingCode = query.value("MappingStatusCode").toInt();

		QMap<QString, QMap<int, StatusCodeMapping>>::iterator itor1 = m_mapStatusMapping.find(scm.strBrandOID);
		if (itor1 == m_mapStatusMapping.end())
		{
			QMap<int, StatusCodeMapping> scmMap;
			scmMap.insert(scm.nStatusCode, scm);
			m_mapStatusMapping.insert(scm.strBrandOID, scmMap);
		}
		else
		{
			itor1->insert(scm.nStatusCode, scm);
		}
	}

	m_dataBase.close();
	return QueryResult::Successed;
}

QueryResult CDBHelper::getSupportPrinterModel(QList<QString>& listPrinterModels)
{
	if (!m_dataBase.open())
	{
		return QueryResult::openDBfailed;
	}
	QString sql = "select strPrinterModel from tab_printer_baseinfo";
	QSqlQuery query;
	query.prepare(sql);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		m_dataBase.close();
		return QueryResult::execSqlfailed;
	}
	while (query.next())
	{
		QString printerModel = query.value("strPrinterModel").toString();
		listPrinterModels.push_back(printerModel);
	}
	m_dataBase.close();
	return QueryResult::Successed;
}
