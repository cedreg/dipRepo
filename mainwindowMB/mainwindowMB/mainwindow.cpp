#include "mainwindow.h"
#include "selectw.h"

#include <QAction>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    w1 = new selectW();
    setMinimumSize(200,150);

    setCentralWidget(w1);

    setupMenuBar();

}

MainWindow::~MainWindow()
{
}


void MainWindow::setupMenuBar()
{
    QMenu* copyM = menuBar()->addMenu(tr("&Copy"));
    QAction* copyAction = new QAction(tr("&Copy Now"));
    copyM->addAction(copyAction);
    connect(copyAction, SIGNAL(triggered()), w1, SLOT(copyTable()));

    QMenu* resetM = menuBar()->addMenu(tr("&Reset"));
    QAction* resetAction = new QAction(tr("&reset Now"));
    resetM->addAction(resetAction);
    connect(resetAction, SIGNAL(triggered()), w1, SLOT(resetTable()));
}
