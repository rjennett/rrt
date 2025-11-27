#include <string>

#include "Node.h"

Node::Node(string s)
{
    data = s;
}

Node::~Node() {}

int Node::getXPos() {
    return x_pos;
}

int Node::getYPos() {
    return y_pos;
}

void Node::setXPos(int x) {
    x_pos = x;
}

void Node::setYPos(int y) {
    y_pos = y;
}

void Node::setPredecessor(Node* n) {
    predecessor = n;
}