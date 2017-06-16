#ifndef DRAWFIELD_H
#define DRAWFIELD_H

#include <QWidget>
class point;

class drawfield : public QWidget
{
    Q_OBJECT
private:
    int mousePressX;
    int mousePressY;
    float dist;
    float tmpDist;

    std::vector<point*> points;
public:
    drawfield();
    void paintEvent(QPaintEvent *pe);
    void mousePressEvent(QMouseEvent* me);

signals:

public slots:
};

#endif // DRAWFIELD_H
