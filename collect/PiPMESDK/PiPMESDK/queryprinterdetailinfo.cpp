#include "queryprinterdetailinfo.h"
#include "QDebug"

QueryPrinterDetailInfo::QueryPrinterDetailInfo()
{
    m_strPrivPwd = "";
    m_strAuthPwd = "";
    m_strSecuName = "";
    m_strContextName = "";
    m_strContextEngineID = "";
    //    m_bSnmpv3 = false;

    initLemarkError();
}
QueryPrinterDetailInfo::~QueryPrinterDetailInfo()
{

}

//void QueryPrinterDetailInfo::writeLog(QString txt)
//{
//	QFile outFile("sdklog.txt");
//	//if (!outFile.exists())
//	//{
//	//	outFile.open(QIODevice::ReadWrite | QIODevice::Text);
//	//	outFile.close();
//	//}
//	bool openStatus = outFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
//	QTextStream ts(&outFile);
//	ts << txt << endl;
//	outFile.close();
//}

void QueryPrinterDetailInfo::initLemarkError()
{
    m_LemarkError.insert("Tray 1 Empty", QStringLiteral("进纸匣1已空"));
    m_LemarkError.insert("Tray 2 Empty", QStringLiteral("进纸匣2已空"));
    m_LemarkError.insert("Tray 3 Empty", QStringLiteral("进纸匣3已空"));
    m_LemarkError.insert("Tray 1 Missing", QStringLiteral("进纸匣1缺少"));
    m_LemarkError.insert("Tray 2 Missing", QStringLiteral("进纸匣2缺少"));
    m_LemarkError.insert("Tray 3 Missing", QStringLiteral("进纸匣3缺少"));
    m_LemarkError.insert("Paper Jam,door A,tray 1", QStringLiteral("卡纸，盖门A，进纸匣1."));
    m_LemarkError.insert("Paper Jam,tray 1", QStringLiteral("卡纸，进纸匣1"));
    m_LemarkError.insert("Paper Jam,tray 2", QStringLiteral("卡纸，进纸匣2"));
    m_LemarkError.insert("Paper Jam,tray 3", QStringLiteral("卡纸，进纸匣3"));
    m_LemarkError.insert("Change tray 1 to Labels A4", QStringLiteral("更改进纸匣1为标签A4"));
    m_LemarkError.insert("Change tray 1 to Plain Paper A5 Long Edge", QStringLiteral("更改进纸匣1为普通纸张A5长边"));
    m_LemarkError.insert("Change tray 2 to Plain Paper A5 Long Edge", QStringLiteral("更改进纸匣2为普通纸张A5长边"));
    m_LemarkError.insert("Change tray 3 to Plain Paper A5 Long Edge", QStringLiteral("更改进纸匣3为普通纸张A5长边"));
    m_LemarkError.insert("Change tray 1 to Plain Paper A5 Short Edge", QStringLiteral("更改进纸匣1为普通纸张A5短边"));
    m_LemarkError.insert("Change tray 2 to Plain Paper A5 Short Edge", QStringLiteral("更改进纸匣2为普通纸张A5短边"));
    m_LemarkError.insert("Change tray 3 to Plain Paper A5 Short Edge", QStringLiteral("更改进纸匣3为普通纸张A5短边"));

    m_LemarkError.insert("Change Tray 1 to Plain Paper A5", QStringLiteral("更改进纸匣1为普通纸张A5短边/长边"));
    m_LemarkError.insert("Change Tray 2 to Plain Paper A5", QStringLiteral("更改进纸匣2为普通纸张A5短边/长边"));
    m_LemarkError.insert("Change Tray 3 to Plain Paper A5", QStringLiteral("更改进纸匣3为普通纸张A5短边/长边"));

    m_LemarkError.insert("Change tray 1 to Labels A4", QStringLiteral("更改进纸匣1为标签A4"));
    m_LemarkError.insert("Change tray 2 to Labels A4", QStringLiteral("更改进纸匣2为标签A4"));
    m_LemarkError.insert("Change tray 3 to Labels A4", QStringLiteral("更改进纸匣3为标签A4"));

    m_LemarkError.insert("Paper Jam,manual feeder", QStringLiteral("卡纸，手动进纸器."));
    //用普通纸张A4加载手动进纸器
    m_LemarkError.insert("Load manual feeder with Plain Paper A4", QStringLiteral("用普通纸张A4加载手动进纸器"));
    m_LemarkError.insert("Load manual feeder with Plain Paper A5 Long Edge", QStringLiteral("用普通纸张A5长边加载手动进纸器"));
    m_LemarkError.insert("Load manual feeder with Labels A4", QStringLiteral("用标签A4加载手动进纸器"));
    m_LemarkError.insert("Scanner jam,remove jammed originals from the scanner", QStringLiteral("扫描仪卡纸，从扫描仪中取出被卡的原件"));
    m_LemarkError.insert("Close all doors.", QStringLiteral("关闭所有盖门"));
    m_LemarkError.insert("Reinstall missing or unresponsive cyan cartridge", QStringLiteral("重新安装缺少或无响应的青色碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive magenta cartridge", QStringLiteral("重新安装缺少或无响应的品红色碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive yellow cartridge", QStringLiteral("重新安装缺少或无响应的黄色碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive black cartridge", QStringLiteral("重新安装缺少或无响应的黑色碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive cyan photoconductor", QStringLiteral("重新安装缺少或无响应的青色硒鼓"));
    m_LemarkError.insert("Reinstall missing or unresponsive magenta photoconductor", QStringLiteral("重新安装缺少或无响应的品红色硒鼓"));
    m_LemarkError.insert("Reinstall missing or unresponsive yellow photoconductor", QStringLiteral("重新安装缺少或无响应的黄色硒鼓"));
    m_LemarkError.insert("Reinstall missing or unresponsive black photoconductor", QStringLiteral("重新安装缺少或无响应的黑色硒鼓"));
    m_LemarkError.insert("Replace missing waste toner bottle.", QStringLiteral("更换缺少的废粉瓶"));

    m_LemarkError.insert("Scanner jam.", QStringLiteral("扫描仪卡纸"));
    m_LemarkError.insert("Cyan cartridge problem.Replace it.", QStringLiteral("青色碳粉盒问题"));
    m_LemarkError.insert("Yellow cartridge problem.Replace it.", QStringLiteral("黄色碳粉盒问题"));
    m_LemarkError.insert("Magenta cartridge problem.Replace it.", QStringLiteral("品红色碳粉盒问题"));
    m_LemarkError.insert("Black cartridge problem.Replace it.", QStringLiteral("黑色碳粉盒问题"));

    m_LemarkError.insert("Close doorA[8.01]、Paper jam,tray 1.[200.91A]、Black cartrige low", QStringLiteral("关闭前部盖门A、卡纸、进纸匣1、黑色碳粉不足"));
    m_LemarkError.insert("Black cartridge low", QStringLiteral("黑色碳粉不足"));
    m_LemarkError.insert("Cyan cartridge low", QStringLiteral("青色碳粉不足"));
    m_LemarkError.insert("Yellow cartridge low", QStringLiteral("黄色碳粉不足"));
    m_LemarkError.insert("Magenta cartridge low", QStringLiteral("品红色碳粉不足"));

    m_LemarkError.insert("Black photoconductor low", QStringLiteral("黑色感光鼓不足"));
    m_LemarkError.insert("Cyan photoconductor low", QStringLiteral("青色感光鼓不足"));
    m_LemarkError.insert("Yellow photoconductor low", QStringLiteral("黄色感光鼓不足"));
    m_LemarkError.insert("Magenta photoconductor low", QStringLiteral("品红色感光鼓不足"));

    m_LemarkError.insert("Close doorA", QStringLiteral("关闭前部盖门A"));
    m_LemarkError.insert("Paper jam", QStringLiteral("卡纸"));
    m_LemarkError.insert("tray 1", QStringLiteral("进纸匣1"));
    m_LemarkError.insert("tray 1 low", QStringLiteral("进纸匣1 纸量低"));
    m_LemarkError.insert("tray 2 low", QStringLiteral("进纸匣2 纸量低"));
    m_LemarkError.insert("tray 3 low", QStringLiteral("进纸匣3 纸量低"));
    m_LemarkError.insert("tray 4 low", QStringLiteral("进纸匣4 纸量低"));
    m_LemarkError.insert("tray 5 low", QStringLiteral("进纸匣5 纸量低"));
    m_LemarkError.insert("Tray 1 Low", QStringLiteral("进纸匣1 纸量低"));
    m_LemarkError.insert("Tray 2 Low", QStringLiteral("进纸匣2 纸量低"));
    m_LemarkError.insert("Tray 3 Low", QStringLiteral("进纸匣3 纸量低"));
    m_LemarkError.insert("Tray 4 Low", QStringLiteral("进纸匣4 纸量低"));
    m_LemarkError.insert("Tray 5 Low", QStringLiteral("进纸匣5 纸量低"));
    m_LemarkError.insert("change tray 1 to Light Paper A3", QStringLiteral("更改纸匣1为轻质纸A3"));
    m_LemarkError.insert("change tray 2 to Light Paper A3", QStringLiteral("更改纸匣2为轻质纸A3"));
    m_LemarkError.insert("change tray 3 to Light Paper A3", QStringLiteral("更改纸匣3为轻质纸A3"));
    m_LemarkError.insert("change tray 4 to Light Paper A3", QStringLiteral("更改纸匣4为轻质纸A3"));
    m_LemarkError.insert("change tray 5 to Light Paper A3", QStringLiteral("更改纸匣5为轻质纸A3"));

    m_LemarkError.insert("Paper Jam,open door C and clear all jammed paper.", QStringLiteral("卡纸打开盖门C并清除所有被卡的纸张."));
    m_LemarkError.insert("Load multipurpose feeder with Plain paper A3", QStringLiteral("用普通纸张A3加载多功能进纸器"));
    m_LemarkError.insert("Change multipurpose feeder to Recyled Ofico(Mexico)", QStringLiteral("更改多功能进纸器为再生纸Oficio(墨西哥)"));
    m_LemarkError.insert("Scanner jam,remove jammed originals from the scanner", QStringLiteral("扫描仪卡纸，从扫描仪中取出被卡的原件"));
    m_LemarkError.insert("Remove paper from bin 1", QStringLiteral("从接纸架1上取走纸张"));
    m_LemarkError.insert("Remove paper from bin 2", QStringLiteral("从接纸架2上取走纸张"));
    m_LemarkError.insert("Remove paper from bin 3", QStringLiteral("从接纸架3上取走纸张"));
    m_LemarkError.insert("Remove paper from bin 4", QStringLiteral("从接纸架4上取走纸张"));
    m_LemarkError.insert("Remove paper from bin 5", QStringLiteral("从接纸架5上取走纸张"));
    m_LemarkError.insert("Bin 1 Full", QStringLiteral("接纸架1已满"));
    m_LemarkError.insert("Bin 2 Full", QStringLiteral("接纸架2已满"));
    m_LemarkError.insert("Bin 3 Full", QStringLiteral("接纸架3已满"));
    m_LemarkError.insert("Bin 4 Full", QStringLiteral("接纸架4已满"));
    m_LemarkError.insert("Bin 5 Full", QStringLiteral("接纸架5已满"));

    m_LemarkError.insert("Close door A", QStringLiteral("关闭盖门A"));
    m_LemarkError.insert("Close door B", QStringLiteral("关闭盖门B"));
    m_LemarkError.insert("Close door C", QStringLiteral("关闭盖门C"));
    m_LemarkError.insert("Close door C.", QStringLiteral("关闭盖门C"));
    m_LemarkError.insert("Close door D", QStringLiteral("关闭盖门D"));
    m_LemarkError.insert("Close door E", QStringLiteral("关闭盖门E"));
    m_LemarkError.insert("Close door F", QStringLiteral("关闭盖门F"));
    m_LemarkError.insert("Close door G", QStringLiteral("关闭盖门G"));
    m_LemarkError.insert("Close door H", QStringLiteral("关闭盖门H"));
    m_LemarkError.insert("Close door I", QStringLiteral("关闭盖门I"));
    m_LemarkError.insert("Close door J", QStringLiteral("关闭盖门J"));
    m_LemarkError.insert("Scanner automatic feeder cover open", QStringLiteral("扫描仪自动进纸器盖板打开"));
    m_LemarkError.insert("Scanner Jam Access Cover Open", QStringLiteral("扫描仪卡纸通道盖板打开"));

    m_LemarkError.insert("Paper jam,Remove tray 1.", QStringLiteral("卡纸，取出进纸匣1"));
    m_LemarkError.insert("Paper jam,Remove tray 2.", QStringLiteral("卡纸，取出进纸匣2"));
    m_LemarkError.insert("Paper jam,Remove tray 3.", QStringLiteral("卡纸，取出进纸匣3"));
    m_LemarkError.insert("Paper jam,Remove tray 4.", QStringLiteral("卡纸，取出进纸匣4"));

    m_LemarkError.insert("Change tray 1to plain Paper A5", QStringLiteral("更改进纸匣1位普通纸张A5加载短边"));
    m_LemarkError.insert("Change tray 2to plain Paper A5", QStringLiteral("更改进纸匣2位普通纸张A5加载短边"));
    m_LemarkError.insert("Change tray 3to plain Paper A5", QStringLiteral("更改进纸匣3位普通纸张A5加载短边"));


    m_LemarkError.insert("Replace black cartridge, 0 estimated pages remain", QStringLiteral("替换黑色粉盒，还可以打印0页"));
    m_LemarkError.insert("E-mail SMTP server not set up. Contact system administrator.", QStringLiteral("SMTP邮箱未设置，请与系统管理员联系"));
    m_LemarkError.insert("Close front door", QStringLiteral("关闭前门"));
    m_LemarkError.insert("Reinstall missing or unresponsive cartridge", QStringLiteral("重新安装缺少或无响应的碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive imaging unit", QStringLiteral("重新安装缺少或无响应的定影单元"));
    m_LemarkError.insert("Replace black cartridge, %1 estimated pages remain", QStringLiteral("替换黑色粉盒，还可以打印%1页"));
    m_LemarkError.insert("Replace cyan cartridge, %1 estimated pages remain", QStringLiteral("替换青色粉盒，还可以打印%1页"));
    m_LemarkError.insert("Replace yellow cartridge, %1 estimated pages remain", QStringLiteral("替换黄色粉盒，还可以打印%1页"));
    m_LemarkError.insert("Replace magenta cartridge, %1 estimated pages remain", QStringLiteral("替换品红色粉盒，还可以打印%1页"));
    /*CM2270ADN*/
    m_LemarkError.insert("Replace black cartridge", QStringLiteral("更换黑色粉盒"));
    m_LemarkError.insert("Replace cyan cartridge", QStringLiteral("更换青色粉盒"));
    m_LemarkError.insert("Replace yellow cartridge", QStringLiteral("更换黄色粉盒"));
    m_LemarkError.insert("Replace magenta cartridge", QStringLiteral("更换品红色粉盒"));

    m_LemarkError.insert("Replace unsupported black cartridge", QStringLiteral("更换不支持的黑色碳粉盒"));
    m_LemarkError.insert("Replace unsupported magenta cartridge", QStringLiteral("更换不支持的品红色碳粉盒"));
    m_LemarkError.insert("Replace unsupported cyan cartridge", QStringLiteral("更换不支持的青色碳粉盒"));
    m_LemarkError.insert("Replace unsupported yellow cartridge", QStringLiteral("更换不支持的黄色碳粉盒"));

    /*7600*/
    m_LemarkError.insert("Replace unsupported cartridge", QStringLiteral("更换不支持的碳粉盒"));
    m_LemarkError.insert("Reinstall missing or unresponsive cartridge", QStringLiteral("重新安装缺少或无响应的碳粉盒"));
    m_LemarkError.insert("Cartridge very low", QStringLiteral("碳粉非常不足"));
    m_LemarkError.insert("Load Multipurpose Feeder with Custom Type3 A4", QStringLiteral("用自定义类型3 A4加载多功能进纸器"));
    m_LemarkError.insert("Load Multipurpose Feeder with Card Stock A5", QStringLiteral("用卡片纸A5加载多功能进纸器"));
    m_LemarkError.insert("Load Tray 1 with labels A5", QStringLiteral("用标签A5加载短边加载进纸匣1"));
    m_LemarkError.insert("50 61 70 65 72 20 6A 61 6D 2C 20 63 6C 65 61 72 Paper jam", QStringLiteral("卡纸，清理多功能进纸器将纸张留在接纸架中"));

    m_LemarkError.insert("Paper Jam, Output Bin, door A.", QStringLiteral("卡纸，接纸架，盖门A"));
    m_LemarkError.insert("Paper jam, open front door.", QStringLiteral("卡纸，打开前盖。"));
    m_LemarkError.insert("Std Bin Full", QStringLiteral("标准接纸架已满"));
    m_LemarkError.insert("Standard Bin Full", QStringLiteral("标准接纸架已满"));
    m_LemarkError.insert("Scanner jam,remove jammed originals from the scanner", QStringLiteral("扫描仪卡纸，从扫描仪中取出被卡的原件"));
    m_LemarkError.insert("Paper Jam,open door C and clear all jammed paper", QStringLiteral("卡纸，打开盖门C并清除所有被卡纸张"));
    m_LemarkError.insert("Paper Jam,clear jammed paper from multipurpose feeder", QStringLiteral("卡纸，从多功能进纸器清除被卡的纸张"));
    m_LemarkError.insert("Load multipurpose feeder with Plain Paper A4 Short Edge", QStringLiteral("用普通纸张A4短边加载多功能进纸器"));

    m_LemarkError.insert("Paper jam,read door", QStringLiteral("卡纸，打开后部盖门"));
    m_LemarkError.insert("Paper jam,manual feeder", QStringLiteral("卡纸，手动进纸器"));
    m_LemarkError.insert("Insert tray 1", QStringLiteral("插入进纸匣1"));
    m_LemarkError.insert("Black cartridge problem.Replace it", QStringLiteral("黑色碳粉盒问题"));
    m_LemarkError.insert("Load tray 1 with Plain Paper A4", QStringLiteral("用普通纸张A4加载进纸匣1"));
    m_LemarkError.insert("Load tray 1 with Plain paper A4", QStringLiteral("用普通纸张A4加载进纸匣1"));
    m_LemarkError.insert("Load Tray 1 with Plain Paper A4", QStringLiteral("用普通纸张A4加载进纸匣1"));
    m_LemarkError.insert("Replace waste toner bottle", QStringLiteral("更换废粉瓶"));
    m_LemarkError.insert("Waste toner bottle nearly full", QStringLiteral("废炭粉瓶即将满"));



}

QString Utf8ToCh(QString src)
{
    src = src.trimmed();
    src.append(" ");

    uchar array[1024] = { "\0" };
    int length = src.size() / 3 + 1;
    bool ok = true;
    for (int i = 0; i < length; i++)
    {
        if (ok)
        {
            array[i] = (uchar)src.mid(i * 3, 2).toUInt(&ok, 16);
        }
    }
    return QString::fromUtf8((char*)array);
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantum4020PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);			//sn
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);		//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";		//sn
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");		//mac
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
//    list_value.clear();
//    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
//    if (nResult != QueryResult::Successed) {
//        return info;
//    }
//    PrinterPCount stPCount;
//    stPCount.nColorType = 0;
//    stPCount.nPaperType = 0;
//    stPCount.strNameEn = "A4 Black";
//    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
//    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPCount);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.1";
    list_value.clear();
    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
    list_value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum4020PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);			//sn
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);		//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";		//sn
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");		//mac
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
//    list_value.clear();
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
//    if (nResult != QueryResult::Successed) {
//        return info;
//    }
//    PrinterPCount stPCount;
//    stPCount.nColorType = 0;
//    stPCount.nPaperType = 0;
//    stPCount.strNameEn = "A4 Black";
//    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
//    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPCount);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.1";
    list_value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
//    list_value.clear();

    //black
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
//    if (nResult != QueryResult::Successed)
//    {
//        return info;
//    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantum1820PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    QueryResult nResult;
    //查询型号
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //查询打印机尺寸信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.13.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.16.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString tmpErrorCode = list_value.size() > 0 ? list_value.at(0).strValue : "";
    QStringList strListError = tmpErrorCode.split(newLine);
    QString strErrorCode;
    for (int i = 0; i < strListError.size(); ++i)
    {
        QString tmp = strListError.at(i);
        tmp = tmp.left(49);
        tmp.replace("  ", " ");
        strListError[i] = tmp;
        strErrorCode.append(strListError[i]);
    }
    strErrorCode = strErrorCode.trimmed();
    QStringList listErroeCode = strErrorCode.split(" ");

    bool ok;
    int nStatusCode = listErroeCode[0].toInt(&ok, 16);
    int nTime = listErroeCode[1].toInt(&ok, 16); //休眠时间
    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;
    if (nStatusCode == 5)//5 错误信息
    {
        PrinterMIBError pError;
        if (listErroeCode[40] == "FE")//内部故障 //1111 1110
        {
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部故障");
            pError.ErrorDescEN = QStringLiteral("Internal Fault");
            pError.nErrorLevel = 1;
        }
        else if (listErroeCode[40] == "FD")//开盖错误 1111 1101
        {
            int nDoorError = listErroeCode[46].toInt(&ok, 16);
            if (nDoorError == 1)
            {
                pError.nErrorCode = 60022;
                pError.ErrorDesc = QStringLiteral("前盖打开");
                pError.ErrorDescEN = QStringLiteral("Front Shell Open");
                pError.nErrorLevel = 5;
            }
            else if (nDoorError == 2)
            {
                pError.nErrorCode = 60021;
                pError.ErrorDesc = QStringLiteral("后盖打开");
                pError.ErrorDescEN = QStringLiteral("Back Shell Open");
                pError.nErrorLevel = 5;
            }
        }
        else if (listErroeCode[40] == "FB")//耗材错误 1111 1011
        {
            //48~51碳粉盒
            //黄色粉盒listErroeCode[48]
            int nYelloTonerError = listErroeCode[48].toInt(&ok, 16);
            switch (nYelloTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[3] = '0';	//未检测到黄色碳粉盒
                break;
            case 2:
                info.adInfo.toners[3] = '2';	//黄色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[3] = '4';	//黄色粉盒寿命尽
                break;
            default:
                break;
            }

            //品红色碳粉盒 listErroeCode[49];
            int nMagentaTonerError = listErroeCode[49].toInt(&ok, 16);
            switch (nMagentaTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[2] = '0';	//未检测到品红色碳粉盒
                break;
            case 2:
                info.adInfo.toners[2] = '2';	//品红色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[2] = '4';	//品红色粉盒寿命尽
                break;
            default:
                break;
            }

            //青色碳粉盒 listErroeCode[50];
            int nCyanTonerError = listErroeCode[50].toInt(&ok, 16);
            switch (nCyanTonerError)
            {
            case 0:
                pError.nErrorCode = 0;
                break;
            case 1:
                info.adInfo.toners[1] = '0';	//未检测到青色碳粉盒
                break;
            case 2:
                info.adInfo.toners[1] = '2';	//青色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[1] = '4';	//青色粉盒寿命尽
                break;
            default:
                break;
            }

            //黑色碳粉盒 listErroeCode[51];
            int nBlackTonerError = listErroeCode[51].toInt(&ok, 16);
            switch (nBlackTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[0] = '0';	//未检测到黑色碳粉盒
                break;
            case 2:
                info.adInfo.toners[0] = '2';	//黑色碳粉盒不匹配状态

                break;
            case 3:
                info.adInfo.toners[0] = '4';	//黑色粉盒寿命尽
                break;
            default:
                break;
            }
        }
        else if (listErroeCode[40] == "F7")//缺纸错误 1111 0111
        {
            int nLackPaperError = listErroeCode[57].toInt(&ok, 16);
            switch (nLackPaperError)
            {
            case 0:
                break;
            case 7:
                pError.nErrorCode = 60065;
                pError.ErrorDesc = QStringLiteral("手动纸盒缺纸");
                pError.ErrorDescEN = QStringLiteral("Manual No Paper");
                pError.nErrorLevel = 5;
                break;
            case 8:
                pError.nErrorCode = 60091;
                pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
                pError.ErrorDescEN = QStringLiteral("Paper Source dismatch");
                pError.nErrorLevel = 5;
                break;
            case 9:
                pError.nErrorCode = 60093;
                pError.ErrorDesc = QStringLiteral("自动进纸盒纸张设置不匹配");
                pError.ErrorDescEN = QStringLiteral("Auto Paper dismatch");
                pError.nErrorLevel = 5;
            default:
                pError.nErrorCode = 60060;
                pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
                pError.ErrorDescEN = QStringLiteral("Paper Feed Fail Or No Paper");
                pError.nErrorLevel = 5;
                break;
            }
        }
        else if (listErroeCode[40] == "EF")//卡纸错误 1110 1111
        {
            int nPaperError = listErroeCode[58].toInt(&ok, 16);
            switch (nPaperError)
            {
            case 0:
                break;
            case 8:
                pError.nErrorCode = 60010;
                pError.ErrorDesc = QStringLiteral("手动进纸卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
                pError.nErrorLevel = 5;
                break;
            case 9:
                pError.nErrorCode = 60066;
                pError.ErrorDesc = QStringLiteral("自动进纸盒进纸失败或缺纸");
                pError.ErrorDescEN = QStringLiteral("Auto No Paper");
                pError.nErrorLevel = 5;
                break;
            case 11:
                pError.nErrorCode = 60008;
                pError.ErrorDesc = QStringLiteral("双面单元卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Two Side Unit");
                pError.nErrorLevel = 5;
            case 13:
                pError.nErrorCode = 60013;
                pError.ErrorDesc = QStringLiteral("出口处卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Exit");
                pError.nErrorLevel = 5;
                break;
            case 14:
                pError.nErrorCode = 60035;
                pError.ErrorDesc = QStringLiteral("手动进纸失败");
                pError.ErrorDescEN = QStringLiteral("Manual No Paper");
                pError.nErrorLevel = 5;
            case 15:
                pError.nErrorCode = 60012;
                pError.ErrorDesc = QStringLiteral("中间卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Middle");
                pError.nErrorLevel = 5;
            default:
                pError.nErrorCode = 60001;
                pError.ErrorDesc = QStringLiteral("卡纸错误");
                pError.ErrorDescEN = QStringLiteral("Paper Jam");
                pError.nErrorLevel = 5;
                break;
            }
        }
        else if (listErroeCode[40] == "DF")//纸盒未插入错误 1101 1111
        {
            int nPaperError = listErroeCode[59].toInt(&ok, 16);
            if (nPaperError == 6)
            {
                pError.nErrorCode = 60094;
                pError.ErrorDesc = QStringLiteral("自动进纸盒未插入");
                pError.ErrorDescEN = QStringLiteral("Input Tray Not Insert ");
                pError.nErrorLevel = 5;
            }
            else if (nPaperError == 8)
            {
                pError.nErrorCode = 60095;
                pError.ErrorDesc = QStringLiteral("找不到匹配纸盒");
                pError.ErrorDescEN = QStringLiteral("cannot find match Carton");
                pError.nErrorLevel = 5;
            }
        }
        else if (listErroeCode[40] == "BF")//出纸口满错误 1011 1111
        {
            pError.nErrorCode = 60040;
            pError.ErrorDesc = QStringLiteral("出纸口满");
            pError.ErrorDescEN = QStringLiteral("Paper Full At Exit ");
            pError.nErrorLevel = 5;
        }

        if (listErroeCode[55].toInt(&ok, 16) == 5) //废粉瓶异常
        {
            int nWasteTonerError = listErroeCode[56].toInt(&ok, 16);
            if (nWasteTonerError == 1)
            {
                info.adInfo.wasteToner = "0";//废粉瓶未安装
            }
            else if (nWasteTonerError == 11)
            {
                info.adInfo.wasteToner = "4";//废粉瓶已满
            }
            //else if (nWasteTonerError == 12)
            //{
            //	pError.nErrorCode = -5;
            //	pError.ErrorDesc = QStringLiteral("废粉瓶将满");
            //	pError.ErrorDescEN = QStringLiteral("Waste Toner Is Nearly Full");
            //	pError.nErrorLevel = 4;
            //	info.adInfo.wasteToner = "3";//废粉瓶将满
            //}
        }

        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询粉量低告警
    int nTonerWarn = listErroeCode[6].toInt(&ok, 16);
    if (nTonerWarn & (1 << 0))
    {
        //将1左移0位后与 nTonerWarn按位与之后的结果非0则表示：黑色粉量低
        info.adInfo.toners[0] = '3';
    }
    if (nTonerWarn & (1 << 1))
    {
        //将1左移1位后与 nTonerWarn按位与之后的结果非0则表示：青色粉量低
        info.adInfo.toners[1] = '3';
    }
    if (nTonerWarn & (1 << 2))
    {
        //将1左移2位后与 nTonerWarn按位与之后的结果非0则表示：品红色粉量低
        info.adInfo.toners[2] = '3';
    }
    if (nTonerWarn & (1 << 3))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：黄色色粉量低
        info.adInfo.toners[3] = '3';
    }
    if (nTonerWarn & (1 << 4))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：废粉盒将满
        info.adInfo.wasteToner = "3";//废粉瓶将满
    }

    //查询印量
    QString strQueryA4BlcakOID = "1.3.6.1.4.1.40093.1.1.3.13.19";
    QString strQueryA4ColorOID = "1.3.6.1.4.1.40093.1.1.3.13.20";
    QString strQueryA3BlackOID = "1.3.6.1.4.1.40093.1.1.3.13.21";
    QString strQueryA3ColorOID = "1.3.6.1.4.1.40093.1.1.3.13.22";
    list_value.clear();
    int nPaperCount = 0;
    //A4
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA4BlcakOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA4BlackPCount;
    stA4BlackPCount.nColorType = 0;
    stA4BlackPCount.nPaperType = 0;
    stA4BlackPCount.strNameEn = "A4 Black";
    stA4BlackPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stA4BlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA4BlackPCount);
    list_value.clear();
    //A4 Color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA4ColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA4ColorPCount;
    stA4ColorPCount.nColorType = 1;
    stA4ColorPCount.nPaperType = 0;
    stA4ColorPCount.strNameEn = "A4 Color";
    stA4ColorPCount.strNameCn = QStringLiteral("A4 彩色印量");
    stA4ColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA4ColorPCount);
    list_value.clear();

    //目前1820都是A4机，故暂时屏蔽A3印量的获取
    /*
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA3BlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
    return info;
    }
    PrinterPCount stA3BlackPCount;
    stA3BlackPCount.nColorType = 0;
    stA3BlackPCount.nPaperType = 1;
    stA3BlackPCount.strNameEn = "A3 Black";
    stA3BlackPCount.strNameCn = QStringLiteral("A3 黑白印量");
    stA3BlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3BlackPCount);
    list_value.clear();

    //A3 Color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA3ColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
    return info;
    }
    PrinterPCount stA3ColorPCount;
    stA3ColorPCount.nColorType = 1;
    stA3ColorPCount.nPaperType = 1;
    stA3ColorPCount.strNameEn = "A3 Color";
    stA3ColorPCount.strNameCn = QStringLiteral("A3 彩色印量");
    stA3ColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3ColorPCount);
    list_value.clear();
    */

    //查询粉盒序列号
    QString strQueryBlackTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.23";
    QString strQueryCyanTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.24";
    QString strQueryMagentaTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.25";
    QString strQueryYellowTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.26";
    //查询粉盒余量
    int nBlackTonerRest = listErroeCode[2].toInt(&ok, 16);
    int nCyanTonerRest = listErroeCode[3].toInt(&ok, 16);
    int nMagentaTonerRest = listErroeCode[4].toInt(&ok, 16);
    int nYellowTonerRest = listErroeCode[5].toInt(&ok, 16);

    //查询黑色粉盒和SN
    PrinterToner stBlackToner;
    stBlackToner.nColorType = 1;
    stBlackToner.nTonerID = 0;
    stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stBlackToner.nCurrent = nBlackTonerRest;
    QString strTempKSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempKSN.replace(" ", "");
    strTempKSN = strTempKSN.left(12);
    stBlackToner.strTonerSN = strTempKSN;
    info.listTonerDetail.push_back(stBlackToner);
    list_value.clear();

    //查询青色粉盒和SN
    PrinterToner stCyanToner;
    stCyanToner.nColorType = 2;
    stCyanToner.nTonerID = 1;
    stCyanToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stCyanToner.nCurrent = nCyanTonerRest;
    QString strTempCSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempCSN.replace(" ", "");
    strTempCSN = strTempCSN.left(12);
    stCyanToner.strTonerSN = strTempCSN;

    info.listTonerDetail.push_back(stCyanToner);
    list_value.clear();

    //查询品红色粉盒和SN
    PrinterToner stMagentaToner;
    stMagentaToner.nColorType = 3;
    stMagentaToner.nTonerID = 2;
    stMagentaToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stMagentaToner.nCurrent = nMagentaTonerRest;
    QString strTempMSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempMSN.replace(" ", "");
    strTempMSN = strTempMSN.left(12);
    stMagentaToner.strTonerSN = strTempMSN;
    info.listTonerDetail.push_back(stMagentaToner);
    list_value.clear();

    //查询黄色粉盒和SN
    PrinterToner stYellowToner;
    stYellowToner.nColorType = 4;
    stYellowToner.nTonerID = 3;
    stYellowToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stYellowToner.nCurrent = nYellowTonerRest;
    QString strTempYSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempYSN.replace(" ", "");
    strTempYSN = strTempYSN.left(12);
    stYellowToner.strTonerSN = strTempYSN;

    info.listTonerDetail.push_back(stYellowToner);
    list_value.clear();


    //1820暂不获取硒鼓
    /*
    //查询硒鼓余量
    QString strQueryBlackRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.15";
    QString strQueryCyanRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.16";
    QString strQueryMagentaRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.17";
    QString strQueryYellowRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.18";

    //查询硒鼓序列号
    QString strQueryBlackDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.27";
    QString strQueryCyanDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.28";
    QString strQueryMagentaDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.29";
    QString strQueryYellowDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.30";
    int nDrumMaxValue = 0;
    int nDrumRestValue = 0;

    //查询黑色硒鼓和SN
    PrinterDrum stBlackDrum;
    stBlackDrum.nColorType = 1;
    stBlackDrum.nDrumID = 0;
    stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stBlackDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stBlackDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";;
    info.listDrumDetail.push_back(stBlackDrum);
    list_value.clear();

    //查询青色硒鼓和SN
    PrinterDrum  stCyanDrum;
    stCyanDrum.nColorType = 2;
    stCyanDrum.nDrumID= 1;
    stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stCyanDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stCyanDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stCyanDrum);
    list_value.clear();

    //查询品红色硒鼓和SN
    PrinterDrum stMagentaDrum;
    stMagentaDrum.nColorType = 3;
    stMagentaDrum.nDrumID = 2;
    stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stMagentaDrum);
    list_value.clear();

    //查询黄色硒鼓和SN
    PrinterDrum stYellowDrum;
    stYellowDrum.nColorType = 4;
    stYellowDrum.nDrumID = 3;
    stYellowDrum.strDrumName = QStringLiteral("Cyan Photoconductor|黄色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stYellowDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stYellowDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stYellowDrum);
    list_value.clear();
    */

    //查询废粉信息
    QString strQueryWasteTonerRestOID = "1.3.6.1.4.1.40093.1.1.3.13.14";
    QString strQueryWasteTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.31";
    PrinterWasteToner stWasteToner;
    stWasteToner.nWasteTonerID = 0;
    stWasteToner.strWasteTonerModel;
    stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryWasteTonerRestOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    stWasteToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryWasteTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stWasteToner.strWasteTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listWasteTonerDetail.push_back(stWasteToner);
    list_value.clear();
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum1820PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //查询打印机尺寸信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.13.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.16.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString tmpErrorCode = list_value.size() > 0 ? list_value.at(0).strValue : "";
    QStringList strListError = tmpErrorCode.split(newLine);
    QString strErrorCode;
    for (int i = 0; i < strListError.size(); ++i)
    {
        QString tmp = strListError.at(i);
        tmp = tmp.left(49);
        tmp.replace("  ", " ");
        strListError[i] = tmp;
        strErrorCode.append(strListError[i]);
    }
    strErrorCode = strErrorCode.trimmed();
    QStringList listErroeCode = strErrorCode.split(" ");

    bool ok;
    int nStatusCode = listErroeCode[0].toInt(&ok, 16);
    int nTime = listErroeCode[1].toInt(&ok, 16); //休眠时间
    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;
    if (nStatusCode == 5)//5 错误信息
    {
        PrinterMIBError pError;
        if (listErroeCode[40] == "FE")//内部故障 //1111 1110
        {
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部故障");
            pError.ErrorDescEN = QStringLiteral("Internal Fault");
            pError.nErrorLevel = 1;
        }
        else if (listErroeCode[40] == "FD")//开盖错误 1111 1101
        {
            int nDoorError = listErroeCode[46].toInt(&ok, 16);
            if (nDoorError == 1)
            {
                pError.nErrorCode = 60022;
                pError.ErrorDesc = QStringLiteral("前盖打开");
                pError.ErrorDescEN = QStringLiteral("Front Shell Open");
                pError.nErrorLevel = 5;
            }
            else if (nDoorError == 2)
            {
                pError.nErrorCode = 60021;
                pError.ErrorDesc = QStringLiteral("后盖打开");
                pError.ErrorDescEN = QStringLiteral("Back Shell Open");
                pError.nErrorLevel = 5;
            }
        }
        else if (listErroeCode[40] == "FB")//耗材错误 1111 1011
        {
            //48~51碳粉盒
            //黄色粉盒listErroeCode[48]
            int nYelloTonerError = listErroeCode[48].toInt(&ok, 16);
            switch (nYelloTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[3] = '0';	//未检测到黄色碳粉盒
                break;
            case 2:
                info.adInfo.toners[3] = '2';	//黄色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[3] = '4';	//黄色粉盒寿命尽
                break;
            default:
                break;
            }

            //品红色碳粉盒 listErroeCode[49];
            int nMagentaTonerError = listErroeCode[49].toInt(&ok, 16);
            switch (nMagentaTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[2] = '0';	//未检测到品红色碳粉盒
                break;
            case 2:
                info.adInfo.toners[2] = '2';	//品红色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[2] = '4';	//品红色粉盒寿命尽
                break;
            default:
                break;
            }

            //青色碳粉盒 listErroeCode[50];
            int nCyanTonerError = listErroeCode[50].toInt(&ok, 16);
            switch (nCyanTonerError)
            {
            case 0:
                pError.nErrorCode = 0;
                break;
            case 1:
                info.adInfo.toners[1] = '0';	//未检测到青色碳粉盒
                break;
            case 2:
                info.adInfo.toners[1] = '2';	//青色碳粉盒不匹配状态
                break;
            case 3:
                info.adInfo.toners[1] = '4';	//青色粉盒寿命尽
                break;
            default:
                break;
            }

            //黑色碳粉盒 listErroeCode[51];
            int nBlackTonerError = listErroeCode[51].toInt(&ok, 16);
            switch (nBlackTonerError)
            {
            case 0:
                break;
            case 1:
                info.adInfo.toners[0] = '0';	//未检测到黑色碳粉盒
                break;
            case 2:
                info.adInfo.toners[0] = '2';	//黑色碳粉盒不匹配状态

                break;
            case 3:
                info.adInfo.toners[0] = '4';	//黑色粉盒寿命尽
                break;
            default:
                break;
            }
        }
        else if (listErroeCode[40] == "F7")//缺纸错误 1111 0111
        {
            int nLackPaperError = listErroeCode[57].toInt(&ok, 16);
            switch (nLackPaperError)
            {
            case 0:
                break;
            case 7:
                pError.nErrorCode = 60065;
                pError.ErrorDesc = QStringLiteral("手动纸盒缺纸");
                pError.ErrorDescEN = QStringLiteral("Manual No Paper");
                pError.nErrorLevel = 5;
                break;
            case 8:
                pError.nErrorCode = 60091;
                pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
                pError.ErrorDescEN = QStringLiteral("Paper Source dismatch");
                pError.nErrorLevel = 5;
                break;
            case 9:
                pError.nErrorCode = 60093;
                pError.ErrorDesc = QStringLiteral("自动进纸盒纸张设置不匹配");
                pError.ErrorDescEN = QStringLiteral("Auto Paper dismatch");
                pError.nErrorLevel = 5;
            default:
                pError.nErrorCode = 60060;
                pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
                pError.ErrorDescEN = QStringLiteral("Paper Feed Fail Or No Paper");
                pError.nErrorLevel = 5;
                break;
            }
        }
        else if (listErroeCode[40] == "EF")//卡纸错误 1110 1111
        {
            int nPaperError = listErroeCode[58].toInt(&ok, 16);
            switch (nPaperError)
            {
            case 0:
                break;
            case 8:
                pError.nErrorCode = 60010;
                pError.ErrorDesc = QStringLiteral("手动进纸卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
                pError.nErrorLevel = 5;
                break;
            case 9:
                pError.nErrorCode = 60066;
                pError.ErrorDesc = QStringLiteral("自动进纸盒进纸失败或缺纸");
                pError.ErrorDescEN = QStringLiteral("Auto No Paper");
                pError.nErrorLevel = 5;
                break;
            case 11:
                pError.nErrorCode = 60008;
                pError.ErrorDesc = QStringLiteral("双面单元卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Two Side Unit");
                pError.nErrorLevel = 5;
            case 13:
                pError.nErrorCode = 60013;
                pError.ErrorDesc = QStringLiteral("出口处卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Exit");
                pError.nErrorLevel = 5;
                break;
            case 14:
                pError.nErrorCode = 60035;
                pError.ErrorDesc = QStringLiteral("手动进纸失败");
                pError.ErrorDescEN = QStringLiteral("Manual No Paper");
                pError.nErrorLevel = 5;
            case 15:
                pError.nErrorCode = 60012;
                pError.ErrorDesc = QStringLiteral("中间卡纸");
                pError.ErrorDescEN = QStringLiteral("Paper Jam At Middle");
                pError.nErrorLevel = 5;
            default:
                pError.nErrorCode = 60001;
                pError.ErrorDesc = QStringLiteral("卡纸错误");
                pError.ErrorDescEN = QStringLiteral("Paper Jam");
                pError.nErrorLevel = 5;
                break;
            }
        }
        else if (listErroeCode[40] == "DF")//纸盒未插入错误 1101 1111
        {
            int nPaperError = listErroeCode[59].toInt(&ok, 16);
            if(nPaperError == 6)
            {
                pError.nErrorCode = 60094;
                pError.ErrorDesc = QStringLiteral("自动进纸盒未插入");
                pError.ErrorDescEN = QStringLiteral("Input Tray Not Insert ");
                pError.nErrorLevel = 5;
            }
            else if (nPaperError == 8)
            {
                pError.nErrorCode = 60095;
                pError.ErrorDesc = QStringLiteral("找不到匹配纸盒");
                pError.ErrorDescEN = QStringLiteral("cannot find match Carton");
                pError.nErrorLevel = 5;
            }
        }
        else if (listErroeCode[40] == "BF")//出纸口满错误 1011 1111
        {
            pError.nErrorCode = 60040;
            pError.ErrorDesc = QStringLiteral("出纸口满");
            pError.ErrorDescEN = QStringLiteral("Paper Full At Exit ");
            pError.nErrorLevel = 5;
        }

        if (listErroeCode[55].toInt(&ok, 16) == 5) //废粉瓶异常
        {
            int nWasteTonerError = listErroeCode[56].toInt(&ok, 16);
            if (nWasteTonerError == 1)
            {
                info.adInfo.wasteToner = "0";//废粉瓶未安装
            }
            else if (nWasteTonerError == 11)
            {
                info.adInfo.wasteToner = "4";//废粉瓶已满
            }
            //else if (nWasteTonerError == 12)
            //{
            //	pError.nErrorCode = -5;
            //	pError.ErrorDesc = QStringLiteral("废粉瓶将满");
            //	pError.ErrorDescEN = QStringLiteral("Waste Toner Is Nearly Full");
            //	pError.nErrorLevel = 4;
            //	info.adInfo.wasteToner = "3";//废粉瓶将满
            //}
        }

        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询粉量低告警
    int nTonerWarn = listErroeCode[6].toInt(&ok, 16);
    if (nTonerWarn & (1 << 0))
    {
        //将1左移0位后与 nTonerWarn按位与之后的结果非0则表示：黑色粉量低
        info.adInfo.toners[0] = '3';
    }
    if (nTonerWarn & (1 << 1))
    {
        //将1左移1位后与 nTonerWarn按位与之后的结果非0则表示：青色粉量低
        info.adInfo.toners[1] = '3';
    }
    if (nTonerWarn & (1 << 2))
    {
        //将1左移2位后与 nTonerWarn按位与之后的结果非0则表示：品红色粉量低
        info.adInfo.toners[2] = '3';
    }
    if (nTonerWarn & (1 << 3))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：黄色色粉量低
        info.adInfo.toners[3] = '3';
    }
    if (nTonerWarn & (1 << 4))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：废粉盒将满
        info.adInfo.wasteToner = "3";//废粉瓶将满
    }

    //查询印量
    QString strQueryA4BlcakOID = "1.3.6.1.4.1.40093.1.1.3.13.19";
    QString strQueryA4ColorOID = "1.3.6.1.4.1.40093.1.1.3.13.20";
    QString strQueryA3BlackOID = "1.3.6.1.4.1.40093.1.1.3.13.21";
    QString strQueryA3ColorOID = "1.3.6.1.4.1.40093.1.1.3.13.22";
    list_value.clear();
    int nPaperCount = 0;
    //A4
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryA4BlcakOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA4BlackPCount;
    stA4BlackPCount.nColorType = 0;
    stA4BlackPCount.nPaperType = 0;
    stA4BlackPCount.strNameEn = "A4 Black";
    stA4BlackPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stA4BlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA4BlackPCount);
    list_value.clear();
    //A4 Color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryA4ColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA4ColorPCount;
    stA4ColorPCount.nColorType = 1;
    stA4ColorPCount.nPaperType = 0;
    stA4ColorPCount.strNameEn = "A4 Color";
    stA4ColorPCount.strNameCn = QStringLiteral("A4 彩色印量");
    stA4ColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA4ColorPCount);
    list_value.clear();

    //目前1820都是A4机，故暂时屏蔽A3印量的获取
    /*
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryA3BlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA3BlackPCount;
    stA3BlackPCount.nColorType = 0;
    stA3BlackPCount.nPaperType = 1;
    stA3BlackPCount.strNameEn = "A3 Black";
    stA3BlackPCount.strNameCn = QStringLiteral("A3 黑白印量");
    stA3BlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3BlackPCount);
    list_value.clear();

    //A3 Color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryA3ColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stA3ColorPCount;
    stA3ColorPCount.nColorType = 1;
    stA3ColorPCount.nPaperType = 1;
    stA3ColorPCount.strNameEn = "A3 Color";
    stA3ColorPCount.strNameCn = QStringLiteral("A3 彩色印量");
    stA3ColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3ColorPCount);
    list_value.clear();
*/

    //查询粉盒序列号
    QString strQueryBlackTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.23";
    QString strQueryCyanTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.24";
    QString strQueryMagentaTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.25";
    QString strQueryYellowTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.26";
    //查询粉盒余量
    int nBlackTonerRest = listErroeCode[2].toInt(&ok, 16);
    int nCyanTonerRest = listErroeCode[3].toInt(&ok, 16);
    int nMagentaTonerRest = listErroeCode[4].toInt(&ok, 16);
    int nYellowTonerRest = listErroeCode[5].toInt(&ok, 16);

    //查询黑色粉盒和SN
    PrinterToner stBlackToner;
    stBlackToner.nColorType = 1;
    stBlackToner.nTonerID = 0;
    stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stBlackToner.nCurrent = nBlackTonerRest;
    QString strTempKSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempKSN.replace(" ", "");
    strTempKSN = strTempKSN.left(12);
    stBlackToner.strTonerSN = strTempKSN;
    info.listTonerDetail.push_back(stBlackToner);
    list_value.clear();

    //查询青色粉盒和SN
    PrinterToner stCyanToner;
    stCyanToner.nColorType = 2;
    stCyanToner.nTonerID = 1;
    stCyanToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryCyanTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stCyanToner.nCurrent = nCyanTonerRest;
    QString strTempCSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempCSN.replace(" ", "");
    strTempCSN = strTempCSN.left(12);
    stCyanToner.strTonerSN = strTempCSN;

    info.listTonerDetail.push_back(stCyanToner);
    list_value.clear();

    //查询品红色粉盒和SN
    PrinterToner stMagentaToner;
    stMagentaToner.nColorType = 3;
    stMagentaToner.nTonerID = 2;
    stMagentaToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
    list_value.clear();

    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMagentaTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stMagentaToner.nCurrent = nMagentaTonerRest;
    QString strTempMSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempMSN.replace(" ", "");
    strTempMSN = strTempMSN.left(12);
    stMagentaToner.strTonerSN = strTempMSN;
    info.listTonerDetail.push_back(stMagentaToner);
    list_value.clear();

    //查询黄色粉盒和SN
    PrinterToner stYellowToner;
    stYellowToner.nColorType = 4;
    stYellowToner.nTonerID = 3;
    stYellowToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryYellowTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stYellowToner.nCurrent = nYellowTonerRest;
    QString strTempYSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempYSN.replace(" ", "");
    strTempYSN = strTempYSN.left(12);
    stYellowToner.strTonerSN =  strTempYSN;

    info.listTonerDetail.push_back(stYellowToner);
    list_value.clear();


    //1820暂不获取硒鼓
    /*
    //查询硒鼓余量
    QString strQueryBlackRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.15";
    QString strQueryCyanRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.16";
    QString strQueryMagentaRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.17";
    QString strQueryYellowRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.18";

    //查询硒鼓序列号
    QString strQueryBlackDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.27";
    QString strQueryCyanDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.28";
    QString strQueryMagentaDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.29";
    QString strQueryYellowDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.30";
    int nDrumMaxValue = 0;
    int nDrumRestValue = 0;

    //查询黑色硒鼓和SN
    PrinterDrum stBlackDrum;
    stBlackDrum.nColorType = 1;
    stBlackDrum.nDrumID = 0;
    stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stBlackDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();

    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stBlackDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";;
    info.listDrumDetail.push_back(stBlackDrum);
    list_value.clear();

    //查询青色硒鼓和SN
    PrinterDrum  stCyanDrum;
    stCyanDrum.nColorType = 2;
    stCyanDrum.nDrumID= 1;
    stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryCyanRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stCyanDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryCyanDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stCyanDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stCyanDrum);
    list_value.clear();

    //查询品红色硒鼓和SN
    PrinterDrum stMagentaDrum;
    stMagentaDrum.nColorType = 3;
    stMagentaDrum.nDrumID = 2;
    stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMagentaRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMagentaDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stMagentaDrum);
    list_value.clear();

    //查询黄色硒鼓和SN
    PrinterDrum stYellowDrum;
    stYellowDrum.nColorType = 4;
    stYellowDrum.nDrumID = 3;
    stYellowDrum.strDrumName = QStringLiteral("Cyan Photoconductor|黄色硒鼓");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryYellowRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stYellowDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryYellowDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stYellowDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stYellowDrum);
    list_value.clear();
*/

    //查询废粉信息
    QString strQueryWasteTonerRestOID = "1.3.6.1.4.1.40093.1.1.3.13.14";
    QString strQueryWasteTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.31";
    PrinterWasteToner stWasteToner;
    stWasteToner.nWasteTonerID = 0;
    stWasteToner.strWasteTonerModel;
    stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryWasteTonerRestOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    stWasteToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryWasteTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stWasteToner.strWasteTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listWasteTonerDetail.push_back(stWasteToner);
    list_value.clear();
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantum2013PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.8", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();
        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case -1://无错误
            break;
        case -2://致命错误
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.1", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
            {
            case 32:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 33:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 34:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 35:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 36:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 37:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 38:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 39:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 40:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 45:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 46:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 47:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case -3://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case -5://粉盒状态
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.3", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners = "0"; //未安装粉盒
                break;
            case 2:
                info.adInfo.toners = "2";	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners = "4";	//粉盒用尽/粉盒寿命尽
                break;
            default:
                break;
            }
            break;
        case -9://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case -17://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case -33://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Setting Mismatch");
            pError.nErrorLevel = 5;
            break;
        case -65://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Mismatch");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.12", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.13", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString strTempSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    stToner.strTonerSN = strTempSN;
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.9.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    //2013机型粉盒未安装时耗材管理延迟显示未安装状态，此版本先不采用下列代码
    /*int nRestValue = 0;
    if (info.adInfo.toners == "0")
    {
    nRestValue = -2;
    }
    else
    {
    nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    }*/

    int nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.8.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nMaxValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 1;
    stToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    info.listTonerDetail.push_back(stToner);

    //查询是否粉量低
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.14.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nWarning = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nWarning == 1)
    {
        info.adInfo.toners = '3';
    }

    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum2013PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.8", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();
        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case -1://无错误
            break;
        case -2://致命错误
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.1", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
            {
            case 32:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 33:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 34:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 35:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 36:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 37:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 38:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 39:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 40:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 45:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 46:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 47:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case -3://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case -5://粉盒状态
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.3", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners = "0"; //未安装粉盒
                break;
            case 2:
                info.adInfo.toners = "2";	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners = "4";	//粉盒用尽/粉盒寿命尽
                break;
            default:
                break;
            }
            break;
        case -9://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case -17://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case -33://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Setting Mismatch");
            pError.nErrorLevel = 5;
            break;
        case -65://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Mismatch");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.12", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.13", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString strTempSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    stToner.strTonerSN = strTempSN;
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.9.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    //2013机型粉盒未安装时耗材管理延迟显示未安装状态，此版本先不采用下列代码
    /*int nRestValue = 0;
    if (info.adInfo.toners == "0")
    {
        nRestValue = -2;
    }
    else
    {
        nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    }*/

    int nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.8.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nMaxValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 1;
    stToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    info.listTonerDetail.push_back(stToner);

    //查询是否粉量低
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.14.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nWarning = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nWarning == 1)
    {
        info.adInfo.toners = '3';
    }

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantumPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    if(info.baseinfo.strPrinterSN.isEmpty())  //old mib
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
        if (nResult != QueryResult::Successed){
            return info;
        }
        info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    }
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);    //old :1.3.6.1.4.1.40093.1.1.3.1
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        case 13://进纸失败或缺纸
            pError.nErrorCode = 60271;
            pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed Or Tray Empty");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }    
    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.4";//3.1.4黑白
    QString strQueryColorOID = "1.3.6.1.4.1.40093.10.3.1.3";//3.1.3彩色
    list_value.clear();

    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
    list_value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();

    //color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    list_value.clear();

    //查询粉盒
    QString strTonerIndexOID = "1.3.6.1.4.1.40093.10.1.5.2.1.1";
    QString strTonerRemainOID = "1.3.6.1.4.1.40093.10.1.5.2.1.3";
    QString strTonerModelOID = "1.3.6.1.4.1.40093.10.1.5.2.1.5";
    QString strTonerSNOID = "1.3.6.1.4.1.40093.10.1.5.2.1.6";
    QString strTonerStatusOID = "1.3.6.1.4.1.40093.10.1.5.2.1.7";

    QList<MibValue> List_Value;
    QString indexOID = strTonerIndexOID;
    //WriteLog::writeToLog("start get oid ...............");
    list_value.clear();
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, indexOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strTonerIndexOID)) {
            WriteLog::writeToLog("oid is " + List_Value.at(0).strOID);
            WriteLog::writeToLog("value is " + List_Value.at(0).strValue);
            indexOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            list_value.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    /*list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strTonerIndexOID, strRet, list_value);
        if (nResult != QueryResult::Successed) {
            return info;
        }*/
    WriteLog::writeToLog("list_value size is " + QString::number(list_value.size()));
    QList<MibValue> listMibValue;
    for (auto oid : list_value)
    {
        WriteLog::writeToLog("start for....");
        PrinterToner stToner;

        //替换余量oid
        QString strRemainOID = oid.strOID;
        strRemainOID.replace(strTonerIndexOID, strTonerRemainOID);
        WriteLog::writeToLog("oid.strOID is " + oid.strOID);
        WriteLog::writeToLog("remain oid is " + strRemainOID);

        //替换型号OID
        QString strModelOID = oid.strOID;
        strModelOID.replace(strTonerIndexOID, strTonerModelOID);
        WriteLog::writeToLog("Model oid is " + strModelOID);
        //替换SN OID
        QString strSNOID = oid.strOID;
        strSNOID.replace(strTonerIndexOID, strTonerSNOID);
        //WriteLog::writeToLog("SN oid is " + strSNOID);
        //替换粉盒状态OID
        QString strStatusOID = oid.strOID;
        strStatusOID.replace(strTonerIndexOID, strTonerStatusOID);
        //WriteLog::writeToLog("status oid is " + strStatusOID);
        /*list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, oid.strOID, strRet, list_value);
            QString strValue = list_value.size() > 0 ? list_value.at(0).strValue : "";*/
        WriteLog::writeToLog("oid.strValue is " + oid.strValue);
        if (oid.strValue.contains("K", Qt::CaseInsensitive))//黑色粉盒
        {
            stToner.nColorType = 1;
            stToner.nTonerID = 0;
            stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            int status_toner = listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : -1;
            WriteLog::writeToLog("K toner status is " + QString::number(status_toner));
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[0] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[0] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[0] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[0] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("C", Qt::CaseInsensitive))//青色粉盒
        {
            stToner.nColorType = 2;
            stToner.nTonerID = 1;
            stToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[1] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[1] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[1] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[1] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("M", Qt::CaseInsensitive))//品红色粉盒
        {
            stToner.nColorType = 3;
            stToner.nTonerID = 2;
            stToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[2] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[2] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[2] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[2] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("Y", Qt::CaseInsensitive))//黄色粉盒
        {
            stToner.nColorType = 4;
            stToner.nTonerID = 3;
            stToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[3] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[3] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[3] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[3] = '3';	//粉盒粉量低
            default:
                break;
            }
        }

        listMibValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strModelOID, strRet, listMibValue);	//型号
        stToner.TonerModel = listMibValue.size() > 0 ? listMibValue.at(0).strValue : "";
        //WriteLog::writeToLog("model is " + stToner.TonerModel);
        listMibValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strSNOID, strRet, listMibValue);	//SN
        stToner.strTonerSN = listMibValue.size() > 0 ? listMibValue.at(0).strValue : "";
        //WriteLog::writeToLog("sn is " + stToner.strTonerSN);

        //查询粉盒余量
        listMibValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strRemainOID, strRet, listMibValue);
        if (nResult != QueryResult::Successed) {
            return info;
        }
        stToner.nCurrent = listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0;
        //WriteLog::writeToLog("current is " + QString::number(stToner.nCurrent));
        info.listTonerDetail.push_back(stToner);
        //WriteLog::writeToLog("success push back stToner");
    }
    WriteLog::writeToLog("start drum query");

    if (info.adInfo.nPrinterColor == 0) //黑白打印机
    {
        //查询鼓组件
        PrinterDrum stDrum;
        stDrum.nColorType = 1;
        stDrum.nDrumID = 0;
        stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
        //查询鼓组件型号、序列号
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.1", strRet, list_value);	//型号
        stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //WriteLog::writeToLog("drum model is " + stDrum.DrumModel);
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.1", strRet, list_value);	//SN
        stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //WriteLog::writeToLog("drum sn is " + stDrum.DrumSN);
        //鼓组件状态
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.1", strRet, list_value);
        int drumRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (drumRet >= 0)// 有硒鼓
        {
            switch (drumRet)
            {
            case 0:
                info.adInfo.drum = "1"; //鼓组件正常
                break;
            case 1:
                info.adInfo.drum = "0";	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum = "2";	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum = "4";	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum = "3";	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.1", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stDrum);
        }

    }
    else //彩色打印机
    {
        //查询黑色鼓组件
        PrinterDrum stBlackDrum;
        stBlackDrum.nColorType = 1;
        stBlackDrum.nDrumID = 0;
        stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
        //查询鼓组件型号、序列号
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.1", strRet, list_value);	//型号
        stBlackDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.1", strRet, list_value);	//SN
        stBlackDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //鼓组件状态
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.1", strRet, list_value);
        int drumRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (drumRet >= 0)// 有硒鼓
        {
            switch (drumRet)
            {
            case 0:
                info.adInfo.drum[0] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[0] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[0] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[0] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[0] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.1", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stBlackDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stBlackDrum);

            //查询青色鼓组件
            PrinterDrum stCyanDrum;
            stCyanDrum.nColorType = 2;
            stCyanDrum.nDrumID = 1;
            stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.2", strRet, list_value);	//型号
            stCyanDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.2", strRet, list_value);	//SN
            stCyanDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.2", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[1] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[1] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[1] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[1] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[1] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.2", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stCyanDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stCyanDrum);

            //查询品红色鼓组件
            PrinterDrum stMagentaDrum;
            stMagentaDrum.nColorType = 3;
            stMagentaDrum.nDrumID = 2;
            stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.3", strRet, list_value);	//型号
            stMagentaDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.3", strRet, list_value);	//SN
            stMagentaDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.3", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[2] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[2] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[2] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[2] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[2] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.3", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stMagentaDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stMagentaDrum);

            //查询黄色鼓组件
            PrinterDrum stYellowDrum;
            stYellowDrum.nColorType = 4;
            stYellowDrum.nDrumID = 3;
            stYellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.4", strRet, list_value);	//型号
            stYellowDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.4", strRet, list_value);	//SN
            stYellowDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.4", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[3] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[3] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[3] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[3] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[3] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.4", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stYellowDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stYellowDrum);
        }
    }

    //废粉盒
    list_value.clear();
    //废粉盒状态
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.1", strRet, list_value);
    if (nResult == QueryResult::Successed)
    {
        int wasteTonerRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (wasteTonerRet != -1)//有正确返回值
        {
            if (wasteTonerRet >= 0)
            {
                switch (wasteTonerRet)
                {
                case 0:
                    info.adInfo.wasteToner = "1";//正常
                    break;
                case 1:
                    info.adInfo.wasteToner = "0";//未安装
                    break;
                case 2:
                    info.adInfo.wasteToner = "4";//已满
                    break;
                case 3:
                    info.adInfo.wasteToner = "3";//将满
                default:
                    break;
                }

                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.nColorType = 1;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                //查询鼓组件型号、序列号
                list_value.clear();
                nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.4", strRet, list_value);	//型号
                stWasteToner.strWasteTonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
                list_value.clear();
                nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.5", strRet, list_value);	//SN
                stWasteToner.strWasteTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
                //废粉盒余量
                list_value.clear();
                nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.2", strRet, list_value);
                if (nResult != QueryResult::Successed) {
                    return info;
                }
                stWasteToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }

        }
    }

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantumPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed){
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed){
        return info;
    }

    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    if(info.baseinfo.strPrinterSN.isEmpty())  //old mib
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
        if (nResult != QueryResult::Successed){
            return info;
        }
        info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    }
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed){
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }

    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        if (nSubErrorCode < 1)
        {
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.9.1.3", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        }

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);
        WriteLog::writeToLog(statusLog);

        PrinterMIBError pError;

        int nEngineCode;

        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            nEngineCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
            if (nEngineCode < 1)
            {
                list_value.clear();
                nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.9.1.5", strRet, list_value);
                if (nResult != QueryResult::Successed)
                {
                    return info;
                }
                nEngineCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
            }
            switch (nEngineCode)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        case 13://进纸失败或缺纸
            pError.nErrorCode = 60271;
            pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed Or Tray Empty");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
