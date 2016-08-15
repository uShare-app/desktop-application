#include "screencapturer.h"

QString ScreenCapturer::captureScreen()
{
    QScreen * screen;
    QPixmap screenshot;

    screen = QGuiApplication::primaryScreen();

    if (!screen)
        return (QString::null);

    screenshot = screen->grabWindow(0);
    screenshot.save("/home/mhammerc/image.png", 0, 0);
    return ("/home/mhammerc/image.png");
}
