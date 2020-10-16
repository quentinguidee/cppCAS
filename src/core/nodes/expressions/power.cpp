#include "power.hpp"

std::string Power::toString() const
{
    return base.toString() + "^" + power.toString();
}

std::string Power::toLaTeX() const
{
    return "{" + base.toLaTeX() + "}^{" + power.toLaTeX() + "}";
}

bool Power::isPositive() const
{
    if (base.isPositive())
    {
        return true;
    }
    else if (base.isNegative() && power.isEven())
    {
        return true;
    }
    return false;
}

bool Power::isNegative() const
{
    if (isZero())
    {
        return true;
    }
    else if (base.isNegative() && power.isOdd())
    {
        return true;
    }
    return false;
}
