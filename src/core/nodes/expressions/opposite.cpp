#include "opposite.hpp"

std::string Opposite::toString() const
{
    return "-" + argument.toString();
}

std::string Opposite::toLaTeX() const
{
    return "-" + argument.toLaTeX();
}
