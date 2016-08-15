#ifndef SCREENCAPTURER_H
#define SCREENCAPTURER_H

# include <QDate>
# include <QGuiApplication>
# include <QObject>
# include <QPixmap>
# include <QScreen>
# include <QString>
# include <QTemporaryDir>
# include <QTime>

class ScreenCapturer : public QObject
{
    Q_OBJECT
public:
    ScreenCapturer() = delete;

public slots:
    static QString captureScreen();

private:
    static QString getNewFileName();
};

#endif // SCREENCAPTURER_H
