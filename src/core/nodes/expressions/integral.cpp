#include "integral.hpp"

#include "values/unknown.hpp"

std::string Integral::toString() const
{
    return "∫" + argument.toString() + " d" + unknown.toString();
}

std::string Integral::toLaTeX() const
{
    return "\\int{" + argument.toLaTeX() + " d" + unknown.toLaTeX() + "}";
}
