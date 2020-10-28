#ifndef MODULUS_HPP
#define MODULUS_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"

class Modulus : public Expression
{
private:
    Expression &argument;

public:
    Modulus(Expression &argument);
    Modulus(const Modulus &modulus);
    ~Modulus() {}

    Expression *simplified() const override { return argument._modulus(); }

    Expression *clone() const override { return new Modulus(*this); }

    bool isPositive() const override { return true; }
    bool isZero() const override { return argument.isZero(); }
    bool isNegative() const override { return false; }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* MODULUS_HPP */
