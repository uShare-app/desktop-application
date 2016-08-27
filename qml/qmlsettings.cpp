#include "qmlsettings.h"

QmlSettings::QmlSettings(QObject * parent) : QSettings(parent)
{

}

QmlSettings::~QmlSettings()
{

}

void QmlSettings::setValue(const QString &key, const QVariant &value)
{
    QSettings::setValue(key, value);
}

void QmlSettings::setValueIfNotSet(const QString &key, const QVariant &value)
{
    if (QSettings::value(key).isNull())
        QSettings::setValue(key, value);
}

QVariant QmlSettings::value(const QString &key)
{
    return (QSettings::value(key));
}

bool QmlSettings::boolValue(const QString &key)
{
    return (QSettings::value(key).toBool());
}
