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

    Graph* buildRRT(Graph* g, int k, int deltaQ, int goalX, int goalY);
    Node* init(int qInitX, int qInitY);
    tuple<int, int> randConf();

    Node* nearestNode(int qRandX, int qRandY, Graph* g);

    double distance(Node* n, int confX, int confY);
    tuple<double, double> normalDist(int normal, Node* qNear, int qRandX, int qRandY);

    Node* getNearestNode();
    int getNearestDist();
    void setNearestNode(Node* n);
    void setNearestDist(int d);

private:
    vector<Node *> nodes;
    vector<Edge *> edges;
    Node* nearest;
    int nearestDist;
};

#endif