#ifndef INTEGRAL_HPP
#define INTEGRAL_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"
#include "values/unknown.hpp"

class Integral : public Expression
{
private:
    Unknown unknown;
    Expression &argument;

public:
    Integral(Expression &argument, Unknown unknown);
    Integral(const Integral &integral);
    ~Integral() {}

    Expression *clone() const override { return new Integral(*this); }

    Expression *simplified() const override { return argument.integrated(unknown); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* INTEGRAL_HPP */
