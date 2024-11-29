#pragma once

#include "qstring.h"
#include "qdatetime.h"
#include "qfile.h"
#include "qsettings.h"

class WriteLog
{
public:
	WriteLog();
	~WriteLog();

	static void writeToLog(QString txt);
};