#include "addition.hpp"

Addition::Addition(std::vector<std::reference_wrapper<Expression>> children) :
    MultiNode('+', "+", children)
{
}

Addition::Addition(std::initializer_list<std::reference_wrapper<Expression>> children) :
    MultiNode('+', "+", children)
{
}

Addition::Addition(const Addition &addition) :
    Addition(addition.getChildren())
{
}
