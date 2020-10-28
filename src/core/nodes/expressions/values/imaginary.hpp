#ifndef IMAGINARY_HPP
#define IMAGINARY_HPP

#include "exceptions/todo.hpp"
#include "real.hpp"
#include "value.hpp"

class Imaginary : public Value
{
private:
    Real value;

public:
    Imaginary(Real value);
    Imaginary(const Imaginary &imaginary);
    ~Imaginary() {}

    Expression *clone() const override { return new Imaginary(*this); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* IMAGINARY_HPP */
