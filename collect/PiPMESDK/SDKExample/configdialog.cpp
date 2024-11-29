#include "configdialog.h"
#include "ui_configdialog.h"

configDialog::configDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configDialog)
{
    ui->setupUi(this);
    m_strAppPath = "";
    m_pSetting = Q_NULLPTR;

    loadV3Type();
    initDialog();
    connectMessage();
}

configDialog::~configDialog()
{
    delete ui;
}

void configDialog::connectMessage()
{
    connect(ui->comboBox_secuLevel, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
        [=](const QString &text){
        this->onSecuLevel(text);
    });
    connect(ui->pushButton_save, &QPushButton::clicked, this, &configDialog::onClickSave);
    connect(ui->pushButton_cancel, &QPushButton::clicked, this, &configDialog::onClickCancel);
}

void configDialog::onClickSave()
{
    if(!m_pSetting)
        this->accept();

    m_pSetting->beginGroup("SNMPV3");

    for (int i = 0; i < m_sSecuLevel.count(); i++) {
        if(ui->comboBox_secuLevel->currentText() == m_sSecuLevel.at(i).desc)
            m_pSetting->setValue("securityLevel", QString::number(m_sSecuLevel.at(i).index));
    }

    for (int i = 0; i < m_sAuthProtocol.count(); i++) {
        if(ui->comboBox_authProtocol->currentText() == m_sAuthProtocol.at(i).desc)
            m_pSetting->setValue("authProtocol", QString::number(m_sAuthProtocol.at(i).index));
    }

    for (int i = 0; i < m_sPrivProtocol.count(); i++) {
        if(ui->comboBox_privProtocol->currentText() == m_sPrivProtocol.at(i).desc)
            m_pSetting->setValue("privProtocol", QString::number(m_sPrivProtocol.at(i).index));
    }

    m_pSetting->setValue("privPassword", ui->lineEdit_privPwd->text());
    m_pSetting->setValue("authPassword", ui->lineEdit_authPwd->text());
    m_pSetting->setValue("securityName", ui->lineEdit_secuName->text());
    m_pSetting->setValue("contextName", ui->lineEdit_contextName->text());
    m_pSetting->setValue("contextEngineID", ui->lineEdit_contentEngineID->text());
    m_pSetting->setValue("communityName", ui->lineEdit_communityName->text());

    m_pSetting->endGroup();
    this->accept();
}

void configDialog::onClickCancel()
{
    this->accept();
}

void configDialog::onSecuLevel(QString strLevel)
{
    for (int i = 0; i < m_sSecuLevel.count(); i++) {
        if(strLevel == m_sSecuLevel.at(i).desc)
        {
            switch (m_sSecuLevel.at(i).index) {
            case 1:
                ui->comboBox_authProtocol->setEnabled(false);
                ui->comboBox_privProtocol->setEnabled(false);
                ui->lineEdit_authPwd->setEnabled(false);
                ui->lineEdit_privPwd->setEnabled(false);
                break;
            case 2:
                ui->comboBox_authProtocol->setEnabled(true);
                ui->comboBox_privProtocol->setEnabled(false);
                ui->lineEdit_authPwd->setEnabled(true);
                ui->lineEdit_privPwd->setEnabled(false);
                break;
            default:
                ui->comboBox_authProtocol->setEnabled(true);
                ui->comboBox_privProtocol->setEnabled(true);
                ui->lineEdit_authPwd->setEnabled(true);
                ui->lineEdit_privPwd->setEnabled(true);
            }
        }
    }
}

