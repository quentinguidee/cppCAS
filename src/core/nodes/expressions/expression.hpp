#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "../node.hpp"

class Expression : public Node
{
private:
public:
    Expression() {}
    ~Expression() {}

    virtual bool isPositive() = 0;
    virtual bool isZero() = 0;
    virtual bool isNegative() = 0;

    bool isStrictlyPositive() { return isPositive() && !isZero(); }
    bool isStrictlyNegative() { return isNegative() && !isZero(); }

    virtual bool isEven() = 0;
    virtual bool isOdd() = 0;
};

#endif /* EXPRESSION_HPP */
