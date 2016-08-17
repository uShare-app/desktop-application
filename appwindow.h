#ifndef APPWINDOW_H
#define APPWINDOW_H

# include <QObject>
# include <QQmlApplicationEngine>

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
    QQmlApplicationEngine engine;
    QObject * root;
};

#endif // APPWINDOW_H
