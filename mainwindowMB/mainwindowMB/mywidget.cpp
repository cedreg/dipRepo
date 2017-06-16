#include "mywidget.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHboxLayout>
#include <QDebug>


myWidget::myWidget(int MAXROWS, QWidget *parent) : MR(MAXROWS), QWidget(parent)
{
    this->setMinimumSize(800,600);

    // check if MR is <= 1. IF SO assign 1 else assign MR
    // important because of the for-loop after we create the tableWidget
    MR <= 1 ? MR = 1 : MR = MR;
    TW = new QTableWidget(MR, 2);

    // There are no items in cells until one sets them with QTableWidget::setItem() or after user has edited them.
    for(int i = 0; i < MR; i++)
    {
        QTableWidgetItem* itmLeft = new QTableWidgetItem();

        QTableWidgetItem* itmRight = new QTableWidgetItem();
        itmRight->setFlags(itmRight->flags() ^ Qt::ItemIsEditable);

        TW->setItem(i, 0, itmLeft);
        TW->setItem(i, 1, itmRight);
    }

    QHBoxLayout* hbox = new QHBoxLayout();

    hbox->addWidget(TW);

    this->setLayout(hbox);
}

void myWidget::cp()
{
    int rows = TW->rowCount();

    for (int i = 0; i < rows; i++)
    {
        QString rowText = (TW->item(i,0)->text().isEmpty()) ? "" : TW->item(i,0)->text();
        TW->item(i, 1)->setText(rowText);
    }
}

void myWidget::rs()
{
    int rows = TW->rowCount();

    for (int i = 0; i < rows; i++)
    {
        TW->item(i, 0)->setText("");
        TW->item(i, 1)->setText("");
    }
}
