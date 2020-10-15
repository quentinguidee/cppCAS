#include "integer.hpp"

std::string Integer::toString()
{
    return std::to_string(value);
}

std::string Integer::toLaTeX()
{
    return toString();
}
