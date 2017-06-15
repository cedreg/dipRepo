#ifndef CONT_H
#define CONT_H

#include <utility>
#include <QDebug>
#include <iostream>

template <class T, class TP>
class cont
{
private:
    std::pair<T, TP> pair;
public:
    cont();
    void setPair(std::pair<T,TP>);
    void showPair();

};

template <class T, class TP>
cont<T, TP>::cont()
{

}

template <class T, class TP>
void cont<T, TP>::setPair(std::pair<T, TP> a)
{
    pair = a;
}


template <class T, class TP>
void cont<T, TP>::showPair()
{
    qDebug() << pair.first << pair.second;
}

#endif // CONT_H


