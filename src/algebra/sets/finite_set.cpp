#include "finite_set.hpp"

FiniteSet::FiniteSet(std::initializer_list<std::reference_wrapper<Expression>> elements) :
    elements(elements)
{
}

FiniteSet::FiniteSet(std::vector<std::reference_wrapper<Expression>> elements) :
    elements(elements)
{
}

FiniteSet::FiniteSet(const FiniteSet& set) :
    elements(set.elements)
{
}

std::string FiniteSet::toString() const
{
    std::string string = "{";
    for (int i = 0; i < elements.size() - 1; i++)
    {
        string += elements[i].get().toString();
        string += ',';
    }
    string += elements.back().get().toString();
    return string + '}';
}

std::string FiniteSet::toLaTeX() const
{
    std::string string = "\\left\\{";
    for (int i = 0; i < elements.size() - 1; i++)
    {
        string += elements[i].get().toLaTeX();
        string += ',';
    }
    string += elements.back().get().toLaTeX();
    return string + "\\right\\}";
}
