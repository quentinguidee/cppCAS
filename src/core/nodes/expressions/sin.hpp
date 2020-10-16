#ifndef SIN_HPP
#define SIN_HPP

#include "expression.hpp"
#include "exceptions/todo.hpp"

class Sin : public Expression
{
private:
    Expression &argument;

public:
    Sin(Expression &argument) : argument(argument) {}
    ~Sin() {}

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* SIN_HPP */
