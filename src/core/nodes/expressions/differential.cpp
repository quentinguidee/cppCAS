#include "differential.hpp"

std::string Differential::toString() const
{
    return "d/d" + unknown.toString() + "(" + argument.toString() + ")";
}

std::string Differential::toLaTeX() const
{
    return "\\frac{d}{d" + unknown.toLaTeX() + "}\\left(" + argument.toLaTeX() + "\\right)";
}
