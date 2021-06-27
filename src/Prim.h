#pragma once

#include "Graph.hpp"

class Prim {
public:
    static bool run(Graph& graph);
    static std::vector<unsigned> getIDsOfEdgesNotInMST(Graph&);
    static void printEdgesNotInMST(Graph&);

private:
    static unsigned getMinCostNodeID(Graph& graph);
};

