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

    std::string toString() override;
    std::string toLaTeX() override;

    bool isPositive() override { return argument.isNegative(); };
    bool isZero() override { return argument.isZero(); }
    bool isNegative() override { return argument.isPositive(); }

    bool isStrictlyPositive() { return argument.isStrictlyNegative(); }
    bool isStrictlyNegative() { return argument.isStrictlyPositive(); }

    bool isEven() override { return argument.isEven(); }
    bool isOdd() override { return argument.isOdd(); }
};

#endif /* OPPOSITE_HPP */
