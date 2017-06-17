#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <vector>
#include <algorithm>
#include <QVBoxLayout>
#include <QHBoxLayout>

Widget::Widget()
{
    this->setMinimumSize(150,250);

    label = new QLabel("App Title");

    lineedit = new QLineEdit();

    bADD = new QPushButton("ADD");
    bCLEAR = new QPushButton("Clear");

    listwidget = new QListWidget();

    bSORT = new QPushButton("Sort");

    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();

    vbox->addWidget(label);
    vbox->addWidget(lineedit);
        hbox->addWidget(bADD);
        hbox->addWidget(bCLEAR);
    vbox->addLayout(hbox);
    vbox->addWidget(listwidget);
    vbox->addWidget(bSORT);

    this->setLayout(vbox);

    connect(bADD,SIGNAL(clicked(bool)), this, SLOT(addItemToList()));
    connect(bCLEAR, SIGNAL(clicked(bool)), listwidget, SLOT(clear()));
    connect(bSORT, SIGNAL(clicked(bool)), this, SLOT(mySort()));


}

Widget::~Widget()
{

}

void Widget::mySort()
{

    std::vector<int> tmp;
    int currSize = listwidget->count();

    for(int i = 0; i < currSize; i++)
    {
        tmp.push_back(listwidget->item(i)->text().toInt());
    }

    std::sort(tmp.begin(), tmp.end());
    listwidget->clear();

    for(int i = 0; i < currSize; i++)
    {
       listwidget->addItem(new QListWidgetItem(QString::number(tmp[i])));
    }

}

void Widget::addItemToList()
{
    // validation
    //leereZeichenkette
    if(lineedit->text() == "")
    {
        lineedit->clear();
        return;
    }
    //whitespace
    if(lineedit->text() == " ")
    {
        lineedit->clear();
        return;
    }
    //keine Zahl
    bool ok = false;
    lineedit->text().toInt(&ok);
    if(ok)
    {
        listwidget->addItem(new QListWidgetItem(QString::number(lineedit->text().toInt())));
        lineedit->clear();
    }
    else
    {
        lineedit->clear();
    }
}
