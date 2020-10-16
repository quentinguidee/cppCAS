#include "expression.hpp"

#include "opposite.hpp"
#include "absolute_value.hpp"

Expression *Expression::opposite() const
{
    return new Opposite(const_cast<Expression &>(*this));
}

Expression *Expression::absoluteValue() const
{
    if (isPositive())
    {
        return &const_cast<Expression &>(*this);
    }
    return new AbsoluteValue(const_cast<Expression &>(*this));
}
