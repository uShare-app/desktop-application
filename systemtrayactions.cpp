#include "systemtrayactions.h"

SystemTrayActions::SystemTrayActions(QObject *parent) : QObject(parent)
{

}

void SystemTrayActions::captureScreen()
{
    QString image;
    HttpFileUploader * http;

    http = new HttpFileUploader;
    image = ScreenCapturer::captureScreen();

    http->setHost("https://uplmg.com/file/upload", 443);
    http->setFile(image);
    http->setSenderId("Uplimg Nightly");

    QObject::connect(http, &HttpFileUploader::uploadProgress, [=](qint64 bytesSent, qint64 bytesTotal)
    {
        qDebug() << bytesSent << "/" << bytesTotal;
    });

    QObject::connect(http, &HttpFileUploader::finished, [=](HttpFileUploader * sender)
    {
        qDebug() << sender->getResponse();
        sender->deleteLater();
    });

    http->sendFile();
}
