#ifndef NODE_H
#define NODE_H
#include <vector>

class node
{
private:
    std::vector<node*> neighbors;
    int value;
    bool visited;

public:
    node(int val);
    int getValue() const;
    void setValue(int value);

    void insertNeighbor(node*);

    bool checkDouble(node*);
    bool getVisited() const;
    void setVisited(bool value);
    std::vector<node*> getNeighbors() const;
};

#endif // NODE_H
