#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include <vector>
#include <initializer_list>

#include "expression.hpp"
#include "multi_node.hpp"
#include "exceptions/todo.hpp"

class Multiplication : public MultiNode
{
public:
    Multiplication(std::initializer_list<std::reference_wrapper<Expression>> children) : MultiNode('*', "\\cdot ", children) {}
    ~Multiplication() {}

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }
};

#endif /* MULTIPLICATION_HPP */
