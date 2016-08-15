#ifndef SCREENCAPTURER_H
#define SCREENCAPTURER_H

# include <QGuiApplication>
# include <QObject>
# include <QPixmap>
# include <QScreen>
# include <QString>

class ScreenCapturer : public QObject
{
    Q_OBJECT
public:
    ScreenCapturer() = delete;

public slots:
    static QString captureScreen();
};

#endif // SCREENCAPTURER_H