//    list_value.clear();
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
//    if (nResult != QueryResult::Successed)	{
//        return info;
//    }
//    PrinterPCount stPCount;
//    stPCount.nColorType = 0;
//    stPCount.nPaperType = 0;
//    stPCount.strNameEn = "A4 Black";
//    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
//    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPCount);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.4";//3.1.4黑白
    QString strQueryColorOID = "1.3.6.1.4.1.40093.10.3.1.3";//3.1.3彩色
    list_value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
    list_value.clear();

    //black
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();

    //color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    list_value.clear();

    //查询粉盒
    QString strTonerIndexOID = "1.3.6.1.4.1.40093.10.1.5.2.1.1";
    QString strTonerRemainOID = "1.3.6.1.4.1.40093.10.1.5.2.1.3";
    QString strTonerModelOID = "1.3.6.1.4.1.40093.10.1.5.2.1.5";
    QString strTonerSNOID = "1.3.6.1.4.1.40093.10.1.5.2.1.6";
    QString strTonerStatusOID = "1.3.6.1.4.1.40093.10.1.5.2.1.7";

    QList<MibValue> List_Value;
    QString indexOID = strTonerIndexOID;
    //WriteLog::writeToLog("start get oid ...............");
    list_value.clear();
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, indexOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strTonerIndexOID)) {
            WriteLog::writeToLog("oid is " + List_Value.at(0).strOID);
            WriteLog::writeToLog("value is " + List_Value.at(0).strValue);
            indexOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            list_value.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    /*list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strTonerIndexOID, strRet, list_value);
        if (nResult != QueryResult::Successed) {
            return info;
        }*/
    WriteLog::writeToLog("list_value size is " + QString::number(list_value.size()));
    QList<MibValue> listMibValue;
    for (auto oid : list_value)
    {
        WriteLog::writeToLog("start for....");
        PrinterToner stToner;

        //替换余量oid
        QString strRemainOID = oid.strOID;
        strRemainOID.replace(strTonerIndexOID, strTonerRemainOID);
        WriteLog::writeToLog("oid.strOID is " + oid.strOID);
        WriteLog::writeToLog("remain oid is " + strRemainOID);

        //替换型号OID
        QString strModelOID = oid.strOID;
        strModelOID.replace(strTonerIndexOID, strTonerModelOID);
        WriteLog::writeToLog("Model oid is " + strModelOID);
        //替换SN OID
        QString strSNOID = oid.strOID;
        strSNOID.replace(strTonerIndexOID, strTonerSNOID);
        //WriteLog::writeToLog("SN oid is " + strSNOID);
        //替换粉盒状态OID
        QString strStatusOID = oid.strOID;
        strStatusOID.replace(strTonerIndexOID, strTonerStatusOID);
        //WriteLog::writeToLog("status oid is " + strStatusOID);
        /*list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, oid.strOID, strRet, list_value);
            QString strValue = list_value.size() > 0 ? list_value.at(0).strValue : "";*/
        WriteLog::writeToLog("oid.strValue is " + oid.strValue);
        if (oid.strValue.contains("K", Qt::CaseInsensitive))//黑色粉盒
        {
            stToner.nColorType = 1;
            stToner.nTonerID = 0;
            stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            int status_toner = listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : -1;
            WriteLog::writeToLog("K toner status is " + QString::number(status_toner));
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[0] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[0] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[0] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[0] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("C", Qt::CaseInsensitive))//青色粉盒
        {
            stToner.nColorType = 2;
            stToner.nTonerID = 1;
            stToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[1] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[1] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[1] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[1] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("M", Qt::CaseInsensitive))//品红色粉盒
        {
            stToner.nColorType = 3;
            stToner.nTonerID = 2;
            stToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[2] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[2] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[2] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[2] = '3';	//粉盒粉量低
            default:
                break;
            }
        }
        else if (oid.strValue.contains("Y", Qt::CaseInsensitive))//黄色粉盒
        {
            stToner.nColorType = 4;
            stToner.nTonerID = 3;
            stToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
            //粉盒状态
            listMibValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strStatusOID, strRet, listMibValue);
            switch (listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0)
            {
            case 1:
                info.adInfo.toners[3] = '0';	//粉盒未安装
                break;
            case 2:
                info.adInfo.toners[3] = '2';	//粉盒不匹配
                break;
            case 3:
                info.adInfo.toners[3] = '4';	//粉盒寿命尽
                break;
            case 4:
                info.adInfo.toners[3] = '3';	//粉盒粉量低
            default:
                break;
            }
        }

        listMibValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strModelOID, strRet, listMibValue);	//型号
        stToner.TonerModel = listMibValue.size() > 0 ? listMibValue.at(0).strValue : "";
        //WriteLog::writeToLog("model is " + stToner.TonerModel);
        listMibValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strSNOID, strRet, listMibValue);	//SN
        stToner.strTonerSN = listMibValue.size() > 0 ? listMibValue.at(0).strValue : "";
        //WriteLog::writeToLog("sn is " + stToner.strTonerSN);

        //查询粉盒余量
        listMibValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strRemainOID, strRet, listMibValue);
        if (nResult != QueryResult::Successed) {
            return info;
        }
        stToner.nCurrent = listMibValue.size() > 0 ? listMibValue.at(0).strValue.toInt() : 0;
        //WriteLog::writeToLog("current is " + QString::number(stToner.nCurrent));
        info.listTonerDetail.push_back(stToner);
        //WriteLog::writeToLog("success push back stToner");
    }
    WriteLog::writeToLog("start drum query");

    if (info.adInfo.nPrinterColor == 0) //黑白打印机
    {
        //查询鼓组件
        PrinterDrum stDrum;
        stDrum.nColorType = 1;
        stDrum.nDrumID = 0;
        stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
        //查询鼓组件型号、序列号
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.1", strRet, list_value);	//型号
        stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //WriteLog::writeToLog("drum model is " + stDrum.DrumModel);
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.1", strRet, list_value);	//SN
        stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //WriteLog::writeToLog("drum sn is " + stDrum.DrumSN);
        //鼓组件状态
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.1", strRet, list_value);
        int drumRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (drumRet >= 0)// 有硒鼓
        {
            switch (drumRet)
            {
            case 0:
                info.adInfo.drum = "1"; //鼓组件正常
                break;
            case 1:
                info.adInfo.drum = "0";	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum = "2";	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum = "4";	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum = "3";	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.1", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stDrum);
        }

    }
    else //彩色打印机
    {
        //查询黑色鼓组件
        PrinterDrum stBlackDrum;
        stBlackDrum.nColorType = 1;
        stBlackDrum.nDrumID = 0;
        stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
        //查询鼓组件型号、序列号
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.1", strRet, list_value);	//型号
        stBlackDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.1", strRet, list_value);	//SN
        stBlackDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
        //鼓组件状态
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.1", strRet, list_value);
        int drumRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (drumRet >= 0)// 有硒鼓
        {
            switch (drumRet)
            {
            case 0:
                info.adInfo.drum[0] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[0] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[0] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[0] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[0] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.1", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stBlackDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stBlackDrum);

            //查询青色鼓组件
            PrinterDrum stCyanDrum;
            stCyanDrum.nColorType = 2;
            stCyanDrum.nDrumID = 1;
            stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.2", strRet, list_value);	//型号
            stCyanDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.2", strRet, list_value);	//SN
            stCyanDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.2", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[1] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[1] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[1] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[1] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[1] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.2", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stCyanDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stCyanDrum);

            //查询品红色鼓组件
            PrinterDrum stMagentaDrum;
            stMagentaDrum.nColorType = 3;
            stMagentaDrum.nDrumID = 2;
            stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.3", strRet, list_value);	//型号
            stMagentaDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.3", strRet, list_value);	//SN
            stMagentaDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.3", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[2] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[2] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[2] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[2] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[2] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.3", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stMagentaDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stMagentaDrum);

            //查询黄色鼓组件
            PrinterDrum stYellowDrum;
            stYellowDrum.nColorType = 4;
            stYellowDrum.nDrumID = 3;
            stYellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
            //查询鼓组件型号、序列号
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4.4", strRet, list_value);	//型号
            stYellowDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5.4", strRet, list_value);	//SN
            stYellowDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
            //鼓组件状态
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6.4", strRet, list_value);
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 0:
                info.adInfo.drum[3] = '1';	//鼓组件正常
                break;
            case 1:
                info.adInfo.drum[3] = '0';	//鼓组件未安装
                break;
            case 2:
                info.adInfo.drum[3] = '2';	//鼓组件不匹配
                break;
            case 3:
                info.adInfo.drum[3] = '4';	//鼓组件寿命尽
                break;
            case 4:
                info.adInfo.drum[3] = '3';	//鼓组件寿命将尽
            default:
                break;
            }
            //查询鼓组件余量
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2.4", strRet, list_value);
            if (nResult != QueryResult::Successed) {
                return info;
            }
            stYellowDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            info.listDrumDetail.push_back(stYellowDrum);
        }
    }

    //废粉盒
    list_value.clear();
    //废粉盒状态
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.1", strRet, list_value);
    if (nResult == QueryResult::Successed)
    {
        int wasteTonerRet = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        if (wasteTonerRet != -1)//有正确返回值
        {
            if (wasteTonerRet >= 0)
            {
                switch (wasteTonerRet)
                {
                case 0:
                    info.adInfo.wasteToner = "1";//正常
                    break;
                case 1:
                    info.adInfo.wasteToner = "0";//未安装
                    break;
                case 2:
                    info.adInfo.wasteToner = "4";//已满
                    break;
                case 3:
                    info.adInfo.wasteToner = "3";//将满
                default:
                    break;
                }

                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.nColorType = 1;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                //查询鼓组件型号、序列号
                list_value.clear();
                nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.4", strRet, list_value);	//型号
                stWasteToner.strWasteTonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
                list_value.clear();
                nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.5", strRet, list_value);	//SN
                stWasteToner.strWasteTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
                //废粉盒余量
                list_value.clear();
                nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.4.1.2", strRet, list_value);
                if (nResult != QueryResult::Successed) {
                    return info;
                }
                stWasteToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }

        }
    }

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantumOld5103PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.8", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case -1://无错误
            break;
        case -2://致命错误
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部故障");
            pError.ErrorDescEN = QStringLiteral("Internal Error");
            pError.nErrorLevel = 1;
            break;
        case -3://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case -5://粉盒状态
            break;
        case -9://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case -17://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case -33://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case -65://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case -129://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.12", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    //list_value.clear();
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    //stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //list_value.clear();
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    //stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.3", strRet, list_value);//1.3.6.1.4.1.40093.1.1.3.14.1
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    default:
        break;
    }
    //粉量低
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.14.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nTonerRMValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nTonerRMValue == 1)
    {
        info.adInfo.toners = "3";
    }

    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.9.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.8.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nMaxValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 1;
    stToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    info.listTonerDetail.push_back(stToner);

    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantumOld5103PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.8", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case -1://无错误
            break;
        case -2://致命错误
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部故障");
            pError.ErrorDescEN = QStringLiteral("Internal Error");
            pError.nErrorLevel = 1;
            break;
        case -3://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case -5://粉盒状态
            break;
        case -9://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case -17://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;
            break;
        case -33://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case -65://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case -129://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.12", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    //list_value.clear();
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    //stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //list_value.clear();
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    //stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.15.3", strRet, list_value);//1.3.6.1.4.1.40093.1.1.3.14.1
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    default:
        break;
    }
    //粉量低
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.14.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nTonerRMValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nTonerRMValue == 1)
    {
        info.adInfo.toners = "3";
    }

    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.9.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nRestValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.8.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nMaxValue = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 1;
    stToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    info.listTonerDetail.push_back(stToner);

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPantum5103PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        case 13://进纸失败或缺纸
            pError.nErrorCode = 60271;
            pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed Or Tray Empty");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
