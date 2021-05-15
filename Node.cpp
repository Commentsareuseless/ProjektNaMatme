/**
 * @file Node.cpp
 * @author The Drim Matma Tim
 * @brief Graph node representation
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 */

#include "Node.hpp"

unsigned Node::idGenerator = 0;

bool Node::HasNeighbourWithId(unsigned ID)
{
    for (auto& nodeId : neighbours)
    {
        if (nodeId == ID) { return true; }
    }
    return false;
}
