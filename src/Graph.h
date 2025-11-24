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
    Graph* buildRRT(int qInitX, int qInitY, int k, int deltaQ, vector<int, int> genConf);
    Node* init(int qInitX, int qInitY);
    tuple<int, int> randConf(vector<int, int> genConf);

private:
    vector<Node *> nodes;
    vector<Edge *> edges;
};

#endif