#ifndef POWER_HPP
#define POWER_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"

class Power : public Expression
{
private:
    Expression &base;
    Expression &power;

public:
    Power(Expression &base, Expression &power);
    Power(const Power &power);
    ~Power() {}

    Expression *simplified() const override;

    Expression *clone() const override { return new Power(*this); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override;
    bool isZero() const override { return base.isZero(); }
    bool isNegative() const override;

    bool isOne() const override { throw TODO(); }

    bool isEven() const override { return false; }  // TODO
    bool isOdd() const override { return false; }   // TODO
};

#endif /* POWER_HPP */
