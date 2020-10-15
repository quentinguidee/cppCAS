#ifndef ABSOLUTE_VALUE_HPP
#define ABSOLUTE_VALUE_HPP

#include "expression.hpp"

class AbsoluteValue : public Expression
{
private:
    Expression &argument;

public:
    AbsoluteValue(Expression &argument) : argument(argument) {}
    ~AbsoluteValue() {}

    std::string toString() override;
    std::string toLaTeX() override;

    bool isPositive() override { return true; };
    bool isZero() override { return argument.isZero(); }
    bool isNegative() override { return false; }

    bool isStrictlyPositive() { return !argument.isZero(); }
    bool isStrictlyNegative() { return false; }

    bool isEven() override { return argument.isEven(); }
    bool isOdd() override { return argument.isOdd(); }
};

#endif /* ABSOLUTE_VALUE_HPP */
