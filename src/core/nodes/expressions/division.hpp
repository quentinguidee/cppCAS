#ifndef DIVISION_HPP
#define DIVISION_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"

class Division : public Expression
{
private:
    Expression &numerator;
    Expression &denominator;

public:
    Division(Expression &numerator, Expression &denominator);
    Division(const Division &division);
    ~Division() {}

    Expression *clone() const override { return new Division(*this); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override;
    bool isZero() const override;
    bool isNegative() const override;

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }
};

#endif /* DIVISION_HPP */
