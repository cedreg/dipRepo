#ifndef CONTAINER_H
#define CONTAINER_H

class QSemaphore;

class container
{
private:
    int value;
    QSemaphore* QS1;
    QSemaphore* QS2;
public:
    container();
    void incValue();
    void decValue();
};

#endif // CONTAINER_H
