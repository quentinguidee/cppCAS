#include "natural.hpp"

Natural::Natural(int value) :
    Integer(value)
{
}

Natural::Natural(const Natural &natural) :
    Integer(natural.value)
{
}
