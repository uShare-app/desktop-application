#ifndef SYSTEMTRAYACTIONS_H
#define SYSTEMTRAYACTIONS_H

# include <QDebug>

# include <QFileDialog>
# include <QObject>
# include <QPixmap>
# include <QString>

# include "network/httpfileuploader.h"
# include "screencapturer.h"

class SystemTrayActions : public QObject
{
    Q_OBJECT
public:
    explicit SystemTrayActions(QObject *parent = 0);

private:
    ScreenCapturer capturer;

public slots:
    void captureScreen();
    void captureArea();
    void sendFile();
};

#endif // SYSTEMTRAYACTIONS_H