//    list_value.clear();
//    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
//    if (nResult != QueryResult::Successed) {
//        return info;
//    }
//    PrinterPCount stPCount;
//    stPCount.nColorType = 0;
//    stPCount.nPaperType = 0;
//    stPCount.strNameEn = "A4 Black";
//    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
//    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPCount);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.1";
    list_value.clear();
    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
    list_value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getPantumKanasPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getPantumKanasPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    QueryResult nResult;
    //查询型号
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.5", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //查询打印机尺寸信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.13.9", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.16.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString tmpErrorCode = list_value.size() > 0 ? list_value.at(0).strValue : "";
    QStringList strListError = tmpErrorCode.split(newLine);
    QString strErrorCode;
    for (int i = 0; i < strListError.size(); ++i)
    {
        QString tmp = strListError.at(i);
        tmp = tmp.left(49);
        tmp.replace("  ", " ");
        strListError[i] = tmp;
        strErrorCode.append(strListError[i]);
    }
    strErrorCode = strErrorCode.trimmed();
    QStringList listErroeCode = strErrorCode.split(" ");

    bool ok;
    int nStatusCode = listErroeCode[0].toInt(&ok, 16);
    int nTime = listErroeCode[1].toInt(&ok, 16); //休眠时间
    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;
    if (nStatusCode == 5)//5 错误信息
    {
        PrinterMIBError pError;
        if (listErroeCode[40] == "FE")//内部故障 //1111 1110
        {
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部故障");
            pError.ErrorDescEN = QStringLiteral("Internal Fault");
            pError.nErrorLevel = 1;
        }
        else if (listErroeCode[40] == "FD")//开盖错误 1111 1101
        {
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Open lid failed");
            pError.nErrorLevel = 5;

        }
        else if (listErroeCode[40] == "FB")//耗材错误 1111 1011
        {
            pError.nErrorCode = 60290;
            pError.ErrorDesc = QStringLiteral("耗材错误");
            pError.ErrorDescEN = QStringLiteral("Supplies error");
            pError.nErrorLevel = 5;
        }
        else if (listErroeCode[40] == "F7")//缺纸错误 1111 0111
        {
            pError.nErrorCode = 60060;
            pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Fail Or No Paper");
            pError.nErrorLevel = 5;

        }
        else if (listErroeCode[40] == "EF")//卡纸错误 1110 1111
        {   
            pError.nErrorCode = 60001;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam");
            pError.nErrorLevel = 5;

        }
        else if (listErroeCode[40] == "DF")//纸盒未插入错误 1101 1111
        {
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒未插入");
            pError.ErrorDescEN = QStringLiteral("Input Tray Not Insert ");
            pError.nErrorLevel = 5;
        }
        else if (listErroeCode[40] == "BF")//纸张不匹配 1011 1111
        {
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper dismatch");
            pError.nErrorLevel = 5;
        }
        else if (listErroeCode[40] == "7F")//扫描模块错误 0111 1111
        {
            pError.nErrorCode = 60320;
            pError.ErrorDesc = QStringLiteral("扫描模块错误");
            pError.ErrorDescEN = QStringLiteral("Scan module error ");
            pError.nErrorLevel = 5;
        }
        else if (listErroeCode[40] == "EFF")//接纸架满错误 1110 1111 1111
        {
            pError.nErrorCode = 60040;
            pError.ErrorDesc = QStringLiteral("接纸架满");
            pError.ErrorDescEN = QStringLiteral("Paper splice holder full");
            pError.nErrorLevel = 5;
        }
        else if (listErroeCode[40] == "DFF")//内部存储器错误 1101 1111 1111
        {
            pError.nErrorCode = 60110;
            pError.ErrorDesc = QStringLiteral("内部存储器错误");
            pError.ErrorDescEN = QStringLiteral("Internal Fault");
            pError.nErrorLevel = 5;
        }

        if (listErroeCode[55].toInt(&ok, 16) == 5) //废粉瓶异常
        {
            int nWasteTonerError = listErroeCode[56].toInt(&ok, 16);
            if (nWasteTonerError == 1)
            {
                info.adInfo.wasteToner = "0";//废粉瓶未安装
            }
            else if (nWasteTonerError == 11)
            {
                info.adInfo.wasteToner = "4";//废粉瓶已满
            }
            //else if (nWasteTonerError == 12)
            //{
            //	pError.nErrorCode = -5;
            //	pError.ErrorDesc = QStringLiteral("废粉瓶将满");
            //	pError.ErrorDescEN = QStringLiteral("Waste Toner Is Nearly Full");
            //	pError.nErrorLevel = 4;
            //	info.adInfo.wasteToner = "3";//废粉瓶将满
            //}
        }

        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询粉量低告警
    int nTonerWarn = listErroeCode[6].toInt(&ok, 16);
    if (nTonerWarn & (1 << 0))
    {
        //将1左移0位后与 nTonerWarn按位与之后的结果非0则表示：黑色粉量低
        info.adInfo.toners[0] = '3';
    }
    if (nTonerWarn & (1 << 1))
    {
        //将1左移1位后与 nTonerWarn按位与之后的结果非0则表示：青色粉量低
        info.adInfo.toners[1] = '3';
    }
    if (nTonerWarn & (1 << 2))
    {
        //将1左移2位后与 nTonerWarn按位与之后的结果非0则表示：品红色粉量低
        info.adInfo.toners[2] = '3';
    }
    if (nTonerWarn & (1 << 3))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：黄色色粉量低
        info.adInfo.toners[3] = '3';
    }
    if (nTonerWarn & (1 << 4))
    {
        //将1左移3位后与 nTonerWarn按位与之后的结果非0则表示：废粉盒将满
        info.adInfo.wasteToner = "3";//废粉瓶将满
    }

    //目前1820都是A4机，故暂时屏蔽A3印量的获取
    /*
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA3BlackOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
    return info;
    }
    PrinterPCount stA3BlackPCount;
    stA3BlackPCount.nColorType = 0;
    stA3BlackPCount.nPaperType = 1;
    stA3BlackPCount.strNameEn = "A3 Black";
    stA3BlackPCount.strNameCn = QStringLiteral("A3 黑白印量");
    stA3BlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3BlackPCount);
    list_value.clear();

    //A3 Color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryA3ColorOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
    return info;
    }
    PrinterPCount stA3ColorPCount;
    stA3ColorPCount.nColorType = 1;
    stA3ColorPCount.nPaperType = 1;
    stA3ColorPCount.strNameEn = "A3 Color";
    stA3ColorPCount.strNameCn = QStringLiteral("A3 彩色印量");
    stA3ColorPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stA3ColorPCount);
    list_value.clear();
    */

    //查询粉盒序列号
    QString strQueryBlackTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.23";
    QString strQueryCyanTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.24";
    QString strQueryMagentaTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.25";
    QString strQueryYellowTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.26";
    //查询粉盒余量
    int nBlackTonerRest = listErroeCode[2].toInt(&ok, 16);
    int nCyanTonerRest = listErroeCode[3].toInt(&ok, 16);
    int nMagentaTonerRest = listErroeCode[4].toInt(&ok, 16);
    int nYellowTonerRest = listErroeCode[5].toInt(&ok, 16);

    //查询黑色粉盒和SN
    PrinterToner stBlackToner;
    stBlackToner.nColorType = 1;
    stBlackToner.nTonerID = 0;
    stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stBlackToner.nCurrent = nBlackTonerRest;
    QString strTempKSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempKSN.replace(" ", "");
    strTempKSN = strTempKSN.left(12);
    stBlackToner.strTonerSN = strTempKSN;
    info.listTonerDetail.push_back(stBlackToner);
    list_value.clear();

    //查询青色粉盒和SN
    PrinterToner stCyanToner;
    stCyanToner.nColorType = 2;
    stCyanToner.nTonerID = 1;
    stCyanToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stCyanToner.nCurrent = nCyanTonerRest;
    QString strTempCSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempCSN.replace(" ", "");
    strTempCSN = strTempCSN.left(12);
    stCyanToner.strTonerSN = strTempCSN;

    info.listTonerDetail.push_back(stCyanToner);
    list_value.clear();

    //查询品红色粉盒和SN
    PrinterToner stMagentaToner;
    stMagentaToner.nColorType = 3;
    stMagentaToner.nTonerID = 2;
    stMagentaToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stMagentaToner.nCurrent = nMagentaTonerRest;
    QString strTempMSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempMSN.replace(" ", "");
    strTempMSN = strTempMSN.left(12);
    stMagentaToner.strTonerSN = strTempMSN;
    info.listTonerDetail.push_back(stMagentaToner);
    list_value.clear();

    //查询黄色粉盒和SN
    PrinterToner stYellowToner;
    stYellowToner.nColorType = 4;
    stYellowToner.nTonerID = 3;
    stYellowToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stYellowToner.nCurrent = nYellowTonerRest;
    QString strTempYSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    strTempYSN.replace(" ", "");
    strTempYSN = strTempYSN.left(12);
    stYellowToner.strTonerSN = strTempYSN;

    info.listTonerDetail.push_back(stYellowToner);
    list_value.clear();


    //1820暂不获取硒鼓
    /*
    //查询硒鼓余量
    QString strQueryBlackRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.15";
    QString strQueryCyanRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.16";
    QString strQueryMagentaRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.17";
    QString strQueryYellowRestDrumOID = "1.3.6.1.4.1.40093.1.1.3.13.18";

    //查询硒鼓序列号
    QString strQueryBlackDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.27";
    QString strQueryCyanDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.28";
    QString strQueryMagentaDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.29";
    QString strQueryYellowDrumSNOID = "1.3.6.1.4.1.40093.1.1.3.13.30";
    int nDrumMaxValue = 0;
    int nDrumRestValue = 0;

    //查询黑色硒鼓和SN
    PrinterDrum stBlackDrum;
    stBlackDrum.nColorType = 1;
    stBlackDrum.nDrumID = 0;
    stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stBlackDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryBlackDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stBlackDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";;
    info.listDrumDetail.push_back(stBlackDrum);
    list_value.clear();

    //查询青色硒鼓和SN
    PrinterDrum  stCyanDrum;
    stCyanDrum.nColorType = 2;
    stCyanDrum.nDrumID= 1;
    stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stCyanDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCyanDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stCyanDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stCyanDrum);
    list_value.clear();

    //查询品红色硒鼓和SN
    PrinterDrum stMagentaDrum;
    stMagentaDrum.nColorType = 3;
    stMagentaDrum.nDrumID = 2;
    stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMagentaDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stMagentaDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stMagentaDrum);
    list_value.clear();

    //查询黄色硒鼓和SN
    PrinterDrum stYellowDrum;
    stYellowDrum.nColorType = 4;
    stYellowDrum.nDrumID = 3;
    stYellowDrum.strDrumName = QStringLiteral("Cyan Photoconductor|黄色硒鼓");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowRestDrumOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stYellowDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryYellowDrumSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
    return info;
    }
    stYellowDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listDrumDetail.push_back(stYellowDrum);
    list_value.clear();
    */

    //查询废粉信息
    QString strQueryWasteTonerRestOID = "1.3.6.1.4.1.40093.1.1.3.13.14";
    QString strQueryWasteTonerSNOID = "1.3.6.1.4.1.40093.1.1.3.13.31";
    PrinterWasteToner stWasteToner;
    stWasteToner.nWasteTonerID = 0;
    stWasteToner.strWasteTonerModel;
    stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryWasteTonerRestOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }

    stWasteToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryWasteTonerSNOID, strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stWasteToner.strWasteTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    info.listWasteTonerDetail.push_back(stWasteToner);
    list_value.clear();

    //动态节点查询印量---------------------------
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.3.16.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    QString dyTmpErrorCode = list_value.size() > 0 ? list_value.at(0).strValue : "";
    WriteLog::writeToLog(dyTmpErrorCode);
    QStringList strDyListError = dyTmpErrorCode.split(newLine);
    QString strDyErrorCode;
    for (int i = 0; i < strDyListError.size(); ++i)
    {
        QString tmp = strDyListError.at(i);
        tmp = tmp.left(49);
        tmp.replace("  ", " ");
        strDyListError[i] = tmp;
        strDyErrorCode.append(strDyListError[i]);
    }
    strDyErrorCode = strDyErrorCode.trimmed();
    QStringList listDyErroeCode = strDyErrorCode.split(" ");
    QString strA4BlackPages=listDyErroeCode[139]+listDyErroeCode[138]+listDyErroeCode[137]+listDyErroeCode[136];
    int nA4PrintBlackPages =strA4BlackPages.toInt(&ok, 16);


    QString strA4ColorPages=listDyErroeCode[143]+listDyErroeCode[142]+listDyErroeCode[141]+listDyErroeCode[140];
    int nA4ColorTotalPages =strA4ColorPages.toInt(&ok, 16);

    list_value.clear();
    //查询总印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.1.1.3.12";
    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
    list_value.clear();

    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = nA4PrintBlackPages;
    info.listPCountDetail.push_back(stBlackPCount);


    PrinterPCount stColorCount;
    stColorCount.nColorType = 1;
    stColorCount.nPaperType = 0;
    stColorCount.strNameEn = "Color Pages";
    stColorCount.strNameCn = QStringLiteral("彩色印量");
    stColorCount.nPCount = nA4ColorTotalPages;
    info.listPCountDetail.push_back(stColorCount);


    list_value.clear();
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum5103PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        case 13://进纸失败或缺纸
            pError.nErrorCode = 60271;
            pError.ErrorDesc = QStringLiteral("进纸失败或缺纸");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed Or Tray Empty");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
