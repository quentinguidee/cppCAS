#include "integer.hpp"

std::string Integer::toString() const
{
    return std::to_string(value);
}

std::string Integer::toLaTeX() const
{
    return toString();
}

Expression *Integer::absoluteValue() const
{
    if (isPositive())
    {
        return &self();
    }
    return opposite();
}
