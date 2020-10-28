#include "sin.hpp"

#include "cos.hpp"
#include "multiplication.hpp"

Sin::Sin(Expression &argument) :
    argument(argument)
{
}

Sin::Sin(const Sin &sin) :
    argument(*sin.argument.clone())
{
}

std::string Sin::toString() const
{
    return "sin(" + argument.toString() + ")";
}

std::string Sin::toLaTeX() const
{
    return "\\sin{(" + argument.toLaTeX() + ")}";
}

Expression *Sin::_differentiated(Unknown unknown) const
{
    Expression *diff = argument.differentiated(unknown);
    Cos *cos = new Cos(argument);
    return new Multiplication({*diff, *cos});
}
