QT += qml quick quickcontrols2 widgets network

CONFIG += c++11

SOURCES += main.cpp \
    systemtrayicon.cpp \
    network/httpfileuploader.cpp \
    screencapturer.cpp \
    systemtrayactions.cpp \
    areaselecter.cpp \
    appwindow.cpp \
    qml/qmlsettings.cpp

RESOURCES += qml.qrc \
    resources/resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += systemtrayicon.h \
    network/httpfileuploader.h \
    screencapturer.h \
    systemtrayactions.h \
    areaselecter.h \
    appwindow.h \
    qml/qmlsettings.h
