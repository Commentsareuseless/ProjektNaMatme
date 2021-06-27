#pragma once

#include "Graph.hpp"

class Prim {



    static void run(Graph& graph);

    private:

    static unsigned getMinCostNodeID(Graph graph);
};

