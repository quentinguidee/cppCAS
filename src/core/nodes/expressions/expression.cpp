#include "expression.hpp"
#include "opposite.hpp"

Expression *Expression::opposite() const
{
    return new Opposite(const_cast<Expression &>(*this));
}
