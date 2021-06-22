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
#include "Debug.hpp"

#include <iostream>

bool GraphBuilder::CreateGraphFromTxt(const std::string& path, Graph& out_graphToFill)
{
    std::ifstream fileToParse{path};
    std::string readLine{};

    unsigned matrixRow{0}, matrixCol{0};
    constexpr char matrixBeginChar = '[';
    constexpr char matrixEndChar = ']';
    constexpr char separator = ' ';

    if (!fileToParse)
    {
        LOG_error("Could not open file! (most likely doesn't exist)");
        return false;
    }

    while (ReadNextLine(fileToParse, readLine))
    {
        if (IsComment(readLine)) { continue; }

        for (auto& character : readLine)
        {
            switch (character)
            {
            case matrixBeginChar:
                continue;
                break;

            case matrixEndChar:
                continue;
                break;

            case '0':
                if (matrixRow == 0)
                {
                    out_graphToFill.AddNode();
                }
                break;

            case '1':
                
                break;

            default:
                LOG_error("Inapropriate syntax");
                return false;
                break;
            }

            matrixCol = 0;
        }
        ++matrixRow;
    }

    fileToParse.close();
}

bool GraphBuilder::ReadNextLine(
    std::ifstream& file,
    std::string& out_readLine)
{
    if(file)
    {
        std::getline(file, out_readLine);
        return true;
    }
    return false;
}

bool GraphBuilder::IsComment(const std::string& textLine)
{
    if (textLine[0] == commentCharacter) return true;

    return false;
}