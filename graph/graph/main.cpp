#include <QCoreApplication>

#include "graph.h"
#include "node.h"

#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    graph* g = new graph();

    g->insert(2);
    g->insert(4);
    g->insert(5);
    g->insert(72);
    g->insert(73);

    qDebug() << g->connect(2,4);
    qDebug() << g->connect(2,5);
    qDebug() << g->connect(5,4);
    qDebug() << g->connect(5,4);
    qDebug() << g->connect(72,73);


    qDebug() << "------------------";

    qDebug() << g->isConnected(4,73);

    return 0;
}
