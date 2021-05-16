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
    static Graph&& CreateGraphFromTxt(const std::string& path);

private:
    GraphBuilder() = delete;
    GraphBuilder(GraphBuilder&) = delete;
    GraphBuilder(GraphBuilder&&) = delete;

    static std::string ReadNextLine(std::ifstream& file);
    static bool IsComment(const std::string& textLine);

};
