#include "imaginary.hpp"

Imaginary::Imaginary(Real value) :
    value(value)
{
}

std::string Imaginary::toString() const
{
    return value.toString() + "i";
}

std::string Imaginary::toLaTeX() const
{
    return value.toLaTeX() + "i";
}
