#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class QTableWidget;

class myWidget : public QWidget
{
    Q_OBJECT
private:
    int MR;
    QTableWidget* TW;


public:
    explicit myWidget(int MAXROWS, QWidget *parent = 0);

signals:

public slots:
    void cp();
    void rs();
};

#endif // MYWIDGET_H
