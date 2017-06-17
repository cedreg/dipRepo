#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class QLineEdit;
class QListWidget;
class QPushButton;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLineEdit * lineedit;
    QLabel *label;
    QPushButton* bADD;
    QPushButton* bCLEAR;
    QPushButton* bSORT;
    QListWidget* listwidget;

public:
    Widget();
    ~Widget();

private slots:
    void mySort();
    void addItemToList();

};

#endif // WIDGET_H
