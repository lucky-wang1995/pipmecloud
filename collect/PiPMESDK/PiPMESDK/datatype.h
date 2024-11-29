#ifndef DATATYPE_H
#define DATATYPE_H
#include "QString"
#include "QList"

enum class QueryMethod
{
	get,
	getNext,
	getBulk
};

struct MibValue
{
	QString strOID;
	QString strValue;
};

enum class QueryResult
{
	Successed,
	snmpOverTime,
	Unsupported,
	InsufficientBuffer,
	invalidIPAddr,
	initSnmpFailed,
	invalidOIDValue,
	openDBfailed,
	execSqlfailed,
	querynodata,
	openIniFailed
};

struct ErrorCodeMapping
{
	ErrorCodeMapping()
	{
		nErrorCode = 0;
		nMappingCode = 0;
	}
	QString strBrandOID;
	int nErrorCode;
	int nMappingCode;
};

struct StatusCodeMapping
{
	StatusCodeMapping()
	{
		nStatusCode = 0;
		nMappingCode = 0;
	}
	QString strBrandOID;
	int nStatusCode;
	int nMappingCode;
};

struct PrinterDrum
{
	PrinterDrum()
	{
		nDrumID = 0;
		nMax = 0;
		nCurrent = 0;
		nColorType = 0;
	}
	int nDrumID;;
	QString strDrumName;
	int nMax;
	int nCurrent;
	int nColorType;
	QString DrumModel;
	QString DrumSN;
	 
	QString strQueryCurrentOID;
};
struct PrinterToner
{
	PrinterToner()
	{
		nTonerID = 0;
		nMax = 0;
		nCurrent = 0;
		nColorType = 0;
	}
	int nTonerID;
	QString strTonerName;
	int nMax;
	int nCurrent;
	int nColorType;
	QString TonerModel;
	QString strQueryCurrentOID;
	QString strQueryMaxOID;
	QString strTonerSN;
};

struct PrinterWasteToner
{
	PrinterWasteToner()
	{
		nWasteTonerID = 0;
		nMax = 0;
		nCurrent = 0;
		nColorType = 0;
	}
	int nWasteTonerID;
	QString strWasteTonerName;
	int nMax;
	int nCurrent;
	int nColorType;
	QString strWasteTonerModel;
	QString strWasteTonerSN;
	QString strQueryMaxOID;
	QString strQueryCurrentOID;
};
struct PrinterRoller
{
	PrinterRoller()
	{
		nRollerID = 0;
		nMax = 0;
		nCurrent = 0;
		nColorType = 0;
	}
	int nRollerID;
	QString strRollerName;
	int nMax;
	int nCurrent;
	int nColorType;
	QString strRollerModel;
	QString strQueryCurrentOID;
};
struct PrinterFuser
{
	PrinterFuser()
	{
		nFuserID = 0;
		nMax = 0;
		nCurrent = 0;
	}
	int nFuserID;
	QString strFuserName;
	int nMax;
	int nCurrent;
	QString strFuserModel;
	QString strQueryCurrentOID;
	QString strQueryModelOID;
};
struct PrinterPCount
{
	PrinterPCount()
	{
		nPCount = 0;
		nPaperType = 0;
		nColorType = 0;
	}
	QString strNameCn;
	QString strNameEn;
	QString strQueryOID;
	int nPCount;
	int nPaperType;
	int nColorType;
};


struct PrinterBaseInfo
{
	PrinterBaseInfo()
	{
		nPrinterID = 0;
		nMethod = -1;
		nPrinterStatus = 0;
		nSuggestCount = 3000;
	}
	int nPrinterID;
	QString strIPaddress;
	QString strBrand;
	QString strModel;
	QString strPrinterSN;
	QString strBrandOID;
	QString strFirmeWire;
	int nPrinterStatus;
	int nMethod;
	int nSuggestCount;

