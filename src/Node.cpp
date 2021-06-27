#include "Node.hpp"

unsigned Node::idGenerator = 0;

std::vector<unsigned> Node::GetEdgesIDs()
{
    std::vector<unsigned> IDs{};

    IDs.reserve(edges.size());

    for (auto& edg : edges)
    {
        IDs.push_back(edg.second);
    }

    return IDs;
}

void Node::print() {
    LOG_debug("ID: " + std::to_string(this->GetID()) + " prevID: " + std::to_string(this->GetPrevID()) + " prevCost: " + std::to_string(this->GetPrevCost()));
}