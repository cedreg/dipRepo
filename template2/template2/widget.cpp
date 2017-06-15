#include "widget.h"
#include <QDebug>
#include "cont.h"
#include <string>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //cont<int, std::string> *d = new cont<int, std::string>;
    cont<int, QString> *e = new cont<int, QString>;


    // d->setPair(std::make_pair(1, "ale"));
    // d->showPair();


    e->setPair(std::make_pair(1, "hohoo"));
    e->showPair();



}

Widget::~Widget()
{

}
