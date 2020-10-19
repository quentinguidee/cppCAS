#include "expression.hpp"

#include "absolute_value.hpp"
#include "differential.hpp"
#include "opposite.hpp"
#include "values/unknown.hpp"

#include "assert.h"

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

Expression *Expression::differentiated(Unknown &unknown) const
{
    return new Differential(const_cast<Expression &>(*this), unknown);
}
