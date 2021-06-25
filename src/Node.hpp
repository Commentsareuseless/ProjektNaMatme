#pragma once

#include <vector>

class Node
{
public:
    Node() { ID = idGenerator++; }

    unsigned GetID() const { return ID; }

    void SetVisited()   { wasVisitedFlag = true; }
    void SetUnvisited() { wasVisitedFlag = false; }
    bool WasVisited() const { return wasVisitedFlag; }

    // Is this even useful for sth ? xD
    // unsigned NodeDegree() {return neighbours.size(); }

    ~Node() = default;
private:
    static unsigned idGenerator;

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