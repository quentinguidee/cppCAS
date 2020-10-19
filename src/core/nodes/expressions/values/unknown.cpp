#include "unknown.hpp"

#include "integer.hpp"

Expression *Unknown::differentiated(Unknown &unknown) const
{
    return symbol == unknown.getSymbol() ? new Integer(1) : new Integer(0);
}
