#ifndef OPPOSITE_HPP
#define OPPOSITE_HPP

#include "expression.hpp"

class Opposite : public Expression
{
private:
    Expression &argument;

public:
    Opposite(Expression &argument) : argument(argument) {}
    ~Opposite() {}

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override { return argument.isNegative(); };
    bool isZero() const override { return argument.isZero(); }
    bool isNegative() const override { return argument.isPositive(); }

    bool isStrictlyPositive() const { return argument.isStrictlyNegative(); }
    bool isStrictlyNegative() const { return argument.isStrictlyPositive(); }

    bool isEven() const override { return argument.isEven(); }
    bool isOdd() const override { return argument.isOdd(); }
};

#endif /* OPPOSITE_HPP */
