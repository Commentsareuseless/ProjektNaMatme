#include <cstdio>

#include "Graph.hpp"
#include "Debug.hpp"
#include "Prim.h"


int main()
{
    LOG_error("Errors work!");
    LOG_info("Info works!");
    LOG_debug("debug works!");

    Graph graph{};

    /* test input

     0 --(2)--1
     |      / |
    (1)  (3) (1)
     | /      |
     2        3

     root 0

     */
    graph.AddNode();
    graph.AddNode();
    graph.AddNode();
    graph.AddNode();
    graph.ConnectNodes(0, 1, 2);
    graph.ConnectNodes(1, 3, 1);
    graph.ConnectNodes(0, 2, 1);
    graph.ConnectNodes(1, 2, 3);
    graph.printEdges();
    graph.printNodes();
    graph.GetNode(0).SetPrevID(0);
    graph.GetNode(0).SetPrevCost(0);
    Prim::run(graph);
    Prim::printEdgesNotInMST(graph); //expected edge 3 : node1 1 : node2 2 : cost 3
    graph.printEdges();
    graph.printNodes();
}