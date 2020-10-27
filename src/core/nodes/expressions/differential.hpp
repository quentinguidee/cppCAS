#ifndef DIFFERENTIAL_HPP
#define DIFFERENTIAL_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"
#include "values/unknown.hpp"

class Differential : public Expression
{
private:
    Unknown unknown;
    Expression &argument;

public:
    Differential(Expression &argument, Unknown unknown);
    ~Differential() {}

    Expression *simplified() const override { return argument.differentiated(unknown); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* DIFFERENTIAL_HPP */
