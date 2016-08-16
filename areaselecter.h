#ifndef AREASELECTER_H
#define AREASELECTER_H

# include <QColor>
# include <QLabel>
# include <QMouseEvent>
# include <QObject>
# include <QRect>
# include <QRubberBand>

# include <random>

class AreaSelecter : public QLabel
{
    Q_OBJECT
public:
    AreaSelecter(QWidget * parent = 0);
    virtual ~AreaSelecter();

    void selectArea();

private:
    QRubberBand * rubberBand;
    QPoint origin;

    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void keyPressEvent(QKeyEvent * event);

signals:
    void areaTaken(QRect);
    void canceled();
};

#endif // AREASELECTER_H
