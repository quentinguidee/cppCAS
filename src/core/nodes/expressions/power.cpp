#include "power.hpp"

std::string Power::toString()
{
    return base.toString() + "^" + power.toString();
}

std::string Power::toLaTeX()
{
    return "{" + base.toLaTeX() + "}^{" + power.toLaTeX() + "}";
}
