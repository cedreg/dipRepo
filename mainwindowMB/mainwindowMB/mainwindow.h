#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class selectW;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    selectW* w1;
    void setupMenuBar();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void copyTable();
};

#endif // MAINWINDOW_H
