#include "unknown.hpp"

#include "../division.hpp"
#include "../multiplication.hpp"
#include "../power.hpp"
#include "integer.hpp"

Unknown::Unknown(const std::string symbol) :
    symbol(symbol)
{
}

Unknown::Unknown(const Unknown &unknown) :
    symbol(unknown.symbol)
{
}

Expression *Unknown::differentiated(Unknown unknown) const
{
    return symbol == unknown.getSymbol() ? new Integer(1) : new Integer(0);
}

Expression *Unknown::integrated(Unknown unknown) const
{
    if (symbol == unknown.getSymbol())
    {
        return new Division(*new Power(self(), *new Integer(2)), *new Integer(2));
    }
    return Value::integrated(unknown);
}
