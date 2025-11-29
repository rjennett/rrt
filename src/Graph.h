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
    Graph(int qInitX, int qInitY);
    ~Graph();
    
    vector<Node *> getNodes();
    vector<Edge *> getEdges();
    void addNode(Node *n);
    void addEdge(Edge *e);

    vector<Node*> buildRRT(Graph* g, int k, int deltaQ, int goalX, int goalY);
    tuple<int, int> randConf(int goalX, int goalY);

    Node* nearestNode(int qRandX, int qRandY, Graph* g);

    double distance(Node* n, int confX, int confY);
    tuple<double, double> normalDist(int normal, Node* qNear, int qRandX, int qRandY);

    Node* getNearestNode();
    int getNearestDist();
    void setNearestNode(Node* n);
    void setNearestDist(int d);
    void computePath(Node* goalNode, vector<Node*>& path);

private:
    vector<Node *> nodes;
    vector<Edge *> edges;
    Node* nearest;
    int nearestDist;
};

#endif