#include "multiplication.hpp"

Multiplication::Multiplication(std::initializer_list<std::reference_wrapper<Expression>> children) :
    MultiNode('*', "\\cdot ", children)
{
}

Multiplication::Multiplication(std::vector<std::reference_wrapper<Expression>> children) :
    MultiNode('*', "\\cdot ", children)
{
}

Multiplication::Multiplication(const Multiplication& multiplication) :
    Multiplication(multiplication.getChildren())
{
}

Expression* Multiplication::_modulus() const
{
    std::vector<std::reference_wrapper<Expression>> result{};
    for (std::reference_wrapper<Expression> child : getChildren())
    {
        result.push_back(*child.get().modulus());
    }
    return new Multiplication(result);
}
