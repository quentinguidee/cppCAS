#ifndef ABSOLUTE_VALUE_HPP
#define ABSOLUTE_VALUE_HPP

#include "expression.hpp"

class AbsoluteValue : public Expression
{
private:
    Expression &argument;

public:
    AbsoluteValue(Expression &argument);
    AbsoluteValue(const AbsoluteValue &absoluteValue);
    ~AbsoluteValue() {}

    Expression *clone() const override { return new AbsoluteValue(*this); }

    Expression *simplified() const override { return argument.absoluteValue(); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override { return true; }
    bool isZero() const override { return argument.isZero(); }
    bool isNegative() const override { return false; }

    bool isStrictlyPositive() const { return !argument.isZero(); }
    bool isStrictlyNegative() const { return false; }

    bool isEven() const override { return argument.isEven(); }
    bool isOdd() const override { return argument.isOdd(); }

    Expression *opposite() const override;
    Expression *absoluteValue() const override { return &self(); }
};

#endif /* ABSOLUTE_VALUE_HPP */
