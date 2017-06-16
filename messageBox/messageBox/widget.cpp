#include "widget.h"

#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(200,200);
    this->setWindowTitle("MessageBoxes");

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
    /*  QInputDialog* mDialogQuestion = new QInputDialog();
     *  Kann als klassenVariabel definiert werden und in dem SLOT queryQuestion
     *  anstatt "text = QInputDialog::getText" über die Variabel "mDialogQuestion->getText"
     *  genutzt werden.
     */

    QVBoxLayout* vbox = new QVBoxLayout();

    vbox->addWidget(infoB);
    vbox->addWidget(warningB);
    vbox->addWidget(errorB);
    vbox->addWidget(questionB);

    this->setLayout(vbox);

    connect(infoB, SIGNAL(clicked(bool)), mBoxInfo, SLOT(show()));
    connect(warningB, SIGNAL(clicked(bool)), mBoxWarning, SLOT(show()));
    connect(errorB, SIGNAL(clicked(bool)), this, SLOT(MBOX()));
    connect(questionB, SIGNAL(clicked(bool)), this, SLOT(queryQuestion()));
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

void Widget::queryQuestion()
{
    bool ok = false;
    QString text;


    text = QInputDialog::getText(0, "QUESTION", "Bitte Namen eingeben:", QLineEdit::Normal, text, &ok );
    if(ok)
    {
        qDebug() << "Guten Tag" << text;
        qDebug() << "user pressed ok\nDO SOMETHING WITH text-variable";
    }
    else
    {
        qDebug() << "user pressed cancel";
    }
}
