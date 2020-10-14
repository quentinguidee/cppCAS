#include "integer.hpp"

Integer::Integer(int value) : value(value)
{
}

std::string Integer::ToString()
{
    return std::to_string(value);
}

std::string Integer::ToLaTeX()
{
    return ToString();
}
