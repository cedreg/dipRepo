#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;


class Widget : public QWidget
{
    Q_OBJECT

private:
    QPushButton* infoB;
    QPushButton* warningB;
    QPushButton* errorB;
    QPushButton* questionB;

    bool testMBOX;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void MBOX();
};

#endif // WIDGET_H
