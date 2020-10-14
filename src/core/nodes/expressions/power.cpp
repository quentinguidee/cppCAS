#include "power.hpp"

Power::Power(Expression &base, Expression &power) : base(base), power(power)
{
}

std::string Power::toString()
{
    return base.toString() + "^" + power.toString();
}

std::string Power::toLaTeX()
{
    return "{" + base.toLaTeX() + "}^{" + power.toLaTeX() + "}";
}
