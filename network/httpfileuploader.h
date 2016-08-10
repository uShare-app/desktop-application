#ifndef HTTPFILEUPLOADER_H
#define HTTPFILEUPLOADER_H

#include <QFile>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QThread>
#include <QUrl>
#include <QObject>
#include <QSslConfiguration>

/* This class upload file to the server.
 * It follow the Uplimg API. See https://doc.uplmg.com
 */
class HttpFileUploader : public QThread
{
    Q_OBJECT
public:
    HttpFileUploader();

    enum Status
    {
        WAITING,
        UPLOADING,
        FILE_ERROR
    };
    Status status;

    void sendFile();

public slots:
    void setHost(QString const &host, int port);
    bool setFile(QString const &pathToFile);
    void setSenderId(QString const &senderId);
    QString getResponse();

signals:
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
    void finished();
    void error(QNetworkReply::NetworkError);
    void statusChanged(Status);

private:
    void run() Q_DECL_OVERRIDE;

    QUrl url;
    QFile file;
    QString senderId;
    QNetworkReply * reply;
    QNetworkAccessManager * manager;
    QHttpMultiPart * container;
};

#endif // HTTPFILEUPLOADER_H
