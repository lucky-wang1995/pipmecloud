#include "csnmphelper.h"

#include "cdbhelper.h"

#include "queryprinterdetailinfo.h"
#include "QEventLoop"

//#define SNMPV3



CSnmpHelper::CSnmpHelper()
{
    m_strPrivPwd = "";
    m_strAuthPwd = "";
    m_strSecuName = "";
    m_strContextName = "";
    m_strContextEngineID = "";

    snmpsession = new SNMPSession();
    //loadV3Config();
}
CSnmpHelper::~CSnmpHelper()
{
    delete snmpsession;
}

void CSnmpHelper::loadSnmpv3Status(bool status)
{
    m_bSnmpv3 = status;
}

void CSnmpHelper::loadV3Config(SNMPARG params)
{
    m_nAuthProtocol = params.nAuthProtocol;
    m_nPrivProtocol = params.nPrivProtocol;
    m_nSecuLevel = params.nSecuLevel;
    m_strAuthPwd = QString::fromStdString(params.strAuthPwd);
    m_strPrivPwd = QString::fromStdString(params.strPrivPwd);
    m_strContextName = QString::fromStdString(params.strContextName);
    m_strContextEngineID = QString::fromStdString(params.strContextEngineID);
    m_strSecuName = QString::fromStdString(params.strSecuName);
    m_strCommunityName = QString::fromStdString(params.strCommunityName);

    //QString appPath = QCoreApplication::applicationDirPath();

    //QSettings iniFile(appPath + "/V3config.ini", QSettings::IniFormat);
    //iniFile.setIniCodec("UTF-8");
    //iniFile.beginGroup("SNMPV3");
    //m_nAuthProtocol = iniFile.value("authProtocol").toInt();
    //m_nPrivProtocol = iniFile.value("privProtocol").toInt();
    //m_nSecuLevel = iniFile.value("secuityLevel").toInt();
    //m_strAuthPwd = iniFile.value("authPassword").toString();
    //m_strPrivPwd = iniFile.value("privatePassword").toString();
    //m_strContextName = iniFile.value("contextName").toString();
    //m_strContextEngineID = iniFile.value("contextEngineId").toString();
    //iniFile.endGroup();
}

QueryResult CSnmpHelper::scanPrintersInNet(QStringList IPAddressList, QStringList& IPList, bool bSnmpv3Status, SnmpArg params)
{
    QStringList ipList;
    if (bSnmpv3Status)//snmpv3
    {
        snmpsession->getV3(IPAddressList, "1.3.6.1.2.1.25.3.2.1.2.1", 1, 10, 1, ipList, params);
    }
    else
    {
        snmpsession->get(IPAddressList, "1.3.6.1.2.1.25.3.2.1.2.1", 1, 10, 1, ipList, params);
    }
    
    IPList = ipList;

    return QueryResult::Successed;
}

QueryResult CSnmpHelper::getPrinterBaseInfo(QString strIPAddress, PrinterBaseInfo& info, int nOvertime, bool bSnmpv3Status, SnmpArg params)
{
    loadV3Config(params);
    m_bSnmpv3 = bSnmpv3Status;
    QString strBrandOID;
    WriteLog::writeToLog("******************getPrinterBaseInfo******************");
    WriteLog::writeToLog(strIPAddress);
    QueryResult nResult = getBrandOID(strIPAddress, strBrandOID, nOvertime);
    if (nResult != QueryResult::Successed)
    {
        WriteLog::writeToLog("getBrandOID error!");
        return nResult;
    }
    PrinterBaseInfo baseinfo;
    baseinfo.strBrandOID = strBrandOID;
    /*QueryResult ret = CDBHelper::getBrandBaseInfoByBrandOID(strBrandOID, baseinfo);
    if (ret != QueryResult::Successed)
    {
    if (ret == QueryResult::querynodata)
    {
    return QueryResult::Unsupported;
    }
    return ret;
    }*/
    if (strBrandOID == "40093")
    {
        baseinfo.strModel = "1.3.6.1.2.1.43.5.1.1.16.1";
        baseinfo.nMethod = 0;
        baseinfo.strPrinterSN = "1.3.6.1.4.1.40093.10.1.1.4";		//新版sn
        //baseinfo.strPrinterSN = "1.3.6.1.4.1.40093.1.1.2.6";		//mac
        baseinfo.strBrand = "Pantum";
    }
    else
    {
        baseinfo.strModel = "1.3.6.1.2.1.43.5.1.1.16.1";
        baseinfo.nMethod = 0;
        baseinfo.strPrinterSN = "1.3.6.1.2.1.43.5.1.1.17.1";
        if (strBrandOID == "641")
        {
            baseinfo.strBrand = "Pantum";
            baseinfo.strModel = "1.3.6.1.4.1.641.6.2.3.1.4.1";
        }
        else if (strBrandOID == "11" || strBrandOID == "1092" || strBrandOID == "16401"
                 || strBrandOID == "11147" || strBrandOID == "46898")
        {
            baseinfo.strBrand = "HP";
        }
        else if (strBrandOID == "1065" || strBrandOID == "1602" || strBrandOID == "11783"
                 || strBrandOID == "25278")
        {
            baseinfo.strBrand = "Canon";
        }
        else if (strBrandOID == "2435")
        {
            baseinfo.strModel = "1.3.6.1.2.1.25.3.2.1.3.1";
            baseinfo.strBrand = "Brother";
        }
        else if (strBrandOID == "253" || strBrandOID == "297")
        {
            baseinfo.strBrand = "Xerox";
        }
        else if (strBrandOID == "367")
        {
            baseinfo.strBrand = "Rich";
        }
        else if (strBrandOID == "18334")
        {
            baseinfo.strBrand = "Conica Minolta";
        }
        else if (strBrandOID == "1347")
        {
            baseinfo.strBrand = "Kyocera";
        }
        else
        {
            baseinfo.strBrand = "Unknown";
        }
    }
    QString strPrinterModel;
    nResult = getPrinterModel(strIPAddress, baseinfo.strModel, strPrinterModel, baseinfo.nMethod, nOvertime);
    if (nResult != QueryResult::Successed)
    {
        WriteLog::writeToLog("getPrinterModel error!");
        return nResult;
    }
    QString strPrinterSN;
    nResult = getPrinterSN(strIPAddress, baseinfo.strPrinterSN, strPrinterSN, baseinfo.nMethod, nOvertime);
    if (nResult != QueryResult::Successed)
    {
        WriteLog::writeToLog("getPrinterSN error!");
        return nResult;
    }

    info.strBrand = baseinfo.strBrand;
    info.strModel = strPrinterModel;
    //if (strPrinterSN.contains(" "))		//利盟
    //{
    //	QStringList strMacList = strPrinterSN.split(" ");
    //	QString strPrinterMac = "";
    //	for (int i = 2; i < 8; i++)
    //	{
    //		strPrinterMac.append(strMacList[i]);
    //	}
    //	info.strPrinterSN = strPrinterMac;
    //}
    //else
    //{
    //	info.strPrinterSN = strPrinterSN.replace(":", "");	//其他mac
    //}
    info.strPrinterSN = strPrinterSN;	//sn
    info.strIPaddress = strIPAddress;
    info.strBrandOID = strBrandOID;
    WriteLog::writeToLog("get baseinfo success");
    return QueryResult::Successed;
}

