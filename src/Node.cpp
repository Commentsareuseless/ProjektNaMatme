#include "Node.hpp"
#include "Debug.hpp"

#include <string>

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
