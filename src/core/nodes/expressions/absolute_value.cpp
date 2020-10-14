#include "absolute_value.hpp"

AbsoluteValue::AbsoluteValue(Expression &argument) : argument(argument)
{
}

AbsoluteValue::~AbsoluteValue()
{
}

std::string AbsoluteValue::ToString()
{
    return "|" + argument.ToString() + "|";
}

std::string AbsoluteValue::ToLaTeX()
{
    return "\\left\\mid" + argument.ToLaTeX() + "\\right\\mid";
}
