#pragma once

class Edge {
public:
    Edge(unsigned _ID1, unsigned _ID2, unsigned _cost) { ID = idGenerator++; nodeID1 = _ID1; nodeID2 = _ID2; cost = _cost;}

    unsigned GetID() const { return ID; }

    void SetMST()   { inMST = true; }
    bool IsInMST() const { return inMST; }

    unsigned GetNodeID1() { return nodeID1; }
    unsigned GetNodeID2() { return nodeID2; }
    unsigned GetCost() { return cost; }

    unsigned GetLastID() { return idGenerator - 1; }

    ~Node() = default;
private:
    static unsigned idGenerator;
    unsigned nodeID1;
    unsigned nodeID2;
    unsigned cost;

    /**
     * @brief This is "built in" indicator, to check
     *        if *edge* is part of MST at the end of algorithm */
    bool inMST = false;
    /**
     * @brief ID should be used to distinguish *edges*, NOT pointer or reference plz */
    unsigned ID;
};
