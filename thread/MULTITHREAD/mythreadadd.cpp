#include "mythreadadd.h"
#include "container.h"

myThreadADD::myThreadADD(container *c) : work(true), ALEsC(c)
{

}

void myThreadADD::run()
{
    int counter = 99;
    while (work && counter >= 0) {
        //msleep(500);
        ALEsC->incValue();
        counter--;
    }
}

void myThreadADD::setWork(bool a)
{
    work = a;
}