//    list_value.clear();
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
//    if (nResult != QueryResult::Successed) {
//        return info;
//    }
//    PrinterPCount stPCount;
//    stPCount.nColorType = 0;
//    stPCount.nPaperType = 0;
//    stPCount.strNameEn = "A4 Black";
//    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
//    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPCount);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.40093.10.3.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.40093.10.3.1.1";
    list_value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryTotalOID, strRet, list_value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalCount;
    stTotalCount.nColorType = 0;
    stTotalCount.nPaperType = 0;
    stTotalCount.strNameEn = "Total Pages";
    stTotalCount.strNameCn = QStringLiteral("总印量");
    stTotalCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalCount);
//  list_value.clear();

    //black
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackOID, strRet, list_value);
//    if (nResult != QueryResult::Successed)
//    {
//        return info;
//    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    list_value.clear();


    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum3320PrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)	//故障
    {
        list_value.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPantum3320PrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "pantum";
    QString strRet;
    QList<MibValue> list_value;
    //查询型号
    list_value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.16", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = list_value.size()>0 ? list_value.at(0).strValue : "";
    //查询SN
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.4", strRet, list_value);
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.1.1.2.6", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //QString strPrinterSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //info.baseinfo.strPrinterSN = strPrinterSN.replace(":", "");
    //查询打印机颜色
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.11", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    if (nColor == 1)
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    else
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //查询打印机尺寸信息

    info.adInfo.nPrinterSize = 0;
    //查询打印机固件信息
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //获取打印机状态信息
    PrinterErrorOID errorOID;
    QueryResult dbRet;
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.2.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nStatusCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;

    QString statusLog = "printer status : " + QString::number(nStatusCode);
    //writeLog(statusLog);

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;

    if (nStatusCode == 5)	//故障
    {
        list_value.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.3", strRet, list_value);
        if (nResult != QueryResult::Successed)
        {
            return info;
        }
        int nSubErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
        list_value.clear();

        QString statusLog = "Error Status : " + QString::number(nSubErrorCode);
        //writeLog(statusLog);

        PrinterMIBError pError;
        switch (nSubErrorCode)
        {
        case 1://引擎故障
            list_value.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.8.1.5", strRet, list_value);
            if (nResult != QueryResult::Successed)
            {
                return info;
            }
            switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1)
            {
            case 801:
                pError.nErrorCode = 60120;
                pError.ErrorDesc = QStringLiteral("引擎通信失败");
                pError.ErrorDescEN = QStringLiteral("Engine Communicate Failed");
                pError.nErrorLevel = 1;
                break;
            case 802:
                pError.nErrorCode = 60121;
                pError.ErrorDesc = QStringLiteral("加热辊全功率加热过长");
                pError.ErrorDescEN = QStringLiteral("Warmer Full Power Warm Overlength");
                pError.nErrorLevel = 1;
                break;
            case 803:
                pError.nErrorCode = 60122;
                pError.ErrorDesc = QStringLiteral("加热辊温升过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Rise Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 804:
                pError.nErrorCode = 60123;
                pError.ErrorDesc = QStringLiteral("加热辊热敏电阻异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Thermistor Exception");
                pError.nErrorLevel = 1;
                break;
            case 805:
                pError.nErrorCode = 60124;
                pError.ErrorDesc = QStringLiteral("加热辊降温过慢");
                pError.ErrorDescEN = QStringLiteral("Warmer Cooling Too Slow");
                pError.nErrorLevel = 1;
                break;
            case 806:
                pError.nErrorCode = 60125;
                pError.ErrorDesc = QStringLiteral("加热辊温度异常");
                pError.ErrorDescEN = QStringLiteral("Warmer Temp Exception");
                pError.nErrorLevel = 1;
                break;
            case 807:
                pError.nErrorCode = 60126;
                pError.ErrorDesc = QStringLiteral("加热辊未达到激光器启动温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Starting Temp Of Laser");
                pError.nErrorLevel = 1;
                break;
            case 808:
                pError.nErrorCode = 60127;
                pError.ErrorDesc = QStringLiteral("加热辊未达到搓纸温度");
                pError.ErrorDescEN = QStringLiteral("Warmer Not Reach Temp Of Rub Paper");
                pError.nErrorLevel = 1;
                break;
            case 809:
                pError.nErrorCode = 60129;
                pError.ErrorDesc = QStringLiteral("激光器行同步异常");
                pError.ErrorDescEN = QStringLiteral("Laser Row Sync Exception");
                pError.nErrorLevel = 1;
                break;
            case 810:
                pError.nErrorCode = 60130;
                pError.ErrorDesc = QStringLiteral("激光器马达异常");
                pError.ErrorDescEN = QStringLiteral("Laser Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 811:
                pError.nErrorCode = 60128;
                pError.ErrorDesc = QStringLiteral("主马达异常");
                pError.ErrorDescEN = QStringLiteral("Main Motor Exception");
                pError.nErrorLevel = 1;
                break;
            case 812:
                pError.nErrorCode = 60310;
                pError.ErrorDesc = QStringLiteral("风扇故障");
                pError.ErrorDescEN = QStringLiteral("Fan Fault");
                pError.nErrorLevel = 1;
                break;
                //case 813:
                //	pError.nErrorCode = 60320;
                //	pError.ErrorDesc = QStringLiteral("其他引擎错误");
                //	pError.ErrorDescEN = QStringLiteral("Other Engine Error");
                //	pError.nErrorLevel = 1;
                //	break;
            case 814:
                pError.nErrorCode = 60331;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 815:
                pError.nErrorCode = 60332;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 816:
                pError.nErrorCode = 60333;
                pError.ErrorDesc = QStringLiteral("选配纸盒1故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 1 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            case 817:
                pError.nErrorCode = 60334;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障1（纸盒中板提升系统故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 1(Paper Box Plate Lifting System Fault)");
                pError.nErrorLevel = 1;
                break;
            case 818:
                pError.nErrorCode = 60335;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障2（纸盒马达故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 2(Paper Box Motor Fault)");
                pError.nErrorLevel = 1;
                break;
            case 819:
                pError.nErrorCode = 60336;
                pError.ErrorDesc = QStringLiteral("选配纸盒2故障3（纸盒通讯故障）");
                pError.ErrorDescEN = QStringLiteral("Optional 2 Error 3(Paper Box Communication Fault)");
                pError.nErrorLevel = 1;
                break;
            default:
                pError.nErrorCode = 60320;
                pError.ErrorDesc = QStringLiteral("其他引擎错误");
                pError.ErrorDescEN = QStringLiteral("Internal Fault");
                pError.nErrorLevel = 1;
                break;
            }
            break;
        case 2://开盖错误
            pError.nErrorCode = 60210;
            pError.ErrorDesc = QStringLiteral("开盖错误");
            pError.ErrorDescEN = QStringLiteral("Cover Open");
            pError.nErrorLevel = 5;
            break;
        case 4://缺纸错误
            pError.nErrorCode = 60220;
            pError.ErrorDesc = QStringLiteral("缺纸错误");
            pError.ErrorDescEN = QStringLiteral("Tray Empty");
            pError.nErrorLevel = 5;
            break;
        case 5://卡纸错误
            pError.nErrorCode = 60230;
            pError.ErrorDesc = QStringLiteral("卡纸错误");
            pError.ErrorDescEN = QStringLiteral("Paper Jam At Entranch");
            pError.nErrorLevel = 5;
            break;
        case 6://纸张设置不匹配
            pError.nErrorCode = 60240;
            pError.ErrorDesc = QStringLiteral("纸张设置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Size Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 7://纸张来源不匹配
            pError.nErrorCode = 60250;
            pError.ErrorDesc = QStringLiteral("纸张来源不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Source Missmatch");
            pError.nErrorLevel = 5;
            break;
        case 9://选配纸盒未安装
            pError.nErrorCode = 60330;
            pError.ErrorDesc = QStringLiteral("选配纸盒未安装");
            pError.ErrorDescEN = QStringLiteral("Select Box Notinstall");
            pError.nErrorLevel = 5;
            break;
        case 10://选配纸盒未安装
            pError.nErrorCode = 60270;
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = QStringLiteral("Paper Feed Failed");
            pError.nErrorLevel = 5;
            break;
        case 11://纸张放置不匹配
            pError.nErrorCode = 60241;
            pError.ErrorDesc = QStringLiteral("纸张放置不匹配");
            pError.ErrorDescEN = QStringLiteral("Paper Put Mismatch");
            pError.nErrorLevel = 5;
            break;
        case 12://纸盒打开
            pError.nErrorCode = 60242;
            pError.ErrorDesc = QStringLiteral("纸盒打开");
            pError.ErrorDescEN = QStringLiteral("Tray Open");
            pError.nErrorLevel = 5;
            break;
        default:
            pError.nErrorCode = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
            pError.ErrorDesc = QStringLiteral("未知故障，固件未定义，故障码%1").arg(pError.nErrorCode);
            pError.ErrorDescEN = QStringLiteral("Fatal Error");
            pError.nErrorLevel = 1;
            break;
        }
        if (pError.nErrorCode != 0)
        {
            info.listPrinterError.append(pError);
        }
    }

    //查询印量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.3.1.1", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    PrinterPCount stPCount;
    stPCount.nColorType = 0;
    stPCount.nPaperType = 0;
    stPCount.strNameEn = "A4 Black";
    stPCount.strNameCn = QStringLiteral("A4 黑白印量");
    stPCount.nPCount = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPCount);

    //查询粉盒
    PrinterToner stToner;
    stToner.nColorType = 1;
    stToner.nTonerID = 0;
    stToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //查询粉盒型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.5.4", strRet, list_value);	//型号
    stToner.TonerModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.6.4", strRet, list_value);	//SN
    stToner.strTonerSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //粉盒状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.7.4", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.toners = "0";	//粉盒未安装
        break;
    case 2:
        info.adInfo.toners = "2";	//粉盒不匹配
        break;
    case 3:
        info.adInfo.toners = "4";	//粉盒寿命尽
        break;
    case 4:
        info.adInfo.toners = "3";	//粉盒粉量低
    default:
        break;
    }
    //查询粉盒余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.2.1.3.4", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stToner.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listTonerDetail.push_back(stToner);

    //查询鼓组件
    PrinterDrum stDrum;
    stDrum.nColorType = 1;
    stDrum.nDrumID = 0;
    stDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //查询鼓组件型号、序列号
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.4", strRet, list_value);	//型号
    stDrum.DrumModel = list_value.size() > 0 ? list_value.at(0).strValue : "";
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.5", strRet, list_value);	//SN
    stDrum.DrumSN = list_value.size() > 0 ? list_value.at(0).strValue : "";
    //鼓组件状态
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.6", strRet, list_value);
    switch (list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0)
    {
    case 1:
        info.adInfo.drum = "0";	//鼓组件未安装
        break;
    case 2:
        info.adInfo.drum = "2";	//鼓组件不匹配
        break;
    case 3:
        info.adInfo.drum = "4";	//鼓组件寿命尽
        break;
    case 4:
        info.adInfo.drum = "3";	//鼓组件寿命将尽
    default:
        break;
    }
    //查询鼓组件余量
    list_value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.40093.10.1.5.3.1.2", strRet, list_value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    stDrum.nCurrent = list_value.size() > 0 ? list_value.at(0).strValue.toInt() : 0;
    info.listDrumDetail.push_back(stDrum);

    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;
    //WriteLog::writeToLog(info.baseinfo.strModel + " nPrinterStatus:" + QString::number(info.baseinfo.nPrinterStatus));

    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;

        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }


        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印") : QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed() : "";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............" || str == "black toner" || str == "black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8") || str == "black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str == "cyan cartridge" || str == "cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str == "photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge" || str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor" || str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle" || str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;
    //WriteLog::writeToLog(info.baseinfo.strModel + " nPrinterStatus:" + QString::number(info.baseinfo.nPrinterStatus));

    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;

        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }


        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }
        info.listPrinterError.append(pError);
    }


    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.641.6.4.2.1.1.4.1.3";
    QString strQueryBlackOID = "1.3.6.1.4.1.641.6.4.2.1.1.4.1.5";
    QString strQueryColorOID = "1.3.6.1.4.1.641.6.4.2.1.1.4.1.6";
    List_Value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();

 /*
    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1:0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印"): QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0? listValue.at(0).strValue.toInt():0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }
*/
    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed():"";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............"|| str=="black toner" || str=="black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8")||str=="black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str=="cyan cartridge" || str=="cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str=="photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge"|| str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor"|| str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle"|| str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkBeaglePrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;
    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;

        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }


        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印") : QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed() : "";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............" || str == "black toner" || str == "black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8") || str == "black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str == "cyan cartridge" || str == "cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str == "photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge" || str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor" || str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle" || str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkBeaglePrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;
    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;

        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }


        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印") : QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed() : "";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............" || str == "black toner" || str == "black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8") || str == "black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str == "cyan cartridge" || str == "cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str == "photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge" || str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor" || str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle" || str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkWilburPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;
    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;


        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }

        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印") : QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed() : "";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............" || str == "black toner" || str == "black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8") || str == "black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str == "cyan cartridge" || str == "cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str == "photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge" || str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor" || str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle" || str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getLexMarkWilburPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    info.Core = "lexmark";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.4.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.2.3.1.5.1", strRet, List_Value);	//sn
    //nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.674.10898.100.1.7.4.0", strRet, List_Value);	//mac
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";	//sn
    //QString strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //QStringList strMacList = strPrinterSN.split(" ");
    //QString strPrinterMac = "";
    //for (int i = 2; i < 8; i++)
    //{
    //	strPrinterMac.append(strMacList[i]);
    //}
    //info.baseinfo.strPrinterSN = strPrinterMac;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getNext, "1.3.6.1.4.1.641.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.firmeware = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, ".1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    for (int i = 0; i < List_Value.size();i++)
    {
        int nPaper = List_Value.at(i).strValue.toInt();
        if (nPaper == 67)
        {
            info.adInfo.nPrinterSize = 1;
            break;
        }
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机错误状态信息
    QString QueryErrorCodeOID = "1.3.6.1.4.1.641.6.5.1.1.5";
    QString QueryErrorDiscOID = "1.3.6.1.4.1.641.6.5.1.1.6";
    QString QueryErrorLevelOID = "1.3.6.1.4.1.641.6.5.1.1.4";

    List_Value.clear();

    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, QueryErrorCodeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(QueryErrorCodeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        pError.ErrorDesc = pError.ErrorDesc.left(pError.ErrorDesc.indexOf("[")).trimmed();
        QMap<QString, QString>::iterator itor = m_LemarkError.begin();
        QString wndIndex;
        if (pError.ErrorDesc.contains("estimated pages remain"))
        {
            QRegExp rx("\\d+");
            rx.indexIn(pError.ErrorDesc, 0);
            wndIndex = rx.cap(0);
            pError.ErrorDesc = pError.ErrorDesc.replace(wndIndex, "%1");
        }
        itor = m_LemarkError.find(pError.ErrorDesc);

        if (itor != m_LemarkError.end())
        {
            pError.ErrorDesc = *itor;
            pError.ErrorDesc = pError.ErrorDesc.arg(wndIndex);
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        else
        {
            pError.ErrorDesc = listValue.at(0).strValue;
            pError.ErrorDescEN = listValue.at(0).strValue;
        }
        listValue.clear();
        nResult = queryMibDataV2(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;


        if (pError.nErrorCode == 209 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else if (pError.nErrorCode == 211 && pError.nErrorLevel == 5)
        {
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }

        if (pError.nErrorCode == 218)//粉盒不匹配
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '2';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '2';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '2';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '2';
            }
            continue;
        }
        if (pError.nErrorCode == 219)//粉盒未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '0';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '0';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '0';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '0';
            }
            continue;
        }
        if (pError.nErrorCode == 207)//粉盒不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 209)//粉盒将尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.toners[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.toners[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.toners[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.toners[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 210)//硒鼓不足
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("black"))
            {
                info.adInfo.drum[0] = '3';
            }
            if (errordesc.contains("cyan"))
            {
                info.adInfo.drum[1] = '3';
            }
            if (errordesc.contains("magenta"))
            {
                info.adInfo.drum[2] = '3';
            }
            if (errordesc.contains("yellow"))
            {
                info.adInfo.drum[3] = '3';
            }
            continue;
        }
        if (pError.nErrorCode == 211)//硒鼓耗尽
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("drum"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '4';
                }
                continue;
            }
            if (errordesc.contains("cartridge"))
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.toners[0] = '4';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.toners[1] = '4';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.toners[2] = '4';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.toners[3] = '4';
                }
                continue;
            }

        }
        if (pError.nErrorCode == 214)//硒鼓、粉盒、废粉瓶未安装
        {
            pError.nErrorLevel = 4;
            QString errordesc = pError.ErrorDescEN.toLower();

            QString strModel = info.baseinfo.strModel.toLower();
            if (strModel.contains("cm8505dn"))
            {
                //粉盒
                if (errordesc.contains("black cartridge"))
                {
                    info.adInfo.toners[0] = '0';
                }
                if (errordesc.contains("cyan cartridge"))
                {
                    info.adInfo.toners[1] = '0';
                }
                if (errordesc.contains("magenta cartridge"))
                {
                    info.adInfo.toners[2] = '0';
                }
                if (errordesc.contains("yellow cartridge"))
                {
                    info.adInfo.toners[3] = '0';
                }
                //硒鼓
                if (errordesc.contains("black photoconductor"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan photoconductor"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta photoconductor"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow photoconductor"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }
            else
            {
                if (errordesc.contains("black"))
                {
                    info.adInfo.drum[0] = '0';
                }
                if (errordesc.contains("cyan"))
                {
                    info.adInfo.drum[1] = '0';
                }
                if (errordesc.contains("magenta"))
                {
                    info.adInfo.drum[2] = '0';
                }
                if (errordesc.contains("yellow"))
                {
                    info.adInfo.drum[3] = '0';
                }
            }

            //废粉瓶
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "0";
            }
            continue;
        }

        if (pError.nErrorCode == 203)	//废粉瓶将满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("nearly full"))
            {
                info.adInfo.wasteToner = "3";
            }
            continue;
        }

        if (pError.nErrorCode == 205)	//废粉瓶满
        {
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("waste toner"))
            {
                info.adInfo.wasteToner = "4";
            }
            continue;
        }

        //if (pError.nErrorCode == 218 && pError.nErrorLevel == 5)
        //{
        //	continue;
        //}
        else if (pError.nErrorCode == 403)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60280;		//出纸错误
        }
        else if (pError.nErrorCode == 2)
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            pError.nErrorLevel = 5;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("smtp") || errordesc.contains("exha"))
            {
                continue;
            }
            else if (errordesc.contains("manual"))
            {
                pError.nErrorCode = 60220;		//缺纸错误
            }
            else if (errordesc.contains("door"))
            {
                pError.nErrorCode = 60210;	//开盖错误
            }
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
        }

        else if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 || pError.nErrorCode == 6)		//开盖错误
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60210;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 301)	//进纸匣1缺少（纸盒错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60300;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 302)	//进纸匣1纸量低（进纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60270;
        }

        else if (pError.nErrorCode == 303)	//进纸匣1已空（缺纸）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60220;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 402)	//标准接纸架已满（出纸错误）
        {
            if (pError.nErrorLevel == 4)
                continue;
            pError.nErrorCode = 60280;
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 501)	//进纸口A卡纸（卡纸错误）/进纸失败
        {
            if (pError.nErrorLevel == 4)
                continue;
            QString errordesc = pError.ErrorDescEN.toLower();
            if (errordesc.contains("jam"))
                pError.nErrorCode = 60230;	//卡纸
            else if (errordesc.contains("loading"))
                pError.nErrorCode = 60270;	//进纸失败
            else
            {
                WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                     " error desc: " + pError.ErrorDescEN);
                pError.nErrorCode = 60260;	//其他错误
            }
            pError.nErrorLevel = 5;
        }

        else if (pError.nErrorCode == 216)
        {
            if (pError.nErrorLevel == 4)
                continue;
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            continue;
        }
        else
        {
            if (pError.nErrorLevel == 4)
            {
                continue;
            }
            WriteLog::writeToLog("LXK error code: " + QString::number(pError.nErrorCode) + " error level: " + QString::number(pError.nErrorLevel) +
                                 " error desc: " + pError.ErrorDescEN);
            pError.nErrorCode = 60260;	//其他错误
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.4.1.641.6.4.2.1.1.2";
    QString strQueryCountValueOID = "1.3.6.1.4.1.641.6.4.2.1.1.4";
    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strQueryCountTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strQueryCountTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }

    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 17)
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 0;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Black Print";
            stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白打印") : QStringLiteral("A4黑白打印");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.toInt() == 18)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色打印") : QStringLiteral("A4彩色打印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 33)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白复印") : QStringLiteral("A4黑白复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 34)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色复印") : QStringLiteral("A4彩色复印");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 49)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black fax";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3黑白传真") : QStringLiteral("A4黑白传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.toInt() == 50)
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Color Copy";
            stPCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3彩色传真") : QStringLiteral("A4彩色传真");
            stPCount.nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (int i = 0; i < List_Value.size();)
    {
        if (List_Value.at(i).strOID.contains(strSupplyTypeOID)) {
            i++;
            continue;
        }
        else
        {
            List_Value.removeAt(i);
        }
    }
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.toLower().trimmed() : "";
            if (str == "Black Cartridge" || str == "e9 bb 91 e8 89 b2 e7 a2 b3 e7 b2 89                ............" || str == "black toner" || str == "black cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (str == "Black Photoconductor" || str == "photo drum:black" || str.contains("e5 85 89 e7 94 b5 e9 bc 93 ef bc 9a e9 bb 91 e8") || str == "black photoconductor")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (str == "Cyan Cartridge" || str == "cyan cartridge" || str == "cyan toner")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }
            if (str == "Cyan Photoconductor" || str == "cyan photoconductor" || str == "photo drum:cyan")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (str == "Magenta Cartridge" || str == "magenta cartridge" || str == "magenta toner")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }
            if (str == "Magenta Photoconductor" || str == "magenta photoconductor" || str == "photo drum:magenta")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (str == "Yellow Cartridge" || str == "yellow cartridge" || str == "yellow toner")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
            if (str == "Yellow Photoconductor" || str == "yellow photoconductor" || str == "photo drum:yellow")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (str == "Waste Toner Bottle" || str == "waste toner bottle" || str.contains("e5 ba 9f e7 a2 b3 e7 b2 89 e7 93 b6"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getHPPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("HP|惠普");
    info.Core = "hp";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt():0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
  //  nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, QueryErrorCodeOID, strRet, List_Value);
    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }
        if (pError.nErrorCode == 22)//已暂停
        {
            continue;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
//    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
//    List_Value.clear();
//    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

//    PrinterPCount stPBlackCount;
//    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.strNameEn = "Print count";
//    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
//    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPBlackCount);


    //查询印量
    QString strQueryTotalOID = "1.3.6.1.2.1.43.10.2.1.4.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.11.2.3.9.4.2.1.4.1.2.6.0";
    QString strQueryColorOID = "1.3.6.1.4.1.11.2.3.9.4.2.1.4.1.2.7.0";
    List_Value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";
    List_Value.clear();

  //  nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    nResult = queryMibDataV2(strIPAddress, QueryMethod::getBulk, strSupplyTypeOID, strRet, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getHPPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("HP|惠普");
    info.Core = "hp";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    //nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);
    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }
        if (pError.nErrorCode == 22)//已暂停
        {
            continue;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
//    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
//    List_Value.clear();
//    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

//    PrinterPCount stPBlackCount;
//    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.strNameEn = "Print count";
//    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
//    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPBlackCount);


    //查询印量
    QString strQueryTotalOID = "1.3.6.1.2.1.43.10.2.1.4.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.11.2.3.9.4.2.1.4.1.2.6.0";
    QString strQueryColorOID = "1.3.6.1.4.1.11.2.3.9.4.2.1.4.1.2.7.0";
    List_Value.clear();

    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    //nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    QList<MibValue> List_Supply;
    QString strSupplyType = strSupplyTypeOID;
    while (true)
    {
        MibValue mibValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strSupplyType, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            strSupplyType = List_Value.at(0).strOID;
            mibValue.strOID = List_Value.at(0).strOID;
            mibValue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibValue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getPrinterDetailInfoV3(QString strIPAddress, PrinterBaseInfo baseInfo)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = baseInfo.strModel;
    QList<MibValue> List_Value;
    QString strRet;
    List_Value.clear();
    //查询供应商名 1.3.6.1.2.1.43.8.2.1.14
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.14", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.Core = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询型号
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;
    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getPrinterDetailInfo(QString strIPAddress, PrinterBaseInfo baseInfo)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = baseInfo.strModel;
    QList<MibValue> List_Value;
    QString strRet;
    List_Value.clear();
    //查询供应商名 1.3.6.1.2.1.43.8.2.1.14
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.14", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.Core = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询型号
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getCanonPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Cannon|佳能");
    info.Core = "cannon";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.16.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.1602.1.1.1.4.0", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    info.firmeware = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)	//故障状态
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1102 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(ErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(ErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountA3BlackOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.8";
    QString strQueryCountA4BlackOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.9";
    QString strQueryCountA3ColorOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.12";
    QString strQueryCountA4ColorOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.13";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCountA4ColorOID, strRet, List_Value);
    PrinterPCount stPColorCount;
    stPColorCount.nColorType = 1;
    stPColorCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPColorCount.strNameEn = "Color Impressions";
    stPColorCount.strNameCn = QStringLiteral("彩色印量");
    stPColorCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPColorCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCountA4BlackOID, strRet, List_Value);
    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Black Impressions";
    stPBlackCount.strNameCn = QStringLiteral("黑白印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPBlackCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCountA3ColorOID, strRet, List_Value);
    PrinterPCount stPA3ColorCount;
    stPA3ColorCount.nColorType = 1;
    stPA3ColorCount.nPaperType = 1;
    stPA3ColorCount.strNameEn = "Color Large Impressions";
    stPA3ColorCount.strNameCn = QStringLiteral("A3彩色印量");
    stPA3ColorCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPA3ColorCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCountA3BlackOID, strRet, List_Value);
    PrinterPCount stPA3BlackCount;
    stPA3BlackCount.nColorType = 0;
    stPA3BlackCount.nPaperType = 1;
    stPA3BlackCount.strNameEn = "Black Large Impressions";
    stPA3BlackCount.strNameCn = QStringLiteral("A3黑白印量");
    stPA3BlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPA3BlackCount);

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString strSupplyType = strSupplyTypeOID;
    while (true)
    {
        MibValue mibValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strSupplyType, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            strSupplyType = List_Value.at(0).strOID;
            mibValue.strOID = List_Value.at(0).strOID;
            mibValue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibValue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 21)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";
            QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
            QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);

            if (OkList.at(0).contains("Black Toner"))
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = "";
                stBlackToner.strTonerSN = "";
                stBlackToner.strTonerName = QStringLiteral("K|黑色墨粉");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[0] = '0';
                }
            }
            if (OkList.at(0).contains("Cyan Toner"))
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = "";
                stCToner.strTonerSN = "";
                stCToner.strTonerName = QStringLiteral("C|青色墨粉");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
            }
            if (OkList.at(0).contains("Magenta Toner"))
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = "";
                stMToner.strTonerSN = "";
                stMToner.strTonerName = QStringLiteral("M|品红色墨粉");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
            }
            if (OkList.at(0).contains("Yellow Toner"))
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = "";
                stYToner.strTonerSN = "";
                stYToner.strTonerName = QStringLiteral("Y|黄色墨粉");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
            }
        }
    }
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getCanonPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Cannon|佳能");
    info.Core = "cannon";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.16.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.1602.1.1.1.4.0", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    info.firmeware = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while(true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)	//故障状态
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1102 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(ErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(ErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountA3BlackOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.8";
    QString strQueryCountA4BlackOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.9";
    QString strQueryCountA3ColorOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.12";
    QString strQueryCountA4ColorOID = "1.3.6.1.4.1.1602.1.11.2.1.1.3.13";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCountA4ColorOID, strRet, List_Value);
    PrinterPCount stPColorCount;
    stPColorCount.nColorType = 1;
    stPColorCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPColorCount.strNameEn = "Color Impressions";
    stPColorCount.strNameCn = QStringLiteral("彩色印量");
    stPColorCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPColorCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCountA4BlackOID, strRet, List_Value);
    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Black Impressions";
    stPBlackCount.strNameCn = QStringLiteral("黑白印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPBlackCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCountA3ColorOID, strRet, List_Value);
    PrinterPCount stPA3ColorCount;
    stPA3ColorCount.nColorType = 1;
    stPA3ColorCount.nPaperType = 1;
    stPA3ColorCount.strNameEn = "Color Large Impressions";
    stPA3ColorCount.strNameCn = QStringLiteral("A3彩色印量");
    stPA3ColorCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPA3ColorCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCountA3BlackOID, strRet, List_Value);
    PrinterPCount stPA3BlackCount;
    stPA3BlackCount.nColorType = 0;
    stPA3BlackCount.nPaperType = 1;
    stPA3BlackCount.strNameEn = "Black Large Impressions";
    stPA3BlackCount.strNameCn = QStringLiteral("A3黑白印量");
    stPA3BlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPA3BlackCount);

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString strSupplyType = strSupplyTypeOID;
    while(true)
    {
        MibValue mibValue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strSupplyType, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            strSupplyType = List_Value.at(0).strOID;
            mibValue.strOID = List_Value.at(0).strOID;
            mibValue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibValue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 21)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";
            QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
            QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);

            if (OkList.at(0).contains("Black Toner"))
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = "";
                stBlackToner.strTonerSN = "";
                stBlackToner.strTonerName = QStringLiteral("K|黑色墨粉");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[0] = '0';
                }
            }
            if (OkList.at(0).contains("Cyan Toner"))
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = "";
                stCToner.strTonerSN = "";
                stCToner.strTonerName = QStringLiteral("C|青色墨粉");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
            }
            if (OkList.at(0).contains("Magenta Toner"))
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = "";
                stMToner.strTonerSN = "";
                stMToner.strTonerName = QStringLiteral("M|品红色墨粉");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
            }
            if (OkList.at(0).contains("Yellow Toner"))
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = "";
                stYToner.strTonerSN = "";
                stYToner.strTonerName = QStringLiteral("Y|黄色墨粉");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);

                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getBrotherPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Brother|兄弟");
    info.Core = "Brother";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }


    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1102 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1115)	// 无硒鼓单元
        {
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }
        if (pError.nErrorCode == 0) //休眠
        {
            continue;
        }
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size()>0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 5;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size()>0 ? listValue.value(0).strValue.trimmed() : "";
            QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
            QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);

            if (OkList.at(0).contains("Black Toner"))
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackToner.nCurrent = nRestValue;
                    info.adInfo.toners[0] = '0';	//未安装/不匹配
                }
                else
                {
                    stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stBlackToner);
            }
            else if (OkList.at(0).contains("Black Drum") || (OkList.at(0).contains("Drum Unit") & info.adInfo.nPrinterColor == 0) || OkList.at(0).contains("Black Drum Unit"))
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackDrum.nCurrent = nRestValue;
                    info.adInfo.drum[0] = '0';	//未安装或不匹配
                }
                else
                {
                    stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stBlackDrum);
            }
            else if (OkList.at(0).contains("Cyan Toner"))
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stCToner.nCurrent = nRestValue;
                    info.adInfo.toners[1] = '0';	//未安装或不匹配
                }
                else
                {
                    stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stCToner);
            }
            else if (OkList.at(0).contains("Cyan Drum") || OkList.at(0).contains("Cyan Drum Unit"))
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                if (nRestValue < 0 | nMaxValue < 0)
                {
                    stCyanDrum.nCurrent = nRestValue;
                    info.adInfo.drum[1] = '0';		//未安装或不匹配
                }
                else
                {
                    stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stCyanDrum);
            }
            else if (OkList.at(0).contains("Magenta Toner"))
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMToner.nCurrent = nRestValue;
                    info.adInfo.toners[2] = '0';	//未按转或不匹配
                }
                else
                {
                    stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listTonerDetail.push_back(stMToner);
            }
            else if (OkList.at(0).contains("Magenta Drum") || OkList.at(0).contains("Magenta Drum Unit"))
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMagentaDrum.nCurrent = nRestValue;
                    info.adInfo.drum[2] = '0';		//未安装或不匹配
                }
                else
                {
                    stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            else if (OkList.at(0).contains("Yellow Toner"))
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stYToner.nCurrent = nRestValue;
                    info.adInfo.toners[3] = '0';	//未安装或不匹配
                }
                else
                {
                    stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stYToner);
            }
            else if (OkList.at(0).contains("Yellow Drum") || OkList.at(0).contains("Yellow Drum Unit"))
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    styellowDrum.nCurrent = nRestValue;
                    info.adInfo.drum[3] = '0';	//未按转或不匹配
                }
                else
                {
                    styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(styellowDrum);
            }
            else if (OkList.at(0).contains("Waste Toner"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stWasteToner.nCurrent = nRestValue;
                    info.adInfo.wasteToner = '0';		//未安装或不匹配
                }
                else
                {
                    info.adInfo.wasteToner = '1';
                    stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                //stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getBrotherPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Brother|兄弟");
    info.Core = "Brother";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }


    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1102 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1115)	// 无硒鼓单元
        {
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }
        if (pError.nErrorCode == 0) //休眠
        {
            continue;
        }
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size()>0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 5;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size()>0 ? listValue.value(0).strValue.trimmed() : "";
            QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
            QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);

            if (OkList.at(0).contains("Black Toner"))
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackToner.nCurrent = nRestValue;
                    info.adInfo.toners[0] = '0';	//未安装/不匹配
                }
                else
                {
                    stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stBlackToner);
            }
            else if (OkList.at(0).contains("Black Drum") || (OkList.at(0).contains("Drum Unit") & info.adInfo.nPrinterColor == 0) || OkList.at(0).contains("Black Drum Unit"))
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackDrum.nCurrent = nRestValue;
                    info.adInfo.drum[0] = '0';	//未安装或不匹配
                }
                else
                {
                    stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stBlackDrum);
            }
            else if (OkList.at(0).contains("Cyan Toner"))
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stCToner.nCurrent = nRestValue;
                    info.adInfo.toners[1] = '0';	//未安装或不匹配
                }
                else
                {
                    stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stCToner);
            }
            else if (OkList.at(0).contains("Cyan Drum") || OkList.at(0).contains("Cyan Drum Unit"))
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                if (nRestValue < 0 | nMaxValue < 0)
                {
                    stCyanDrum.nCurrent = nRestValue;
                    info.adInfo.drum[1] = '0';		//未安装或不匹配
                }
                else
                {
                    stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stCyanDrum);
            }
            else if (OkList.at(0).contains("Magenta Toner"))
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMToner.nCurrent = nRestValue;
                    info.adInfo.toners[2] = '0';	//未按转或不匹配
                }
                else
                {
                    stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listTonerDetail.push_back(stMToner);
            }
            else if (OkList.at(0).contains("Magenta Drum") || OkList.at(0).contains("Magenta Drum Unit"))
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMagentaDrum.nCurrent = nRestValue;
                    info.adInfo.drum[2] = '0';		//未安装或不匹配
                }
                else
                {
                    stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            else if (OkList.at(0).contains("Yellow Toner"))
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stYToner.nCurrent = nRestValue;
                    info.adInfo.toners[3] = '0';	//未安装或不匹配
                }
                else
                {
                    stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stYToner);
            }
            else if (OkList.at(0).contains("Yellow Drum") || OkList.at(0).contains("Yellow Drum Unit"))
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    styellowDrum.nCurrent = nRestValue;
                    info.adInfo.drum[3] = '0';	//未按转或不匹配
                }
                else
                {
                    styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(styellowDrum);
            }
            else if (OkList.at(0).contains("Waste Toner"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stWasteToner.nCurrent = nRestValue;
                    info.adInfo.wasteToner = '0';		//未安装或不匹配
                }
                else
                {
                    info.adInfo.wasteToner = '1';
                    stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                //stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}

PrinterDetailInfo QueryPrinterDetailInfo::getFujiXeroxPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Fuji|富士施乐");
    info.Core = "FujiXerox";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    if(info.baseinfo.strModel.toLower().contains("pantum"))
    {
        info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    }
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";

    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    info.firmeware = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
   // info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    //错误信息
    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101 || nErrorCode == 1102)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.at(0).strValue.toInt())
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }
        if (pError.nErrorCode == 23)
        {
            continue;
        }
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        //	pError.ErrorDesc = listValue.at(0).strValue;
        pError.ErrorDesc = QStringLiteral("错误码 : %1").arg(pError.nErrorCode);
        pError.ErrorDescEN = QString("Error Code : %1").arg(pError.nErrorCode);
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        //	pError.nErrorLevel = listValue.at(0).strValue.toInt();
        pError.nErrorLevel = 5;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.7";
    QString strQueryColorOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.29";
    List_Value.clear();

    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();

    QList<MibValue> List_Count;
    //查询印量
 /*
    QString strQueryCountTypeOID = "1.3.6.1.4.1.253.8.53.13.2.1.8";
    QString strQueryCountValueOID = "1.3.6.1.4.1.253.8.53.13.2.1.6";
    List_Value.clear();


    QString queryCountOID = strQueryCountTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, queryCountOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strQueryCountTypeOID)) {
            queryCountOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Count.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Count)
    {
        if (item.strValue.trimmed() == "Color Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 1;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Color Impressions";
            stPBlackCount.strNameCn = QStringLiteral("彩色印量");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.trimmed() == "Black Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Impressions";
            stPCount.strNameCn = QStringLiteral("黑白印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }

        if (item.strValue.trimmed() == "Color Large Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = 1;
            stPCount.strNameEn = "Color Large Impressions";
            stPCount.strNameCn = QStringLiteral("A3彩色印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.trimmed() == "Black Large Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = 1;
            stPCount.strNameEn = "Black Large Impressions";
            stPCount.strNameCn = QStringLiteral("A3黑白印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }
*/
    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Count.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size()>0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString str = listValue.size()>0 ? listValue.value(0).strValue.trimmed() : "";
            QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
            QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);
            if (OkList.at(0) == "E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B 43 5D" || OkList.at(0).contains("Black Toner") || OkList.at(0).contains("E9 BB 91 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92"))
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackToner.nCurrent = nRestValue;
                    info.adInfo.toners[0] = '0';	//未安装/不匹配
                }
                else
                {
                    stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 31 5D" || OkList.at(0).contains("Black Drum")
                    || OkList.at(0).contains("E9 BB 91 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93") || OkList.at(0).contains("Drum Unit"))
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackDrum.nCurrent = nRestValue;
                    info.adInfo.drum[0] = '0';	//未安装或不匹配
                }
                else
                {
                    stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (OkList.at(0) == "E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B" || OkList.at(0).contains("Cyan Toner") || OkList.at(0).contains("E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92"))
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stCToner.nCurrent = nRestValue;
                    info.adInfo.toners[1] = '0';	//未安装或不匹配
                }
                else
                {
                    stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 32 5D" || OkList.at(0).contains("Cyan Drum") || OkList.at(0).contains("E9 9D 92 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93"))
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                if (nRestValue < 0 | nMaxValue < 0)
                {
                    stCyanDrum.nCurrent = nRestValue;
                    info.adInfo.drum[1] = '0';		//未安装或不匹配
                }
                else
                {
                    stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (OkList.at(0) == "E6 B4 8B E7 BA A2 E8 89 B2 E5 A2 A8 E7 B2 89 E7" || OkList.at(0).contains("Magenta Toner") || OkList.at(0).contains("E5 93 81 E7 BA A2 E8 89 B2 E5 A2 A8 E7 B2 89 E7"))
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMToner.nCurrent = nRestValue;
                    info.adInfo.toners[2] = '0';	//未按转或不匹配
                }
                else
                {
                    stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listTonerDetail.push_back(stMToner);
            }
            if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 33 5D" || OkList.at(0).contains("magenta Drum") || OkList.at(0).contains("E5 93 81 E7 BA A2 E8 89 B2 E6 84 9F E5 85 89 E9"))
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMagentaDrum.nCurrent = nRestValue;
                    info.adInfo.drum[2] = '0';		//未安装或不匹配
                }
                else
                {
                    stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (OkList.at(0) == "E9 BB 84 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B" || OkList.at(0).contains("Yellow Toner") || OkList.at(0).contains("E9 BB 84 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92"))
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stYToner.nCurrent = nRestValue;
                    info.adInfo.toners[3] = '0';	//未安装或不匹配
                }
                else
                {
                    stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 34 5D" || OkList.at(0).contains("Yellow Drum") || OkList.at(0).contains("E9 BB 84 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93"))
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    styellowDrum.nCurrent = nRestValue;
                    info.adInfo.drum[3] = '0';	//未按转或不匹配
                }
                else
                {
                    styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (OkList.at(0) == "E5 BA 9F E7 B2 89 E7 9B 92 5B 52 35 5D" || OkList.at(0).contains("Waste Toner") || OkList.at(0).contains("E5 BA 9F E7 B2 89 E7 9B 92"))
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stWasteToner.nCurrent = nRestValue;
                    info.adInfo.wasteToner = '0';		//未安装或不匹配
                }
                else
                {
                    stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getFujiXeroxPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Fuji|富士施乐");
    info.Core = "FujiXerox";
    QString strRet;
    QList<MibValue> List_Value;
    WriteLog::writeToLog("query model!");
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    if(info.baseinfo.strModel.toLower().contains("pantum"))
    {
        info.baseinfo.strBrand = QStringLiteral("Pantum|奔图");
    }
    WriteLog::writeToLog("query SN!");
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    WriteLog::writeToLog("query color!");
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
        info.adInfo.drum = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
        info.adInfo.drum = "1";
    }

    //废粉瓶信息
    info.adInfo.wasteToner = "1";
    WriteLog::writeToLog("query size!");
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }
    WriteLog::writeToLog("query FW!");
    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    info.firmeware = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    WriteLog::writeToLog("query Status!");
    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 1;
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;
    WriteLog::writeToLog("query error!");
    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryGroupIndexOID = "1.3.6.1.2.1.43.18.1.1.5";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    //错误信息
    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        int nErrorCode = item.strValue.toInt();
        if (nErrorCode == 801 || nErrorCode == 802 || nErrorCode == 803 || nErrorCode == 804
                || nErrorCode == 805 || nErrorCode == 806 || nErrorCode == 807 || nErrorCode == 808)
        {
            pError.nErrorCode = 60270;	//进纸错误
        }
        else if (nErrorCode == 3 || nErrorCode == 4 || nErrorCode == 5
                 || nErrorCode == 501 || nErrorCode == 502)
        {
            pError.nErrorCode = 60210;	//开盖错误
        }
        else if (nErrorCode == 8)
        {
            pError.nErrorCode = 60230;	//卡纸错误
        }
        else if (nErrorCode == 2 || nErrorCode == 1)
        {
            pError.nErrorCode = 60260;	//其他错误
        }
        else if (nErrorCode == 1001 || nErrorCode == 1002 || nErrorCode == 1103
                 || nErrorCode == 1105 || nErrorCode == 1106 || nErrorCode == 1108
                 || nErrorCode == 1110 || nErrorCode == 1113
                 || nErrorCode == 1114)
        {
            pError.nErrorCode = 60290;	//耗材状态异常
        }
        else if (nErrorCode == 1101 || nErrorCode == 1102)	//粉盒空
        {//get
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '4';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '4';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '4';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1104)	//粉盒将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色粉盒
                info.adInfo.toners[0] = '3';
                break;
            case 2:	//青色粉盒
                info.adInfo.toners[1] = '3';
                break;
            case 3:	//品红色粉盒
                info.adInfo.toners[2] = '3';
                break;
            case 4:	//黄色粉盒
                info.adInfo.toners[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1107)	//废粉将满
        {
            info.adInfo.wasteToner = '3';
            continue;
        }
        else if (nErrorCode == 1109)	//废粉已满
        {
            info.adInfo.wasteToner = '4';
            continue;
        }
        else if (nErrorCode == 1111)	//硒鼓寿命将尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '3';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '3';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '3';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '3';
                break;
            default:
                break;
            }
            continue;
        }
        else if (nErrorCode == 1112)		//硒鼓寿命尽
        {
            QString temp = item.strOID;
            QString IndexOID = temp.replace(QueryErrorCodeOID, QueryGroupIndexOID);
            List_Value.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, IndexOID, strRet, List_Value);
            switch (List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0)
            {
            case 1:	//黑色硒鼓
                info.adInfo.drum[0] = '4';
                break;
            case 2:	//青色硒鼓
                info.adInfo.drum[1] = '4';
                break;
            case 3:	//品红色硒鼓
                info.adInfo.drum[2] = '4';
                break;
            case 4:	//黄色硒鼓
                info.adInfo.drum[3] = '4';
                break;
            default:
                break;
            }
            continue;
        }
        else
        {
            pError.nErrorCode = nErrorCode;		//未知错误
        }
        if (pError.nErrorCode == 23)
        {
            continue;
        }
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        //	pError.ErrorDesc = listValue.at(0).strValue;
        pError.ErrorDesc = QStringLiteral("错误码 : %1").arg(pError.nErrorCode);
        pError.ErrorDescEN = QString("Error Code : %1").arg(pError.nErrorCode);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        //	pError.nErrorLevel = listValue.at(0).strValue.toInt();
        pError.nErrorLevel = 5;
        info.listPrinterError.append(pError);
    }
    WriteLog::writeToLog("query Count!");

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.7";
    QString strQueryColorOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.1.20.29";
    List_Value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    List_Value.clear();

    //black copy
    QString strQueryBlackCopyCountOID =  "1.3.6.1.4.1.253.8.53.13.2.1.6.103.20.4";
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryBlackCopyCountOID, strRet, List_Value);
    PrinterPCount stPCopyCount;
    stPCopyCount.nColorType = 0;
    stPCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPCopyCount.strNameEn = "black copy counter";
    stPCopyCount.strNameCn = QStringLiteral("黑白复印印量");
    stPCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;

    //黑白印量=黑白打印+黑白复印
    stBlackPCount.nPCount=stBlackPCount.nPCount + stPCopyCount.nPCount;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    List_Value.clear();

    QString strQueryColorCopyCountOID = "1.3.6.1.4.1.253.8.53.13.2.1.6.103.20.25";
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorCopyCountOID, strRet, List_Value);
    PrinterPCount stPColorCopyCount;
    stPColorCopyCount.nColorType = 1;
    stPColorCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPColorCopyCount.strNameEn = "color copy counter";
    stPColorCopyCount.strNameCn = QStringLiteral("彩色复印印量");
    stPColorCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    stColorPCount.nPCount= stColorPCount.nPCount + stPColorCopyCount.nPCount;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();
    //查印量
