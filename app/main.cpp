#include <iostream>
#include <algorithm>

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

    // Take start coordinates
    int startX;
    int startY;

    cout << "Enter start X coordinate: ";
    cin >> startX;
    cout << "Enter start Y coordinate: ";
    cin >> startY;
    
    // Take goal coordinates
    int goalX;
    int goalY;

    cout << "Enter goal X coordinate: ";
    cin >> goalX;
    cout << "Enter goal Y coordinate: ";
    cin >> goalY;

    // (LATER) Initialize obstacle coordinates
    // (LATER) Initialize obstacle dimensions
    // (LATER) Differentiate the set of free coordinates from obs coordinates(?)

    // Initialize the graph
    Graph* g(new Graph());
    Node* n = g->init(startX, startY);
    g->addNode(n);

    // Max number of nodes in graph
    int k;
    cout << "Enter max tree size: ";
    cin >> k;

    // Max distance for a node to travel upon creation
    int deltaQ;
    cout << "Enter distance for each step to travel (1 is a good base): ";
    cin >> deltaQ;

    // Graph->buildRRT()
    vector<Node*> goalPath = g->buildRRT(g, k, deltaQ, goalX, goalY);
    // Path was build from end to start, reverse for pretty printing
    reverse(goalPath.begin(), goalPath.end());

    // Output final path
    cout << "Start: " << "(" << startX << ", " << startY << ")" << endl;
    cout << "Goal: " << "(" << goalX << ", " << goalY << ")" << endl;
    if (goalPath.size() == 0) {
        cout << "Path to goal not found. Please try again." << endl;
        return 0;
    }
    cout << "Node path to goal: " << endl;
    for (auto i : goalPath) {
        cout << "(" << i->getXPos() << ", " << i->getYPos() << ")" << endl;
    }
}
