#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "value.hpp"

class Integer : public Value
{
private:
    int value;

public:
    Integer(int value) : value(value) {}
    ~Integer() {}

    std::string toString() override;
    std::string toLaTeX() override;

    bool isPositive() override { return value >= 0; }
    bool isZero() override { return value == 0; }
    bool isNegative() override { return value <= 0; }

    bool isStrictlyPositive() { return value > 0; }
    bool isStrictlyNegative() { return value < 0; }

    bool isEven() override { return value % 2 == 0; }
    bool isOdd() override { return value % 2 != 0; }
};

#endif /* INTEGER_HPP */
