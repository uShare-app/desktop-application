#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

# include <QApplication>
# include <QSystemTrayIcon>
# include <QMenu>
# include <QAction>

class SystemTrayIcon : public QSystemTrayIcon
{
public:
    SystemTrayIcon();

private:
    QAction *captureScreen;
    QAction *captureArea;
    QAction *createPaste;
    QAction *sendFile;
    QAction *open;
    QAction *quit;
};

#endif // SYSTEMTRAYICON_H
