#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
  Node *left;
  Node *right;
  int value;
  Node(int value) : left(0), right(0), value(value) {}
};

class BinaryTree {
private:
  Node *root;
  void insert(int value, Node* node) {
    if (node->value < value) {
      // insert right
      if (node->right == 0) node->right = new Node(value);
      else insert(value, node->right);
    } else {
      // insert left
      if (node->left == 0) node->left = new Node(value);
      else insert(value, node->left);
    }
  }
  int sumEven(Node* t)
  {
      if (t == 0)
      {
          return 0;
      }
      if (t->value % 2 == 0)
      {
          return t->value + sumEven(t->left) + sumEven(t->right);
      }
      else
      {
          return 0 + sumEven(t->left) + sumEven(t->right);
      }
  }

public:
  BinaryTree() : root(0) {}
  void insert(int value) {
    if (root == 0) {
      root = new Node(value);
    } else {
      insert(value, root);
    }
  }
  int sumEven()
  {
      if (root == 0)
      {
          return -1;
      }
      return sumEven(root);
  }
};

int main(int argc, char **argv) {
  BinaryTree bt ;
  bt.insert (2);
  bt.insert (5);
  bt.insert (5);
  bt.insert (4);
  bt.insert (1000);
  bt.insert (5);

  std::cout << bt.sumEven() <<std::endl;
  
  return 0;
}

