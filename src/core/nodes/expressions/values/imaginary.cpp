#include "imaginary.hpp"

Imaginary::Imaginary(Real value) :
    value(value)
{
}

Imaginary::Imaginary(const Imaginary& imaginary) :
    value(imaginary.value)
{
}

bool Imaginary::isZero() const
{
    return value.isZero();
}

std::string Imaginary::toString() const
{
    return value.toString() + "i";
}

std::string Imaginary::toLaTeX() const
{
    return value.toLaTeX() + "i";
}

Expression* Imaginary::_modulus() const
{
    return value.absoluteValue();
}
