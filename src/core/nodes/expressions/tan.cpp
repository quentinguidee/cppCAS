#include "tan.hpp"

#include "division.hpp"
#include "sin.hpp"
#include "cos.hpp"

std::string Tan::toString() const
{
    return "tan(" + argument.toString() + ")";
}

std::string Tan::toLaTeX() const
{
    return "\\tan{(" + argument.toLaTeX() + ")}";
}

Expression *Tan::differentiated(Unknown &unknown) const
{
    Sin *numerator = new Sin(argument);
    Cos *denominator = new Cos(argument);
    Division *division = new Division(*numerator, *denominator);
    Expression *div = division->differentiated(unknown);
    return div;
}
