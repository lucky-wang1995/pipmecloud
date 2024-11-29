#pragma once

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>


class JsonHelper
{
public:
	JsonHelper();
	~JsonHelper();


public:

	bool syncPrinterBaseInfo(QString json);

	bool syscPrinterDetailInfo(QString json);
};

