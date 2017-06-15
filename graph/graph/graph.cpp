#include "graph.h"
#include <stack>

graph::graph()
{
}

bool graph::connect(int valNodeSelf , int valNodeNeighbor)
{
    if (allNodes.size() < 2)
        return false;

    node* nSelf = nullptr;
    node* nNeighbor = nullptr;

    for(node* n : allNodes)
    {
        if(n->getValue() == valNodeSelf)
        {
            nSelf = n;
        }
        if(n->getValue() == valNodeNeighbor)
        {
            nNeighbor = n;
        }
    }

    if(nSelf != nullptr && nNeighbor != nullptr)
    {
        //verbinden der zwei nodes
        if(!nSelf->checkDouble(nNeighbor))
        {
            nSelf->insertNeighbor(nNeighbor);
            return true;
        }

        //nNeighbor->insertNeighbor(nSelf);
        return false;
    }
    else
    {
        return false;
    }

}

bool graph::isConnected(int valNodeSelf, int valNodeNeighbor)
{

    std::stack<node*> stackNodes;
    node* nSelf = nullptr;
    node* nNeighbor = nullptr;

    for(node* n : allNodes)
    {
        if(n->getValue() == valNodeSelf)
        {
            nSelf = n;
        }
        if(n->getValue() == valNodeNeighbor)
        {
            nNeighbor = n;
        }
    }

    if(nSelf != nullptr && nNeighbor != nullptr)
    {
        stackNodes.push(nSelf);
        while (!stackNodes.empty()) {
            node* n = stackNodes.top();
            stackNodes.pop();
            if (n->getValue() == nNeighbor->getValue())
            {
                resetVisited();
                return true;
            }
            if (n->getVisited() == false)
            {
                n->setVisited(true);
                for(node* tmpn : n->getNeighbors())
                {
                    stackNodes.push(tmpn);
                }
            }
        }

        resetVisited();
        return false;
    }
    else
    {
        return false;
    }
/*
    3      S.push(v)
    4      while S is not empty
    5          v = S.pop()
    6          if v is not labeled as discovered:
    7              label v as discovered
    8              for all edges from v to w in G.adjacentEdges(v) do
    9                  S.push(w)
*/


}

void graph::resetVisited()
{
    for(auto * wert : allNodes)
    {
        wert->setVisited(false);
    }
}

void graph::insert(int val)
{

    for(const node* n : allNodes)
    {
        if(n->getValue() == val)
        {
            return;
        }
    }

    allNodes.push_back(new node(val));

}
