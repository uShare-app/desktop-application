#ifndef SCREENCAPTURER_H
#define SCREENCAPTURER_H

# include <QDebug>

# include <QDate>
# include <QGuiApplication>
# include <QObject>
# include <QPixmap>
# include <QScreen>
# include <QString>
# include <QTemporaryDir>
# include <QTime>

# include "areaselecter.h"

class ScreenCapturer : public QObject
{
    Q_OBJECT
public:
    ScreenCapturer(QObject * parent = 0);

public slots:
    QString captureScreen();
    void captureArea();

signals:
    void done(QString);
    void canceled();

private:
    QString getNewFileName();

    QTemporaryDir dir;
};

#endif // SCREENCAPTURER_H
