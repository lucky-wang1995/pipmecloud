#include "writelog.h"



WriteLog::WriteLog()
{
}


WriteLog::~WriteLog()
{
}

void WriteLog::writeToLog(QString txt)
{
    QString logPath;
    QString logFilePath;
    QString logName = QString("pipmesdk%1.txt").arg(QDateTime::currentDateTime().toString("yyyyMMdd"));
#ifdef Q_OS_WIN32
//    QString systemPath = QDir::rootPath();
//    logPath = systemPath + "Users\\Public\\PiPMECloud\\pipmesdk\\";
//    logFilePath = logPath + logName;

    logPath = QCoreApplication::applicationDirPath() + "\\PiPMECloud\\pipmesdk\\";
    logFilePath = logPath + logName;
#else   //linux
    logPath = "/var/log/PIPMECloud/pipmesdk/";
    logFilePath = logPath + logName;
#endif
    QDir dir;
    if(!dir.exists(logPath))
    {
        dir.mkpath(logPath);
    }
    QFile outFile(logFilePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QString log = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + ": " + txt + "\r\n";
        outFile.write(log.toLocal8Bit());
        outFile.close();
    }
}

void WriteLog::writeBaseInfo(PrinterBaseInfo info)
{
	writeToLog("strBrand: " + info.strBrand);
	writeToLog("strModel: " + info.strModel);
	writeToLog("strPrinterSN: " + info.strPrinterSN);
	writeToLog("strIPaddress: " + info.strIPaddress);
	writeToLog("strBrandOID: " + info.strBrandOID);
}

void WriteLog::writeDetailInfo(PrinterDetailInfo info)
{
	writeBaseInfo(info.baseinfo);
	writeToLog("Core: " + info.Core);
	writeToLog("strFirmeWire: " + info.baseinfo.strFirmeWire);
	writeToLog("nPrinterStatus: " + QString::number(info.baseinfo.nPrinterStatus));
	writeAdvanceInfo(info.adInfo);
	writeErrorInfo(info.listPrinterError);
	writeTonerInfo(info.listTonerDetail);
	writeDrumInfo(info.listDrumDetail);
	writeWasteTonerInfo(info.listWasteTonerDetail);
	writPCountInfo(info.listPCountDetail);
}

void WriteLog::writeAdvanceInfo(PrinterAdvancedInfo adInfo)
{
	writeToLog("ePColorType: " + QString::number(adInfo.nPrinterColor));
	writeToLog("ePSizeType: " + QString::number(adInfo.nPrinterSize));
	writeToLog("Toners: " + adInfo.toners);
	writeToLog("Drum: " + adInfo.drum);
	writeToLog("wasteToner: " + adInfo.wasteToner);
}

void WriteLog::writeErrorInfo(QList<PrinterMIBError> listPrinterError)
{
	for (int i = 0; i < listPrinterError.count(); i++)
	{
		writeToLog("nErrorCode: " + QString::number(listPrinterError.at(i).nErrorCode));
		writeToLog("strErrorString: " + listPrinterError.at(i).ErrorDesc);
		writeToLog("strErrorStringEn: " + listPrinterError.at(i).ErrorDescEN);
		writeToLog("nErrorLevel: " + listPrinterError.at(i).nErrorLevel);
		writeToLog("");
	}
}

void WriteLog::writeTonerInfo(QList<PrinterToner> listToner)
{
	for (int i = 0; i < listToner.count(); i++)
	{
		writeToLog("strTonerName: " + listToner.at(i).strTonerName);
		writeToLog("strTonerID: " + QString::number(listToner.at(i).nTonerID));
		writeToLog("strTonerModel: " + listToner.at(i).TonerModel);
		writeToLog("strTonerSN: " + listToner.at(i).strTonerSN);
		writeToLog("strTonerColor: " + QString::number(listToner.at(i).nColorType));
		writeToLog("strTonerRest: " + QString::number(listToner.at(i).nCurrent));
		writeToLog("");
	}
}

void WriteLog::writeDrumInfo(QList<PrinterDrum> listDrum)
{
	for (int i = 0; i < listDrum.count(); i++)
	{
		writeToLog("strDrumName: " + listDrum.at(i).strDrumName);
		writeToLog("strDrumID: " + QString::number(listDrum.at(i).nDrumID));
		writeToLog("strDrumModel: " + listDrum.at(i).DrumModel);
		writeToLog("strDrumSN: " + listDrum.at(i).DrumSN);
		writeToLog("strDrumColor: " + QString::number(listDrum.at(i).nColorType));
		writeToLog("strDrumRest: " + QString::number(listDrum.at(i).nCurrent));
		writeToLog("");
	}
}

void WriteLog::writeWasteTonerInfo(QList<PrinterWasteToner> listWasteToner)
{
	for (int i = 0; i < listWasteToner.count(); i++)
	{
		writeToLog("strWasteTonerName: " + listWasteToner.at(i).strWasteTonerName);
		writeToLog("strWasteTonerID: " + QString::number(listWasteToner.at(i).nWasteTonerID));
		writeToLog("strWasteTonerModel: " + listWasteToner.at(i).strWasteTonerModel);
		writeToLog("strWasteTonerSN: " + listWasteToner.at(i).strWasteTonerSN);
		writeToLog("strWasteTonerColor: " + QString::number(listWasteToner.at(i).nColorType));
		writeToLog("strWasteTonerRest: " + QString::number(listWasteToner.at(i).nCurrent));
		writeToLog("");
	}
}

void WriteLog::writPCountInfo(QList<PrinterPCount> listPCount)
{
	for (int i = 0; i < listPCount.count(); i++)
	{
		writeToLog("strCounterName: " + listPCount.at(i).strNameCn);
		writeToLog("nPaperSize: " + QString::number(listPCount.at(i).nPaperType));
		writeToLog("ncolor: " + QString::number(listPCount.at(i).nColorType));
		writeToLog("ncount: " + QString::number(listPCount.at(i).nPCount));
		writeToLog("");
	}
}