QueryResult CSnmpHelper::getPrinterDetailInfo(QString strIPAdress, PrinterDetailInfo& info, bool bSnmpv3Status, SnmpArg params)
{
    //获取打印机基本信息
    PrinterBaseInfo baseinfo;
    QueryResult nRet = getPrinterBaseInfo(strIPAdress, baseinfo, 1, bSnmpv3Status, params);
    if (QueryResult::Successed != nRet)
    {
        return nRet;
    }
    //WriteLog::writeToLog("******************getPrinterDetailInfo******************");
    QString iniPath = QCoreApplication::applicationDirPath();
    if (iniPath.isEmpty())
        iniPath = QDir::currentPath();
    //QString iniPath = QDir::currentPath();
    //QString iniPath = "D://project//1.0.2.15//pipme//x32_bin";
    QString iniFilePath = iniPath + "/printer.ini";
    if (!QFileInfo::exists(iniFilePath))
    {
        WriteLog::writeToLog("iniFile is not exists");
        return QueryResult::openIniFailed;
    }
    QSettings iniFile(iniPath + "/printer.ini", QSettings::IniFormat);
    WriteLog::writeToLog("iniFile Path: " + iniPath + "/printer.ini");
    iniFile.setIniCodec("UTF-8");
    iniFile.beginGroup("pantum");
    QString pantum4020 = iniFile.value("4020").toString().toLower();
    QString pantum5103 = iniFile.value("5103").toString().toLower();
    QString pantum2013 = iniFile.value("2013").toString().toLower();
    QString pantum3320 = iniFile.value("3320").toString().toLower();
    QString pantum1820 = iniFile.value("1820").toString().toLower();
    QString pantumOld5103 = iniFile.value("old5103").toString().toLower();
    QString pantumKanas = iniFile.value("kanas").toString().toLower();
    QString pantumFujiXerox = iniFile.value("fujixerox").toString().toLower();
	iniFile.endGroup();
	iniFile.beginGroup("lexmark");
	QString printerWilbur = iniFile.value("wilbur").toString();
	QString printerBeagle = iniFile.value("beagle").toString();
    QString printerKyocera = iniFile.value("kyocera").toString();
	iniFile.endGroup();

	if (!pantum3320.size() > 0 || !pantum4020.size() > 0 || !pantum5103.size() > 0 || !pantum1820.size() > 0 || !pantum2013.size() > 0
        || !pantumFujiXerox.size() > 0 || !printerWilbur.size() > 0 || !printerBeagle.size() > 0 || !pantumOld5103.size() > 0 ||!printerKyocera.size() > 0)	//确保ini文件完整读取
	{
		WriteLog::writeToLog("iniFile Open Failed!");
		return QueryResult::openIniFailed;
	}
	WriteLog::writeToLog("iniFile is ok");

    QueryPrinterDetailInfo qD;
    qD.loadV3Config(bSnmpv3Status, params); //传v3参数

    if (m_bSnmpv3) {
        if (baseinfo.strBrandOID == "40093")
        {
            QString strModel = baseinfo.strModel.toLower();
            /*if (strModel.contains("cm410adn")|| strModel.contains("bm410adn") || strModel.contains("cm310adn")|| strModel.contains("bm310adn")
        || strModel.contains("cm260adn") || strModel.contains("bm260adn") || strModel.contains("cm415adn") || strModel.contains("bm415adn")
        || strModel.contains("cm315adn") || strModel.contains("bm315adn") || strModel.contains("cm265adn") || strModel.contains("bm265adn"))*/
            if (pantumFujiXerox.contains(strModel))		//OEM施乐机型
            {
                info = qD.getFujiXeroxPrinterDetailInfoV3(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else
                //if (strModel.contains("cm1108adn")|| strModel.contains("cm1100dn") || strModel.contains("cm1100dw") || strModel.contains("cm1100adn")
                //	|| strModel.contains("cm1100adw") || strModel.contains("cm1100fdn") || strModel.contains("cm1100fdw") || strModel.contains("cp1100dn") || strModel.contains("cp1100dw")
                //	|| strModel.contains("cp1108dn"))//Pantum 1820型号（小写））
                if (pantum1820.contains(strModel))
                {
                    info = qD.getPantum1820PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
            /*else if (strModel.contains("bp5100dn") || strModel.contains("bp5100dw") || strModel.contains("bp5105dn") || strModel.contains("bp5101dn")
        || strModel.contains("bm5100adn") || strModel.contains("bm5100fdn") || strModel.contains("bm5100adw") || strModel.contains("bm5100fdw") || strModel.contains("bm5105adn") || strModel.contains("bm5105fdn"))
        */else if (pantum4020.contains(strModel)) {
                    info = qD.getPantum4020PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantum3320.contains(strModel)) {
                    info = qD.getPantum3320PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantumKanas.contains(strModel)) {
                    info = qD.getPantumKanasPrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
            //else if (strModel.contains("m655") || strModel.contains("m620") || strModel.contains("m650") || strModel.contains("m651")
            //	|| strModel.contains("ms6550") || strModel.contains("m6655") || strModel.contains("m620"))//Pantum 2013型号
                else if (pantum2013.contains(strModel))
                {
                    info = qD.getPantum2013PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantum5103.contains(strModel))
                {
                    info = qD.getPantum5103PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantumOld5103.contains(strModel))
                {
                    info = qD.getPantumOld5103PrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else
                {
                    info = qD.getPantumPrinterDetailInfoV3(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
        }
        else if (baseinfo.strBrandOID == "641")
        {
            QString strModel = baseinfo.strModel.toLower();
            if (printerWilbur.contains(strModel))
            {
                info = qD.getLexMarkWilburPrinterDetailInfoV3(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else if (printerBeagle.contains(strModel))
            {
                info = qD.getLexMarkBeaglePrinterDetailInfoV3(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else
            {
                info = qD.getLexMarkPrinterDetailInfoV3(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }

        }
        else if (baseinfo.strBrandOID == "11" || baseinfo.strBrandOID == "1092" || baseinfo.strBrandOID == "16401" || baseinfo.strBrandOID == "11147" || baseinfo.strBrandOID == "46898")
        {
            info = qD.getHPPrinterDetailInfoV3(strIPAdress);

            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "253" || baseinfo.strBrandOID == "297")
        {
            info = qD.getFujiXeroxPrinterDetailInfoV3(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "18334")
        {
            info = qD.getKonicaMinoltaPrinterDetailInfoV3(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "1065" || baseinfo.strBrandOID == "1602" || baseinfo.strBrandOID == "11783"
                 || baseinfo.strBrandOID == "25278")
        {
            info = qD.getCanonPrinterDetailInfoV3(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "2435")
        {
            info = qD.getBrotherPrinterDetailInfoV3(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if(baseinfo.strBrandOID == "1347")
        {
            info = qD.getKyoceraPrinterDetailInfoV3(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else {
            info = qD.getPrinterDetailInfoV3(strIPAdress, baseinfo);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
    }
    else {   //snmpv1/v2
        if (baseinfo.strBrandOID == "40093")
        {
            QString strModel = baseinfo.strModel.toLower();
            /*if (strModel.contains("cm410adn")|| strModel.contains("bm410adn") || strModel.contains("cm310adn")|| strModel.contains("bm310adn")
        || strModel.contains("cm260adn") || strModel.contains("bm260adn") || strModel.contains("cm415adn") || strModel.contains("bm415adn")
        || strModel.contains("cm315adn") || strModel.contains("bm315adn") || strModel.contains("cm265adn") || strModel.contains("bm265adn"))*/
            if (pantumFujiXerox.contains(strModel))		//OEM施乐机型
            {
                info = qD.getFujiXeroxPrinterDetailInfo(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else
                //if (strModel.contains("cm1108adn")|| strModel.contains("cm1100dn") || strModel.contains("cm1100dw") || strModel.contains("cm1100adn")
                //	|| strModel.contains("cm1100adw") || strModel.contains("cm1100fdn") || strModel.contains("cm1100fdw") || strModel.contains("cp1100dn") || strModel.contains("cp1100dw")
                //	|| strModel.contains("cp1108dn"))//Pantum 1820型号（小写））
                if (pantum1820.contains(strModel))
                {
                    info = qD.getPantum1820PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
            /*else if (strModel.contains("bp5100dn") || strModel.contains("bp5100dw") || strModel.contains("bp5105dn") || strModel.contains("bp5101dn")
        || strModel.contains("bm5100adn") || strModel.contains("bm5100fdn") || strModel.contains("bm5100adw") || strModel.contains("bm5100fdw") || strModel.contains("bm5105adn") || strModel.contains("bm5105fdn"))
        */else if (pantum4020.contains(strModel)) {
                    info = qD.getPantum4020PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantum3320.contains(strModel)) {
                    info = qD.getPantum3320PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
            //else if (strModel.contains("m655") || strModel.contains("m620") || strModel.contains("m650") || strModel.contains("m651")
            //	|| strModel.contains("ms6550") || strModel.contains("m6655") || strModel.contains("m620"))//Pantum 2013型号
                else if (pantum2013.contains(strModel))
                {
                    info = qD.getPantum2013PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantumKanas.contains(strModel)) {
                    info = qD.getPantumKanasPrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantum5103.contains(strModel))
                {
                    info = qD.getPantum5103PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else if (pantumOld5103.contains(strModel))
                {
                    info = qD.getPantumOld5103PrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
                else
                {
                    info = qD.getPantumPrinterDetailInfo(strIPAdress);
                    if (info.nResult == -1)
                    {
                        return QueryResult::Unsupported;
                    }
                }
        }
        else if (baseinfo.strBrandOID == "641")
        {
            QString strModel = baseinfo.strModel.toLower();
            if (printerWilbur.contains(strModel))
            {
                info = qD.getLexMarkWilburPrinterDetailInfo(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else if (printerBeagle.contains(strModel))
            {
                info = qD.getLexMarkBeaglePrinterDetailInfo(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }
            else
            {
                info = qD.getLexMarkPrinterDetailInfo(strIPAdress);
                if (info.nResult == -1)
                {
                    return QueryResult::Unsupported;
                }
            }

        }
        else if (baseinfo.strBrandOID == "11" || baseinfo.strBrandOID == "1092" || baseinfo.strBrandOID == "16401" || baseinfo.strBrandOID == "11147" || baseinfo.strBrandOID == "46898")
        {
            info = qD.getHPPrinterDetailInfo(strIPAdress);


            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "253" || baseinfo.strBrandOID == "297")
        {
            info = qD.getFujiXeroxPrinterDetailInfo(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "18334")
        {
            info = qD.getKonicaMinoltaPrinterDetailInfo(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "1065" || baseinfo.strBrandOID == "1602" || baseinfo.strBrandOID == "11783"
                 || baseinfo.strBrandOID == "25278")
        {
            info = qD.getCanonPrinterDetailInfo(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if (baseinfo.strBrandOID == "2435")
        {
            info = qD.getBrotherPrinterDetailInfo(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else if(baseinfo.strBrandOID == "1347")
        {
            info = qD.getKyoceraPrinterDetailInfo(strIPAdress);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        else {
            info = qD.getPrinterDetailInfo(strIPAdress, baseinfo);
            if (info.nResult == -1)
            {
                return QueryResult::Unsupported;
            }
        }
        WriteLog::writeToLog("get detailinfo success");
        //WriteLog::writeDetailInfo(info);

        /*
        info.baseinfo = baseinfo;
        //获取打印机进阶信息
        PrinterAdvancedInfo adinfo;
        QueryResult dbRet = CDBHelper::getPrinterMib(baseinfo.strModel, adinfo);
        if (dbRet == QueryResult::querynodata )
        {
        //dbRet = CDBHelper::getBrandMib(baseinfo.strBrandOID, adinfo);
        }
        if (dbRet != QueryResult::Successed)
        {
        return dbRet;
        }

        info.adInfo = adinfo;
        //获取打印机状态信息
        PrinterErrorOID errorOID;
        dbRet = CDBHelper::getQueryErrorOID(adinfo.nPrinterID, errorOID);
        QString strValue;
        QString strRet;
        nRet = queryMibDataV2(strIPAdress, QueryMethod::getNext, errorOID.strStatusOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        return nRet;
        }
        int nStatusCode = strValue.toInt();
        int nMappingStatusCode = CDBHelper::getMappingStatusCode(info.baseinfo.strBrandOID, nStatusCode);
        if (nMappingStatusCode == -1)
        {
        info.errorInfo.nPrinterStatus = nStatusCode;
        info.errorInfo.strPrinterStatusString = "UNKOWN PRINTER STATUS!";
        }
        else if (nMappingStatusCode == 5)
        {
        QString StatusString;
        CDBHelper::getStatusString(nMappingStatusCode, StatusString);
        info.errorInfo.nPrinterStatus = nMappingStatusCode;
        info.errorInfo.strPrinterStatusString = StatusString;

        nRet = queryMibDataV2(strIPAdress, QueryMethod::getNext, errorOID.strErrorOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        return nRet;
        }
        int nErrorcode = strValue.toInt();

        int nMappingErrorCode = CDBHelper::getMappingErrorCode(info.baseinfo.strBrandOID, nErrorcode);

        if (nMappingErrorCode == 1)
        {
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, errorOID.strfatalErrorOID, strRet, strValue);
        info.errorInfo.nErrorCode = strValue.toInt();
        }
        else if (nMappingErrorCode == -1)
        {
        info.errorInfo.nErrorCode = nErrorcode;
        info.errorInfo.strPrinterErrorString = "Unsuport Printer Error.";
        }
        else
        {
        QString errorString;
        CDBHelper::getErrorString(nMappingErrorCode, info.baseinfo.strBrandOID,errorString);
        info.errorInfo.nErrorCode = nErrorcode;
        info.errorInfo.strPrinterErrorString = errorString;
        }
        }
        else
        {
        QString StatusString;
        CDBHelper::getStatusString(nMappingStatusCode, StatusString);
        info.errorInfo.nPrinterStatus = nMappingStatusCode;
        info.errorInfo.strPrinterStatusString = StatusString;
        }

        //获取打印机硒鼓信息
        QList<PrinterDrum> listPrinterDrum;
        dbRet = CDBHelper::getPrinterDrumInfo(adinfo.nPrinterID, listPrinterDrum);
        info.listDrumDetail = listPrinterDrum;
        if (info.listDrumDetail.size() > 0)
        {
        QList<PrinterDrum>::iterator itor = info.listDrumDetail.begin();
        for (itor; itor != info.listDrumDetail.end(); itor++)
        {
        //获取硒鼓当前量
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryCurrentOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        itor->nCurrent = strValue.toInt();
        }
        }
        //获取印量信息
        QList<PrinterPCount> listPrinterPCount;
        dbRet = CDBHelper::getPrinterPCountInfo(adinfo.nPrinterID, listPrinterPCount);
        info.listPCountDetail = listPrinterPCount;
        if (info.listPCountDetail.size() > 0)
        {
        QList<PrinterPCount>::iterator itor = info.listPCountDetail.begin();
        for (itor;itor != info.listPCountDetail.end();itor++)
        {
        //查询印量 x2
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        itor->nPCount = strValue.toInt();
        }

        }
        //获取粉盒信息
        QList<PrinterToner> listPrinterToner;
        dbRet = CDBHelper::getPrinterTonerInfo(adinfo.nPrinterID, listPrinterToner);
        info.listTonerDetail = listPrinterToner;
        if (info.listTonerDetail.size() > 0)
        {
        QList<PrinterToner>::iterator itor = info.listTonerDetail.begin();
        for (itor; itor != info.listTonerDetail.end();itor++)
        {
        //查询碳粉余量 x4
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryCurrentOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        int nRestValue = strValue.toInt();
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryMaxOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        int nMaxValue = strValue.toInt();

        itor->nCurrent = (int)(double)nRestValue/(double)nMaxValue * 100;
        }
        }
        //获取废粉盒信息
        QList<PrinterWasteToner> listPrinterWastToner;
        dbRet = CDBHelper::getPrinterWastTonerInfo(adinfo.nPrinterID, listPrinterWastToner);
        info.listWasteTonerDetail = listPrinterWastToner;
        if (info.listWasteTonerDetail.size() > 0)
        {
        QList<PrinterWasteToner>::iterator itor = info.listWasteTonerDetail.begin();
        for (itor; itor != info.listWasteTonerDetail.end(); itor++)
        {
        //查询碳粉余量 x4
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryCurrentOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        int nRestValue = strValue.toInt();
        nRet = queryMibDataV2(strIPAdress, QueryMethod::get, itor->strQueryMaxOID, strRet, strValue);
        if (nRet != QueryResult::Successed)
        {
        continue;
        }
        int nMaxValue = strValue.toInt();

        itor->nCurrent = 100 - (int)(double)nRestValue / (double)nMaxValue * 100;
        }
        }*/


    }
    return QueryResult::Successed;
}

QueryResult CSnmpHelper::getBrandOID(QString strIPAddress, QString& strBrandOID, int nOvertime)
{
    QString strValue;
    QString strRet;
    QString strQueryBrandOID = "1.3.6.1.2.1.1.2.0";
    QList<MibValue> list_value;
    QueryResult nResult;
    if(m_bSnmpv3)
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBrandOID, strRet, strValue, nOvertime);
    else
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryBrandOID, strRet, strValue, nOvertime);

    if (nResult != QueryResult::Successed)
    {
        return nResult;
    }

    QStringList oidlist = strValue.split(".");
    if (oidlist.size() < 7)
    {
        return QueryResult::invalidOIDValue;//获得的值不正确
    }
    strBrandOID = oidlist.at(6);
    return nResult;
}

QueryResult CSnmpHelper::getPrinterBrand(QString strIPAdress, PrinterBaseInfo& info)
{
    return QueryResult::Successed;
}
QueryResult CSnmpHelper::getPrinterModel(QString strIPAddress, QString strQueryOID, QString& strModel, int nMethod, int nOvertime)
{
    QString strRet;
    QueryResult nResult;
    if (nMethod == 0)
    {
        if(m_bSnmpv3)
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strModel, nOvertime);
        else
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryOID, strRet, strModel, nOvertime);
    }
    else
    {
        if(m_bSnmpv3)
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strModel, nOvertime);
        else
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryOID, strRet, strModel, nOvertime);
    }


    if (nResult != QueryResult::Successed)
    {
        return nResult;
    }

    return QueryResult::Successed;
}

QueryResult CSnmpHelper::getPrinterSN(QString strIPAddress, QString strQueryOID, QString& strSN, int nMethod, int nOvertime)
{
    QString strRet;
    QueryResult nResult;
    if (nMethod == 0)
    {
        if(m_bSnmpv3)
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
        else
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
    }
    else
    {
        if(m_bSnmpv3)
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
        else
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
    }

    if (strSN.isEmpty())
    {
        if (strQueryOID.contains("40093"))
        {
            strQueryOID = "1.3.6.1.4.1.40093.1.1.1.5";	//old sn oid
            if (nMethod == 0)
            {
                if(m_bSnmpv3)
                    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
                else
                    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
            }
            else
            {
                if(m_bSnmpv3)
                    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
                else
                    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryOID, strRet, strSN, nOvertime);
            }
            //1.3.6.1.2.1.43.5.1.1.17 施乐SN
            if (strSN.isEmpty())
            {
                strQueryOID = "1.3.6.1.2.1.43.5.1.1.17";	//old sn oid
                if (nMethod == 0)
                {
                    if(m_bSnmpv3)
                        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryOID, strRet, strSN, nOvertime);
                    else
                        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryOID, strRet, strSN, nOvertime);
                }
                else
                {
                    if(m_bSnmpv3)
                        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryOID, strRet, strSN, nOvertime);
                    else
                        nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, strQueryOID, strRet, strSN, nOvertime);
                }
            }
        }
        if (nResult != QueryResult::Successed)
            return nResult;
    }

    return QueryResult::Successed;
}

QueryResult CSnmpHelper::queryMibDataV2(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime)
{
    if (strIPAdress.contains("255"))
    {
        return QueryResult::invalidIPAddr;//ip地址无效
    }
    QString SnmpCmd = "get";
    QString m_ret;
    Snmp::socket_startup();
    qDebug() << strIPAdress;
    QByteArray arr = strIPAdress.toLatin1();
    UdpAddress address(arr.constData());
    if (!address.valid())
    {
        Snmp::socket_cleanup();
        return QueryResult::invalidIPAddr;//ip地址无效
    }
    //---------[ determine options to use ]-----------------------------------
    snmp_version version = version2c;          // default is v2c
    //snmp_version version = version1;          // default is v2c
    int retries = 1;                          // default retries is 1
    int timeout = nOverTime * 100;                        // default is 1 second (100unit)
    u_short port = 161;                       // default snmp port is 161
    OctetStr community;
    if (!m_strCommunityName.isEmpty())
    {
        community = OctetStr(m_strCommunityName.toStdString().c_str());
    }
    else
    {
        community = OctetStr("public");           // community name
    }
    int non_reps = 0;                         // non repeaters default is 0
    int max_reps = 10;                        // maximum repetitions default is 10
    char* ptr;
    //----------[ create a SNMP++ session ]-----------------------------------
    int status;
    // bind to any port and use IPv6 if needed
    Snmp snmp(status, 0, (address.get_ip_version() == Address::version_ipv6));
    //snmp.start_poll_thread(1);
    if (status != SNMP_CLASS_SUCCESS)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;//snmp初始化失败
    }
    //--------[ build up SNMP++ object needed ]-------------------------------
    address.set_port(port);
    CTarget ctarget(address);             // make a target using the address
    ctarget.set_version(version);         // set the SNMP version SNMPV1 or V2
    ctarget.set_retry(retries);           // set the number of auto retries
    ctarget.set_timeout(timeout);         // set timeout
    ctarget.set_readcommunity(community); // set the read community name
    //-------[ issue the request, blocked mode ]-----------------------------
    Pdu pdu;
    Vb vb;
    Oid oid(OID.toLatin1().constData());
    //oid.set_data((const char*)CW2A(m_oid), m_oid.GetLength());
    vb.set_oid(oid);
    pdu += vb;
    SnmpTarget* target;
    target = &ctarget;

    if (eMethod == QueryMethod::get)
    {
        status = snmp.get(pdu, *target);
    }
    else
    {
        status = snmp.get_next(pdu, *target);
    }
    if (SNMP_CLASS_TIMEOUT == status || SNMP_CLASS_TL_ACCESS_DENIED == status)
    {
        Snmp::socket_cleanup();
        return QueryResult::snmpOverTime;//超时
    }

    if (SNMP_CLASS_SUCCESS == status)
    {
        for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
        {
            pdu.get_vb(vb, vbi);
            if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
                    && (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
                ;//continue;//只显示要求OID的内容
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                strValue = QString::fromLocal8Bit(vb.get_printable_value());
                m_ret += ("\r\n");
            }
            else
            {
                m_ret += ("End of MIB view.\r\n");
            }
        }
    }
    Snmp::socket_cleanup();
    strRet = m_ret;
    return QueryResult::Successed;
}

QueryResult CSnmpHelper::queryMibDataV3(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime)
{
    if (strIPAdress.contains("255"))
    {
        return QueryResult::invalidIPAddr;//ip地址无效
    }

    QString m_ret;
    Snmp::socket_startup();
    QByteArray arr = strIPAdress.toLatin1();
    UdpAddress address(arr.constData());
    if (!address.valid())
    {
        Snmp::socket_cleanup();
        return QueryResult::invalidIPAddr;//ip地址无效
    }
    //---------[ determine options to use ]-----------------------------------
    snmp_version version = version3;          // default is v2c
    int retries = 1;                          // default retries is 1
    int timeout = nOverTime * 100;                        // default is 1 second (100unit)
    u_short port = 161;                       // default snmp port is 161
    OctetStr community;
    if (!m_strCommunityName.isEmpty())
    {
        community = OctetStr(m_strCommunityName.toStdString().c_str());
    }
    else
    {
        community = OctetStr("public");           // community name
    }
    int non_reps = 0;                         // non repeaters default is 0
    int max_reps = 10;                        // maximum repetitions default is 10
    char* ptr;

    //--------- [ parameters of SNMP V3 ]--------------------------------------
    OctetStr privPassword(m_strPrivPwd.toStdString().c_str());
    OctetStr authPassword(m_strAuthPwd.toStdString().c_str());
    OctetStr securityName(m_strSecuName.toStdString().c_str());
    int securityModel = SNMP_SECURITY_MODEL_USM;
    int securityLevel = m_nSecuLevel;
    OctetStr contextName(m_strContextName.toStdString().c_str());
    OctetStr contextEngineID(m_strContextEngineID.toStdString().c_str());
    long authProtocol = m_nAuthProtocol;
    long privProtocol = m_nPrivProtocol;
    //v3MP *v3_MP;

    //----------[ create a SNMP++ session ]-----------------------------------
    int status;
    // bind to any port and use IPv6 if needed
    SNMP_AUTHPROTOCOL_HMACMD5;
    Snmp snmp(status, 0, (address.get_ip_version() == Address::version_ipv6));
    if (status != SNMP_CLASS_SUCCESS)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;//snmp初始化失败
    }

    //---------[ init SnmpV3 ]--------------------------------------------
    //char strEngineId[256];
    //if (eMethod == QueryMethod::get)
    //{
    //	strcpy(strEngineId, "snmpGet");
    //}
    //else if (eMethod == QueryMethod::getNext)
    //{
    //	strcpy(strEngineId, "snmpNext");
    //}
    //else if (eMethod == QueryMethod::getBulk)
    //{
    //	strcpy(strEngineId, "snmpBulk");
    //}
    //const char* strFileName = "snmpv3_boot_counter";
    //unsigned int snmpEngineBoots = 0;

    //status = getBootCounter(strFileName, strEngineId, snmpEngineBoots);
    //if ((status != SNMPv3_OK) && (status < SNMPv3_FILEOPEN_ERROR))
    //{
    //	Snmp::socket_cleanup();
    //	return QueryResult::initSnmpFailed;
    //}
    //snmpEngineBoots++;
    //status = saveBootCounter(strFileName, strEngineId, snmpEngineBoots);
    //if (status != SNMPv3_OK)
    //{
    //	Snmp::socket_cleanup();
    //	return QueryResult::initSnmpFailed;
    //}

    //int construct_status;
    //v3_MP = new v3MP(strEngineId, snmpEngineBoots, construct_status);
    //if (construct_status != SNMPv3_MP_OK)
    //{
    //	Snmp::socket_cleanup();
    //	//delete v3_MP;
    //	return QueryResult::initSnmpFailed;
    //}

    //USM *usm = v3_MP->get_usm();
    USM *usm = SNMPSession::v3_MP->get_usm();
    usm->add_usm_user(securityName,
                      authProtocol, privProtocol,
                      authPassword, privPassword);

    //--------[ build up SNMP++ object needed ]-------------------------------
    Pdu pdu;                               // construct a Pdu object
    Vb vb;                                 // construct a Vb object
    Oid oid(OID.toLatin1().constData());
    vb.set_oid(oid);
    pdu += vb;

    address.set_port(port);
    UTarget utarget(address);
    utarget.set_version(version);          // set the SNMP version SNMPV1 or V2 or V3
    utarget.set_retry(retries);            // set the number of auto retries
    utarget.set_timeout(timeout);          // set timeout
    utarget.set_security_model(securityModel);
    utarget.set_security_name(securityName);
    pdu.set_security_level(securityLevel);
    bool pduRet;
    pduRet = pdu.set_context_name(contextName);
    pduRet = pdu.set_context_engine_id(contextEngineID);

    SnmpTarget* target;
    target = &utarget;

    if (eMethod == QueryMethod::get)
    {
        status = snmp.get(pdu, *target);
    }
    else if (eMethod == QueryMethod::getNext)
    {
        status = snmp.get_next(pdu, *target);
    }
    else if (eMethod == QueryMethod::getBulk)
    {
        status = snmp.get_bulk(pdu, *target, 0, 25);
    }

    if (SNMP_CLASS_TIMEOUT == status || SNMP_CLASS_TL_ACCESS_DENIED == status)
    {
        //delete v3_MP;
        Snmp::socket_cleanup();
        return QueryResult::snmpOverTime;//超时
    }

    if (SNMP_CLASS_SUCCESS == status)
    {
        for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
        {
            MibValue mibvalue;
            pdu.get_vb(vb, vbi);
            if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
                    && (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
                ;//continue;//只显示要求OID的内容
            if (pdu.get_type() == REPORT_MSG) {
                Oid tmp;
                vb.get_oid(tmp);
                m_ret += "Received a reportPdu: ";
                m_ret += QString(snmp.error_msg(tmp));
                m_ret += "\r\n";
                m_ret += vb.get_printable_oid();
                m_ret += " + ";
                m_ret += vb.get_printable_value();
                m_ret += "\r\n";
            }
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                strValue = QString::fromLocal8Bit(vb.get_printable_value());
                m_ret += "\r\n";
            }
            else
            {
                m_ret += ("End of MIB view.\r\n");
            }
        }
    }
    //delete v3_MP;
    Snmp::socket_cleanup();
    strRet = m_ret;
    return QueryResult::Successed;
}

QueryResult CSnmpHelper::queryMibDataV1(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QString& strValue, int nOverTime)
{
    if (strIPAdress.contains("255"))
    {
        return QueryResult::invalidIPAddr;//ip地址无效
    }
    QString SnmpCmd = "get";
    QString m_ret;
    Snmp::socket_startup();
    QByteArray arr = strIPAdress.toLatin1();
    UdpAddress address(arr.constData());
    if (!address.valid())
    {
        Snmp::socket_cleanup();
        return QueryResult::invalidIPAddr;//ip地址无效
    }
    //---------[ determine options to use ]-----------------------------------
    //snmp_version version = version2c;          // default is v2c
    snmp_version version = version1;          // default is v1
    int retries = 1;                          // default retries is 1
    int timeout = nOverTime * 100;                        // default is 1 second (100unit)
    u_short port = 161;                       // default snmp port is 161
    OctetStr community;
    if (!m_strCommunityName.isEmpty())
    {
        community = OctetStr(m_strCommunityName.toStdString().c_str());
    }
    else
    {
        community = OctetStr("public");           // community name
    }
    int non_reps = 0;                         // non repeaters default is 0
    int max_reps = 10;                        // maximum repetitions default is 10
    char* ptr;
    //----------[ create a SNMP++ session ]-----------------------------------
    int status;
    // bind to any port and use IPv6 if needed
    Snmp snmp(status, 0, (address.get_ip_version() == Address::version_ipv6));
    //snmp.start_poll_thread(1);
    if (status != SNMP_CLASS_SUCCESS)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;//snmp初始化失败
    }
    //--------[ build up SNMP++ object needed ]-------------------------------
    address.set_port(port);
    CTarget ctarget(address);             // make a target using the address
    ctarget.set_version(version);         // set the SNMP version SNMPV1 or V2
    ctarget.set_retry(retries);           // set the number of auto retries
    ctarget.set_timeout(timeout);         // set timeout
    ctarget.set_readcommunity(community); // set the read community name
    //-------[ issue the request, blocked mode ]-----------------------------
    Pdu pdu;
    Vb vb;
    Oid oid(OID.toLatin1().constData());
    //oid.set_data((const char*)CW2A(m_oid), m_oid.GetLength());
    vb.set_oid(oid);
    pdu += vb;
    SnmpTarget* target;
    target = &ctarget;

    if (eMethod == QueryMethod::get)
    {
        status = snmp.get(pdu, *target);
    }
    else
    {
        status = snmp.get_next(pdu, *target);
    }
    if (SNMP_CLASS_TIMEOUT == status || SNMP_CLASS_TL_ACCESS_DENIED == status)
    {
        Snmp::socket_cleanup();
        return QueryResult::snmpOverTime;//超时
    }

    if (SNMP_CLASS_SUCCESS == status)
    {
        for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
        {
            pdu.get_vb(vb, vbi);
            if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
                    && (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
                ;//continue;//只显示要求OID的内容
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                strValue = QString::fromLocal8Bit(vb.get_printable_value());
                m_ret += ("\r\n");
            }
            else
            {
                m_ret += ("End of MIB view.\r\n");
            }
        }
    }
    Snmp::socket_cleanup();
    strRet = m_ret;
    return QueryResult::Successed;
}

void CSnmpHelper::sessionCallback(int reason, Snmp* session, Pdu& pdu, SnmpTarget& target, void* data)
{
    Q_UNUSED(session)
    Q_UNUSED(target)

    CSnmpHelper* snmp = static_cast<CSnmpHelper*>(data);

    if (reason != SNMP_CLASS_SUCCESS)
    {
        return;
    }

    for (int vbi = 0; vbi < pdu.get_vb_count(); vbi++)
    {
        /*pdu.get_vb(vb, vbi);
        if ((0 == strstr(vb.get_printable_oid(), OID.toLatin1().constData()))
        && (0 == strstr(OID.toLatin1().constData(), vb.get_printable_oid())))
        ;//continue;//只显示要求OID的内容
        m_ret += ("Oid = ");
        m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
        m_ret += ("\r\n");
        if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
        {
        m_ret += ("Value = ");
        m_ret += QString::fromLocal8Bit(vb.get_printable_value());
        strValue = QString::fromLocal8Bit(vb.get_printable_value());
        m_ret += ("\r\n");
        }
        else
        {
        m_ret += ("End of MIB view.\r\n");
        }*/
    }
}
