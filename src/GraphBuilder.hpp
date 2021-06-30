#pragma once

#include <string>
#include <fstream>
#include <string_view>
#include <vector>
#include <bitset>

#include "Graph.hpp"

class GraphBuilder
{
public:
    /**
     * @brief Parse .txt file to produce new graph
     * @param path relative path to file
     * @return Returns empty graph in case of non-existing file
     *          or file with incorrect syntax
     */
    static bool CreateGraphFromTxt(
        const std::string& path,
        Graph& out_graphToFill);

private:
    /**
     * @brief IDK if flags are good idea but
     *        seems nc :)
     */
    enum GBFlags
    {
        START_OF_MATRIX,    /* Begin reading neighbourhood matrix */
        END_OF_MATRIX,      /* End reading neighbourhood matrix */
        ARE_NODES_RDY,      /* Set after first row is read, indicates that nodes should not be changed any more */
        EOM_NOT_FOUND,      /* Error, u forgot ] at the end ? */
        FLAGS_NUM
    };

    GraphBuilder() = delete;
    GraphBuilder(GraphBuilder&) = delete;
    GraphBuilder(GraphBuilder&&) = delete;

    static bool ReadNextLine(std::ifstream& file, std::string& out_readLine);

    static bool IsComment(const std::string& textLine);
    static bool NextToken(const std::string& inStr, std::string& token);
    static unsigned StrRow2VecOfInts(
        const std::string& matrixRow,
        std::vector<int>& rowVals);
    static bool isGraphValid(const std::vector<int>& graphAsVec, unsigned numOfNodes);

    static std::bitset<FLAGS_NUM> flags;

    static constexpr char commentCharacter = '#';
    static constexpr char matrixBeginChar = '[';
    static constexpr char matrixEndChar = ']';
    static constexpr char separator = ' ';
};
