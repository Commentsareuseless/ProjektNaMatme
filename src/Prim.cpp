#include "Prim.h"

bool Prim::run(Graph &graph) {
    for ( int i = 0; i < graph.GraphRow(); i++) { //For each Node
        unsigned id = getMinCostNodeID(Graph graph);
        graph.GetNode(id).SetVisited();
        for (auto const& e : graph.GetNode(id).GetEdges()) {
            if (!graph.GetNode(e.first).WasVisited())
                if (graph.GetNode(e.first).GetPrevCost() > graph.GetNode(id).GetPrevCost() + graph.GetEdge(e.second).GetCost())
                    graph.GetNode(e.first).SetPrevID(id);
                    graph.GetNode(e.first).SetPrevCost(graph.GetNode(id).GetPrevCost() + graph.GetEdge(e.second).GetCost());
        }
    }
    for ( int i = 0; i < graph.GraphRow(); i++)
        if (graph.GetNode(i).GetPrevCost() == UINT32_MAX)
            return false;
    return true;
}

unsigned Prim::getMinCostNodeID(Graph graph) {
    unsigned min = UINT32_MAX, id;

    for (int i = 0; i < graph.GraphRow(); i++) { //For each Node
        if (!graph.GetNode(i).WasVisited() && !graph.GetNode(i).IsPrevCostWorse(min)) {
            min = graph.GetNode(i).GetPrevCost();
            id = i;
        }
    }
    return id;
}