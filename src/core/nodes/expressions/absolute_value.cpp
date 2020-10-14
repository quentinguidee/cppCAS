#include "absolute_value.hpp"

AbsoluteValue::AbsoluteValue(Expression &argument) : argument(argument)
{
}

std::string AbsoluteValue::toString()
{
    return "|" + argument.toString() + "|";
}

std::string AbsoluteValue::toLaTeX()
{
    return "\\left\\mid" + argument.toLaTeX() + "\\right\\mid";
}
