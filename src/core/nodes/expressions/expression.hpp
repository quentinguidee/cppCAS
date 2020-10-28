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
    virtual Expression *clone() const = 0;

    virtual Expression *simplified() const { return clone(); }

    virtual bool isPositive() const = 0;
    virtual bool isZero() const = 0;
    virtual bool isNegative() const = 0;

    bool isStrictlyPositive() const { return isPositive() && !isZero(); }
    bool isStrictlyNegative() const { return isNegative() && !isZero(); }

    virtual bool isEven() const = 0;
    virtual bool isOdd() const = 0;

    Expression *opposite() const;
    Expression *absoluteValue() const;
    Expression *differentiated(Unknown unknown) const;
    Expression *integrated(Unknown unknown) const;

    // Do not call these methods:

    virtual Expression *_opposite() const;
    virtual Expression *_absoluteValue() const;
    virtual Expression *_differentiated(Unknown unknown) const;
    virtual Expression *_integrated(Unknown unknown) const;
};

#endif /* EXPRESSION_HPP */