//    QList<MibValue> listValue;
//    QString strQueryCountValueOID = "1.3.6.1.2.1.43.10.2.1.4.1.1";
//    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCountValueOID, strRet, listValue);
//    int nPCount = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
//    PrinterPCount stPBlackCount;
//    stPBlackCount.nColorType = info.adInfo.nPrinterColor == 1 ? 1 : 0;
//    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.strNameEn = "Color Impressions";
//    stPBlackCount.strNameCn = QStringLiteral("印量");
//    stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
//    info.listPCountDetail.push_back(stPBlackCount);


    /*WriteLog::writeToLog("query Count11!");
    for (auto item : List_Count)
    {
        if (item.strValue.trimmed() == "Color Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryMonoOID;
            QString temp;
            temp = item.strOID;
            strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
            PrinterPCount stPBlackCount;
            stPBlackCount.nColorType = 1;
            stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPBlackCount.strNameEn = "Color Impressions";
            stPBlackCount.strNameCn = QStringLiteral("彩色印量");
            stPBlackCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPBlackCount);
        }
        if (item.strValue.trimmed() == "Black Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
            stPCount.strNameEn = "Black Impressions";
            stPCount.strNameCn = QStringLiteral("黑白印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }

        if (item.strValue.trimmed() == "Color Large Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 1;
            stPCount.nPaperType = 1;
            stPCount.strNameEn = "Color Large Impressions";
            stPCount.strNameCn = QStringLiteral("A3彩色印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
        if (item.strValue.trimmed() == "Black Large Impressions")
        {
            QList<MibValue> listValue;
            QString strQueryColorOID;
            QString temp;
            temp = item.strOID;
            strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
            PrinterPCount stPCount;
            stPCount.nColorType = 0;
            stPCount.nPaperType = 1;
            stPCount.strNameEn = "Black Large Impressions";
            stPCount.strNameCn = QStringLiteral("A3黑白印量");
            stPCount.nPCount = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
            info.listPCountDetail.push_back(stPCount);
        }
    }*/
    WriteLog::writeToLog("query toner!");
    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();


    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    WriteLog::writeToLog("auto color type!");
    QString strSupplyColorantValueOID = "1.3.6.1.2.1.43.12.1.1.4";

    QList<QString> listColor;
    QString ColorantValueOID = strSupplyColorantValueOID;
    while (true)
    {
        List_Value.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, ColorantValueOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyColorantValueOID)) {
            ColorantValueOID = List_Value.at(0).strOID;
            listColor.push_back(List_Value.at(0).strValue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    WriteLog::writeToLog("auto color type finish!");
    WriteLog::writeToLog("listColor size is  " + QString::number(listColor.size()));
    int tonerID = 0;
    int drumID = 0;

    for (auto item : List_Supply)
    {
        QList<MibValue> listValue;
        QString QueryMaxOID;
        QString QueryCurrentOID;
        QString QuerySeriOID;
        QString QueryModelOID;
        QString TempOID = item.strOID;
        QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
        TempOID = item.strOID;
        QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
        TempOID = item.strOID;
        QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
        TempOID = item.strOID;
        QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
        int nMaxValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 100;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
        int nRestValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
        QString strSupplySeri = listValue.size()>0 ? listValue.value(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
        QString strSupplyModel = listValue.size()>0 ? listValue.value(0).strValue : "";
        listValue.clear();
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 21)	//粉盒
        {
            WriteLog::writeToLog("toner class! listColor size is  " + QString::number(listColor.size()));
            if (listColor.at(tonerID).contains("black", Qt::CaseInsensitive))
            {
                WriteLog::writeToLog("black toner!");
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackToner.nCurrent = nRestValue;
                    info.adInfo.toners[0] = '0';	//未安装/不匹配
                }
                else
                {
                    stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listColor.at(tonerID).contains("cyan", Qt::CaseInsensitive))
            {
                WriteLog::writeToLog("cyan toner");
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stCToner.nCurrent = nRestValue;
                    info.adInfo.toners[1] = '0';	//未安装或不匹配
                }
                else
                {
                    stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listColor.at(tonerID).contains("yellow", Qt::CaseInsensitive))
            {
                WriteLog::writeToLog("yellow toner");
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stYToner.nCurrent = nRestValue;
                    info.adInfo.toners[3] = '0';	//未安装或不匹配
                }
                else
                {
                    stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listColor.at(tonerID).contains("magenta", Qt::CaseInsensitive))
            {
                WriteLog::writeToLog("magenta toner");
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMToner.nCurrent = nRestValue;
                    info.adInfo.toners[2] = '0';	//未按转或不匹配
                }
                else
                {
                    stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listTonerDetail.push_back(stMToner);
            }
            tonerID++;
        }
        if (item.strValue.toInt() == 9)		//硒鼓
        {
            WriteLog::writeToLog("drum class! ");
            if (listColor.at(drumID).contains("black", Qt::CaseInsensitive))
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stBlackDrum.nCurrent = nRestValue;
                    info.adInfo.drum[0] = '0';	//未安装或不匹配
                }
                else
                {
                    stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stBlackDrum);
            }
            if (listColor.at(drumID).contains("cyan", Qt::CaseInsensitive))
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
                if (nRestValue < 0 | nMaxValue < 0)
                {
                    stCyanDrum.nCurrent = nRestValue;
                    info.adInfo.drum[1] = '0';		//未安装或不匹配
                }
                else
                {
                    stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }

                info.listDrumDetail.push_back(stCyanDrum);
            }
            if (listColor.at(drumID).contains("magenta", Qt::CaseInsensitive))
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    stMagentaDrum.nCurrent = nRestValue;
                    info.adInfo.drum[2] = '0';		//未安装或不匹配
                }
                else
                {
                    stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(stMagentaDrum);
            }
            if (listColor.at(drumID).contains("yellow", Qt::CaseInsensitive))
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
                if (nRestValue < 0 || nMaxValue < 0)
                {
                    styellowDrum.nCurrent = nRestValue;
                    info.adInfo.drum[3] = '0';	//未按转或不匹配
                }
                else
                {
                    styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                }
                info.listDrumDetail.push_back(styellowDrum);
            }

            drumID++;
        }
        if (item.strValue.toInt() == 4)	//废粉盒
        {
            WriteLog::writeToLog("drum class! ");
            PrinterWasteToner stWasteToner;
            stWasteToner.nWasteTonerID = 0;
            stWasteToner.strWasteTonerModel = strSupplyModel;
            stWasteToner.strWasteTonerSN = strSupplySeri;
            stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶 .");
            if (nRestValue < 0 || nMaxValue < 0)
            {
                stWasteToner.nCurrent = nRestValue;
                info.adInfo.wasteToner = '0';		//未安装或不匹配
            }
            else
            {
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
            }
            stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
            info.listWasteTonerDetail.push_back(stWasteToner);
        }

    }
    //for (auto item : List_Supply)
    //{
    //	if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 9)
    //	{
    //		QList<MibValue> listValue;
    //		QString QueryMaxOID;
    //		QString QueryCurrentOID;
    //		QString QueryDiscriptOID;
    //		QString QuerySeriOID;
    //		QString QueryModelOID;
    //		QString TempOID = item.strOID;
    //		QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
    //		TempOID = item.strOID;
    //		QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
    //		TempOID = item.strOID;
    //		QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
    //		TempOID = item.strOID;
    //		QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
    //		TempOID = item.strOID;
    //		QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
    //		listValue.clear();
    //		nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
    //		int nMaxValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 100;
    //		listValue.clear();
    //		nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
    //		int nRestValue = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
    //		listValue.clear();
    //		nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
    //		QString strSupplySeri = listValue.size()>0 ? listValue.value(0).strValue : "";
    //		listValue.clear();
    //		nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
    //		QString strSupplyModel = listValue.size()>0 ? listValue.value(0).strValue : "";
    //		listValue.clear();
    //		nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
    //		QString str = listValue.size()>0 ? listValue.value(0).strValue.trimmed() : "";
    //		QStringList mtfList = str.split(newLine, QString::SkipEmptyParts);
    //		QStringList OkList = mtfList.at(0).split("  ", QString::SkipEmptyParts);
    //		WriteLog::writeToLog("ip: " +  strIPAddress + " \r\n Max: "+ nMaxValue + " \r\n nRestValue: " + nRestValue + " \r\n toner or other: " + OkList.at(0));
    //		if (OkList.at(0) == "E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B 43 5D" || OkList.at(0).contains("Black Toner", Qt::CaseInsensitive) ||
    //			OkList.at(0).contains("E9 BB 91 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92", Qt::CaseInsensitive) || OkList.at(0).contains("E9.BB.91.E8.89.B2.E5.A2.A8.E7.B2.89.E7.AD.92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.BB.91.E8.89.B2.E5.A2.A8.E7.B2.89.E7.9B.92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("Toner Cartridge", Qt::CaseInsensitive) || OkList.at(0).contains("Print Cartridge", Qt::CaseInsensitive))
    //		{
    //			PrinterToner stBlackToner;
    //			stBlackToner.nColorType = 1;
    //			stBlackToner.nTonerID = 0;
    //			stBlackToner.TonerModel = strSupplyModel;
    //			stBlackToner.strTonerSN = strSupplySeri;
    //			stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stBlackToner.nCurrent = nRestValue;
    //				info.adInfo.toners[0] = '0';	//未安装/不匹配
    //			}
    //			else
    //			{
    //				stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			info.listTonerDetail.push_back(stBlackToner);
    //		}
    //		if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 31 5D" || OkList.at(0).contains("Black Drum", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9 BB 91 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93", Qt::CaseInsensitive) || OkList.at(0).contains("Drum Unit", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.BB.91.E8.89.B2.E6.84.9F.E5.85.89.E9.BC.93", Qt::CaseInsensitive))
    //		{
    //			PrinterDrum stBlackDrum;
    //			stBlackDrum.nColorType = 1;
    //			stBlackDrum.nDrumID = 0;
    //			stBlackDrum.DrumModel = strSupplyModel;
    //			stBlackDrum.DrumSN = strSupplySeri;
    //			stBlackDrum.strDrumName = QStringLiteral("Black Photoconductor|黑色硒鼓");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stBlackDrum.nCurrent = nRestValue;
    //				info.adInfo.drum[0] = '0';	//未安装或不匹配
    //			}
    //			else
    //			{
    //				stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}

    //			info.listDrumDetail.push_back(stBlackDrum);
    //		}
    //		if (OkList.at(0) == "E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B" || OkList.at(0).contains("Cyan Toner", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9 9D 92 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.9D.92.E8.89.B2.E5.A2.A8.E7.B2.89.E7.AD.92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.9D.92.E8.89.B2.E5.A2.A8.E7.B2.89.E7.9B.92", Qt::CaseInsensitive))
    //		{
    //			//查询青红粉盒
    //			PrinterToner stCToner;
    //			stCToner.nColorType = 2;
    //			stCToner.nTonerID = 1;
    //			stCToner.TonerModel = strSupplyModel;
    //			stCToner.strTonerSN = strSupplySeri;
    //			stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stCToner.nCurrent = nRestValue;
    //				info.adInfo.toners[1] = '0';	//未安装或不匹配
    //			}
    //			else
    //			{
    //				stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			info.listTonerDetail.push_back(stCToner);
    //		}
    //		if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 32 5D" || OkList.at(0).contains("Cyan Drum", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9 9D 92 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.9D.92.E8.89.B2.E6.84.9F.E5.85.89.E9.BC.93", Qt::CaseInsensitive))
    //		{
    //			PrinterDrum stCyanDrum;
    //			stCyanDrum.nColorType = 2;
    //			stCyanDrum.nDrumID = 1;
    //			stCyanDrum.DrumModel = strSupplyModel;
    //			stCyanDrum.DrumSN = strSupplySeri;
    //			stCyanDrum.strDrumName = QStringLiteral("Cyan Photoconductor|青色硒鼓");
    //			if (nRestValue < 0 | nMaxValue < 0)
    //			{
    //				stCyanDrum.nCurrent = nRestValue;
    //				info.adInfo.drum[1] = '0';		//未安装或不匹配
    //			}
    //			else
    //			{
    //				stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}

    //			info.listDrumDetail.push_back(stCyanDrum);
    //		}
    //		if (OkList.at(0) == "E6 B4 8B E7 BA A2 E8 89 B2 E5 A2 A8 E7 B2 89 E7" || OkList.at(0).contains("Magenta Toner", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5 93 81 E7 BA A2 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5.93.81.E7.BA.A2.E8.89.B2.E5.A2.A8.E7.B2.89.E7.AD.92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5.93.81.E7.BA.A2.E8.89.B2.E5.A2.A8.E7.B2.89.E7.9B.92", Qt::CaseInsensitive))
    //		{
    //			PrinterToner stMToner;
    //			stMToner.nColorType = 3;
    //			stMToner.nTonerID = 2;
    //			stMToner.TonerModel = strSupplyModel;
    //			stMToner.strTonerSN = strSupplySeri;
    //			stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stMToner.nCurrent = nRestValue;
    //				info.adInfo.toners[2] = '0';	//未按转或不匹配
    //			}
    //			else
    //			{
    //				stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}

    //			info.listTonerDetail.push_back(stMToner);
    //		}
    //		if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 33 5D" || OkList.at(0).contains("magenta Drum", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5 93 81 E7 BA A2 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5.93.81.E7.BA.A2.E8.89.B2.E6.84.9F.E5.85.89.E9.BC.93", Qt::CaseInsensitive))
    //		{
    //			PrinterDrum stMagentaDrum;
    //			stMagentaDrum.nColorType = 3;
    //			stMagentaDrum.nDrumID = 2;
    //			stMagentaDrum.DrumModel = strSupplyModel;
    //			stMagentaDrum.DrumSN = strSupplySeri;
    //			stMagentaDrum.strDrumName = QStringLiteral("Magenta Photoconductor|品红色硒鼓");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stMagentaDrum.nCurrent = nRestValue;
    //				info.adInfo.drum[2] = '0';		//未安装或不匹配
    //			}
    //			else
    //			{
    //				stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			info.listDrumDetail.push_back(stMagentaDrum);
    //		}
    //		if (OkList.at(0) == "E9 BB 84 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92 5B" || OkList.at(0).contains("Yellow Toner", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9 BB 84 E8 89 B2 E5 A2 A8 E7 B2 89 E7 AD 92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.BB.84.E8.89.B2.E5.A2.A8.E7.B2.89.E7.AD.92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.BB.84.E8.89.B2.E5.A2.A8.E7.B2.89.E7.9B.92", Qt::CaseInsensitive))
    //		{
    //			PrinterToner stYToner;
    //			stYToner.nColorType = 4;
    //			stYToner.nTonerID = 3;
    //			stYToner.TonerModel = strSupplyModel;
    //			stYToner.strTonerSN = strSupplySeri;
    //			stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stYToner.nCurrent = nRestValue;
    //				info.adInfo.toners[3] = '0';	//未安装或不匹配
    //			}
    //			else
    //			{
    //				stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			info.listTonerDetail.push_back(stYToner);
    //		}
    //		if (OkList.at(0) == "E6 84 9F E5 85 89 E9 BC 93 5B 52 34 5D" || OkList.at(0).contains("Yellow Drum", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9 BB 84 E8 89 B2 E6 84 9F E5 85 89 E9 BC 93", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E9.BB.84.E8.89.B2.E6.84.9F.E5.85.89.E9.BC.93", Qt::CaseInsensitive))
    //		{
    //			PrinterDrum styellowDrum;
    //			styellowDrum.nColorType = 4;
    //			styellowDrum.nDrumID = 3;
    //			styellowDrum.DrumModel = strSupplyModel;
    //			styellowDrum.DrumSN = strSupplySeri;
    //			styellowDrum.strDrumName = QStringLiteral("Yellow Photoconductor|黄色硒鼓");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				styellowDrum.nCurrent = nRestValue;
    //				info.adInfo.drum[3] = '0';	//未按转或不匹配
    //			}
    //			else
    //			{
    //				styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			info.listDrumDetail.push_back(styellowDrum);
    //		}
    //		if (OkList.at(0) == "E5 BA 9F E7 B2 89 E7 9B 92 5B 52 35 5D" || OkList.at(0).contains("Waste Toner", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5 BA 9F E7 B2 89 E7 9B 92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5.BA.9F.E7.B2.89.E7.9B.92", Qt::CaseInsensitive)
    //			|| OkList.at(0) == "E5 BA 9F E7 B2 89 E7 9B 92")
    //		{
    //			PrinterWasteToner stWasteToner;
    //			stWasteToner.nWasteTonerID = 0;
    //			stWasteToner.strWasteTonerModel = strSupplyModel;
    //			stWasteToner.strWasteTonerSN = strSupplySeri;
    //			stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stWasteToner.nCurrent = nRestValue;
    //				info.adInfo.wasteToner = '0';		//未安装或不匹配
    //			}
    //			else
    //			{
    //				stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			info.listWasteTonerDetail.push_back(stWasteToner);
    //		}
    //		if (OkList.at(0) == "E5 BA 9F E7 B2 89 E7 9B 92 5B 52 35 5D" || OkList.at(0).contains("Waste Toner", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5 BA 9F E7 B2 89 E7 9B 92", Qt::CaseInsensitive)
    //			|| OkList.at(0).contains("E5.BA.9F.E7.B2.89.E7.9B.92", Qt::CaseInsensitive)
    //			|| OkList.at(0) == "E5.BA.9F.E7.B2.89.E7.9B.92")
    //		{
    //			PrinterWasteToner stWasteToner;
    //			stWasteToner.nWasteTonerID = 0;
    //			stWasteToner.strWasteTonerModel = strSupplyModel;
    //			stWasteToner.strWasteTonerSN = strSupplySeri;
    //			stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶 .");
    //			if (nRestValue < 0 || nMaxValue < 0)
    //			{
    //				stWasteToner.nCurrent = nRestValue;
    //				info.adInfo.wasteToner = '0';		//未安装或不匹配
    //			}
    //			else
    //			{
    //				stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			}
    //			stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
    //			info.listWasteTonerDetail.push_back(stWasteToner);
    //		}
    //	}
    //}
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getLenovoPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Lenovo|联想");
    info.Core = "lenovo";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}



