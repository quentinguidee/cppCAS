#include "modulus.hpp"

Modulus::Modulus(Expression &argument) :
    argument(argument)
{
}

Modulus::Modulus(const Modulus &modulus) :
    argument(*modulus.argument.clone())
{
}

std::string Modulus::toString() const
{
    return "|" + argument.toString() + "|";
}

std::string Modulus::toLaTeX() const
{
    return "\\left|" + argument.toLaTeX() + "\\right|";
}
