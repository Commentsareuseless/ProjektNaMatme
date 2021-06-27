#pragma once

#include "Node.hpp"
#include "Edge.h"

using NodeVec = std::vector<Node>;
using EdgeVec = std::vector<Edge>;

class Graph
{
public:

    Graph() = default;
    Graph(Graph&) = delete;
    Graph(NodeVec&& initialNodes);

    void AddNode();
    //void AddNode(Node&& node) { listOfNodes.push_back(node); }
    void AddNodes(NodeVec& nodes);

    void ConnectNodes(unsigned ID1, unsigned ID2, unsigned cost = 1);

    Node& GetNode(unsigned ID);
    Node& FirstNode();
    Node& LastNode();

    Edge& GetEdge(unsigned ID);

    unsigned GraphRow() { return listOfNodes.size(); }
    unsigned GetNumberOfEdges() { return edges.size(); }

private:
    unsigned GetCostOfConnection(unsigned ID1, unsigned ID2);

    EdgeVec edges{};
    NodeVec listOfNodes{};
};

