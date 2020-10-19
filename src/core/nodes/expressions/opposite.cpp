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
    if (argument.isPositive())
    {
        return &argument;
    }
    return this->Expression::absoluteValue();
}

Expression *Opposite::differentiated(Unknown &unknown) const
{
    Expression *expression = argument.differentiated(unknown);
    return new Opposite(*expression);
}
