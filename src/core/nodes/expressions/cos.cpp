#include "cos.hpp"

#include "multiplication.hpp"
#include "sin.hpp"
#include "opposite.hpp"

std::string Cos::toString() const
{
    return "cos(" + argument.toString() + ")";
}

std::string Cos::toLaTeX() const
{
    return "\\cos{(" + argument.toLaTeX() + ")}";
}

Expression *Cos::differentiated(Unknown &unknown) const
{
    Expression *diff = argument.differentiated(unknown);
    Opposite *opposite = new Opposite(*new Sin(argument));
    return new Multiplication({*diff, *opposite});
}
