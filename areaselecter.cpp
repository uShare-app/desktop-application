#include "areaselecter.h"

AreaSelecter::AreaSelecter(QWidget * parent): QLabel(parent)
{
    QColor color;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    color.setRed(dist(mt));
    color.setGreen(dist(mt));
    color.setBlue(dist(mt));

    setCursor(Qt::CrossCursor);
    rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

    QPalette palette;
    palette.setColor(QPalette::Normal, QPalette::Highlight, color);
    rubberBand->setPalette(palette);
}

AreaSelecter::~AreaSelecter()
{
    releaseKeyboard();
}

void AreaSelecter::selectArea()
{
    showFullScreen();
}

void AreaSelecter::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    origin = event->pos();
    rubberBand->setGeometry(QRect(origin, QSize(0, 0)));
    rubberBand->show();
}

void AreaSelecter::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
}

void AreaSelecter::mouseReleaseEvent(QMouseEvent *event)
{
    QRect area;


    if (event->button() != Qt::LeftButton)
        return;

    area = QRect(origin, event->pos()).normalized();
    if (area.height() < 4 || area.width() < 4)
        return;

    rubberBand->hide();
    this->hide();
    emit areaTaken(area);
}

void AreaSelecter::keyPressEvent(QKeyEvent * event)
{
    if (event->key() != Qt::Key_Escape)
       return;

   emit canceled();
}
