#include <iostream>
#include "../src/Graph.h"
#include "../src/Node.h"
#include "../src/Edge.h"

using namespace std;

int main()
{
    // Test build
    // int var;
    // cout << "Hello potato, how many penguins?" << endl;
    // cin >> var;
    // cout << "Penguins to feed: " << var << endl;

    // Initialize general configuration space as array of coordinates
    int genConf[6][6] = {
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5},
        {0, 1, 2, 3, 4, 5}
    };
    // Initialize start coordinates
    int startX = 0;
    int startY = 0;
    
    // Initialize goal coordinates
    int goalX = 5;
    int goalY = 5;
    
    // (LATER) Initialize obstacle coordinates
    // (LATER) Initialize obstacle dimensions
    // (LATER) Differentiate the set of free coordinates from obs coordinates(?)

    // Initialize the graph
    Graph* g(new Graph());
    Node* n = g->init(startX, startY);
    g->addNode(n);

    // Max number of nodes in graph
    int k = 5;
    // Max distance for a node to travel upon creation
    int deltaQ = 1;

    // Graph->buildRRT()
    Graph* newGraph = g->buildRRT(g, k, deltaQ, genConf, goalX, goalY);

    // Output final path
    cout << "New graph created!" << endl;
    cout << "Start: " << "(" << startX << ", " << startY << ")" << endl;
    cout << "Goal: " << "(" << goalX << ", " << goalY << ")" << endl;
    cout << "Graph node coordinates: " << endl;
    for (auto i : g->getNodes()) {
        cout << "(" << i->getXPos() << ", " << i->getYPos() << ")" << endl;
    }
}
