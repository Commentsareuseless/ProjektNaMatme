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
    if (GetCostOfConnection(ID1, ID2))
    {
        LOG_error("Edge already exists");
        return;
    }
    edges.push_back(Edge(ID1, ID2, cost));
    GetNode(ID1).BondEdge(Edge::GetLastID(), ID2);
    GetNode(ID2).BondEdge(Edge::GetLastID(), ID1);
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

Edge& Graph::GetEdge(unsigned ID)
{
    for(auto& edge : edges)
    {
        if(edge.GetID() == ID)
        {
            return edge;
        }
    }
    LOG_error("GetEdge(): Invalid ID");
    return *edges.end();
}

unsigned Graph::GetCostOfConnection(unsigned ID1, unsigned ID2) //returns cost, not existence
{
    for(auto edgeID : GetNode(ID1).GetEdgesIDs())
    {
        if(GetEdge(edgeID).GetNodeID1() == ID1 && GetEdge(edgeID).GetNodeID2() == ID2)
            return GetEdge(edgeID).GetCost();

        if(GetEdge(edgeID).GetNodeID1() == ID2 && GetEdge(edgeID).GetNodeID2() == ID1)
            return GetEdge(edgeID).GetCost();
    }
    return 0; //aka false
}
