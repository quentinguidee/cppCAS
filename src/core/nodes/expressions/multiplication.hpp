#ifndef MULTIPLICATION_HPP
#define MULTIPLICATION_HPP

#include <initializer_list>
#include <vector>

#include "exceptions/todo.hpp"
#include "expression.hpp"
#include "multi_node.hpp"

class Multiplication : public MultiNode
{
public:
    Multiplication(std::initializer_list<std::reference_wrapper<Expression>> children);
    Multiplication(std::vector<std::reference_wrapper<Expression>> children);
    Multiplication(const Multiplication &multiplication);
    ~Multiplication() {}

    Expression *clone() const override { return new Multiplication(*this); }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    Expression *_modulus() const override;
};

#endif /* MULTIPLICATION_HPP */
