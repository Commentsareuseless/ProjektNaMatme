/**
 * @file Graph.cpp
 * @author The Drim Matma Tim
 * @brief Representatnion of graph
 * @version 0.1
 * @date 2021-05-15
 *
 * @copyright Copyright (c) 2021
 */

#include "Graph.hpp"
#include "Debug.hpp"

#include <utility>
#include <cstdio>
#include <iostream>

Graph::Graph(NodeVec&& initialNodes)
{
    listOfNodes = std::move(initialNodes);
}

/**
 * @brief Creates generic node, with next available ID
 *        and no neighbours
 */
void Graph::AddNode()
{
    listOfNodes.push_back(Node());
}

void Graph::AddNodes(NodeVec& nodes)
{
    listOfNodes.reserve(nodes.size());

    auto iter = listOfNodes.begin();
    auto listSize = listOfNodes.size();

    listOfNodes.insert(iter + listSize, nodes.begin(), nodes.end());
}

/**
 * @brief Connection means that edge is added to list of all edges
 *
 * @param ID1 ID of one node
 * @param ID2 ID of another node
 * @param cost "weight" of edge
 */
void Graph::ConnectNodes(unsigned ID1, unsigned ID2, unsigned cost)
{
    if (ID1 == ID2)
    {
        LOG_error("Given IDs are the same :(");
        return;
    }

    if(DoesConnectionExist(ID1, ID2))
    {
        LOG_error("Connection already exist! ID1=" << ID1 << " ID2=" << ID2);
        return;
    }

    edges.push_back(Edge(ID1, ID2, cost));
}

Node& Graph::GetNode(unsigned ID)
{
    for(auto& node : listOfNodes)
    {
        if(node.GetID() == ID)
        {
            return node;
        }
    }
    LOG_error("GetNode(): Invalid ID");
    return *listOfNodes.end();
}

Graph::Edge::Edge(unsigned _ID1, unsigned _ID2, unsigned _cost) :
    node1(_ID1), node2(_ID2), cost(_cost)
{}

bool Graph::DoesConnectionExist(unsigned ID1, unsigned ID2)
{
    for(auto& edge : edges)
    {
        if(edge.node1 == ID1 && edge.node2 == ID2)
            return true;

        if(edge.node1 == ID2 && edge.node2 == ID1)
            return true;
    }
    return false;
}
