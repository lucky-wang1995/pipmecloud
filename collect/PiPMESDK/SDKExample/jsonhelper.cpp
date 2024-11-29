#include "jsonhelper.h"
#include "QDebug"


JsonHelper::JsonHelper()
{

}
JsonHelper::~JsonHelper()
{

}

bool JsonHelper::syncPrinterBaseInfo(QString json)
{
	QJsonParseError parseJsonErr;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &parseJsonErr);
	if (!(parseJsonErr.error == QJsonParseError::NoError))
	{
		qDebug() << QStringLiteral("");//解析json文件错误！
		return false;
	}
	QJsonObject jsonObject = document.object();
	if (jsonObject.contains(QStringLiteral("strIPAddress")))
	{
		QJsonValue version_value = jsonObject.take("strIPAddress");
		if (version_value.isString())
		{
			QString strIPaddress = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPBrand")))
	{
		QJsonValue version_value = jsonObject.take("strPBrand");
		if (version_value.isString())
		{
			QString strBrand = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPModel")))
	{
		QJsonValue version_value = jsonObject.take("strPModel");
		if (version_value.isString())
		{
			QString strModel = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPSN")))
	{
		QJsonValue version_value = jsonObject.take("strPSN");
		if (version_value.isString())
		{
			QString strPrinterSN = version_value.toVariant().toString();
		}
	}
	return true;
}

bool JsonHelper::syscPrinterDetailInfo(QString json)
{
	QJsonParseError parseJsonErr;
	QJsonDocument document = QJsonDocument::fromJson(json.toUtf8(), &parseJsonErr);
	if (!(parseJsonErr.error == QJsonParseError::NoError))
	{
		qDebug() << QStringLiteral("");//解析json文件错误！
		return false;
	}
	QJsonObject jsonObject = document.object();
	if (jsonObject.contains(QStringLiteral("strIPAddress")))
	{
		QJsonValue version_value = jsonObject.take("strIPAddress");
		if (version_value.isString())
		{
			QString strIPaddress = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPBrand")))
	{
		QJsonValue version_value = jsonObject.take("strPBrand");
		if (version_value.isString())
		{
			QString strBrand = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPModel")))
	{
		QJsonValue version_value = jsonObject.take("strPModel");
		if (version_value.isString())
		{
			QString strModel = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("strPSN")))
	{
		QJsonValue version_value = jsonObject.take("strPSN");
		if (version_value.isString())
		{
			QString strPrinterSN = version_value.toVariant().toString();
		}
	}
	if (jsonObject.contains(QStringLiteral("error")))
	{
		QJsonValue Error_value = jsonObject.take("error");
		if (Error_value.isObject())
		{
			QJsonObject Error_Obj = Error_value.toObject();
			if (Error_Obj.contains("data"))
			{
				QJsonValue data_value = Error_Obj.take("data");
				if (data_value.isArray())
				{
					QJsonArray data_array = data_value.toArray();
					for (int i = 0; i< data_array.size();i++)
					{
						QJsonValue arrayValue = data_array.at(i);
						if (arrayValue.isObject())
						{

							QJsonObject ErrorItem = arrayValue.toObject();
							if (ErrorItem.contains("nErrorCode"))
							{
								QJsonValue v = ErrorItem.take("nErrorCode");
								int n = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strErrorString"))
							{
								QJsonValue v = ErrorItem.take("strErrorString");
								QString errorString = v.toVariant().toString();
							}
							if (ErrorItem.contains("nErrorLevel"))
							{
								QJsonValue v = ErrorItem.take("nErrorLevel");
								int n = v.toVariant().toInt();
							}
						}
					}
				}
			}
		}
	}
	if (jsonObject.contains(QStringLiteral("drum")))
	{
		QJsonValue Error_value = jsonObject.take("drum");
		if (Error_value.isObject())
		{
			QJsonObject Error_Obj = Error_value.toObject();
			if (Error_Obj.contains("data"))
			{
				QJsonValue data_value = Error_Obj.take("data");
				if (data_value.isArray())
				{
					QJsonArray data_array = data_value.toArray();
					for (int i = 0; i < data_array.size(); i++)
					{
						QJsonValue arrayValue = data_array.at(i);
						if (arrayValue.isObject())
						{

							QJsonObject ErrorItem = arrayValue.toObject();
							if (ErrorItem.contains("strDrumName"))
							{
								QJsonValue v = ErrorItem.take("strDrumName");
								int n = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strDrumModel"))
							{
								QJsonValue v = ErrorItem.take("strDrumModel");
								QString errorString = v.toVariant().toString();
							}
							if (ErrorItem.contains("strDrumColor"))
							{
								QJsonValue v = ErrorItem.take("strDrumColor");
								int n = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strDrumRest"))
							{
								QJsonValue v = ErrorItem.take("strDrumRest");
								int n = v.toVariant().toInt();
							}
						}
					}
				}
			}
		}
	}
	if (jsonObject.contains(QStringLiteral("Toner")))
	{
		QJsonValue Error_value = jsonObject.take("Toner");
		if (Error_value.isObject())
		{
			QJsonObject Error_Obj = Error_value.toObject();
			if (Error_Obj.contains("data"))
			{
				QJsonValue data_value = Error_Obj.take("data");
				if (data_value.isArray())
				{
					QJsonArray data_array = data_value.toArray();
					for (int i = 0; i < data_array.size(); i++)
					{
						QJsonValue arrayValue = data_array.at(i);
						if (arrayValue.isObject())
						{

							QJsonObject ErrorItem = arrayValue.toObject();
							if (ErrorItem.contains("strTonerName"))
							{
								QJsonValue v = ErrorItem.take("strTonerName");
								QString strTonerName = v.toVariant().toString();
							}
							if (ErrorItem.contains("strTonerID"))
							{
								QJsonValue v = ErrorItem.take("strTonerID");
								int n = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strTonerModel"))
							{
								QJsonValue v = ErrorItem.take("strTonerModel");
								QString strTonerModel = v.toVariant().toString();
							}
							if (ErrorItem.contains("strTonerSN"))
							{
								QJsonValue v = ErrorItem.take("strTonerSN");
								QString strTonerSN = v.toVariant().toString();
							}
							if (ErrorItem.contains("strTonerColor"))
							{
								QJsonValue v = ErrorItem.take("strTonerColor");
								int n = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strTonerRest"))
							{
								QJsonValue v = ErrorItem.take("strTonerRest");
								int n = v.toVariant().toInt();
							}
						}
					}
				}
			}
		}
	}
	if (jsonObject.contains(QStringLiteral("Counter")))
	{
		QJsonValue Error_value = jsonObject.take("Counter");
		if (Error_value.isObject())
		{
			QJsonObject Error_Obj = Error_value.toObject();
			if (Error_Obj.contains("data"))
			{
				QJsonValue data_value = Error_Obj.take("data");
				if (data_value.isArray())
				{
					QJsonArray data_array = data_value.toArray();
					for (int i = 0; i < data_array.size(); i++)
					{
						QJsonValue arrayValue = data_array.at(i);
						if (arrayValue.isObject())
						{

							QJsonObject ErrorItem = arrayValue.toObject();
							if (ErrorItem.contains("strCounterName"))
							{
								QJsonValue v = ErrorItem.take("strCounterName");
								QString strCounterName = v.toVariant().toString();
							}
							if (ErrorItem.contains("nPaperSize"))
							{
								QJsonValue v = ErrorItem.take("nPaperSize");
								int nPaperSize = v.toVariant().toInt();
							}
							if (ErrorItem.contains("nColor"))
							{
								QJsonValue v = ErrorItem.take("nColor");
								int nColor = v.toVariant().toInt();
							}
							if (ErrorItem.contains("nCount"))
							{
								QJsonValue v = ErrorItem.take("nCount");
								int nCount = v.toVariant().toInt();
							}							
						}
					}
				}
			}
		}
	}
	if (jsonObject.contains(QStringLiteral("WasteToner")))
	{
		QJsonValue Error_value = jsonObject.take("WasteToner");
		if (Error_value.isObject())
		{
			QJsonObject Error_Obj = Error_value.toObject();
			if (Error_Obj.contains("data"))
			{
				QJsonValue data_value = Error_Obj.take("data");
				if (data_value.isArray())
				{
					QJsonArray data_array = data_value.toArray();
					for (int i = 0; i < data_array.size(); i++)
					{
						QJsonValue arrayValue = data_array.at(i);
						if (arrayValue.isObject())
						{

							QJsonObject ErrorItem = arrayValue.toObject();
							if (ErrorItem.contains("strWasteTonerName"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerName");
								QString strCounterName = v.toVariant().toString();
							}
							if (ErrorItem.contains("strWasteTonerID"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerID");
								int strWasteTonerID = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strWasteTonerModel"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerModel");
								QString strWasteTonerModel = v.toVariant().toString();
							}
							if (ErrorItem.contains("strWasteTonerSN"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerSN");
								QString strWasteTonerSN = v.toVariant().toString();
							}
							if (ErrorItem.contains("strWasteTonerColor"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerColor");
								int strWasteTonerColor = v.toVariant().toInt();
							}
							if (ErrorItem.contains("strWasteTonerRest"))
							{
								QJsonValue v = ErrorItem.take("strWasteTonerRest");
								int strWasteTonerRest = v.toVariant().toInt();
							}
						}
					}
				}
			}
		}
	}
	return true;
}