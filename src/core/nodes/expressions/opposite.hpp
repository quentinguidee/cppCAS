#ifndef OPPOSITE_HPP
#define OPPOSITE_HPP

#include "expression.hpp"
#include "values/unknown.hpp"

class Opposite : public Expression
{
private:
    Expression &argument;

public:
    Opposite(Expression &argument);
    Opposite(const Opposite &opposite);
    ~Opposite() {}

    Expression *clone() const override { return new Opposite(*this); }

    Expression *simplified() const override { return argument._opposite(); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override { return argument.isNegative(); }
    bool isZero() const override { return argument.isZero(); }
    bool isNegative() const override { return argument.isPositive(); }

    bool isStrictlyPositive() const { return argument.isStrictlyNegative(); }
    bool isStrictlyNegative() const { return argument.isStrictlyPositive(); }

    bool isOne() const override { throw TODO(); }

    bool isEven() const override { return argument.isEven(); }
    bool isOdd() const override { return argument.isOdd(); }

    Expression *_opposite() const override { return &argument; };
    Expression *_absoluteValue() const override;
    Expression *_differentiated(Unknown unknown) const override;
    Expression *_integrated(Unknown unknown) const override;
};

#endif /* OPPOSITE_HPP */
