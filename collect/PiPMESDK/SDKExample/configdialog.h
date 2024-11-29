#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QList>
#include <QSettings>
#include <QCoreApplication>


struct v3type
{
    QString desc;
    int index;
};

namespace Ui {
class configDialog;
}

class configDialog : public QDialog
{
    Q_OBJECT

public:
    explicit configDialog(QWidget *parent = nullptr);
    ~configDialog();

protected:
    void loadV3Type();
    void initDialog();
    void connectMessage();

protected slots:
    void onSecuLevel(QString strLevel);
    void onClickSave();
    void onClickCancel();

private:
    Ui::configDialog *ui;

    QList<v3type> m_sSecuLevel;
    QList<v3type> m_sAuthProtocol;
    QList<v3type> m_sPrivProtocol;

    QString m_strAppPath;
    QSettings *m_pSetting;
};

#endif // CONFIGDIALOG_H
