#include <gtest/gtest.h>
#include <string>

#define private public
#include "../src/Edge.h"
#include "../src/Graph.h"
#include "../src/Node.h"

using namespace std;

class test_rrt : public ::testing::Test
{
};

// Forward declaration of helpers
Graph *mkgraph();

// Tests

TEST_F(test_rrt, rrt_GraphTest)
{
    Graph *graph = mkgraph();
    vector<Node *> nodes = graph->getNodes();
    ASSERT_EQ(nodes[0]->data, "n");
    ASSERT_EQ(nodes[nodes.size() - 1]->data, "g");
}

TEST_F(test_rrt, rrt_InputTest) {
    int startX = 1;
    int startY = 2;
    int goalX = 7;
    int goalY = 8;

    // Initialize the graph
    Graph* g(new Graph(startX, startY));

    // Max number of nodes in graph
    int k = 500;
    // Max distance for a node to travel upon creation
    int deltaQ = 1;

    // Graph->buildRRT()
    vector<Node*> goalPath = g->buildRRT(g, k, deltaQ, goalX, goalY);

    // This test really just automates inputs
    // The algorithm is non-deterministic, so it may fail often
    ASSERT_GT(goalPath.size(), 0);
}

// Helpers
Graph *mkgraph()
{
    Graph *ret(new Graph(0, 0));
    Node *a(new Node("a"));
    Node *b(new Node("b"));
    Node *c(new Node("c"));
    Node *d(new Node("d"));
    Node *e(new Node("e"));
    Node *f(new Node("f"));
    Node *g(new Node("g"));

    Edge *ab(new Edge(a, b));
    Edge *ac(new Edge(a, c));
    Edge *bc(new Edge(b, c));
    Edge *ae(new Edge(a, e));
    Edge *ce(new Edge(c, e));
    Edge *cd(new Edge(c, d));
    Edge *dg(new Edge(d, g));
    Edge *eg(new Edge(e, g));
    Edge *df(new Edge(d, f));
    Edge *fb(new Edge(f, b));

    ret->addNode(a);
    ret->addNode(b);
    ret->addNode(c);
    ret->addNode(d);
    ret->addNode(e);
    ret->addNode(f);
    ret->addNode(g);

    ret->addEdge(ab);
    ret->addEdge(ac);
    ret->addEdge(bc);
    ret->addEdge(ae);
    ret->addEdge(ce);
    ret->addEdge(cd);
    ret->addEdge(dg);
    ret->addEdge(eg);
    ret->addEdge(df);
    ret->addEdge(fb);

    return ret;
}