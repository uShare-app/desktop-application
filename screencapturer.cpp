#include "screencapturer.h"

ScreenCapturer::ScreenCapturer(QObject * parent): QObject(parent)
{

}

QString ScreenCapturer::captureScreen()
{
    QScreen * screen;
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

void ScreenCapturer::captureArea()
{
    QScreen * screen;
    QPixmap screenshot;
    QString path;
    AreaSelecter * selecter;

    screen = QGuiApplication::primaryScreen();

    if (!screen || !dir.isValid())
        return;

    path = dir.path() + "/" + getNewFileName();
    screenshot = screen->grabWindow(0);

    selecter = new AreaSelecter;
    selecter->setPixmap(screenshot);
    selecter->selectArea();

    QObject::connect(selecter, &AreaSelecter::areaTaken, [=](QRect area)
    {
        screenshot.copy(area).save(path, 0, 0);
        emit done(path);
        selecter->deleteLater();
    });
}

QString ScreenCapturer::getNewFileName()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();

    QString fileName = QString::number(date.day())
                       + QString::number(date.month())
                       + QString::number(time.hour())
                       + QString::number(time.minute())
                       + QString::number(time.second());

    return fileName + ".png";
}
