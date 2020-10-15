#include "opposite.hpp"

std::string Opposite::toString()
{
    return "-" + argument.toString();
}

std::string Opposite::toLaTeX()
{
    return "-" + argument.toLaTeX();
}
