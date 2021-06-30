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

std::bitset<GraphBuilder::FLAGS_NUM> GraphBuilder::flags{};

bool GraphBuilder::CreateGraphFromTxt(const std::string& path, Graph& out_graphToFill)
{
    std::ifstream fileToParse{path};
    std::string readLine{};
    std::vector<int> rowAsNums{};
    std::vector<int> allNodesVec{};
    unsigned numOfCols{0};
    unsigned numOfRow{0};

    if (!fileToParse)
    {
        LOG_error("Could not open file! (most likely doesn't exist)");
        return false;
    }

    while (ReadNextLine(fileToParse, readLine))
    {
        if (IsComment(readLine)) { continue; }

        StrRow2VecOfInts(readLine, rowAsNums);

        allNodesVec.insert(
            allNodesVec.begin() + allNodesVec.size(),
            rowAsNums.begin(),
            rowAsNums.end());

        if(flags.test(START_OF_MATRIX))
        {
            for (auto val : rowAsNums)
            {
                (void)val;
                out_graphToFill.AddNode();
                ++numOfCols;
            }
            flags.reset(START_OF_MATRIX);
        }

        // for (int i{0}; i < rowAsNums.size(); ++i)
        // {
        //     if (rowAsNums[i] != -1 && rowAsNums[i] != 0)
        //     {
        //         out_graphToFill.ConnectNodes(numOfRow, i, rowAsNums[i]);
        //         LOG_info("Connecting: " << numOfRow << " with " << i + numOfRow << " with cost: " << rowAsNums[i]);
        //     }
        // }

        if(flags.test(END_OF_MATRIX))
        {
            LOG_info("End of matrix detected");
            LOG_info("Got following graph: ");
            for (auto val : allNodesVec)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";

            // return true;
            break;
        }
        ++numOfRow;
    }
    fileToParse.close();

    if (!isGraphValid(allNodesVec, numOfCols))
    {
        LOG_error("Proszę poprawić macierz w pliku txt");
    }

    for (int y(0); y < numOfCols; y++)
    {
        for (int x(0); x < numOfCols; x++)
        {
           if (allNodesVec[x + y * numOfCols] != 0)
           {
               LOG_info("Connecting: " << x << " with " << y << " cost->" << allNodesVec[x + y * numOfCols]);
               out_graphToFill.ConnectNodes(x, y, allNodesVec[x + y * numOfCols]);
           }
        }
    }

    LOG_info("Got following graph(class): ");
    LOG_info("Nodes: " << out_graphToFill.GraphRow());
    LOG_info("Num of edges " << out_graphToFill.GetNumberOfEdges());

    return true;
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

/**
 * @brief Converts string read form txt to vector of matrix values
 * 
 * @return unsigned - number of values written to vector
 */
unsigned GraphBuilder::StrRow2VecOfInts(
    const std::string& matrixRow,
    std::vector<int>& rowVals)
{
    // This stores numbers as chars
    constexpr unsigned maxNumberLength = 4;
    char nums[maxNumberLength] = {0};

    // unsigned numOfValues = 0;
    // int readVal;
    int i = 0;
    std::string token{};
    token.reserve(29);

    rowVals.clear();

    while (NextToken(matrixRow, token))
    {
        if (token.at(0) == matrixBeginChar)
        {
            flags.set(START_OF_MATRIX);
            continue;
        }

        if(token.empty())
        {
            std::cout << "Jest niedobrze :(" << std::endl;
            LOG_info("Jest niedobrze w " << __FILE__ << ":" << __LINE__ << ":(");
            continue;
        }
        rowVals.push_back(std::stoi(token));
        ++i;
    }

    if (token.at(0) == matrixEndChar)
    {
        flags.set(END_OF_MATRIX);
    }
    else
    {
        rowVals.push_back(std::stoi(token));
    }
    return ++i;
}

bool GraphBuilder::NextToken(const std::string& inStr, std::string& token)
{
    static int lastStrChar = 0;
    unsigned spaceGapWidth = 0;

    token.clear();
    LOG_info("Got string |" << inStr << "|");
    for(int i = lastStrChar; i < inStr.size(); ++i)
    {
        if(inStr.at(i) == ' ' && inStr.at(i+1) == ' ')
        {
            spaceGapWidth = 1;
            lastStrChar += 2;
            continue;
        }

        if (inStr.at(i) == ' ')
        {
            token = inStr.substr(lastStrChar, spaceGapWidth);
            lastStrChar = ++i;
            std::cout << "Ret token: *" << token << "*" << std::endl;
            spaceGapWidth = 1;
            return true;
        }
        ++spaceGapWidth;
    }
    token = inStr.substr(lastStrChar, spaceGapWidth);
    std::cout << "xd" <<"Ret token:5 *" << token << "*\n";
    lastStrChar = 0;
    return false;
}

bool GraphBuilder::isGraphValid(const std::vector<int>& graphAsVec, unsigned numOfNodes)
{
    for (int i(0); i < numOfNodes; i++)
    {
        if(0 != graphAsVec[i + i * numOfNodes]) return false;
    }

    for (int x(0); x < numOfNodes; x++)
    {
        for (int y(0); y < numOfNodes; y++)
        {
            if (graphAsVec[x + y * numOfNodes] != graphAsVec[y + x * numOfNodes])
            {
                LOG_error("Macierz nie jest symetryczna wzgl. diagoanali");
                return false;
            }
        }
    }
    return true;
}
