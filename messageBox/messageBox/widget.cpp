#include "widget.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{


    infoB = new QPushButton("INFO");
    warningB = new QPushButton("WARNING");
    errorB = new QPushButton("ERROR");
    questionB = new QPushButton("QUESTION");

    /// M1
    QMessageBox* mBoxInfo = new QMessageBox(QMessageBox::Information, "INFO", "Das ist eine INFO",QMessageBox::StandardButton::Ok);

    /// M2
    int intInMBox = 1;
    QMessageBox* mBoxWarning = new QMessageBox();
    mBoxWarning->setIcon(QMessageBox::Warning);
    mBoxWarning->setWindowTitle("WARNING");
    mBoxWarning->setText("Das ist " + QString::number(intInMBox)+ " Warnung");
    mBoxWarning->setStandardButtons(QMessageBox::StandardButton::Abort | QMessageBox::StandardButton::Ok);

    /// M3
    testMBOX = true;

    /// M4
    QDialogButtonBox* mDialogQuestion = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);





    QVBoxLayout* vbox = new QVBoxLayout();

    vbox->addWidget(infoB);
    vbox->addWidget(warningB);
    vbox->addWidget(errorB);
    vbox->addWidget(questionB);

    this->setLayout(vbox);

    connect(infoB, SIGNAL(clicked(bool)), mBoxInfo, SLOT(show()));
    connect(warningB, SIGNAL(clicked(bool)), mBoxWarning, SLOT(show()));
    connect(errorB, SIGNAL(clicked(bool)), this, SLOT(MBOX()));
    connect(questionB, SIGNAL(clicked(bool)), mDialogQuestion, SLOT(show()));
}

Widget::~Widget()
{

}


void Widget::MBOX()
{
    if (testMBOX)
    {
        QMessageBox mBoxError(QMessageBox::Critical, "ERROR", "Linux ist abgestürzt", QMessageBox::StandardButton::Close);
        mBoxError.exec();
    }
}
