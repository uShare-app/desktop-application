#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "systemtrayicon.h"
#include <QMenu>
#include <iostream>
#include <QQuickStyle>

#include "network/httpfileuploader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("uSquare");
    QCoreApplication::setOrganizationDomain("uplmg.com");
    QCoreApplication::setApplicationName("Uplimg");
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    QQuickStyle::setStyle("Default");

    SystemTrayIcon icon;
    icon.show();

    return app.exec();
}
