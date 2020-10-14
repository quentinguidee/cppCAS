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
    std::string ToString() override;
    std::string ToLaTeX() override;
};

#endif /* OPPOSITE_HPP */
