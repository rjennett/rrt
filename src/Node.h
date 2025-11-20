#ifndef NODE_H__
#define NODE_H__

#include <memory>

using namespace std;

class Node
{
private:
    int x_pos;
    int y_pos;
    Node *predecessor;

public:
    Node(int x, int y);
    ~Node();
    int getXPos();
    int getYPos();
    void setXPos();
    void setYPos();
    void setPredecessor(Node *other);
};

#endif