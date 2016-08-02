QT += qml quick quickcontrols2 widgets

CONFIG += c++11

SOURCES += main.cpp \
    systemtrayicon.cpp

RESOURCES += qml.qrc \
    resources/resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    systemtrayicon.h
