#ifndef QMLSETTINGS_H
#define QMLSETTINGS_H

# include <QObject>
# include <QSettings>

class QmlSettings : public QSettings
{
    Q_OBJECT
public:
    QmlSettings(QObject * parent = 0);
    virtual ~QmlSettings();

    Q_INVOKABLE void setValue(QString const &key, QVariant const &value);
    Q_INVOKABLE void setValueIfNotSet(QString const &key, QVariant const &value);
    Q_INVOKABLE QVariant value(QString const &key);
    Q_INVOKABLE bool boolValue(QString const &key);
};

#endif // QMLSETTINGS_H
