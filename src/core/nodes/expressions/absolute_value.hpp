#ifndef ABSOLUTE_VALUE_HPP
#define ABSOLUTE_VALUE_HPP

#include "expression.hpp"

class AbsoluteValue : public Expression
{
private:
    Expression &argument;

public:
    AbsoluteValue(Expression &argument);
    ~AbsoluteValue(){};
    std::string toString() override;
    std::string toLaTeX() override;
};

#endif /* ABSOLUTE_VALUE_HPP */
