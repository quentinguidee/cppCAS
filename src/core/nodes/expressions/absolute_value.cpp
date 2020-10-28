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

Expression *AbsoluteValue::simplified() const
{
    if (argument.isPositive())
    {
        return argument.clone();
    }
    return argument._absoluteValue();
}

std::string AbsoluteValue::toString() const
{
    return "|" + argument.toString() + "|";
}

std::string AbsoluteValue::toLaTeX() const
{
    return "\\left\\mid" + argument.toLaTeX() + "\\right\\mid";
}

Expression *AbsoluteValue::_opposite() const
{
    return argument.isStrictlyPositive() ? new Opposite(argument) : &argument;
}
