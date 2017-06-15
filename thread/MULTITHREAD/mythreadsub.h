#ifndef MYTHREADSUB_H
#define MYTHREADSUB_H

#include <QThread>
class container;

class myThreadSUB : public QThread
{
    bool work;
    container* ALEsC;
public:
    myThreadSUB(container *c);
    void run();
    void setWork(bool);
};

#endif // MYTHREADSUB_H
