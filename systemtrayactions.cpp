#include "systemtrayactions.h"

SystemTrayActions::SystemTrayActions(QObject *parent) : QObject(parent)
{
    window = nullptr;
}

/* Todo move sending code to another file */
void SystemTrayActions::captureScreen()
{
    QString image;
    HttpFileUploader * http;

    http = new HttpFileUploader;
    image = capturer.captureScreen();

    http->setHost("https://uplmg.com/file/upload", 443);
    http->setFile(image);
    http->setSenderId("Uplimg Nightly");

    QObject::connect(http, &HttpFileUploader::uploadProgress, [](qint64 bytesSent, qint64 bytesTotal)
    {
        qDebug() << bytesSent << "/" << bytesTotal;
    });

    QObject::connect(http, &HttpFileUploader::finished, [](HttpFileUploader * sender)
    {
        qDebug() << sender->getResponse();
        sender->deleteLater();
    });

    http->sendFile();
}


void SystemTrayActions::captureArea()
{
    QObject::connect(&capturer, &ScreenCapturer::done, [] (QString path)
    {
        HttpFileUploader * http;

        http = new HttpFileUploader;
        http->setHost("https://uplmg.com/file/upload", 443);
        http->setFile(path);
        http->setSenderId("Uplimg Nightly");

        QObject::connect(http, &HttpFileUploader::uploadProgress, [] (qint64 bytesSent, qint64 bytesTotal)
        {
            qDebug() << bytesSent << "/" << bytesTotal;
        });

        QObject::connect(http, &HttpFileUploader::finished, [] (HttpFileUploader * sender)
        {
            qDebug() << sender->getResponse();
            sender->deleteLater();
        });

        http->sendFile();
    });

    capturer.captureArea();
}

void SystemTrayActions::sendFile()
{
    QString path;
    HttpFileUploader * http;

    http = new HttpFileUploader;
    path = QFileDialog::getOpenFileName(Q_NULLPTR, "Choose file");

    http->setHost("https://uplmg.com/file/upload", 443);
    http->setFile(path);
    http->setSenderId("Uplimg Nightly");

    QObject::connect(http, &HttpFileUploader::uploadProgress, [](qint64 bytesSent, qint64 bytesTotal)
    {
        qDebug() << bytesSent << "/" << bytesTotal;
    });

    QObject::connect(http, &HttpFileUploader::finished, [](HttpFileUploader * sender)
    {
        qDebug() << sender->getResponse();
        sender->deleteLater();
    });

    http->sendFile();
}

void SystemTrayActions::openWindow()
{
    if (!window)
    {
        window = new AppWindow(this);
        return;
    }

    window->show();
}
