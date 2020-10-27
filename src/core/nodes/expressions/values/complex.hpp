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
    ~Complex() {}

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* COMPLEX_HPP */
