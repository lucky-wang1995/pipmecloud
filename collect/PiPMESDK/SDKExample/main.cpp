#include "SDKExample.h"
#include <QtWidgets/QApplication>
#include "../PiPMESDK/pipmesdk.h"
//#pragma comment(lib,"../Release/PiPMESDK.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDKExample w;
    w.show();

    return a.exec();
}
