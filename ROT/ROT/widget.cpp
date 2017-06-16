#include "widget.h"
#include "rottestclass.h"
#include <QDebug>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    qDebug() <<"CREATE NEW ONE AND INSERT DATA...";
    rotTestClass* t1 = new rotTestClass(10);
    for (int i = 0; i < 20; i++ )
    {
        t1->push_back(i);
    }
    t1->COUT();

    qDebug() <<"\nCREATE NEW ONE AND ASSIGN t1...";
    rotTestClass* t2 = new rotTestClass(12);
    t2 = t1;
    t2->COUT();

    qDebug() <<"\nCREATE NEW ONE AND USE COPY CONSTRUCTOR TO COPY DATA FROM t2...";
    rotTestClass* t3 = new rotTestClass(*t2);
    t3->COUT();
}

Widget::~Widget()
{
}
