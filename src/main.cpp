#include <cstdio>

#include "Graph.hpp"
#include "Debug.hpp"
#include "Prim.h"
#include "GraphBuilder.hpp"


int main()
{
    Graph graph{};

    GraphBuilder::CreateGraphFromTxt("src/graphData.txt", graph);

    graph.GetNode(0).SetPrevID(0);
    graph.GetNode(0).SetPrevCost(0);
    graph.GetNode(0).SetRoot();
    Prim::run(graph);
    Prim::printEdgesNotInMST(graph);
    graph.printNodes();

    int dummy;
    std::cin >> dummy;
}
