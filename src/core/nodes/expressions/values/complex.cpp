#include "complex.hpp"

Complex::Complex(Real real, Imaginary imaginary) :
    real(real),
    imaginary(imaginary)
{
}

std::string Complex::toString() const
{
    return real.toString() + "+" + imaginary.toString();
}

std::string Complex::toLaTeX() const
{
    return real.toLaTeX() + "+" + imaginary.toLaTeX();
}
