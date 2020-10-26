#include "imaginary.hpp"

std::string Imaginary::toString() const
{
    return value.toString() + "i";
}

std::string Imaginary::toLaTeX() const
{
    return value.toLaTeX() + "i";
}
