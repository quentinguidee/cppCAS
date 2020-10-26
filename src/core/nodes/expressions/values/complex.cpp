#include "complex.hpp"

std::string Complex::toString() const
{
    return real.toString() + "+" + imaginary.toString();
}

std::string Complex::toLaTeX() const
{
    return real.toLaTeX() + "+" + imaginary.toLaTeX();
}