PrinterDetailInfo QueryPrinterDetailInfo::getLenovoPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Lenovo|联想");
    info.Core = "lenovo";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.10.2.1.6.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
  //  info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

    PrinterPCount stPBlackCount;
    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPBlackCount.strNameEn = "Print count";
    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
    info.listPCountDetail.push_back(stPBlackCount);


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getKyoceraPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Kyocera|京瓷");
    info.Core = "kyocera";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();//1.3.6.1.2.1.43.11.1.1.3.1.2
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatusCode = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    if (nStatusCode != 5)
    {
       if (nStatusCode == 2)
       {
           nStatusCode = 2;	//预热
       }
       else {
           nStatusCode = 1; //正常
       }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;
    //查询黑色粉盒
    QString QueryBlackTonerOID = "1.3.6.1.2.1.43.11.1.1.9.1.1";
    QString QueryTotalTonerOID = "1.3.6.1.2.1.43.11.1.1.8.1.1";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryBlackTonerOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    int nBlackRestValue = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryTotalTonerOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    int nBlackMaxValue = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    //获取粉盒状态
    QString QueryTonerStatusOID = "1.3.6.1.2.1.43.10.2.1.15.1.1";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, QueryTonerStatusOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    int nTonerStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    switch (nTonerStatus)
    {
    case 0:
      break;
    case 1:
      info.adInfo.toners[0] = '0';	//未检测到黑色碳粉盒
      break;
    case 2:
      info.adInfo.toners[0] = '2';	//黑色碳粉盒不匹配状态
      break;
    case 3:
      info.adInfo.toners[0] = '4';	//黑色粉盒寿命尽
      break;
    default:
      break;
    }

    QString QuertTonerDescription="1.3.6.1.2.1.43.11.1.1.6";//1.3.6.1.2.1.43.11.1.1.6
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, QuertTonerDescription, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    QString strBlackTonerModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    PrinterToner stBlackToner;
    stBlackToner.nColorType = 1;
    stBlackToner.nTonerID = 0;
    stBlackToner.TonerModel = strBlackTonerModel;
    stBlackToner.strTonerSN = "";
    stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    stBlackToner.nCurrent = (int)(double) nBlackRestValue/ (double)nBlackMaxValue * 100;
    if (nBlackRestValue < 0 || nBlackMaxValue < 0)//未安装/不匹配
    {
      info.adInfo.toners[0] = '0';
    }

    info.listTonerDetail.push_back(stBlackToner);

    //查询印量
    QString strQueryTotalOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";
    QString strQueryColorOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";//ECOSYS M2040d为黑白机无彩色印量，故彩色印量设为0
    List_Value.clear();

    //total
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
      return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color  ECOSYS M2040d为黑白机无彩色印量，故彩色印量设为0
    //    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
    //    if (nResult != QueryResult::Successed)
    //    {
    //        return info;
    //    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount =0;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();

    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
//    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
//    List_Value.clear();
//    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

//    PrinterPCount stPBlackCount;
//    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.strNameEn = "Print count";
//    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
//    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPBlackCount);

    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getKyoceraPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("Kyocera|京瓷");
    info.Core = "kyocera";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.25.3.2.1.3.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.size()>0 ? List_Value.at(0).strValue : "";
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.5.1.1.17.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.size() > 0 ? List_Value.at(0).strValue : "";
    //查询打印机颜色
    List_Value.clear();//1.3.6.1.2.1.43.11.1.1.3.1.2
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.43.11.1.1.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    if (nColor > 0)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.4", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.8.2.1.5", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.4.1.641.6.4.2.3.1.2", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatusCode = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    if (nStatusCode != 5)
    {
        if (nStatusCode == 2)
        {
            nStatusCode = 2;	//预热
        }
        else {
            nStatusCode = 1; //正常
        }
    }
    info.baseinfo.nPrinterStatus = nStatusCode;


    //查询黑色粉盒
    QString QueryBlackTonerOID = "1.3.6.1.2.1.43.11.1.1.9.1.1";
    QString QueryTotalTonerOID = "1.3.6.1.2.1.43.11.1.1.8.1.1";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryBlackTonerOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nBlackRestValue = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryTotalTonerOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nBlackMaxValue = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;

    //获取粉盒状态
    QString QueryTonerStatusOID = "1.3.6.1.2.1.43.10.2.1.15.1.1";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, QueryTonerStatusOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nTonerStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    switch (nTonerStatus)
    {
    case 0:
        break;
    case 1:
        info.adInfo.toners[0] = '0';	//未检测到黑色碳粉盒
        break;
    case 2:
        info.adInfo.toners[0] = '2';	//黑色碳粉盒不匹配状态
        break;
    case 3:
        info.adInfo.toners[0] = '4';	//黑色粉盒寿命尽
        break;
    default:
        break;
    }

    QString QuertTonerDescription="1.3.6.1.2.1.43.11.1.1.6";//1.3.6.1.2.1.43.11.1.1.6
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, QuertTonerDescription, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    QString strBlackTonerModel = List_Value.size() > 0 ? List_Value.at(0).strValue : "";

    PrinterToner stBlackToner;
    stBlackToner.nColorType = 1;
    stBlackToner.nTonerID = 0;
    stBlackToner.TonerModel = strBlackTonerModel;
    stBlackToner.strTonerSN = "";
    stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
    stBlackToner.nCurrent = (int)(double) nBlackRestValue/ (double)nBlackMaxValue * 100;
    if (nBlackRestValue < 0 || nBlackMaxValue < 0)//未安装/不匹配
    {
        info.adInfo.toners[0] = '0';
    }

    info.listTonerDetail.push_back(stBlackToner);

    //查询印量

    QString strQueryTotalOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";
    QString strQueryBlackOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";
    QString strQueryColorOID = "1.3.6.1.4.1.1347.43.10.1.1.12.1.1";//ECOSYS M2040d为黑白机无彩色印量，故彩色印量设为0
    List_Value.clear();

    //total
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryTotalOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stTotalPCount;
    stTotalPCount.nColorType = 0;
    stTotalPCount.nPaperType = 0;
    stTotalPCount.strNameEn = "Total Pages";
    stTotalPCount.strNameCn = QStringLiteral("总印量");
    stTotalPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stTotalPCount);
    List_Value.clear();

    //black
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get,strQueryBlackOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    PrinterPCount stBlackPCount;
    stBlackPCount.nColorType = 0;
    stBlackPCount.nPaperType = 0;
    stBlackPCount.strNameEn = "Black Pages";
    stBlackPCount.strNameCn = QStringLiteral("黑白印量");
    stBlackPCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;;
    info.listPCountDetail.push_back(stBlackPCount);
    List_Value.clear();

    //Color  ECOSYS M2040d为黑白机无彩色印量，故彩色印量设为0
