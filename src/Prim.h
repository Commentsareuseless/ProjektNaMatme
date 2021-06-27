#pragma once

#include "Graph.hpp"

class Prim {
    static bool run(Graph& graph);

private:
    static unsigned getMinCostNodeID(Graph& graph);
};

