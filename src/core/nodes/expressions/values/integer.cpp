#include "integer.hpp"

Integer::Integer(int value) :
    Rational(value)
{
}

Integer::Integer(const Integer &integer) :
    Rational(integer.value)
{
}
