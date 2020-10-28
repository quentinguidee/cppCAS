#include "differential.hpp"

Differential::Differential(Expression &argument, Unknown unknown) :
    argument(argument),
    unknown(unknown)
{
}

Differential::Differential(const Differential &differential) :
    argument(*differential.argument.clone()),
    unknown(Unknown(differential.unknown))
{
}

std::string Differential::toString() const
{
    return "d/d" + unknown.toString() + "(" + argument.toString() + ")";
}

std::string Differential::toLaTeX() const
{
    return "\\frac{d}{d" + unknown.toLaTeX() + "}\\left(" + argument.toLaTeX() + "\\right)";
}
