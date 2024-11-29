#pragma once

#include "qstring.h"
#include "qdatetime.h"
#include "qfile.h"
#include "datatype.h"
#include "qsettings.h"

#include <QDir>
#include <QFile>
#include <QCoreApplication>

class WriteLog
{
public:
	WriteLog();
	~WriteLog();

	static void writeToLog(QString txt);
	static void writeBaseInfo(PrinterBaseInfo info);
	static void writeDetailInfo(PrinterDetailInfo info);

	static void writeAdvanceInfo(PrinterAdvancedInfo adInfo);
	static void writeErrorInfo(QList<PrinterMIBError> listPrinterError);
	static void writeTonerInfo(QList<PrinterToner> listToner);
	static void writeDrumInfo(QList<PrinterDrum> listDrum);
	static void writeWasteTonerInfo(QList<PrinterWasteToner> listWasteToner);
	static void writPCountInfo(QList<PrinterPCount> listPCount);
};

