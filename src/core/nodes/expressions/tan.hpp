#ifndef TAN_HPP
#define TAN_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"

class Tan : public Expression
{
private:
    Expression &argument;

public:
    Tan(Expression &argument);
    Tan(const Tan &tan);
    ~Tan() {}

    Expression *clone() const override { return new Tan(*this); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isOne() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    Expression *_differentiated(Unknown unknown) const override;
};

#endif /* TAN_HPP */
