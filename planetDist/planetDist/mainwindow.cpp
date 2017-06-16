#include "mainwindow.h"
#include "drawfield.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setMinimumSize(800, 600);

    field = new drawfield();

    this->setCentralWidget(field);
}

MainWindow::~MainWindow()
{

}
