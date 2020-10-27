#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include "real.hpp"

class Rational : public Real
{
public:
    Rational(double value);
    Rational(int value);
    ~Rational() {}

    Real toReal() const { return Real(value); }

    Rational operator=(double value) const { return Rational(value); }
};

#endif /* RATIONAL_HPP */
