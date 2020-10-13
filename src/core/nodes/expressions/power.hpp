#ifndef POWER_HPP
#define POWER_HPP

#include "expression.hpp"

class Power : public Expression
{
private:
    Expression *base;
    Expression *power;

public:
    Power(Expression *base, Expression *power);
    ~Power();
    std::string ToString();
    std::string ToLaTeX();
};

#endif /* POWER_HPP */
