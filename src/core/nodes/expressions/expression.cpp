#include "expression.hpp"

#include "absolute_value.hpp"
#include "differential.hpp"
#include "opposite.hpp"
#include "values/unknown.hpp"

#include "assert.h"

Expression *Expression::opposite() const
{
    return new Opposite(self());
}

Expression *Expression::absoluteValue() const
{
    if (isPositive())
    {
        return &self();
    }
    return new AbsoluteValue(self());
}

Expression *Expression::differentiated(Unknown &unknown) const
{
    return new Differential(self(), unknown);
}
