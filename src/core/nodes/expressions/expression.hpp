#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "../node.hpp"

class Unknown;

class Expression : public Node
{
private:
public:
    Expression() {}
    ~Expression() {}

    Expression &self() const { return const_cast<Expression &>(*this); }

    virtual Expression *simplified() const { return &self(); }

    virtual bool isPositive() const = 0;
    virtual bool isZero() const = 0;
    virtual bool isNegative() const = 0;

    bool isStrictlyPositive() const { return isPositive() && !isZero(); }
    bool isStrictlyNegative() const { return isNegative() && !isZero(); }

    virtual bool isEven() const = 0;
    virtual bool isOdd() const = 0;

    virtual Expression *opposite() const;
    virtual Expression *absoluteValue() const;
    virtual Expression *differentiated(Unknown &unknown) const;
    virtual Expression *integrated(Unknown &unknown) const;
};

#endif /* EXPRESSION_HPP */
