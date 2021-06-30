#pragma once

#include <string>
#include <fstream>

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

    static bool CreateGraphFromEdges(
        const std::string& path,
        Graph& out_graphToFill);

private:
    GraphBuilder() = delete;
    GraphBuilder(GraphBuilder&) = delete;
    GraphBuilder(GraphBuilder&&) = delete;

    static bool ReadNextLine(std::ifstream& file, std::string& out_readLine);
    static bool IsComment(const std::string& textLine);

    static constexpr char commentCharacter = '#';
};
