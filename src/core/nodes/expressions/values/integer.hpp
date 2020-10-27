#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <cmath>

#include "../expression.hpp"
#include "rational.hpp"

class Integer : public Rational
{
public:
    Integer(int value) : Rational(value) {}
    ~Integer() {}

    std::string toString() const override { return std::to_string((int)round(value)); }
    std::string toLaTeX() const override { return std::to_string((int)round(value)); }

    Rational toRational() const { return Rational(value); }

    Expression *opposite() const override { return new Integer(-value); }
    Expression *differentiated(Unknown unknown) const override { return new Integer(0); }

    Integer operator=(int value) const { return Integer(value); }
};

#endif /* INTEGER_HPP */
