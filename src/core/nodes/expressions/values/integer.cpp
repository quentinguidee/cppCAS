#include "integer.hpp"

std::string Integer::toString() const
{
    return std::to_string(value);
}

std::string Integer::toLaTeX() const
{
    return toString();
}
