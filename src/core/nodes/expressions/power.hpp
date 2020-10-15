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

    std::string toString() override;
    std::string toLaTeX() override;

    bool isPositive() override;
    bool isZero() override { return base.isZero(); }
    bool isNegative() override;

    bool isEven() override { return false; } // TODO
    bool isOdd() override { return false; }  // TODO
};

#endif /* POWER_HPP */
