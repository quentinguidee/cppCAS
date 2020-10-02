#include "power.hpp"

Power::Power(Node *base, Node *power)
{
    this->base = base;
    this->power = power;
}

Power::~Power()
{
}

std::string Power::ToString()
{
    return base->ToString() + "^" + power->ToString();
}

std::string Power::ToLaTeX()
{
    return "{" + base->ToLaTeX() + "}^{" + power->ToLaTeX() + "}";
}
