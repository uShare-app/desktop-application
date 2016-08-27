#ifndef APPWINDOW_H
#define APPWINDOW_H

# include <QObject>
# include <QQmlApplicationEngine>
# include <QQmlComponent>
# include <QQmlContext>
# include <QQmlEngine>

# include "qml/qmlsettings.h"

class AppWindow : public QObject
{
    Q_OBJECT
public:
    explicit AppWindow(QObject *parent = 0);

signals:

public slots:
    void show();
    void hide();

private:
    QQmlEngine engine;
    QQmlComponent * component;
    QQmlContext * context;
    QObject * window;
};

#endif // APPWINDOW_H
