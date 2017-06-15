#include "mythreadsub.h"
#include "container.h"

myThreadSUB::myThreadSUB(container *c) : work(true), ALEsC(c)
{

}

void myThreadSUB::run()
{
    int counter = 99;
    while (work && counter >= 0) {
        //msleep(100);
        ALEsC->decValue();
        counter--;
    }
}

void myThreadSUB::setWork(bool a)
{
    work = a;
}
