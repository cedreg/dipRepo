#include "node.h"

int node::getValue() const
{
    return value;
}

void node::setValue(int value)
{
    this->value = value;
}

void node::insertNeighbor(node * n)
{
    neighbors.push_back(n);
}

bool node::checkDouble(node * chkNode)
{
    for(node* n : neighbors)
    {
        if(n == chkNode)
        {
            return true;
        }
    }
    return false;
}

bool node::getVisited() const
{
    return visited;
}

void node::setVisited(bool value)
{
    visited = value;
}

std::vector<node *> node::getNeighbors() const
{
    return neighbors;
}

node::node(int val) : value(val), visited(false)
{
}
