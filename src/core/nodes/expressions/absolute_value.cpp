#include "absolute_value.hpp"

std::string AbsoluteValue::toString()
{
    return "|" + argument.toString() + "|";
}

std::string AbsoluteValue::toLaTeX()
{
    return "\\left\\mid" + argument.toLaTeX() + "\\right\\mid";
}
