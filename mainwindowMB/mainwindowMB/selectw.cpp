#include "selectw.h"
#include "mywidget.h"

#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

selectW::selectW(QWidget *parent) : QWidget(parent)
{
    mw = nullptr;
    QPushButton *mb = new QPushButton("LOS");

    insertLine = new QLineEdit();

    QHBoxLayout* hbox = new QHBoxLayout();

    hbox->addWidget(mb);
    hbox->addWidget(insertLine);


    this->setLayout(hbox);

    connect(mb, SIGNAL(clicked(bool)), this, SLOT(createTABLE()));
}

void selectW::createTABLE()
{
    if (mw != nullptr)
    {
        disconnect(this, SIGNAL(mwCopyTable()), mw, SLOT(cp()));
        disconnect(this, SIGNAL(mwResetTable()), mw, SLOT(rs()));
        delete mw;
    }

    mw = new myWidget(insertLine->text().toInt());
    connect(this, SIGNAL(mwCopyTable()), mw, SLOT(cp()));
    connect(this, SIGNAL(mwResetTable()), mw, SLOT(rs()));
    mw->show();
}

void selectW::copyTable()
{
    emit mwCopyTable();
}

void selectW::resetTable()
{
    emit mwResetTable();
}
