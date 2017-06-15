#ifndef MYTHREADADD_H
#define MYTHREADADD_H

#include <QThread>
class container;
class myThreadADD : public QThread
{
private:
    bool work;
    container* ALEsC;
public:
    myThreadADD(container * c);
    void run();
    void setWork(bool);

};

#endif // MYTHREADADD_H
