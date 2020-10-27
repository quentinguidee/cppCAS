#include "multiplication.hpp"

Multiplication::Multiplication(std::initializer_list<std::reference_wrapper<Expression>> children) :
    MultiNode('*', "\\cdot ", children)
{
}