//    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, List_Value);
//    if (nResult != QueryResult::Successed)
//    {
//        return info;
//    }
    PrinterPCount stColorPCount;
    stColorPCount.nColorType = 1;
    stColorPCount.nPaperType = 0;
    stColorPCount.strNameEn = "Color Pages";
    stColorPCount.strNameCn = QStringLiteral("彩色印量");
    stColorPCount.nPCount =0;
    info.listPCountDetail.push_back(stColorPCount);
    List_Value.clear();



    //查询打印机故障状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    QString QueryErrorLocation = "1.3.6.1.2.1.43.18.1.1.6";
    List_Value.clear();
    nResult = WalkMib(strIPAddress, QueryErrorCodeOID, List_Value);

    for (auto item : List_Value)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        if (pError.nErrorCode == 808 || pError.nErrorCode == 1)
        {
            continue;
        }

        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        temp = item.strOID;
        QString LocationOID = temp.replace(QueryErrorCodeOID, QueryErrorLocation);

        QList<MibValue> listValue;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size() > 0 ? listValue.at(0).strValue : "";
        //strPModel":"HP LaserJet M506" 需要进行转换编码
        //pError.ErrorDesc = Utf8ToCh(pError.ErrorDesc);
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LocationOID, strRet, listValue);
        if (pError.nErrorCode == 1102)
        {
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 0:
                info.adInfo.toners[0] = '4';
                pError.ErrorDesc = QStringLiteral("黑色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Black Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 1:
                info.adInfo.toners[1] = '4';
                pError.ErrorDesc = QStringLiteral("青色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Cyan Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 2:
                info.adInfo.toners[2] = '4';
                pError.ErrorDesc = QStringLiteral("品红色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Magenta Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            case 3:
                info.adInfo.toners[3] = '4';
                pError.ErrorDesc = QStringLiteral("黄色耗材: 耗材余量严重不足。");
                pError.ErrorDescEN = "Yellow Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("耗材余量严重不足。");
                pError.ErrorDescEN = "Cartridge:empty ";
                pError.nErrorLevel = 4;
                break;
            }
            continue;
        }
        if (pError.nErrorCode == 3 || pError.nErrorCode == 4 || pError.nErrorCode == 5 ||
                pError.nErrorCode == 6 || pError.nErrorCode == 501 || pError.nErrorCode == 502)
        {
            pError.nErrorCode = 60210;		//开盖错误
            int nLocation = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : -1;
            switch (nLocation)
            {
            case 6:
                pError.ErrorDesc = QStringLiteral("关闭后门。");
                pError.ErrorDescEN = "Close back door";
                pError.nErrorLevel = 5;
                break;
            case 2:
                pError.ErrorDesc = QStringLiteral("请关闭墨盒检修门。");
                pError.ErrorDescEN = "Please Close Cartridge door";
                pError.nErrorLevel = 5;
                break;
            default:
                pError.ErrorDesc = QStringLiteral("关闭盖门。");
                pError.ErrorDescEN = "Close door";
                pError.nErrorLevel = 5;
                break;
            }
        }
        if (pError.nErrorCode == 8)
        {
            pError.nErrorCode = 60230;		//卡纸错误
            pError.ErrorDesc = QStringLiteral("卡纸，打开盖门清除纸张。");
            pError.ErrorDescEN = "Paper jam, open shell remove the paper.";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 801 || pError.nErrorCode == 802 || pError.nErrorCode == 803 || pError.nErrorCode == 804
                || pError.nErrorCode == 805 || pError.nErrorCode == 806 || pError.nErrorCode == 807 || pError.nErrorCode == 808)
        {
            pError.nErrorCode = 60270;		//进纸失败
            pError.ErrorDesc = QStringLiteral("进纸失败");
            pError.ErrorDescEN = "Paper Feed Failed";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 901 || pError.nErrorCode == 902 || pError.nErrorCode == 903)
        {
            pError.nErrorCode = 60280;		//出纸错误
            pError.ErrorDesc = QStringLiteral("出纸错误");
            pError.ErrorDescEN = "Paper Out Error";
            pError.nErrorLevel = 5;
        }
        if (pError.nErrorCode == 1501 || pError.nErrorCode == 1502 || pError.nErrorCode == 1503 || pError.nErrorCode == 1504
                || pError.nErrorCode == 1505 || pError.nErrorCode == 1506 || pError.nErrorCode == 1507)
        {
            pError.nErrorCode = 60110;		//内部错误
            pError.ErrorDesc = QStringLiteral("内部错误");
            pError.ErrorDescEN = "Internal Error";
            pError.nErrorLevel = 1;
        }

        info.listPrinterError.append(pError);
    }

    //查询印量
//    QString strQueryCountTypeOID = "1.3.6.1.2.1.43.10.2.1.4";
//    List_Value.clear();
//    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, strQueryCountTypeOID, strRet, List_Value);

//    PrinterPCount stPBlackCount;
//    stPBlackCount.nColorType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
//    stPBlackCount.strNameEn = "Print count";
//    stPBlackCount.strNameCn = info.adInfo.nPrinterSize == 1 ? QStringLiteral("A3 印量") : QStringLiteral("A4 印量");
//    stPBlackCount.nPCount = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : -1;
//    info.listPCountDetail.push_back(stPBlackCount);



    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();
    nResult = WalkMib(strIPAddress, strSupplyTypeOID, List_Value);
    for (auto item : List_Value)
    {
        if (item.strValue.toInt() == 3 || item.strValue.toInt() == 4 || item.strValue.toInt() == 21 || item.strValue.toInt() == 9 || item.strValue.toInt() == 6)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.at(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            QStringList emptyList;
            QStringList hpDesc = listValue.size() > 0 ? listValue.at(0).strValue.split(newLine) : emptyList;
            QString strName;
            QString strModel;
            if (hpDesc.size() > 0)
            {
                strName = hpDesc.at(0);

                QStringList namelist = strName.split("  ", QString::SkipEmptyParts);
                if (namelist.size() > 1)
                {
                    strName = namelist.at(1);
                }
            }
            if (hpDesc.size() > 1)
            {
                strModel = hpDesc.at(1);
                QStringList modelList = strModel.split("  ", QString::SkipEmptyParts);
                if (modelList.size() > 0)
                {
                    strModel = modelList.at(1);
                }
            }

            if (listValue.at(0).strValue.contains("Black Cartridge") || strName == "Black Cartridge")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("Black Cartridge|黑色粉盒");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装/不匹配
                {
                    info.adInfo.toners[0] = '0';
                }

                info.listTonerDetail.push_back(stBlackToner);
            }
            if (listValue.at(0).strValue.contains("Cyan Cartridge") || strName == "Cyan Cartridge")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("Cyan Cartridge|青色粉盒");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[1] = '0';
                }
                info.listTonerDetail.push_back(stCToner);
            }
            if (listValue.at(0).strValue.contains("Magenta Cartridge") || strName == "Magenta Cartridge")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("Magenta Cartridge|品红色粉盒");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)	//未安装
                {
                    info.adInfo.toners[2] = '0';
                }
                info.listTonerDetail.push_back(stMToner);
            }
            if (listValue.at(0).strValue.contains("Yellow Cartridge") || strName == "Yellow Cartridge")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Yellow Cartridge|黄色粉盒");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.toners[3] = '0';
                }
                info.listTonerDetail.push_back(stYToner);
            }
            if (listValue.at(0).strValue == "Waste Toner Bottle")
            {
                PrinterWasteToner stWasteToner;
                stWasteToner.nWasteTonerID = 0;
                stWasteToner.strWasteTonerModel = strSupplyModel;
                stWasteToner.strWasteTonerSN = strSupplySeri;
                stWasteToner.strWasteTonerName = QStringLiteral("Waste Toner Bottle|废粉瓶");
                stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                if (nRestValue < 0 || nMaxValue < 0)//未安装
                {
                    info.adInfo.wasteToner = '0';
                }
                info.listWasteTonerDetail.push_back(stWasteToner);
            }
        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getKonicaMinoltaPrinterDetailInfoV3(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("KM|科美");
    info.Core = "km";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.9.2.1.15", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.9.2.1.16", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
   // info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size()>0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV3(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCopyCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.1.1";
    QString strQueryPrintCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.1.2";
    QString strQueryColorCopyCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.2.1";
    QString strQueryColorPrintCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.2.2";
    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryCopyCountOID, strRet, List_Value);
    PrinterPCount stPCopyCount;
    stPCopyCount.nColorType = 0;
    stPCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPCopyCount.strNameEn = "black copy counter";
    stPCopyCount.strNameCn = QStringLiteral("黑白复印印量");
    stPCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPCopyCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryPrintCountOID, strRet, List_Value);
    PrinterPCount stPPrintCount;
    stPPrintCount.nColorType = 0;
    stPPrintCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPPrintCount.strNameEn = "black print counter";
    stPPrintCount.strNameCn = QStringLiteral("黑白打印印量");
    stPPrintCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPPrintCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorCopyCountOID, strRet, List_Value);
    PrinterPCount stPColorCopyCount;
    stPColorCopyCount.nColorType = 1;
    stPColorCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPColorCopyCount.strNameEn = "color copy counter";
    stPColorCopyCount.strNameCn = QStringLiteral("彩色复印印量");
    stPColorCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPColorCopyCount);

    List_Value.clear();
    nResult = queryMibDataV3(strIPAddress, QueryMethod::get, strQueryColorPrintCountOID, strRet, List_Value);
    PrinterPCount stPcolorPrintCount;
    stPcolorPrintCount.nColorType = 1;
    stPcolorPrintCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPcolorPrintCount.strNameEn = "color print counter";
    stPcolorPrintCount.strNameCn = QStringLiteral("彩色打印印量");
    stPcolorPrintCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPcolorPrintCount);


    // 	if (item.strValue.trimmed() == "Color Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryMonoOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
    // 		PrinterPCount stPBlackCount;
    // 		stPBlackCount.nColorType = 1;
    // 		stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    // 		stPBlackCount.strNameEn = "Color Impressions";
    // 		stPBlackCount.strNameCn = QStringLiteral("彩色印量");
    // 		stPBlackCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPBlackCount);
    // 	}
    // 	if (item.strValue.trimmed() == "Black Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 0;
    // 		stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    // 		stPCount.strNameEn = "Black Impressions";
    // 		stPCount.strNameCn = QStringLiteral("黑白印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}
    //
    // 	if (item.strValue.trimmed() == "Color Large Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 1;
    // 		stPCount.nPaperType = 1;
    // 		stPCount.strNameEn = "Color Large Impressions";
    // 		stPCount.strNameCn = QStringLiteral("A3彩色印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}
    // 	if (item.strValue.trimmed() == "Black Large Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 0;
    // 		stPCount.nPaperType = 1;
    // 		stPCount.strNameEn = "Black Large Impressions";
    // 		stPCount.strNameCn = QStringLiteral("A3黑白印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV3(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString strTonerDesc = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";

            if (strTonerDesc == "Toner (Black)")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("K|黑色");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }

            if (strTonerDesc == "Toner (Cyan)")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("C|青色墨粉");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }

            if (strTonerDesc == "Toner (Magenta)")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("M|品红色墨粉");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }

            if (strTonerDesc == "Toner (Yellow)")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Y|黄色墨粉");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
        }
        if (item.strValue.toInt() == 4)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            PrinterWasteToner stWasteToner;
            stWasteToner.nWasteTonerID = 0;
            stWasteToner.strWasteTonerModel = strSupplyModel;
            stWasteToner.strWasteTonerSN = strSupplySeri;
            stWasteToner.strWasteTonerName = QStringLiteral("WasteToner|废粉盒");
            stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
            info.listWasteTonerDetail.push_back(stWasteToner);

        }
        if (item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV3(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString strDrumDesc = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";

            if (strDrumDesc == "Drum Cartridge (Black)")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("K|黑色");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }

            if (strDrumDesc == "Drum Cartridge (Cyan)")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("C|青色");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }

            if (strDrumDesc == "Drum Cartridge (Yellow)")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Y|黄色");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (strDrumDesc == "Drum Cartridge (Magenta)")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("M|品红色");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }

        }
    }
    info.nResult = 0;
    return info;
}


