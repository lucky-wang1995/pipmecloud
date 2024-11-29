#pragma once

#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include "ui_SDKExample.h"
#include "../PiPMESDK/pipmesdk.h"
#include "configdialog.h"
#include "writelog.h"

class SDKExample : public QMainWindow
{
    Q_OBJECT

public:
    SDKExample(QWidget *parent = Q_NULLPTR);
    ~SDKExample();

	SNMPARG m_sSnmpArg;

private:
    Ui::SDKExampleClass *ui;

    PiPMESDK sdk;

    int nPType;

    std::list<std::string> IPCheckedList;

protected:
	void initDialog();
    void connectMessage();
    void loadV3Config();

protected slots:

    void OnBaseInfo();
    void OnDetailInfo();
    void OnSDKVersion();
    void OnSupportList();
    void OnClickedV1V2();
    void OnClickedV3();
    void OnClickedConfig();

private:
    configDialog *m_dConfig;
    bool m_bSnmpV3;
    
};
