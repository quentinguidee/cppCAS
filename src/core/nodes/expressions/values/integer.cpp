#include "integer.hpp"

Integer::Integer(int value) : value(value)
{
}

std::string Integer::toString()
{
    return std::to_string(value);
}

std::string Integer::toLaTeX()
{
    return toString();
}
