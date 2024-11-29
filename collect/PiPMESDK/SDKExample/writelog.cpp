#include "writelog.h"



WriteLog::WriteLog()
{
}


WriteLog::~WriteLog()
{
}

void WriteLog::writeToLog(QString txt)
{
#ifdef Q_OS_WIN32
	/*QString regPath = "HKEY_LOCAL_MACHINE\\Software\\Pantum\\PiPME\\settings";
	QSettings regSetting(regPath, QSettings::Registry32Format);
	QString path = regSetting.value("InstallPath", "").toString();
	QFile outFile(path + "\\Pantum Intelligent Printer Management Expert Log\\PiPMESDKLog.txt");*/
	QFile outFile("C:\\Users\\Public\\pipme\\pipmesdk\\log.txt");
	if (outFile.open(QIODevice::WriteOnly | QIODevice::Append))
	{
		QString log = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + ": " + txt + "\r\n";
		outFile.write(log.toLocal8Bit());
		outFile.close();
	}
#endif
}