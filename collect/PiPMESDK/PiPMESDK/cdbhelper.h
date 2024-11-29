#ifndef CDBHELPER_H
#define CDBHELPER_H

#include "QSqlDatabase"
#include <QSqlQuery>
#include "QDebug"
#include "QDir"
#include "datatype.h"

#include "string.h"

#ifdef Q_OS_WIN
#include "qt_windows.h"
#else
#include "unistd.h"
#define Sleep(value) usleep(value * 1000);
#endif

using namespace std;


class CDBHelper
{
public:

	CDBHelper();
	~CDBHelper();

	static bool init();
private:

	static QSqlDatabase m_dataBase;
	
public:
	static QueryResult getBrandBaseInfoByBrandOID(QString strBrandOID, PrinterBaseInfo& baseinfo);
	static QueryResult getBrandMib(QString strBrandOID, BrandMIB& bmib);
	static QueryResult getPrinterMib(QString strPModel, PrinterAdvancedInfo& adinfo);
	static QueryResult getPrinterBaseInfoByModel(QString strPModel, PrinterBaseInfo& baseinfo);
	static QueryResult getPrinterAdvancedInfo(int nPrinterID,PrinterAdvancedInfo& adInfo);
	static QueryResult getPrinterDrumInfo(int nPrinterID,QList<PrinterDrum>& listPrinterDrum);

	static QueryResult getPrinterFuserInfo(int nPrinterID, QList<PrinterFuser> &listPrinterFuser);
	static QueryResult getPrinterPCountInfo(int nPrinterID,QList<PrinterPCount> &listPrinterPCount);
	static QueryResult getPrinterTonerInfo(int nPrinterID, QList<PrinterToner> &listPrinterToner);
	static QueryResult getPrinterWastTonerInfo(int nPrinterID, QList<PrinterWasteToner>& listPrinterToner);
	static QueryResult getQueryErrorOID(int nPrinterID,PrinterErrorOID &ErrorOID);
	static QueryResult getErrorString(int nErrorCode, QString strBrandOID, QString &strErrorString);
	static QueryResult getStatusString(int StatusCode, QString& strErrorString);
	static QueryResult getSupportPrinterModel(QList<QString> &listPrinterModels);

	static int getMappingErrorCode(QString strBrandOID,int nErrorCode);
	static int getMappingStatusCode(QString strBrandOID, int nStatusCode);

private:

	static QMap<QString, QMap<int, ErrorCodeMapping>> m_mapErrorMapping;
	static QMap<QString, QMap<int, StatusCodeMapping>> m_mapStatusMapping;

	static QueryResult loadErrorCodeMapping();
	static QueryResult loadStatusCodeMapping();
};

#endif //CDBHELPER_H