void configDialog::initDialog()
{
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    setWindowTitle(QString::fromLocal8Bit("SNMPv3配置"));

    m_strAppPath = QCoreApplication::applicationDirPath();

    m_pSetting = new QSettings(m_strAppPath + "/V3config.ini", QSettings::IniFormat, this);
    m_pSetting->setIniCodec("UTF-8");
    m_pSetting->beginGroup("SNMPV3");
    int a = m_pSetting->value("securityLevel").toInt();
    for (int i = 0; i < m_sSecuLevel.count(); i++) {
        ui->comboBox_secuLevel->addItem(m_sSecuLevel.at(i).desc);
        if(m_pSetting->value("securityLevel").toInt() == m_sSecuLevel.at(i).index)
        {
            ui->comboBox_secuLevel->setCurrentText(m_sSecuLevel.at(i).desc);
        }
    }
    for (int i = 0; i < m_sAuthProtocol.count(); i++) {
        ui->comboBox_authProtocol->addItem(m_sAuthProtocol.at(i).desc);
        if(m_pSetting->value("authProtocol").toInt() == m_sAuthProtocol.at(i).index)
            ui->comboBox_authProtocol->setCurrentText(m_sAuthProtocol.at(i).desc);
        }
    for (int i = 0; i < m_sPrivProtocol.count(); i++) {
        ui->comboBox_privProtocol->addItem(m_sPrivProtocol.at(i).desc);
        if(m_pSetting->value("privProtocol").toInt() == m_sPrivProtocol.at(i).index)
            ui->comboBox_privProtocol->setCurrentText(m_sPrivProtocol.at(i).desc);
    }

    ui->lineEdit_authPwd->setText(m_pSetting->value("authPassword").toString());
    ui->lineEdit_authPwd->setEchoMode(QLineEdit::Password);
	QFont authFont("", 8);
	ui->pushButton_authPassword->setFont(authFont);
	ui->pushButton_authPassword->setText(QString::fromLocal8Bit("显"));
	QObject::connect(ui->pushButton_authPassword, &QPushButton::clicked, [&]() {
		if (ui->lineEdit_authPwd->echoMode() == QLineEdit::Password) {
			ui->lineEdit_authPwd->setEchoMode(QLineEdit::Normal); // 显示明文
			ui->pushButton_authPassword->setText(QString::fromLocal8Bit("隐"));
		}
		else {
			ui->lineEdit_authPwd->setEchoMode(QLineEdit::Password); // 隐藏明文
			ui->pushButton_authPassword->setText(QString::fromLocal8Bit("显"));
		}
	});

	ui->lineEdit_privPwd->setText(m_pSetting->value("privPassword").toString());
	ui->lineEdit_privPwd->setEchoMode(QLineEdit::Password);
	QFont privFont("", 8);
	ui->pushButton_privPassword->setFont(authFont);
	ui->pushButton_privPassword->setText(QString::fromLocal8Bit("显"));
	QObject::connect(ui->pushButton_privPassword, &QPushButton::clicked, [&]() {
		if (ui->lineEdit_privPwd->echoMode() == QLineEdit::Password) {
			ui->lineEdit_privPwd->setEchoMode(QLineEdit::Normal); // 显示明文
			ui->pushButton_privPassword->setText(QString::fromLocal8Bit("隐"));
		}
		else {
			ui->lineEdit_privPwd->setEchoMode(QLineEdit::Password); // 隐藏明文
			ui->pushButton_privPassword->setText(QString::fromLocal8Bit("显"));
		}
	});

    ui->lineEdit_secuName->setText(m_pSetting->value("securityName").toString());

    ui->lineEdit_contextName->setText(m_pSetting->value("contextName").toString());

    ui->lineEdit_contentEngineID->setText(m_pSetting->value("contextEngineID").toString());

    ui->lineEdit_communityName->setText(m_pSetting->value("communityName").toString());

    m_pSetting->endGroup();

    onSecuLevel(ui->comboBox_secuLevel->currentText());
}

void configDialog::loadV3Type()
{
    m_sSecuLevel = {
        {"NOAUTH_NOPRIV", 1},
        {"AUTH_NOPRIV", 2},
        {"AUTH_PRIV", 3}
    };

    m_sAuthProtocol = {
        {"NONE", 1},
        {"HMACMD5", 2},
        {"HMACSHA", 3}/*,
        {"HMAC128SHA224", 4},
        {"HMAC192SHA256", 5},
        {"HMAC256SHA384", 6},
        {"HMAC384SHA512", 7}*/
    };

    m_sPrivProtocol = {
        {"NONE", 1},
        {"DES", 2},
        {"AES128", 4},
        {"IDEA", 9},
        {"AES192", 20},
        {"AES256", 21},
        {"3DESEDE", 3}/*,
        {"AES128W3DESKEYEXT", 22},
        {"AES192W3DESKEYEXT", 23},
        {"AES256W3DESKEYEXT", 24}*/
    };

}
