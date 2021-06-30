#include "GraphBuilder.hpp"
#include "Debug.hpp"

#include <iostream>
#include <string>

bool GraphBuilder::CreateGraphFromTxt(const std::string& path, Graph& out_graphToFill)
{
    std::ifstream fileToParse{ path };
    std::string readLine{};

    unsigned matrixRow{ 0 }, matrixCol{ 0 };
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

bool GraphBuilder::CreateGraphFromEdges(const std::string& path, Graph& graph)
{
    std::ifstream fileToParse{ path };

    if (!fileToParse)
    {
        LOG_error("Could not open file! (most likely doesn't exist)");
        return false;
    }

    int N;
    fileToParse >> N;
    std::string root;
    fileToParse >> root;
    std::string tmp1, tmp2;
    int tmp3;

    for (int i = 0; i < N; i++) {
        fileToParse >> tmp1;
        fileToParse >> tmp2;
        fileToParse >> tmp3;
        if (graph.names.count(tmp1) == 0) {
            graph.AddNode();
            graph.names.insert(std::pair<std::string, unsigned>(tmp1, Node::GetLastID()));
        }
        if (graph.names.count(tmp2) == 0) {
            graph.AddNode();
            graph.names.insert(std::pair<std::string, unsigned>(tmp2, Node::GetLastID()));
        }
        graph.ConnectNodes(graph.names.at(tmp1), graph.names.at(tmp2), tmp3);
    }
    fileToParse.close();
    unsigned id = graph.names.at(root);
    graph.GetNode(id).SetPrevID(0);
    graph.GetNode(id).SetPrevCost(0);
    graph.GetNode(id).SetRoot();

    return true;
}

bool GraphBuilder::ReadNextLine(
    std::ifstream& file,
    std::string& out_readLine)
{
    if (file)
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