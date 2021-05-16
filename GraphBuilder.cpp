/**
 * @file GraphBuilder.cpp
 * @author The Drim Matma Tim
 * @brief This class parses txt file to create new graph
 * @version 0.1
 * @date 2021-05-16
 * 
 * @copyright Copyright (c) 2021
 */

#include "GraphBuilder.hpp"

#include <iostream>

Graph&& GraphBuilder::CreateGraphFromTxt(const std::string& path)
{
    std::ifstream fileToParse{path};

    if (!fileToParse)
    {
        std::cerr << "[ERROR]\t Could not open file! (most likely doesn't exist)\n ";
    }

    fileToParse.close();
}

std::string GraphBuilder::ReadNextLine(std::ifstream& file)
{
    std::string newLine{};
    std::getline(file, newLine);

    return newLine;
}

bool GraphBuilder::IsComment(const std::string& textLine)
{
    char commentCharacter = '#';

    if (textLine[0] == commentCharacter) return true;

    return false;
}