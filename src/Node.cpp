#include <string>

#include "Node.h"

Node::Node(string s)
{
    data = s;
}

Node::~Node() {}

double Node::getXPos() {
    return x_pos;
}

double Node::getYPos() {
    return y_pos;
}

void Node::setXPos(double x) {
    x_pos = x;
}

void Node::setYPos(double y) {
    y_pos = y;
}

void Node::setPredecessor(Node* n) {
    predecessor = n;
}