	QString toJson()
	{
		QString strJson;
		strJson.push_back("{"); strJson.push_back("\n");
		//基本信息
		strJson.push_back("\"version\":"); strJson.push_back("\""); strJson.push_back("0.2.6.4"); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strIPAddress\":"); strJson.push_back("\""); strJson.push_back(strIPaddress); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPBrand\":"); strJson.push_back("\""); strJson.push_back(strBrand); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPModel\":"); strJson.push_back("\""); strJson.push_back(strModel); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"nSuggestCount\":"); strJson.push_back("\""); strJson.push_back(QString::number(nSuggestCount)); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPSN\":"); strJson.push_back("\""); strJson.push_back(strPrinterSN); strJson.push_back("\""); strJson.push_back("\n");
		strJson.push_back("}");
		return strJson;
	}
};

struct BrandMIB 
{
	QString strStatusOID;
	int nStatusGet;
	QString strErrorOID;
	int nErrorGet;
	QString strDrumCountOID;

};

struct PrinterMIBError
{
	PrinterMIBError()
	{
		nErrorCode = 0;
		nErrorLevel = 0;
	}
	int nErrorCode;
	QString ErrorDesc;
	QString ErrorDescEN;
	int nErrorLevel;
};

struct PrinterAdvancedInfo
{
	PrinterAdvancedInfo()
	{
		strModel = "";
		nPrinterID = 0;
		nPrinterSize = 0;
		nPrinterColor = 0;
		nDrumCount = 0;
		nTonerCount = 0;
		nRollerCount = 0;
		nFuserCount = 0;
	}
	QString strModel;
	QString toners;
	QString drum;
	int nPrinterID;
	int nPrinterSize;
	int nPrinterColor;
	int nDrumCount;
	int nTonerCount;
	int nRollerCount;
	int nFuserCount;
	QString wasteToner;
};

struct PrinterErrorInfo
{
	PrinterErrorInfo()
	{
		nPrinterStatus = 0;
		strPrinterStatusString = "";
		nErrorCode = 0;
		strPrinterErrorString = "";
	}
	int nPrinterStatus;
	QString strPrinterStatusString;
	int nErrorCode;
	QString strPrinterErrorString;
};

struct PrinterErrorOID
{
	PrinterErrorOID()
	{
		nPrinterID = 0;
	}
	int nPrinterID;
	QString strStatusOID;
	QString strErrorOID;
	QString strfatalErrorOID;
	QString strShellOpenOID;
	QString strTonerErrorOID;
	QString strNoPaperOID;
	QString strPaperJamOID;
	QString strPapersizeOID;
	QString strPaperSourceOID;
};

