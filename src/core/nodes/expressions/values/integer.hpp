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

    std::string toString() const override;
    std::string toLaTeX() const override;

    bool isPositive() const override { return value >= 0; }
    bool isZero() const override { return value == 0; }
    bool isNegative() const override { return value <= 0; }

    bool isStrictlyPositive() const { return value > 0; }
    bool isStrictlyNegative() const { return value < 0; }

    bool isEven() const override { return value % 2 == 0; }
    bool isOdd() const override { return value % 2 != 0; }

    Expression *opposite() const override { return new Integer(-value); }
    Expression *absoluteValue() const override;
    Expression *differentiated(Unknown &unknown) const override { return new Integer(0); };

    Integer operator=(int i) const { return Integer(i); }
};

#endif /* INTEGER_HPP */
