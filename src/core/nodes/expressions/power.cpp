#include "power.hpp"

Power::Power(Expression &base, Expression &power) : base(base), power(power)
{
}

Power::~Power()
{
}

std::string Power::ToString()
{
    return base.ToString() + "^" + power.ToString();
}

std::string Power::ToLaTeX()
{
    return "{" + base.ToLaTeX() + "}^{" + power.ToLaTeX() + "}";
}
