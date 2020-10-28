#include "multi_node.hpp"

#include <iostream>
#include <vector>

MultiNode::MultiNode(char symbol, std::string latexSymbol, std::initializer_list<std::reference_wrapper<Expression>> children) :
    symbol(symbol),
    latexSymbol(latexSymbol),
    children(children)
{
}

MultiNode::MultiNode(const MultiNode &multiNode) :
    symbol(multiNode.symbol),
    latexSymbol(multiNode.latexSymbol),
    children(multiNode.children)
{
}

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
