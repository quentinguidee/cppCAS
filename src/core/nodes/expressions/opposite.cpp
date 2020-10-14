#include "opposite.hpp"

Opposite::Opposite(Expression &argument) : argument(argument)
{
}

std::string Opposite::toString()
{
    return "-" + argument.toString();
}

std::string Opposite::toLaTeX()
{
    return "-" + argument.toLaTeX();
}
