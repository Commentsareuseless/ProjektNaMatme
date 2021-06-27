#include <cstdio>

#include "Graph.hpp"
#include "Debug.hpp"


int main()
{
    NodeVec nodz = {Node(), Node(), Node()};

    LOG_error("Errors work!");
    LOG_info("Info works!");
    LOG_debug("debug works!");

    Graph graf{};

    graf.AddNode();

    graf.AddNodes(nodz);
}