#ifndef SIN_HPP
#define SIN_HPP

#include "exceptions/todo.hpp"
#include "expression.hpp"
#include "values/unknown.hpp"

class Sin : public Expression
{
private:
    Expression &argument;

public:
    Sin(Expression &argument);
    Sin(const Sin &sin);
    ~Sin() {}

    Expression *clone() const override { return new Sin(*this); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override;
    std::string toLaTeX() const override;

    Expression *differentiated(Unknown unknown) const override;
};

#endif /* SIN_HPP */
