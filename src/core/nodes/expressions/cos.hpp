#ifndef COS_HPP
#define COS_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"

class Cos : public Expression
{
private:
    Expression &argument;

public:
    Cos(Expression &argument);
    Cos(const Cos &cos);
    ~Cos() {}

    Expression *clone() const override { return new Cos(*this); }

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

#endif /* COS_HPP */
