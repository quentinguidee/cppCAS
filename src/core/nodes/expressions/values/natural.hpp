#ifndef NATURAL_HPP
#define NATURAL_HPP

#include "integer.hpp"

class Natural : public Integer
{
public:
    Natural(int value);
    Natural(const Natural &natural);
    ~Natural() {}

    Expression *clone() const override { return new Natural(*this); }

    Integer toInteger() const { return Integer(value); }

    Natural operator=(int value) const { return Natural(value); }
};

#endif /* NATURAL_HPP */
