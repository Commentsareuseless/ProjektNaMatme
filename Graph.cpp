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

void Graph::AddNode()
{
    listOfNodes.push_back(Node());
}

void Graph::AddNodeWithNeighbours(const NodeVec& neighbours)
{
    Node newNode{};

    for (auto& nbr : neighbours)
    {
        newNode.AddNeighbour(nbr.GetID());
    }

    AddNode(std::move(newNode));
}

void Graph::AddNodes(NodeVec& nodes)
{
    listOfNodes.reserve(nodes.size());

    auto iter = listOfNodes.begin();
    auto listSize = listOfNodes.size();

    listOfNodes.insert(iter + listSize, nodes.begin(), nodes.end());

    // Debug
    // int i = 0;
    // for (auto& nod : listOfNodes)
    // {
    //     printf("Element nr: %d\t %d\n", i, nod.GetID());
    //     ++i;
    // }
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
