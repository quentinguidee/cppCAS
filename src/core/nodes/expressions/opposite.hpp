#ifndef OPPOSITE_HPP
#define OPPOSITE_HPP

#include "expression.hpp"

class Opposite : public Expression
{
private:
    Expression &argument;

public:
    Opposite(Expression &argument);
    ~Opposite(){};
    std::string toString() override;
    std::string toLaTeX() override;
};

#endif /* OPPOSITE_HPP */
