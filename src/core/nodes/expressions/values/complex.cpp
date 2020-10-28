#include "complex.hpp"

#include "../addition.hpp"
#include "../division.hpp"
#include "../power.hpp"
#include "integer.hpp"

Complex::Complex(Real real, Imaginary imaginary) :
    real(real),
    imaginary(imaginary)
{
}

Complex::Complex(const Complex &complex) :
    real(Real(complex.real)),
    imaginary(Imaginary(complex.imaginary))
{
}

std::string Complex::toString() const
{
    if (imaginary.isRealComponentNegative())
    {
        return real.toString() + imaginary.toString();
    }
    else if (imaginary.isRealComponentZero())
    {
        return real.toString();
    }
    else if (real.isZero())
    {
        return imaginary.toString();
    }
    return real.toString() + "+" + imaginary.toString();
}

std::string Complex::toLaTeX() const
{
    if (imaginary.isRealComponentNegative())
    {
        return real.toLaTeX() + imaginary.toLaTeX();
    }
    else if (imaginary.isRealComponentZero())
    {
        return real.toLaTeX();
    }
    else if (real.isZero())
    {
        return imaginary.toLaTeX();
    }
    return real.toLaTeX() + "+" + imaginary.toLaTeX();
}

Complex Complex::conjuguated() const
{
    return Complex(real, dynamic_cast<Imaginary &>(*imaginary.opposite()));
}

Expression *Complex::_modulus() const
{
    return new Power(
        *new Addition{
            *new Power(*real.clone(), *new Integer(2)),
            *new Power(*imaginary.getReal().clone(), *new Integer(2))},
        *new Division(*new Integer(1), *new Integer(2)));
}
