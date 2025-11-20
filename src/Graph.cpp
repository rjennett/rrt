#include "Graph.h"

using namespace std;

Graph::Graph()
{
}

Graph::~Graph() {}

vector<Node *> Graph::getNodes()
{
    return nodes;
}

vector<Edge *> Graph::getEdges()
{
    return edges;
}

void Graph::addNode(Node *n)
{
    nodes.push_back(n);
}

void Graph::addEdge(Edge *e)
{
    edges.push_back(e);
}
