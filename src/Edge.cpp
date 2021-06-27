#include "Edge.h"

unsigned Edge::idGenerator = 0;

void Edge::print() {
    LOG_debug("ID: " + std::to_string(this->GetID()) + " node1: " + std::to_string(this->GetNodeID1()) + " node2: " + std::to_string(this->GetNodeID2()));
}
