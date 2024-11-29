#include "SDKExample.h"
#include "jsonhelper.h"

SDKExample::SDKExample(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::SDKExampleClass)
{
    ui->setupUi(this);

    m_dConfig = Q_NULLPTR;
	nPType = 0;

    connectMessage();
    initDialog();
}

SDKExample::~SDKExample()
{
    delete ui;
}

void SDKExample::connectMessage()
{
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(OnBaseInfo()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(OnDetailInfo()));
    connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(OnSDKVersion()));
    connect(ui->pushButton_4, SIGNAL(clicked()), SLOT(OnSupportList()));
    connect(ui->radioButton_v1v2, &QRadioButton::clicked, this, &SDKExample::OnClickedV1V2);
    connect(ui->radioButton_v3, &QRadioButton::clicked, this, &SDKExample::OnClickedV3);
    connect(ui->pushButton_v3config, &QPushButton::clicked, this, &SDKExample::OnClickedConfig);
}

void SDKExample::loadV3Config()
{
    QString appPath = QCoreApplication::applicationDirPath();

    QSettings iniFile(appPath + "/V3config.ini", QSettings::IniFormat);
    iniFile.setIniCodec("UTF-8");
    iniFile.beginGroup("SNMPV3");
    m_sSnmpArg.nAuthProtocol = iniFile.value("authProtocol").toLongLong();
    m_sSnmpArg.nPrivProtocol = iniFile.value("privProtocol").toLongLong();
    m_sSnmpArg.nSecuLevel = iniFile.value("securityLevel").toInt();
    m_sSnmpArg.strAuthPwd = iniFile.value("authPassword").toString().toStdString();
    m_sSnmpArg.strPrivPwd = iniFile.value("privPassword").toString().toStdString();
    m_sSnmpArg.strContextName = iniFile.value("contextName").toString().toStdString();
    m_sSnmpArg.strContextEngineID = iniFile.value("contextEngineId").toString().toStdString();
    m_sSnmpArg.strSecuName = iniFile.value("securityName").toString().toStdString();
    m_sSnmpArg.strCommunityName = iniFile.value("communityName").toString().toStdString();
    iniFile.endGroup();
}

void SDKExample::OnClickedConfig()
{
    m_dConfig = new configDialog(this);
    m_dConfig->exec();
}

void SDKExample::OnClickedV3()
{
    ui->pushButton_v3config->setEnabled(true);
//    sdk.mps_api_snmpv3Status(true);
    m_bSnmpV3 = true;
}

void SDKExample::OnClickedV1V2()
{
    ui->pushButton_v3config->setEnabled(false);
//    sdk.mps_api_snmpv3Status(false);
    m_bSnmpV3 = false;
}

void SDKExample::initDialog()
{
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    ui->radioButton_v1v2->click();
    if(ui->radioButton_v1v2->isDown())
    {
        ui->pushButton_v3config->setEnabled(false);
    }
//    sdk.mps_api_snmpv3Status(false);
}


void SDKExample::OnBaseInfo()
{
    loadV3Config();
    QString strIP = ui->lineEdit->text().trimmed();
	if (strIP.contains("*"))
	{
		strIP = strIP.replace("*", "%1");
		char* p = new char[4096];
		QString IPSourceList;
		for (int i=1;i<255;i++)
		{
			IPSourceList.append(strIP.arg(i));
			IPSourceList.append(",");
		}
		IPSourceList.remove(IPSourceList.size() - 1, 1);
		QByteArray array = IPSourceList.toLatin1();
		p = array.data();
		int nlen = 4096;
		char* buff = new char[nlen];
        sdk.mps_api_seekPrinter(p,4096, buff, nlen, m_bSnmpV3, m_sSnmpArg);
		QString json = QString(buff);
		ui->textEdit->setText(json);
		delete[] buff;
	}
	else
	{
		int nLen = 1024;
		char* buffer = new char[nLen];
		memset(buffer, 0, 512);
        sdk.mps_api_getPrinterBaseInfo(strIP.toStdString().c_str(), buffer, nLen, 1, m_bSnmpV3, m_sSnmpArg);
		QString json = QString(buffer);
        ui->textEdit->setText(json);
		delete[] buffer;
	}	
}
void SDKExample::OnDetailInfo()
{
    loadV3Config();
    QString strIP = ui->lineEdit->text().trimmed();
	int nLen = 1024*16;
	char* buffer = new char[nLen];
	memset(buffer, 0, nLen);

    int nResult = sdk.mps_api_getPrinterDetailInfo(strIP.toStdString().c_str(), buffer, nLen,ui->radioButton->isChecked()?0:1, "1234", m_bSnmpV3, m_sSnmpArg);
	if (nResult != 0)
	{
        switch (nResult) {
        case 10:
            QMessageBox::warning(this, QString::fromLocal8Bit("´íÎó"), QString::fromLocal8Bit("printer.ini´ò¿ªÊ§°Ü£¡"));
        }
	}	
	QString json = QString(buffer);
    ui->textEdit->setText(json);

	JsonHelper jh;
	jh.syscPrinterDetailInfo(json);
	delete[] buffer;
}
void SDKExample::OnSDKVersion()
{
	int nLen = 1024;
	char* buffer = new char[nLen];
	memset(buffer, 0, nLen);
	int nResult = sdk.mps_api_getSDKVersion(buffer, nLen);
	if (nResult != 0)
	{
	}
	QString json = QString(buffer);
    ui->textEdit->setText(json);

	delete[] buffer;
}
void SDKExample::OnSupportList()
{
	int nLen = 1024;
	char* buffer = new char[nLen];
	memset(buffer, 0, nLen);
	int nResult = sdk.mps_api_getSupportPrinters(buffer, nLen);
	if (nResult !=0)
	{
	}
	QString json = QString(buffer);
    ui->textEdit->setText(json);
	delete[] buffer;
}