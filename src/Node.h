#ifndef NODE_H__
#define NODE_H__

#include <memory>
#include <string>

using namespace std;

class Node
{
private:
    string data;
    int x_pos;
    int y_pos;
    Node *predecessor;

public:
    Node(string data);
    ~Node();
    int getXPos();
    int getYPos();
    void setXPos(int);
    void setYPos(int);
    void setPredecessor(Node *other);
};

#endif