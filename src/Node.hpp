#pragma once

#include <vector>

class Node
{
public:
    Node() { ID = idGenerator++; }

    unsigned GetID() const { return ID; }

    const std::vector<unsigned>& GetNeighbours() const { return neighbours; }

    void AddNeighbour(unsigned ID) { neighbours.push_back(ID); }

    void SetVisited()   { wasVisitedFlag = true; }
    void SetUnvisited() { wasVisitedFlag = false; }
    bool WasVisited() const { return wasVisitedFlag; }

    unsigned NodeDegree() {return neighbours.size(); }

    bool HasNeighbourWithId(unsigned ID);

    ~Node() = default;
private:
    static unsigned idGenerator;

    /**
     * @brief This is "built in" indicator, to check
     *        if node was visited by algorithm
     */
    bool wasVisitedFlag;
    /**
     * @brief ID should be used to distinguish nodes, NOT pointer or reference plz
     */
    unsigned ID;
    /**
     * @brief IDs of all node neighbours, neighbours are stored as ID
     *        to avoid some messy dependencies hehe
     */
    std::vector<unsigned> neighbours{};
};