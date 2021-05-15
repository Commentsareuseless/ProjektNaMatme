#pragma once

#include "Node.hpp"

using NodeVec = std::vector<Node>;

class Graph
{
public:

    Graph() = default;
    Graph(NodeVec&& initialNodes);

    /**
     * @brief Generates generic node, with next available ID
     *        and no neighbours
     */
    void AddNode();
    void AddNode(Node&& node) { listOfNodes.push_back(node); }
    void AddNodeWithNeighbours(const NodeVec& neighbours);
    void AddNodes(NodeVec& nodes);

    void ConnectNodes(unsigned ID1, unsigned ID2);

    Node& GetNode(unsigned ID);

    unsigned GraphRow() {return listOfNodes.size(); }
private:

    /**
     * @brief Graph OWMS all nodes, this is why nodes should not
     *        own themselves as neighbours (otherwise there will be mess :()
     */
    NodeVec listOfNodes{};
};

