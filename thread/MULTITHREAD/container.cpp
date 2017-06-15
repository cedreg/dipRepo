#include "container.h"
#include <QDebug>
#include <QSemaphore>

container::container() : value(0)
{
    //this->value = 0;
    QS1 = new QSemaphore(1); // für inc         // qs1 hat 1 resource
    QS2 = new QSemaphore(0); // für dec         // qs2 hat 0

}

void container::incValue()
{
    QS1->acquire(1);                    // TADD nimmt 1 resource von qs1
    value++;
    qDebug() << "INC VALUE:" << value;
    QS2->release(1);                    // TADD gibt 1 resource an qs2
}

void container::decValue()
{
    QS2->acquire(1);                    // tSUB nimmt 1 resource von qs2
    value--;
    qDebug() << "DEC VALUE:" << value;
    QS1->release(1);                    // tsub gibt 1 resource an qs1
}
