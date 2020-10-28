#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "exceptions/todo.hpp"
#include "imaginary.hpp"
#include "real.hpp"
#include "value.hpp"

class Complex : public Value
{
private:
    Real real;
    Imaginary imaginary;

public:
    Complex(Real real, Imaginary imaginary);
    Complex(const Complex &complex);
    ~Complex() {}

    Expression *clone() const override { return new Complex(*this); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    Complex conjuguated() const;
    Expression *modulus() const;  // TODO: Make a modulus operator.
};

#endif /* COMPLEX_HPP */
