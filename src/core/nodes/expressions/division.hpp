#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "expression.hpp"
#include "exceptions/todo.hpp"

class Division : public Expression
{
private:
    Expression &numerator;
    Expression &denominator;

public:
    Division(Expression &numerator, Expression &denominator) : numerator(numerator), denominator(denominator) {}
    ~Division() {}

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override;
    bool isZero() const override;
    bool isNegative() const override;

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }
};

#endif /* DIVISION_HPP */
