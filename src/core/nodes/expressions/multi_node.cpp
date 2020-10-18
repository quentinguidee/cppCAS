#include "multi_node.hpp"

#include <vector>
#include <iostream>
#include <functional>

std::string MultiNode::toString() const
{
    std::string string = "";
    for (int i = 0; i < children.size() - 1; i++)
    {
        string += children[i].get().toString();
        string += symbol;
    }
    string += children.back().get().toString();
    return string;
}

std::string MultiNode::toLaTeX() const
{
    std::string string = "";
    for (int i = 0; i < children.size() - 1; i++)
    {
        string += children[i].get().toLaTeX();
        string += latexSymbol;
    }
    string += children.back().get().toLaTeX();
    return string;
}
