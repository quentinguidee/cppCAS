#include "cos.hpp"

std::string Cos::toString() const
{
    return "cos(" + argument.toString() + ")";
}

std::string Cos::toLaTeX() const
{
    return "\\cos{(" + argument.toLaTeX() + ")}";
}
