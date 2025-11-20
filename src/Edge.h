#ifndef EDGE_H__
#define EDGE_H__

#include "Node.h"
#include <memory>

using namespace std;

class Edge
{
private:
    // Start node
    Node *a;
    // End node
    Node *b;

public:
    Edge(Node *n1, Node *n2);
    ~Edge();
    Node *getStart();
    Node *getEnd();
};

#endif