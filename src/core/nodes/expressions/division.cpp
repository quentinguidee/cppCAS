#include "division.hpp"

std::string Division::toString() const
{
    return numerator.toString() + "/" + denominator.toString();
}

std::string Division::toLaTeX() const
{
    return "\\frac{" + numerator.toLaTeX() + "}{" + denominator.toLaTeX() + "}";
}

bool Division::isPositive() const
{
    if (numerator.isZero())
    {
        return true;
    }
    else if (numerator.isPositive() && denominator.isPositive())
    {
        return true;
    }
    else if (numerator.isNegative() && denominator.isNegative())
    {
        return true;
    }
    return false;
}

bool Division::isZero() const
{
    return numerator.isZero();
}

bool Division::isNegative() const
{
    if (numerator.isZero())
    {
        return true;
    }
    else if (numerator.isPositive() && denominator.isNegative())
    {
        return true;
    }
    else if (numerator.isNegative() && denominator.isPositive())
    {
        return true;
    }
    return false;
}
