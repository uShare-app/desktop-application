#include "screencapturer.h"

QString ScreenCapturer::captureScreen()
{
    QScreen * screen;
    static QTemporaryDir dir;
    QPixmap screenshot;
    QString path;

    screen = QGuiApplication::primaryScreen();

    if (!screen || !dir.isValid())
        return (QString::null);

    path = dir.path() + "/" + getNewFileName();
    screenshot = screen->grabWindow(0);
    screenshot.save(path, 0, 0);
    return (path);
}

QString ScreenCapturer::getNewFileName()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();

    QString fileName = QString::number(date.dayOfYear())
                       + QString::number(time.hour())
                       + QString::number(time.minute())
                       + QString::number(time.second());

    return fileName + ".png";
}