PrinterDetailInfo QueryPrinterDetailInfo::getKonicaMinoltaPrinterDetailInfo(QString strIPAddress)
{
    PrinterDetailInfo info;
    info.baseinfo.strIPaddress = strIPAddress;
    info.baseinfo.strBrand = QStringLiteral("KM|科美");
    info.Core = "km";
    QString strRet;
    QList<MibValue> List_Value;
    //查询型号
    List_Value.clear();
    QueryResult nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.25.3.2.1.3", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strModel = List_Value.at(0).strValue;
    //查询SN
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.5.1.1.17", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strPrinterSN = List_Value.at(0).strValue;
    //查询打印机颜色
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.10.2.1.6", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nColor = List_Value.at(0).strValue.toInt();
    if (nColor > 1)
    {
        info.adInfo.nPrinterColor = 1;
        info.adInfo.toners = "1111";
    }
    else
    {
        info.adInfo.nPrinterColor = 0;
        info.adInfo.toners = "1";
    }
    //查询打印机尺寸信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.9.2.1.15", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    int nPaperLen = List_Value.at(0).strValue.toInt();
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, "1.3.6.1.2.1.43.9.2.1.16", strRet, List_Value);
    int nPaperwidth = List_Value.at(0).strValue.toInt();
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.adInfo.nPrinterSize = 0;
    if (nPaperLen >= 420000 && nPaperwidth >= 297000)
    {
        info.adInfo.nPrinterSize = 1;
    }

    //查询打印机固件信息
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, "1.3.6.1.2.1.1.1", strRet, List_Value);
    if (nResult != QueryResult::Successed) {
        return info;
    }
    info.baseinfo.strFirmeWire = List_Value.size()>0 ? List_Value.at(0).strValue : "";

    //查询打印机状态信息
    QString QueryStatusCodeOID = "1.3.6.1.2.1.25.3.2.1.5.1";

    List_Value.clear();
    nResult = queryMibDataV2(strIPAddress, QueryMethod::get, QueryStatusCodeOID, strRet, List_Value);
    if (nResult != QueryResult::Successed)
    {
        return info;
    }
    int nStatus = List_Value.size() > 0 ? List_Value.at(0).strValue.toInt() : 0;
    //WriteLog::writeToLog(info.baseinfo.strModel + " status:" + QString::number(nStatus));
    if (nStatus == 5)
    {
        info.baseinfo.nPrinterStatus = 5;
    }
    else
    {
        info.baseinfo.nPrinterStatus = 1;
    }
 //   info.baseinfo.nPrinterStatus = nStatus;

    //查询打印机状态信息
    QString QueryErrorCodeOID = "1.3.6.1.2.1.43.18.1.1.7";
    QString QueryErrorDiscOID = "1.3.6.1.2.1.43.18.1.1.8";
    QString QueryErrorLevelOID = "1.3.6.1.2.1.43.18.1.1.2";
    List_Value.clear();

    QList<MibValue> List_Error;
    QString ErrorCodeOID = QueryErrorCodeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, ErrorCodeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(QueryErrorCodeOID)) {
            ErrorCodeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Error.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }

    for (auto item : List_Error)
    {
        PrinterMIBError pError;
        pError.nErrorCode = item.strValue.toInt();
        QString temp = item.strOID;
        QString DiscOID = temp.replace(QueryErrorCodeOID, QueryErrorDiscOID);
        temp = item.strOID;
        QString LevelOID = temp.replace(QueryErrorCodeOID, QueryErrorLevelOID);
        QList<MibValue> listValue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, DiscOID, strRet, listValue);
        pError.ErrorDesc = listValue.size()>0 ? listValue.at(0).strValue : "";
        listValue.clear();
        nResult = queryMibDataV1(strIPAddress, QueryMethod::get, LevelOID, strRet, listValue);
        pError.nErrorLevel = listValue.size()>0 ? listValue.at(0).strValue.toInt() : 0;
        info.listPrinterError.append(pError);
    }

    //查询印量
    QString strQueryCopyCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.1.1";
    QString strQueryPrintCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.1.2";
    QString strQueryColorCopyCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.2.1";
    QString strQueryColorPrintCountOID = "1.3.6.1.4.1.18334.1.1.1.5.7.2.2.1.5.2.2";
    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryCopyCountOID, strRet, List_Value);
    PrinterPCount stPCopyCount;
    stPCopyCount.nColorType = 0;
    stPCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPCopyCount.strNameEn = "black copy counter";
    stPCopyCount.strNameCn = QStringLiteral("黑白复印印量");
    stPCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPCopyCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryPrintCountOID, strRet, List_Value);
    PrinterPCount stPPrintCount;
    stPPrintCount.nColorType = 0;
    stPPrintCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPPrintCount.strNameEn = "black print counter";
    stPPrintCount.strNameCn = QStringLiteral("黑白打印印量");
    stPPrintCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPPrintCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryColorCopyCountOID, strRet, List_Value);
    PrinterPCount stPColorCopyCount;
    stPColorCopyCount.nColorType = 1;
    stPColorCopyCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPColorCopyCount.strNameEn = "color copy counter";
    stPColorCopyCount.strNameCn = QStringLiteral("彩色复印印量");
    stPColorCopyCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPColorCopyCount);

    List_Value.clear();
    nResult = queryMibDataV1(strIPAddress, QueryMethod::get, strQueryColorPrintCountOID, strRet, List_Value);
    PrinterPCount stPcolorPrintCount;
    stPcolorPrintCount.nColorType = 1;
    stPcolorPrintCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    stPcolorPrintCount.strNameEn = "color print counter";
    stPcolorPrintCount.strNameCn = QStringLiteral("彩色打印印量");
    stPcolorPrintCount.nPCount = List_Value.size()>0 ? List_Value.at(0).strValue.toInt() : 0;
    info.listPCountDetail.push_back(stPcolorPrintCount);


    // 	if (item.strValue.trimmed() == "Color Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryMonoOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryMonoOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryMonoOID, strRet, listValue);
    // 		PrinterPCount stPBlackCount;
    // 		stPBlackCount.nColorType = 1;
    // 		stPBlackCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    // 		stPBlackCount.strNameEn = "Color Impressions";
    // 		stPBlackCount.strNameCn = QStringLiteral("彩色印量");
    // 		stPBlackCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPBlackCount);
    // 	}
    // 	if (item.strValue.trimmed() == "Black Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 0;
    // 		stPCount.nPaperType = info.adInfo.nPrinterSize == 1 ? 1 : 0;
    // 		stPCount.strNameEn = "Black Impressions";
    // 		stPCount.strNameCn = QStringLiteral("黑白印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}
    //
    // 	if (item.strValue.trimmed() == "Color Large Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 1;
    // 		stPCount.nPaperType = 1;
    // 		stPCount.strNameEn = "Color Large Impressions";
    // 		stPCount.strNameCn = QStringLiteral("A3彩色印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}
    // 	if (item.strValue.trimmed() == "Black Large Impressions")
    // 	{
    // 		QList<MibValue> listValue;
    // 		QString strQueryColorOID;
    // 		QString temp;
    // 		temp = item.strOID;
    // 		strQueryColorOID = temp.replace(strQueryCountTypeOID, strQueryCountValueOID);
    // 		nResult = queryMibDataV2(strIPAddress, QueryMethod::get, strQueryColorOID, strRet, listValue);
    // 		PrinterPCount stPCount;
    // 		stPCount.nColorType = 0;
    // 		stPCount.nPaperType = 1;
    // 		stPCount.strNameEn = "Black Large Impressions";
    // 		stPCount.strNameCn = QStringLiteral("A3黑白印量");
    // 		stPCount.nPCount = listValue.at(0).strValue.toInt();
    // 		info.listPCountDetail.push_back(stPCount);
    // 	}


    //查询墨盒 废粉盒
    QString strSupplyTypeOID = "1.3.6.1.2.1.43.11.1.1.5";
    QString strSupplyDiscripeOID = "1.3.6.1.2.1.43.11.1.1.6";
    QString strSupplyCurrentOID = "1.3.6.1.2.1.43.11.1.1.9";
    QString strSupplyMaxLifeOID = "1.3.6.1.2.1.43.11.1.1.8";
    QString strSupplySeriOID = "1.3.6.1.4.1.641.6.4.4.1.1.6";
    QString strSupplyModelOID = "1.3.6.1.4.1.641.6.4.4.1.1.7";

    List_Value.clear();

    QList<MibValue> List_Supply;
    QString supplyTypeOID = strSupplyTypeOID;
    while (true)
    {
        MibValue mibvalue;
        nResult = queryMibDataV1(strIPAddress, QueryMethod::getNext, supplyTypeOID, strRet, List_Value);
        if (List_Value.at(0).strOID.contains(strSupplyTypeOID)) {
            supplyTypeOID = List_Value.at(0).strOID;
            mibvalue.strOID = List_Value.at(0).strOID;
            mibvalue.strValue = List_Value.at(0).strValue;
            List_Supply.push_back(mibvalue);
            List_Value.clear();
            continue;
        }
        else
        {
            break;
        }
    }
    for (auto item : List_Supply)
    {
        if (item.strValue.toInt() == 3)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString strTonerDesc = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";

            if (strTonerDesc == "Toner (Black)")
            {
                PrinterToner stBlackToner;
                stBlackToner.nColorType = 1;
                stBlackToner.nTonerID = 0;
                stBlackToner.TonerModel = strSupplyModel;
                stBlackToner.strTonerSN = strSupplySeri;
                stBlackToner.strTonerName = QStringLiteral("K|黑色");
                stBlackToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stBlackToner);
            }

            if (strTonerDesc == "Toner (Cyan)")
            {
                //查询青红粉盒
                PrinterToner stCToner;
                stCToner.nColorType = 2;
                stCToner.nTonerID = 1;
                stCToner.TonerModel = strSupplyModel;
                stCToner.strTonerSN = strSupplySeri;
                stCToner.strTonerName = QStringLiteral("C|青色墨粉");
                stCToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stCToner);
            }

            if (strTonerDesc == "Toner (Magenta)")
            {
                PrinterToner stMToner;
                stMToner.nColorType = 3;
                stMToner.nTonerID = 2;
                stMToner.TonerModel = strSupplyModel;
                stMToner.strTonerSN = strSupplySeri;
                stMToner.strTonerName = QStringLiteral("M|品红色墨粉");
                stMToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stMToner);
            }

            if (strTonerDesc == "Toner (Yellow)")
            {
                PrinterToner stYToner;
                stYToner.nColorType = 4;
                stYToner.nTonerID = 3;
                stYToner.TonerModel = strSupplyModel;
                stYToner.strTonerSN = strSupplySeri;
                stYToner.strTonerName = QStringLiteral("Y|黄色墨粉");
                stYToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listTonerDetail.push_back(stYToner);
            }
        }
        if (item.strValue.toInt() == 4)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);

            PrinterWasteToner stWasteToner;
            stWasteToner.nWasteTonerID = 0;
            stWasteToner.strWasteTonerModel = strSupplyModel;
            stWasteToner.strWasteTonerSN = strSupplySeri;
            stWasteToner.strWasteTonerName = QStringLiteral("WasteToner|废粉盒");
            stWasteToner.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
            info.listWasteTonerDetail.push_back(stWasteToner);

        }
        if (item.strValue.toInt() == 9)
        {
            QList<MibValue> listValue;
            QString QueryMaxOID;
            QString QueryCurrentOID;
            QString QueryDiscriptOID;
            QString QuerySeriOID;
            QString QueryModelOID;
            QString TempOID = item.strOID;
            QueryMaxOID = TempOID.replace(strSupplyTypeOID, strSupplyMaxLifeOID);
            TempOID = item.strOID;
            QueryCurrentOID = TempOID.replace(strSupplyTypeOID, strSupplyCurrentOID);
            TempOID = item.strOID;
            QueryDiscriptOID = TempOID.replace(strSupplyTypeOID, strSupplyDiscripeOID);
            TempOID = item.strOID;
            QuerySeriOID = TempOID.replace(strSupplyTypeOID, strSupplySeriOID);
            TempOID = item.strOID;
            QueryModelOID = TempOID.replace(strSupplyTypeOID, strSupplyModelOID);
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryMaxOID, strRet, listValue);
            int nMaxValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 100;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryCurrentOID, strRet, listValue);
            int nRestValue = listValue.size() > 0 ? listValue.at(0).strValue.toInt() : 0;
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QuerySeriOID, strRet, listValue);
            QString strSupplySeri = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryModelOID, strRet, listValue);
            QString strSupplyModel = listValue.size() > 0 ? listValue.value(0).strValue : "";
            listValue.clear();
            nResult = queryMibDataV1(strIPAddress, QueryMethod::get, QueryDiscriptOID, strRet, listValue);
            QString strDrumDesc = listValue.size() > 0 ? listValue.at(0).strValue.trimmed() : "";

            if (strDrumDesc == "Drum Cartridge (Black)")
            {
                PrinterDrum stBlackDrum;
                stBlackDrum.nColorType = 1;
                stBlackDrum.nDrumID = 0;
                stBlackDrum.DrumModel = strSupplyModel;
                stBlackDrum.DrumSN = strSupplySeri;
                stBlackDrum.strDrumName = QStringLiteral("K|黑色");
                stBlackDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stBlackDrum);
            }

            if (strDrumDesc == "Drum Cartridge (Cyan)")
            {
                PrinterDrum stCyanDrum;
                stCyanDrum.nColorType = 2;
                stCyanDrum.nDrumID = 1;
                stCyanDrum.DrumModel = strSupplyModel;
                stCyanDrum.DrumSN = strSupplySeri;
                stCyanDrum.strDrumName = QStringLiteral("C|青色");
                stCyanDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stCyanDrum);
            }

            if (strDrumDesc == "Drum Cartridge (Yellow)")
            {
                PrinterDrum styellowDrum;
                styellowDrum.nColorType = 4;
                styellowDrum.nDrumID = 3;
                styellowDrum.DrumModel = strSupplyModel;
                styellowDrum.DrumSN = strSupplySeri;
                styellowDrum.strDrumName = QStringLiteral("Y|黄色");
                styellowDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(styellowDrum);
            }
            if (strDrumDesc == "Drum Cartridge (Magenta)")
            {
                PrinterDrum stMagentaDrum;
                stMagentaDrum.nColorType = 3;
                stMagentaDrum.nDrumID = 2;
                stMagentaDrum.DrumModel = strSupplyModel;
                stMagentaDrum.DrumSN = strSupplySeri;
                stMagentaDrum.strDrumName = QStringLiteral("M|品红色");
                stMagentaDrum.nCurrent = (int)(double)nRestValue / (double)nMaxValue * 100;
                info.listDrumDetail.push_back(stMagentaDrum);
            }

        }
    }
    info.nResult = 0;
    return info;
}

QueryResult QueryPrinterDetailInfo::queryMibDataV1(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value)
{
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
    snmp_version version = version1;          // default is v1
    int retries = 1;                          // default retries is 1
    int timeout = 300;                        // default is 1 second (100unit)
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
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strValue = QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strOID = QString::fromLocal8Bit(vb.get_printable_oid());
                List_Value.push_back(mibvalue);
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

//void QueryPrinterDetailInfo::loadSnmpv3Status(bool status)
//{
//    m_bSnmpv3 = status;
//}

void QueryPrinterDetailInfo::loadV3Config(bool bSnmpStatus, SnmpArg params)
{
    m_bSnmpv3 = bSnmpStatus;

    m_nAuthProtocol = params.nAuthProtocol;
    m_nPrivProtocol = params.nPrivProtocol;
    m_nSecuLevel = params.nSecuLevel;
    m_strAuthPwd = QString::fromStdString(params.strAuthPwd);
    m_strPrivPwd = QString::fromStdString(params.strPrivPwd);
    m_strContextName = QString::fromStdString(params.strContextName);
    m_strContextEngineID = QString::fromStdString(params.strContextEngineID);
    m_strSecuName = QString::fromStdString(params.strSecuName);
    m_strCommunityName = QString::fromStdString(params.strCommunityName);


    /*QString appPath = QCoreApplication::applicationDirPath();

    QSettings iniFile(appPath + "/V3config.ini", QSettings::IniFormat);
    iniFile.setIniCodec("UTF-8");
    iniFile.beginGroup("SNMPV3");
    m_nAuthProtocol = iniFile.value("authProtocol").toInt();
    m_nPrivProtocol = iniFile.value("privProtocol").toInt();
    m_nSecuLevel = iniFile.value("secuityLevel").toInt();
    m_strAuthPwd = iniFile.value("authPassword").toString();
    m_strPrivPwd = iniFile.value("privatePassword").toString();
    m_strContextName = iniFile.value("contextName").toString();
    m_strContextEngineID = iniFile.value("contextEngineId").toString();
    iniFile.endGroup();*/
}


QueryResult QueryPrinterDetailInfo::queryMibDataV3(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value)
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
    snmp_version version = version3;          // default is v3
    int retries = 1;                          // default retries is 1
    int timeout = 300;                        // default is 1 second (100unit)
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
    Snmp snmp(status, 0, (address.get_ip_version() == Address::version_ipv6));
    if (status != SNMP_CLASS_SUCCESS)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;//snmp初始化失败
    }

    //---------[ init SnmpV3 ]--------------------------------------------
    //QString strEngineId;

    /*char strEngineId[256];
    if (eMethod == QueryMethod::get)
    {
        strcpy(strEngineId, "snmpGet");
    }
    else if (eMethod == QueryMethod::getNext)
    {
        strcpy(strEngineId, "snmpNext");
    }
    else if (eMethod == QueryMethod::getBulk)
    {
        strcpy(strEngineId, "snmpBulk");
    }
    const char* strFileName = "snmpv3_boot_counter";
    unsigned int snmpEngineBoots = 0;

    status = getBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
    if ((status != SNMPv3_OK) && (status < SNMPv3_FILEOPEN_ERROR))
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;
    }
    snmpEngineBoots++;
    status = saveBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
    if (status != SNMPv3_OK)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;
    }

    int construct_status;
    v3_MP = new v3MP((const char*)strEngineId, snmpEngineBoots, construct_status);
    if (construct_status != SNMPv3_MP_OK)
    {
        delete v3_MP;
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;
    }

    USM *usm = v3_MP->get_usm();*/
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
    pdu.set_context_name(contextName);
    pdu.set_context_engine_id(contextEngineID);

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
                mibvalue.strValue = QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strOID = QString::fromLocal8Bit(vb.get_printable_oid());
                List_Value.push_back(mibvalue);
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

QueryResult QueryPrinterDetailInfo::queryMibDataV2(QString strIPAdress, QueryMethod eMethod, QString OID, QString& strRet, QList<MibValue>& List_Value)
{
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
    snmp_version version = version2c;          // default is v2c
    int retries = 1;                          // default retries is 1
    int timeout = 300;                        // default is 1 second (100unit)
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
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strValue = QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strOID = QString::fromLocal8Bit(vb.get_printable_oid());
                List_Value.push_back(mibvalue);
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

QueryResult QueryPrinterDetailInfo::WalkMib(QString strIPAdress, QString OID, QList<MibValue>& List_Value)
{
    Pdu pdu;
    Vb vb;
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
    snmp_version version;
    if (m_bSnmpv3)
    {
        version = version3;          // default is v1
    }
    else
    {
        version = version1;          // default is v1
    }

    int retries = 1;                          // default retries is 1
    int timeout = 300;                        // default is 1 second (100unit)
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
    if (status != SNMP_CLASS_SUCCESS)
    {
        Snmp::socket_cleanup();
        return QueryResult::initSnmpFailed;//snmp初始化失败
    }
    //--------[ build up SNMP++ object needed ]-------------------------------

    SnmpTarget* target;
  //  CTarget ctarget;             // make a target using the address v1/v2
    address.set_port(port);// make a target using the address
    UTarget utarget;            //snmpv3
    CTarget ctarget(address);

    if (m_bSnmpv3)
    {
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

        //---------[ init SnmpV3 ]--------------------------------------------
        //QString strEngineId;

        /*char strEngineId[256];

        strcpy(strEngineId, "snmpGet");

        const char* strFileName = "snmpv3_boot_counter";
        unsigned int snmpEngineBoots = 0;

        status = getBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
        if ((status != SNMPv3_OK) && (status < SNMPv3_FILEOPEN_ERROR))
        {
            Snmp::socket_cleanup();
            return QueryResult::initSnmpFailed;
        }
        snmpEngineBoots++;
        status = saveBootCounter(strFileName, (const char*)strEngineId, snmpEngineBoots);
        if (status != SNMPv3_OK)
        {
            Snmp::socket_cleanup();
            return QueryResult::initSnmpFailed;
        }

        int construct_status;
        v3_MP = new v3MP((const char*)strEngineId, snmpEngineBoots, construct_status);
        if (construct_status != SNMPv3_MP_OK)
        {
            delete v3_MP;
            Snmp::socket_cleanup();
            return QueryResult::initSnmpFailed;
        }

        USM *usm = v3_MP->get_usm();*/
        USM *usm = SNMPSession::v3_MP->get_usm();
        usm->add_usm_user(securityName,
                          authProtocol, privProtocol,
                          authPassword, privPassword);

        utarget.set_version(version);          // set the SNMP version SNMPV1 or V2 or V3
        utarget.set_retry(retries);            // set the number of auto retries
        utarget.set_timeout(timeout);          // set timeout
        utarget.set_security_model(securityModel);
        utarget.set_security_name(securityName);
        pdu.set_security_level(securityLevel);
        pdu.set_context_name(contextName);
        pdu.set_context_engine_id(contextEngineID);
        target = &utarget;
    }
    else {
        //        CTarget ctarget;             // make a target using the address
        ctarget.set_version(version);         // set the SNMP version SNMPV1 or V2
        ctarget.set_retry(retries);           // set the number of auto retries
        ctarget.set_timeout(timeout);         // set timeout
        ctarget.set_readcommunity(community); // set the read community name
        target = &ctarget;
    }

    //address.set_port(port);
    //CTarget ctarget(address);             // make a target using the address
    //ctarget.set_version(version);         // set the SNMP version SNMPV1 or V2
    //ctarget.set_retry(retries);           // set the number of auto retries
    //ctarget.set_timeout(timeout);         // set timeout
    //ctarget.set_readcommunity(community); // set the read community name
    //-------[ issue the request, blocked mode ]-----------------------------
    int oidindex = 1;
    while (oidindex <= 25)
    {

        QString  queryOID = OID + (".1.%1");
        queryOID = queryOID.arg(oidindex);
        qDebug() << queryOID;
        qDebug() << OID;

        Oid oid(queryOID.toLatin1().constData());
        vb.set_oid(oid);
        pdu += vb;
        SnmpTarget* target;
        target = &ctarget;
        status = snmp.get(pdu, *target);
        if (SNMP_CLASS_TIMEOUT == status || SNMP_CLASS_TL_ACCESS_DENIED == status)
        {
            Snmp::socket_cleanup();
            return QueryResult::snmpOverTime;//超时
        }

        if (SNMP_CLASS_SUCCESS == status)
        {
            MibValue mibvalue;
            pdu.get_vb(vb, 0);
            if (vb.get_exception_status() != 0)
            {
                break;
            }
            m_ret += ("Oid = ");
            m_ret += QString::fromLocal8Bit(vb.get_printable_oid());
            m_ret += ("\r\n");
            if (vb.get_syntax() != sNMP_SYNTAX_ENDOFMIBVIEW)
            {
                m_ret += ("Value = ");
                m_ret += QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strValue = QString::fromLocal8Bit(vb.get_printable_value());
                mibvalue.strOID = QString::fromLocal8Bit(vb.get_printable_oid());
                if (mibvalue.strValue.length() != 0)
                {
                    List_Value.push_back(mibvalue);
                }
            }
            else
            {
                m_ret += ("End of MIB view.\r\n");
                break;
            }
            QThread::usleep(10);
        }
        oidindex++;
    }

    Snmp::socket_cleanup();
    return QueryResult::Successed;
}

