#include <random>
#include <tuple>

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

Graph* Graph::buildRRT(int qInitX, int qInitY, int k, int deltaQ, vector<int, int> genConf) {
    // Initialize the graph
    Graph* g(new Graph());
    Node* n = g->init(qInitX, qInitY);
    g->addNode(n);

    // Iterate to k
    for (int i = 0; i < k; ++i) {
        // Get a random configuration qRand
        auto [qRandX, qRandY] = randConf(genConf);

        // Get the nearest node to qRand qNear
        // Get the next node qNew using qNear and qRand
        int qNewX;
        // Init node
        // Set node data for easy reference: "n" + k
        Node* n(new Node("n" + k));
        
        // Set node x
        n->setXPos(qNewX);

        // Set node y
        // Set node predecessor
        // Add node to graph
        // Add edge to graph
    }
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
tuple<int, int> Graph::randConf(vector<int, int> genConf) {
    // Set up random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, genConf[0].size() - 1);

    // Section assumes square configuration space

    // Get a random x in the range
    int x = distrib(gen);

    // Get a random y in the range
    int y = distrib(gen);

    return make_tuple(x, y);
}

