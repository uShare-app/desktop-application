#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "systemtrayicon.h"
#include <QMenu>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    SystemTrayIcon icon;

    return app.exec();
}
