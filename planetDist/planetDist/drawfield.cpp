#include "drawfield.h"
#include "point.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <ctime>
#include <QDebug>
#include <cmath>

drawfield::drawfield()
{

    std::srand(time(0));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));
    points.push_back(new point(std::rand() % 790 + 10,std::rand() % 590 + 10));

    mousePressX = -1;
    mousePressY = -1;



}

void drawfield::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;

    pen.setWidth(15);

    painter.setPen(pen);

    for (unsigned int i = 0; i < points.size(); i++)
    {
        painter.drawPoint(points[i]->getX(), points[i]->getY());
        painter.drawText(points[i]->getX()+15,points[i]->getY() + 3,QString::number(i));
    }

    if (mousePressX > 0)
    {
           painter.drawText(mousePressX, mousePressY,QString::number(tmpDist));
    }



}

void drawfield::mousePressEvent(QMouseEvent *me)
{
    mousePressX = me->x();
    mousePressY = me->y();
    dist = 0;
    tmpDist = -1;


    if(points.empty())
    {
        return;
    }
    else
    {
       for(unsigned int i=0; i<points.size();i++){
           dist=sqrt(pow(mousePressX-points[i]->getX(),2)+pow(mousePressY-points[i]->getY(),2));
           qDebug() <<"PUNKT " + QString::number(i) <<dist;
           if(dist < tmpDist || tmpDist== -1){
               tmpDist=dist;

           }

       }

       //qDebug() << "Kleinste Distanz ist: " << tmpDist;

    }
    this->update();
}
