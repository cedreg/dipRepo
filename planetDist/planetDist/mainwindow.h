#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
class drawfield;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    drawfield *field;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
