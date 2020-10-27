#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "exceptions/todo.hpp"
#include "multi_node.hpp"

class Addition : public MultiNode
{
public:
    Addition(std::initializer_list<std::reference_wrapper<Expression>> children);
    ~Addition() {}

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }
};

#endif /* ADDITION_HPP */
