#include "real.hpp"

#include <cmath>

#include "integer.hpp"

Real::Real(double value) :
    value(value)
{
}
Real::Real(int value) :
    value(value)
{
}

Real::Real(const Real &real) :
    value(real.value)
{
}

Expression *Real::absoluteValue() const
{
    return isPositive() ? &self() : opposite();
}

bool Real::isEven() const
{
    int *ptr_val = toIntIfPossible();
    if (ptr_val == nullptr)
    {
        return false;
    }
    int val = *ptr_val;
    return val % 2 == 0;
}

bool Real::isOdd() const
{
    int *ptr_val = toIntIfPossible();
    if (ptr_val == nullptr)
    {
        return false;
    }
    int val = *ptr_val;
    return val % 2 != 0;
}

int *Real::toIntIfPossible() const
{
    int roundedValue = round(value);
    int *ptr_roundedValue = &roundedValue;
    if (value == roundedValue)
    {
        return ptr_roundedValue;
    }
    return nullptr;
}
