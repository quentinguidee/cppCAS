#include "integral.hpp"

#include "values/unknown.hpp"

Integral::Integral(Expression &argument, Unknown unknown) :
    argument(argument),
    unknown(unknown)
{
}

Integral::Integral(const Integral &integral) :
    argument(*integral.argument.clone()),
    unknown(Unknown(integral.unknown))
{
}

std::string Integral::toString() const
{
    return "∫" + argument.toString() + " d" + unknown.toString();
}

std::string Integral::toLaTeX() const
{
    return "\\int{" + argument.toLaTeX() + " d" + unknown.toLaTeX() + "}";
}
