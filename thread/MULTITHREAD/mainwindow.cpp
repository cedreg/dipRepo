#include "mainwindow.h"
#include "container.h"
#include "mythreadadd.h"
#include "mythreadsub.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    container* c;
    c = new container();
    myThreadADD* tADD = new myThreadADD(c);
    myThreadSUB* tSUB = new myThreadSUB(c);

    tADD->start();
    tSUB->start();

}

MainWindow::~MainWindow()
{

}
