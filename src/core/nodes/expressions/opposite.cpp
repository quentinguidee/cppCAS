#include "opposite.hpp"

Opposite::Opposite(Expression &argument) : argument(argument)
{
}

std::string Opposite::ToString()
{
    return "-" + argument.ToString();
}

std::string Opposite::ToLaTeX()
{
    return "-" + argument.ToLaTeX();
}
