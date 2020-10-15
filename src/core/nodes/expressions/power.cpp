#include "power.hpp"

std::string Power::toString()
{
    return base.toString() + "^" + power.toString();
}

std::string Power::toLaTeX()
{
    return "{" + base.toLaTeX() + "}^{" + power.toLaTeX() + "}";
}

bool Power::isPositive()
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

bool Power::isNegative()
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
