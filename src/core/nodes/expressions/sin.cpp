#include "sin.hpp"

std::string Sin::toString() const
{
    return "sin(" + argument.toString() + ")";
}

std::string Sin::toLaTeX() const
{
    return "\\sin{(" + argument.toLaTeX() + ")}";
}
