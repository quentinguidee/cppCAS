#include "expression.hpp"

#include "absolute_value.hpp"
#include "assert.h"
#include "differential.hpp"
#include "integral.hpp"
#include "opposite.hpp"
#include "values/unknown.hpp"

Expression *Expression::opposite() const
{
    return new Opposite(self());
}

Expression *Expression::absoluteValue() const
{
    return isPositive() ? &self() : new AbsoluteValue(self());
}

Expression *Expression::differentiated(Unknown &unknown) const
{
    return new Differential(self(), unknown);
}

Expression *Expression::integrated(Unknown &unknown) const
{
    return new Integral(self(), unknown);
}
