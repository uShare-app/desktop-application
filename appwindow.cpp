#include "appwindow.h"

AppWindow::AppWindow(QObject *parent) : QObject(parent)
{
    engine.load(QUrl(QLatin1String("qrc:/window/main.qml")));
    root = engine.rootObjects().first();
}

void AppWindow::show()
{
    root->setProperty("visible", true);
}

void AppWindow::hide()
{
    root->setProperty("visible", false);
}
