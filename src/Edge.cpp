#include "Edge.h"
#include "Debug.hpp"

#include <string>

unsigned Edge::idGenerator = 0;

void Edge::print() {
    LOG_debug("ID: " + std::to_string(this->GetID()) + " node1: " + std::to_string(this->GetNodeID1()) + " node2: " + std::to_string(this->GetNodeID2()) + " cost: " + std::to_string(this->GetCost()));
}
