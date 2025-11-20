#include "Edge.h"

Edge::Edge(Node *n1, Node *n2)
{
    a = n1;
    b = n2;
}

Edge::~Edge()
{
}

Node *Edge::getStart()
{
    return a;
}

Node *Edge::getEnd()
{
    return b;
}