struct PrinterDetailInfo
{
	PrinterDetailInfo()
	{
		nResult = -1;
	}
	PrinterBaseInfo baseinfo;
	PrinterAdvancedInfo adInfo;
	PrinterErrorInfo errorInfo;
	QList<PrinterDrum> listDrumDetail;
	QList<PrinterToner> listTonerDetail;
	QList<PrinterWasteToner> listWasteTonerDetail;
	QList<PrinterRoller> listRollerDetail;
	QList<PrinterFuser> listFuserDetail;
	QList<PrinterPCount> listPCountDetail;
	QList<PrinterMIBError> listPrinterError;
	QString Core;
	QString firmeware;
	QString UUID;
	int nResult;
	QString toJson()
	{
		QString strJson;
		strJson.push_back("{"); strJson.push_back("\n");
		//基本信息

		strJson.push_back("\"version\":"); strJson.push_back("\""); strJson.push_back("0.2.6.4"); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strIPAddress\":"); strJson.push_back("\""); strJson.push_back(baseinfo.strIPaddress); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPBrand\":"); strJson.push_back("\""); strJson.push_back(baseinfo.strBrand); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPModel\":"); strJson.push_back("\""); strJson.push_back(baseinfo.strModel); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"strPSN\":"); strJson.push_back("\""); strJson.push_back(baseinfo.strPrinterSN); strJson.push_back("\""); strJson.push_back(",\n");
        strJson.push_back("\"PrinterStatus\":"); strJson.push_back("\""); strJson.push_back(QString::number(baseinfo.nPrinterStatus)); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"nSuggestCount\":"); strJson.push_back("\""); strJson.push_back(QString::number(baseinfo.nSuggestCount)); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"Core\":"); strJson.push_back("\""); strJson.push_back(Core); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"FW\":"); strJson.push_back("\""); strJson.push_back(firmeware); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"UUID\":"); strJson.push_back("\""); strJson.push_back(UUID); strJson.push_back("\""); strJson.push_back(",\n");

		strJson.push_back("\"ePType\":"); strJson.push_back("1"); strJson.push_back(",\n");
		strJson.push_back("\"ePColorType\":"); strJson.push_back(QString::number(adInfo.nPrinterColor)); strJson.push_back(",\n");
		strJson.push_back("\"ePSizeType\":"); strJson.push_back(QString::number(adInfo.nPrinterSize)); strJson.push_back(",\n");
		strJson.push_back("\"Toners\":"); strJson.push_back("\""); strJson.push_back(adInfo.toners); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"Drums\":"); strJson.push_back("\""); strJson.push_back(adInfo.drum); strJson.push_back("\""); strJson.push_back(",\n");
		strJson.push_back("\"wasteToner\":"); strJson.push_back("\""); strJson.push_back(adInfo.wasteToner); strJson.push_back("\""); strJson.push_back(",\n");
		//状态及错误信息
		strJson.push_back("\"error\":"); strJson.push_back("{\n"); strJson.push_back("\n");
		strJson.push_back("\"data\":[");
		for (int i=0;i<listPrinterError.count();i++)
		{
			strJson.push_back("{"); strJson.push_back("\n");
			strJson.push_back("\"nErrorCode\":"); strJson.push_back(QString::number(listPrinterError.at(i).nErrorCode)); strJson.push_back(",\n");
			QString errordesc = listPrinterError.at(i).ErrorDesc;
			QString errordescEn = listPrinterError.at(i).ErrorDescEN;
			strJson.push_back("\"strErrorString\":"); strJson.push_back("\""); strJson.push_back(errordesc.replace("\"","")); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strErrorStringEn\":"); strJson.push_back("\""); strJson.push_back(errordescEn.replace("\"", "")); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"nErrorLevel\":"); strJson.push_back(QString::number(listPrinterError.at(i).nErrorLevel)); strJson.push_back("\n");
			strJson.push_back("}");
			if (i + 1 < listPrinterError.count())
			{
				strJson.push_back(",\n");
			}
		}
		strJson.push_back("]\n");
		strJson.push_back("\n}"); strJson.push_back(",\n");
		//硒鼓信息
		strJson.push_back("\"drum\":"); strJson.push_back("{\n"); strJson.push_back("\n");
		strJson.push_back("\"data\":[");
		for (int i=0;i< listDrumDetail.count();i++)
		{
			strJson.push_back("{"); strJson.push_back("\n");
			strJson.push_back("\"strDrumName\":"); strJson.push_back("\""); strJson.push_back(listDrumDetail.at(i).strDrumName); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strDrumID\":"); strJson.push_back(QString::number(listDrumDetail.at(i).nDrumID)); strJson.push_back(",\n");
			strJson.push_back("\"strDrumModel\":"); strJson.push_back("\""); strJson.push_back(listDrumDetail.at(i).DrumModel); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strDrumSN\":"); strJson.push_back("\""); strJson.push_back(listDrumDetail.at(i).DrumSN); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strDrumColor\":");strJson.push_back(QString::number(listDrumDetail.at(i).nColorType)); strJson.push_back(",\n");
			strJson.push_back("\"strDrumRest\":"); strJson.push_back(QString::number(listDrumDetail.at(i).nCurrent,'f',0)); strJson.push_back("\n");
			strJson.push_back("}");
			if (i + 1 < listDrumDetail.count())
			{
				strJson.push_back(",\n");
			}			
		}
		strJson.push_back("]\n}"); strJson.push_back(",\n");
		//墨盒信息
		strJson.push_back("\"Toner\":"); strJson.push_back("{\n"); strJson.push_back("\n");
		strJson.push_back("\"data\":[");
		for (int i=0;i<listTonerDetail.count();i++)
		{
			strJson.push_back("{"); strJson.push_back("\n");
			strJson.push_back("\"strTonerName\":"); strJson.push_back("\""); strJson.push_back(listTonerDetail.at(i).strTonerName); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strTonerID\":"); strJson.push_back(QString::number(listTonerDetail.at(i).nTonerID));strJson.push_back(",\n");
			strJson.push_back("\"strTonerModel\":"); strJson.push_back("\""); strJson.push_back(listTonerDetail.at(i).TonerModel); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strTonerSN\":"); strJson.push_back("\""); strJson.push_back(listTonerDetail.at(i).strTonerSN); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strTonerColor\":"); strJson.push_back(QString::number(listTonerDetail.at(i).nColorType));strJson.push_back(",\n");
			strJson.push_back("\"strTonerRest\":"); strJson.push_back(QString::number(listTonerDetail.at(i).nCurrent,'f',0)); strJson.push_back("\n");

			strJson.push_back("}");
			if (i + 1 < listTonerDetail.count())
			{
				strJson.push_back(",\n");
			}
		}
		strJson.push_back("]\n");
		strJson.push_back("\n}"); strJson.push_back(",\n");
		//印量信息
		strJson.push_back("\"Counter\":"); strJson.push_back("{\n"); strJson.push_back("\n");
		strJson.push_back("\"data\":[");
		for (int i=0;i<listPCountDetail.count();i++)
		{
			strJson.push_back("{"); strJson.push_back("\n");
			strJson.push_back("\"strCounterName\":"); strJson.push_back("\""); strJson.push_back(listPCountDetail.at(i).strNameCn + "|" + listPCountDetail.at(i).strNameEn); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"nPaperSize\":"); strJson.push_back(QString::number(listPCountDetail.at(i).nPaperType)); strJson.push_back(",\n");
			strJson.push_back("\"nColor\":"); strJson.push_back(QString::number(listPCountDetail.at(i).nColorType)); strJson.push_back(",\n");
			strJson.push_back("\"nCount\":"); strJson.push_back(QString::number(listPCountDetail.at(i).nPCount)); strJson.push_back("\n");
			strJson.push_back("}");
			if (i + 1 < listPCountDetail.count())
			{
				strJson.push_back(",\n");
			}
		}
		strJson.push_back("]\n}"); strJson.push_back(",\n");
		//废粉盒信息
		strJson.push_back("\"WasteToner\":"); strJson.push_back("{\n"); strJson.push_back("\n");
		strJson.push_back("\"data\":[");
		for (int i = 0; i < listWasteTonerDetail.count(); i++)
		{
			strJson.push_back("{"); strJson.push_back("\n");
			strJson.push_back("\"strWasteTonerName\":"); strJson.push_back("\""); strJson.push_back(listWasteTonerDetail.at(i).strWasteTonerName); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strWasteTonerID\":"); strJson.push_back(QString::number(listWasteTonerDetail.at(i).nWasteTonerID)); strJson.push_back(",\n");
			strJson.push_back("\"strWasteTonerModel\":"); strJson.push_back("\""); strJson.push_back(listWasteTonerDetail.at(i).strWasteTonerModel); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strWasteTonerSN\":"); strJson.push_back("\""); strJson.push_back(listWasteTonerDetail.at(i).strWasteTonerSN); strJson.push_back("\""); strJson.push_back(",\n");
			strJson.push_back("\"strWasteTonerColor\":"); strJson.push_back(QString::number(listWasteTonerDetail.at(i).nColorType)); strJson.push_back(",\n");
	
			strJson.push_back("\"strWasteTonerRest\":"); strJson.push_back(QString::number(listWasteTonerDetail.at(i).nCurrent, 'f', 0)); strJson.push_back("\n"); strJson.push_back("}");
			if (i + 1 < listWasteTonerDetail.count())
			{
				strJson.push_back(",\n");
			}
		}
		strJson.push_back("]\n}"); strJson.push_back("\n");
		strJson.push_back("}");

		return strJson;
	}
};

#endif//DATATYPE_H
