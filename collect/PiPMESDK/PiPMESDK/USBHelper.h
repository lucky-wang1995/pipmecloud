#pragma once
#include "QString"
#include "QStringList"
#include "datatype.h"



class USBHelper
{
public:
	USBHelper();
	~USBHelper();

public:

	QueryResult getUSBPrinterInfo(QString strIPAdress, QByteArray& info);
};

