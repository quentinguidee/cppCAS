#include "absolute_value.hpp"

std::string AbsoluteValue::toString() const
{
    return "|" + argument.toString() + "|";
}

std::string AbsoluteValue::toLaTeX() const
{
    return "\\left\\mid" + argument.toLaTeX() + "\\right\\mid";
}
