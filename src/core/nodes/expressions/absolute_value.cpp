#include "absolute_value.hpp"

#include "opposite.hpp"

AbsoluteValue::AbsoluteValue(Expression &argument) :
    argument(argument)
{
}

AbsoluteValue::AbsoluteValue(const AbsoluteValue &absoluteValue) :
    argument(*absoluteValue.argument.clone())
{
}

std::string AbsoluteValue::toString() const
{
    return "|" + argument.toString() + "|";
}

std::string AbsoluteValue::toLaTeX() const
{
    return "\\left\\mid" + argument.toLaTeX() + "\\right\\mid";
}

Expression *AbsoluteValue::opposite() const
{
    return argument.isStrictlyPositive() ? new Opposite(argument) : &argument;
}
