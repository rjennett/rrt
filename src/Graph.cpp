#include <random>
#include <tuple>
#include <cmath>
#include <array>

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

Node* Graph::getNearestNode() {
    return nearest;
}

int Graph::getNearestDist() {
    return nearestDist;
}

void Graph::setNearestNode(Node* n) {
    nearest = n;
}

void Graph::setNearestDist(int d) {
    nearestDist = d;
}

Graph* Graph::buildRRT(Graph* g, int k, int deltaQ, int genConf[][6]) {
    // Iterate to k
    for (int i = 0; i < k; ++i) {
        // Get a random configuration qRand
        auto [qRandX, qRandY] = randConf(genConf);

        // Get the nearest node to qRand qNear
        Node* qNear = nearestNode(qRandX, qRandY, g);

        // Create the next node qNew using qNear and qRand
        // Set node data for easy reference: "n" + k
        Node* qNew(new Node("n" + to_string(k)));

        // Calculate new qx, qy at unit dist from qNear, towards qRand
        int unitDist = 1;
        
        // Set qNew->x
        qNew->setXPos(qNear->getXPos() + 1);

        // Set qNew->y
        qNew->setYPos(qNear->getYPos() + 1);

        // Set qNew->predecessor
        qNew->setPredecessor(qNear);

        // Add qNew node to graph
        g->addNode(qNew);

        // Add qNew edge to graph
        Edge* e(new Edge(qNear, qNew));
        g->addEdge(e);
    }
    return g;
}

// Initialize a graph with one root node with attributes set
// to the arguments
// TODO: this is should probably be in the graph constructor
Node* Graph::init(int qInitX, int qInitY) {
    // Init node
    Node* n(new Node("n"));

    // Assign node x
    n->setXPos(qInitX);

    // Assign node y
    n->setYPos(qInitY);

    // Assign predecessor NULL
    n->setPredecessor(NULL);

    return n;
}

// Get a random configuration in the general configuration space
tuple<int, int> Graph::randConf(int genConf[][6]) {
    // Set up random
    random_device rd;
    mt19937 gen(rd());
    // TODO: remove hardcoded sub-array length of 6
    uniform_int_distribution<> distrib(0, 6 - 1);

    // Section assumes square configuration space

    // Get a random x in the range
    int x = distrib(gen);

    // Get a random y in the range
    int y = distrib(gen);

    return make_tuple(x, y);
}

// Get the nearest existing node to the random conf
Node* Graph::nearestNode(int qRandX, int qRandY, Graph* g) {
    // For each node in the graph
    // If graph only has one node, use that one
    if (g->getNodes().size() == 1) {
        setNearestNode(g->getNodes()[0]);
        int dist = distance(g->getNodes()[0], qRandX, qRandY);
        setNearestDist(dist);
        return getNearestNode();
    }

    // Search graph for nearest node
    for (Node* n : g->getNodes()) {
        // Use helper distance() to find distance of n to point
        int dist = distance(n, qRandX, qRandY);

        // Use accumulator pattern to store nearest-so-far
        if (dist <= getNearestDist()) {
            // Set Graph->nearest = the passed node
            setNearestNode(n);
            // Set Graph->nearestDist = passed node's distance
            setNearestDist(dist);
        }
    }
    return getNearestNode();
}

// Get the distance from a node to a conf
// TODO: what to return from this most effectively? int/double
int Graph::distance(Node* n, int confX, int confY) {
    // Calculate Euclidean distance
    int dist = sqrt((pow((n->getXPos() - confX), 2)) + pow((n->getYPos() - confY), 2));
    return dist;
}