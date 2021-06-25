#pragma once

#include "Node.hpp"

using NodeVec = std::vector<Node>;

class Graph
{
public:

    Graph() = default;
    Graph(Graph&) = delete;
    Graph(NodeVec&& initialNodes);

    void AddNode();
    void AddNode(Node&& node) { listOfNodes.push_back(node); }
    void AddNodes(NodeVec& nodes);

    void ConnectNodes(unsigned ID1, unsigned ID2, unsigned cost = 1);

    Node& GetNode(unsigned ID);
    Node& FirstNode();
    Node& LastNode();

    unsigned GraphRow() {return listOfNodes.size(); }
private:
    struct Edge
    {
        Edge(unsigned, unsigned , unsigned);

        unsigned node1, node2, cost;
    };
    using EdgeVec = std::vector<Edge>;

    bool DoesConnectionExist(unsigned ID1, unsigned ID2);

    EdgeVec edges{};
    NodeVec listOfNodes{};
};

