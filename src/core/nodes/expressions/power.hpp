#ifndef POWER_HPP
#define POWER_HPP

#include "expression.hpp"

class Power : public Expression
{
private:
    Expression &base;
    Expression &power;

public:
    Power(Expression &base, Expression &power) : base(base), power(power) {}
    ~Power() {}

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override;
    bool isZero() const override { return base.isZero(); }
    bool isNegative() const override;

    bool isEven() const override { return false; } // TODO
    bool isOdd() const override { return false; }  // TODO
};

#endif /* POWER_HPP */
