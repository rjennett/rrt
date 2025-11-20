#ifndef GRAPH_H__
#define GRAPH_H__

#include "Edge.h"
#include "Node.h"
#include <memory>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph();
    ~Graph();
    vector<Node *> getNodes();
    vector<Edge *> getEdges();
    void addNode(Node *n);
    void addEdge(Edge *e);

private:
    vector<Node *> nodes;
    vector<Edge *> edges;
};

#endif