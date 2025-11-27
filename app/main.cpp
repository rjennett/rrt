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

    // Graph->buildRRT()
    Graph* newGraph = g->buildRRT(g, 5, 1, genConf);

    // Output final path
    cout << "New graph created!" << endl;
}
