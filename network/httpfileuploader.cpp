#include "httpfileuploader.h"

HttpFileUploader::HttpFileUploader()
{
    status = Status::WAITING;
}

void HttpFileUploader::run()
{
    static bool started = false;

    if (started)
        return;
    if (status != Status::UPLOADING)
        return;
    started = true;
    this->exec();
}

void HttpFileUploader::setHost(const QString &host, int port)
{
    url.setUrl(host);
    url.setPort(port);
}

bool HttpFileUploader::setFile(const QString &pathToFile)
{
    file.setFileName(pathToFile);
    return (file.exists());
}

void HttpFileUploader::setSenderId(const QString &senderId)
{
    this->senderId = senderId;
}

QString HttpFileUploader::getResponse()
{
    return QString(reply->readAll());
}

void HttpFileUploader::sendFile()
{
    if (!file.open(QIODevice::ReadOnly))
    {
        status = Status::FILE_ERROR;
        emit statusChanged(status);
        return;
    }

    QSslConfiguration sslConfig;
    sslConfig.setProtocol(QSsl::SecureProtocols);

    QHttpPart filePart;
    QVariant fileHeader("form-data; name=\"file\"; filename=\""
                        + file.fileName() + "\"");
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader, fileHeader);
    filePart.setBodyDevice(&file);

    QHttpPart senderIdPart;
    senderIdPart.setHeader(QNetworkRequest::ContentDispositionHeader,
                           QVariant("form-data; name=\"senderid\""));
    senderIdPart.setBody(senderId.toLocal8Bit());

    container = new QHttpMultiPart(QHttpMultiPart::FormDataType, this);
    container->append(filePart);
    container->append(senderIdPart);

    QNetworkRequest request;
    request.setUrl(url);
    request.setSslConfiguration(sslConfig);
    manager = new QNetworkAccessManager(this);
    reply = manager->post(request, container);

    QObject::connect(reply, &QNetworkReply::finished, this,
                     &HttpFileUploader::finished);
    QObject::connect(reply, &QNetworkReply::uploadProgress, this,
                     &HttpFileUploader::uploadProgress);
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this,
                     SIGNAL(error(QNetworkReply::NetworkError)));

    status = Status::UPLOADING;
    emit statusChanged(status);
    this->run();
}

