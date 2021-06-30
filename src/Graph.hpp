#pragma once

#include "Node.hpp"
#include "Edge.h"
#include <string>

using NodeVec = std::vector<Node>;
using EdgeVec = std::vector<Edge>;

class Graph
{
public:

    Graph() = default;
    Graph(Graph&) = delete;
    Graph(NodeVec&& initialNodes);

    void AddNode();
    void AddNodes(NodeVec& nodes);

    void ConnectNodes(unsigned ID1, unsigned ID2, unsigned cost = 1);

    Node& GetNode(unsigned ID);
    Edge& GetEdge(unsigned ID);

    unsigned GraphRow() { return listOfNodes.size(); }
    unsigned GetNumberOfEdges() { return edges.size(); }

    void printNodes();
    void printEdges();

    //std::map<std::string, unsigned> names; //Too bad!

    /*std::string GetNodeName(unsigned id) {
        for (auto& e : names)
        {
            if (e.second == id)
                return e.first;
        }
        return "ERR";
    }*/

private:
    unsigned GetCostOfConnection(unsigned ID1, unsigned ID2);

    EdgeVec edges{};
    NodeVec listOfNodes{};
};
