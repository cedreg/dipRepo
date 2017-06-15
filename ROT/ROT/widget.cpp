#include "widget.h"
#include "rottestclass.h"
#include <QDebug>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    rotTestClass* t1 = new rotTestClass(10);

    for (int i = 0; i < 20; i++ )
    {
        t1->push_back(i);
    }
    t1->COUT();

    qDebug() <<"\nCREATE AND COPY NEW ONE...\n";
    rotTestClass* t2 = new rotTestClass(12);
    t2 = t1;
    t2->COUT();

    rotTestClass* t3 = new rotTestClass(*t2);

    t3->COUT();
}

Widget::~Widget()
{
}
