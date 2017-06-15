#ifndef SELECTW_H
#define SELECTW_H

#include <QWidget>
class QLineEdit;
class myWidget;
class selectW : public QWidget
{
    Q_OBJECT
private:
    myWidget* mw;
    QLineEdit* insertLine;
public:
    explicit selectW(QWidget *parent = 0);

signals:
    void mwCopyTable();
    void mwResetTable();

public slots:
    void createTABLE();
    void copyTable();
    void resetTable();
};

#endif // SELECW_H
