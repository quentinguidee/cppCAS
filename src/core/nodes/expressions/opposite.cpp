#include "opposite.hpp"

Opposite::Opposite(Expression &argument) :
    argument(argument)
{
}

Opposite::Opposite(const Opposite &opposite) :
    argument(*opposite.argument.clone())
{
}

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

Expression *Opposite::differentiated(Unknown unknown) const
{
    return new Opposite(*argument.differentiated(unknown));
}

Expression *Opposite::integrated(Unknown unknown) const
{
    return new Opposite(*argument.integrated(unknown));
}
