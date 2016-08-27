#include "appwindow.h"

AppWindow::AppWindow(QObject *parent) : QObject(parent)
{
    component = new QQmlComponent(&engine, QUrl(QLatin1String("qrc:/window/main.qml")));
    context = new QQmlContext(&engine);

    QmlSettings * settings = new QmlSettings(this);
    context->setContextProperty("Settings", settings);

    window = component->create(context);
}

void AppWindow::show()
{
    window->setProperty("visible", true);
}

void AppWindow::hide()
{
    window->setProperty("visible", false);
}
