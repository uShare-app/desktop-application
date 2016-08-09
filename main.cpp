#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "systemtrayicon.h"
#include <QMenu>
#include <iostream>

#include "network/httpfileuploader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    SystemTrayIcon icon;
    icon.show();

    HttpFileUploader http;
    http.setHost("https://uplmg.com", 80);
    http.setFile("/home/mhammerc/Dev/cmdUplmg/README.md");
    http.setSenderId("Uplimg Desktop 1.0.0 Nightly");

    QObject::connect(&http, &HttpFileUploader::finished, [&http]()
    {
        std::cout << http.getResponse().toStdString() << std::endl; //Will show the access link
    });

    QObject::connect(&http, &HttpFileUploader::uploadProgress, [](qint64 bytesSent, qint64 bytesTotal)
    {
        if(bytesTotal == 0) return; //If the bytesTotal is 0, there is a problem and it is no possible. So we avoid the showing of false informations.
        std::cout << bytesSent << " bytes sent, for a total of " << bytesTotal << " bytes. "
                  << (float)bytesSent/(float)bytesTotal*100.0 << "%"
                  << std::endl;
    });

    http.sendFile();

    return app.exec();
}
