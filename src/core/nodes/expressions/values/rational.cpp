#include "rational.hpp"

Rational::Rational(double value) :
    Real(value)
{
}

Rational::Rational(int value) :
    Real(value)
{
}

Rational::Rational(const Rational &rational) :
    Real(rational.value)
{
}
