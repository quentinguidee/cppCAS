#include "tan.hpp"

#include "cos.hpp"
#include "division.hpp"
#include "sin.hpp"

std::string Tan::toString() const
{
    return "tan(" + argument.toString() + ")";
}

std::string Tan::toLaTeX() const
{
    return "\\tan{(" + argument.toLaTeX() + ")}";
}

Expression *Tan::differentiated(Unknown unknown) const
{
    Division *division = new Division(
        *new Sin(argument),
        *new Cos(argument));

    return division->differentiated(unknown);
}
