#ifndef GRAPH_H
#define GRAPH_H
#include "node.h"
#include <vector>

class graph
{
private:
    std::vector<node*> allNodes;

public:
    graph();
    void insert(int val);
    bool connect(int valNodeSelf , int valNodeNeighbor);
    bool isConnected(int valNodeSelf, int valNodeNeighbor);
    void resetVisited();
};

#endif // GRAPH_H
