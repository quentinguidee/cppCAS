#ifndef FINITE_SET_HPP
#define FINITE_SET_HPP

#include <vector>

#include "core/nodes/expressions/expression.hpp"
#include "set.hpp"

class FiniteSet : public Set
{
private:
    std::vector<std::reference_wrapper<Expression>> elements;

public:
    FiniteSet(std::initializer_list<std::reference_wrapper<Expression>> elements);
    FiniteSet(std::vector<std::reference_wrapper<Expression>> elements);
    FiniteSet(const FiniteSet& set);
    ~FiniteSet() {}

    Set* clone() const override { return new FiniteSet(*this); }
    Set* simplified() const override { return clone(); }

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* FINITE_SET_HPP */
