#include "USBHelper.h"
#include "QUdpSocket"
#include "QThread"

USBHelper::USBHelper()
{

}
USBHelper::~USBHelper()
{

}

QueryResult USBHelper::getUSBPrinterInfo(QString strIPAdress, QByteArray& info)
{
	QUdpSocket usbSocket;
	QString Order = "pipme";
	QByteArray data = Order.toLatin1();
	while (true)
	{
		qint64 nbytes = usbSocket.writeDatagram(data, QHostAddress(strIPAdress), 50723);
		usbSocket.waitForBytesWritten(-1);

		if (usbSocket.hasPendingDatagrams())
		{
			info.resize(usbSocket.pendingDatagramSize());
			usbSocket.readDatagram(info.data(), info.size());
		}
		
		if (QString::fromLatin1(info) == "end")
		{
			break;
		}
		QThread::msleep(200);

	}	
	return QueryResult::Successed;
}