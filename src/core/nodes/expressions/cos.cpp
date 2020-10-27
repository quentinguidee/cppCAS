#include "cos.hpp"

#include "multiplication.hpp"
#include "opposite.hpp"
#include "sin.hpp"

Cos::Cos(Expression &argument) :
    argument(argument)
{
}

std::string Cos::toString() const
{
    return "cos(" + argument.toString() + ")";
}

std::string Cos::toLaTeX() const
{
    return "\\cos{(" + argument.toLaTeX() + ")}";
}

Expression *Cos::differentiated(Unknown unknown) const
{
    Expression *diff = argument.differentiated(unknown);
    Opposite *opposite = new Opposite(*new Sin(argument));
    return new Multiplication({*diff, *opposite});
}
