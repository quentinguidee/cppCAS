#include "opposite.hpp"

std::string Opposite::toString() const
{
    return "-" + argument.toString();
}

std::string Opposite::toLaTeX() const
{
    return "-" + argument.toLaTeX();
}

Expression *Opposite::absoluteValue() const
{
    return argument.isPositive() ? &argument : this->Expression::absoluteValue();
}

Expression *Opposite::differentiated(Unknown &unknown) const
{
    return new Opposite(*argument.differentiated(unknown));
}
