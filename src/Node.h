#ifndef NODE_H__
#define NODE_H__

#include <memory>
#include <string>

using namespace std;

class Node
{
private:
    string data;
    double x_pos;
    double y_pos;
    Node *predecessor;

public:
    Node(string data);
    ~Node();
    double getXPos();
    double getYPos();
    void setXPos(double);
    void setYPos(double);
    void setPredecessor(Node *other);
};

#endif