#ifndef NATURAL_HPP
#define NATURAL_HPP

#include "integer.hpp"

class Natural : public Integer
{
public:
    Natural(int value) : Integer(value) {}
    ~Natural() {}

    Integer toInteger() const { return Integer(value); }

    Natural operator=(int value) const { return Natural(value); }
};

#endif /* NATURAL_HPP */
