#ifndef SYSTEMTRAYACTIONS_H
#define SYSTEMTRAYACTIONS_H

# include <QDebug>

# include <QObject>
# include <QPixmap>

# include "network/httpfileuploader.h"
# include "screencapturer.h"

class SystemTrayActions : public QObject
{
    Q_OBJECT
public:
    explicit SystemTrayActions(QObject *parent = 0);

signals:

public slots:
    void captureScreen();
};

#endif // SYSTEMTRAYACTIONS_H
