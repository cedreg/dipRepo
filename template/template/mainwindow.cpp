#include "mainwindow.h"
#include "container.h"
#include <QDebug>
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    // INT
    container<int> i1;          // i1() OHNE () da der compiler sonst meint, es sei eine funktion mit container<int> rückgabe [NUR WEIL CONSTRUCTOR KEINE PARAMETER NIMMT]
    container<int> i2;          // gleich wie bei i1
    i1.setValue(3);
    i2.setValue(5);

    // DOUBLE*
    container<double>* d1 = new container<double>();
    container<double>* d2 = new container<double>();
    d1->setValue(5.9);
    d2->setValue(1.9);

    // string*
    container<std::string> * s1 = new container<std::string>();
    s1->setValue("HALLO");

    ///AUSGABE AUF STD::COUT-stream
    //std::cout << i1;
    //std::cout << *d1;
    //std::cout << *s1;

    ///TEST OB relational-operatoren funktionieren
    qDebug() << "i1 < i2:" << (i1 < i2);
    qDebug() << "i1 >= i2:" << (i1 >= i2);
    qDebug() << "*d1 < *d2:" << (*d1 < *d2); // dereference sonst werden die adressen des SPEICHERS verglichen...

    ///TEST OB gleich/ungleich funktioniert
    qDebug() << "i1 == i2:" << ((i1 == i2) ? "ist gleich" : "ist ungleich");

    ///TEST OB Assignment operator funktioniert
    i1 = i2;
    qDebug() << "i1 = i2 \ni1 == i2:" << (i1 == i2);

    ///TEST OB ^= funktioniert (squared)
    ///i1 ist hier druch zuweisung auf zeile 40 -> 5 = resultat muesste pow(5, 2) -> 25 sein
    i1 ^= 2;
    qDebug() << i1.getValue();

}

MainWindow::~MainWindow()
{

}
