#include "addition.hpp"

Addition::Addition(std::initializer_list<std::reference_wrapper<Expression>> children) :
    MultiNode('+', "+", children)
{
}

Addition::Addition(const Addition &addition) :
    MultiNode(addition)
{
}
