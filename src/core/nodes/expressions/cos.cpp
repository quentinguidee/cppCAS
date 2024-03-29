#include "cos.hpp"

#include "multiplication.hpp"
#include "opposite.hpp"
#include "sin.hpp"

Cos::Cos(Expression &argument) :
    argument(argument)
{
}

Cos::Cos(const Cos &cos) :
    argument(*cos.argument.clone())
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

Expression *Cos::_differentiated(Unknown unknown) const
{
    Expression *diff = argument.differentiated(unknown);
    Opposite *opposite = new Opposite(*new Sin(argument));
    return new Multiplication({*diff, *opposite});
}
