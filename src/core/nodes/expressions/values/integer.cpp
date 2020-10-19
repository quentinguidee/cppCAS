#include "integer.hpp"

Expression *Integer::absoluteValue() const
{
    return isPositive() ? &self() : opposite();
}
