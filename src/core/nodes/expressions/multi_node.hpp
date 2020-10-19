#ifndef MULTI_NODE_HPP
#define MULTI_NODE_HPP

#include <vector>
#include <initializer_list>
#include <functional>

#include "expression.hpp"

class MultiNode : public Expression
{
private:
    const char symbol;
    const std::string latexSymbol;
    std::vector<std::reference_wrapper<Expression>> children;

public:
    MultiNode(char symbol, std::string latexSymbol, std::initializer_list<std::reference_wrapper<Expression>> children) : symbol(symbol), latexSymbol(latexSymbol), children(children) {}
    ~MultiNode() {}

    virtual bool isPositive() const override = 0;
    virtual bool isZero() const override = 0;
    virtual bool isNegative() const override = 0;

    virtual bool isEven() const override = 0;
    virtual bool isOdd() const override = 0;

    std::string toString() const override;
    std::string toLaTeX() const override;
};

#endif /* MULTI_NODE_HPP */
