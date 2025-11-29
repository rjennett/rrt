#include <random>
#include <tuple>
#include <cmath>
#include <array>

#include "Graph.h"

using namespace std;

Graph::Graph(int qInitX, int qInitY)
{
    // Init node
    Node* n(new Node("n"));

    // Assign node x
    n->setXPos(qInitX);

    // Assign node y
    n->setYPos(qInitY);

    // Assign predecessor NULL
    n->setPredecessor(NULL);

    // Add the root node to the graph
    addNode(n);
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

vector<Node*> Graph::buildRRT(Graph* g, int k, int deltaQ, int goalX, int goalY) {
    // Path will be empty if RRT fails
    vector<Node*> path;
    // Iterate to k
    for (int i = 0; i < k - 1; ++i) {
        // Get a random configuration qRand
        auto [qRandX, qRandY] = randConf(goalX, goalY);

        // Get the nearest node to qRand qNear
        Node* qNear = nearestNode(qRandX, qRandY, g);

        // Create the next node qNew using qNear and qRand
        // Set node data for easy reference: "n" + i
        Node* qNew(new Node("n" + to_string(i)));

        // Calculate new qx, qy at unit dist from qNear, towards qRand
        auto [qNewX, qNewY] = normalDist(deltaQ, qNear, qRandX, qRandY);
        
        // Set qNew->x
        qNew->setXPos(qNewX);

        // Set qNew->y
        qNew->setYPos(qNewY);

        // Set qNew->predecessor
        qNew->setPredecessor(qNear);

        // Add qNew node to graph
        g->addNode(qNew);

        // Add qNew edge to graph
        Edge* e(new Edge(qNear, qNew));
        g->addEdge(e);

        // End the tree if it found the goal
        if (distance(qNew, goalX, goalY) < 0.5) {
            // Consider the goal found
            // Calculate the path to the goal
            computePath(qNew, path);
            return path;
        }
    }
    return path;
}

// Get a random configuration in the general configuration space
tuple<int, int> Graph::randConf(int goalX, int goalY) {
    // Set up random
    random_device rd;
    mt19937 gen(rd());

    // Get a random x in the range
    uniform_int_distribution<> distribX(1, goalX);
    int x = distribX(gen);

    // Get a random y in the range
    uniform_int_distribution<> distribY(1, goalY);
    int y = distribY(gen);

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
double Graph::distance(Node* n, int confX, int confY) {
    // Calculate Euclidean distance
    double dist = sqrt((pow((n->getXPos() - confX), 2)) + pow((n->getYPos() - confY), 2));
    return dist;
}

tuple<double, double> Graph::normalDist(int deltaQ, Node* qNear, int qRandX, int qRandY) {
    // Calc distance from qNear to qRand
    double dist = distance(qNear, qRandX, qRandY);

    // Return the point if it's nearer than the deltaQ
    if (dist <= deltaQ) {
        return make_tuple(qRandX, qRandY);
    }

    double theta = atan2(qRandY - qNear->getYPos(), qRandX - qNear->getXPos());
    double newX = qNear->getXPos() + deltaQ * cos(theta);
    double newY = qNear->getYPos() + deltaQ * cos(theta);

    return make_tuple(newX, newY);
}

void Graph::computePath(Node* goalNode, vector<Node*>& path) {
    // Recursively move to predecessor
    if (goalNode->getPredecessor() == NULL) {
        return;
    }
    // Add to path vector
    path.push_back(goalNode);
    computePath(goalNode->getPredecessor(), path);
}