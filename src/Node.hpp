#pragma once

#include <vector>
#include <map>
#include <limits>

class Node
{
public:
    Node() { ID = idGenerator++; prevID = UINT32_MAX; prevCost = UINT32_MAX;}

    unsigned GetID() const { return ID; }

    void SetVisited()   { wasVisitedFlag = true; }
    void SetUnvisited() { wasVisitedFlag = false; }
    bool WasVisited() const { return wasVisitedFlag; }

    void SetPrevID(unsigned id) { prevID = id; }
    unsigned GetPrevID() { return prevID; }

    void SetPrevCost(unsigned cost) { prevCost = cost; }
    unsigned GetPrevCost() { return prevCost; }
    bool IsPrevCostWorse(unsigned newCost) { return newCost < prevCost?true:false; } //"Worse" because we need better or equal

    void BondEdge(unsigned edgeID, unsigned nodeID) { edges.insert(std::pair<unsigned, unsigned>(nodeID, edgeID)); }

    std::map<unsigned, unsigned> GetEdges() { return edges; } //returns map <nodeID, edgeID>

    std::vector<unsigned> GetEdgesIDs();

    ~Node() = default;
private:
    static unsigned idGenerator;

    unsigned prevID; //TODO: change name, idk how to name it
    unsigned prevCost; //TODO: ^^

    std::map<unsigned, unsigned > edges;

    /**
     * @brief Useful to mark capital of SE :)
     */
    bool isRootFlag;
    /**
     * @brief This is "built in" indicator, to check
     *        if node was visited by algorithm */
    bool wasVisitedFlag;
    /**
     * @brief ID should be used to distinguish nodes, NOT pointer or reference plz */
    unsigned ID;
};