#ifndef REAL_HPP
#define REAL_HPP

#include <string>

#include "unknown.hpp"
#include "value.hpp"

class Real : public Value
{
protected:
    double value;

public:
    Real(double value);
    Real(int value);
    Real(const Real &real);
    ~Real() {}

    Expression *clone() const override { return new Real(*this); }

    int *toIntIfPossible() const;

    std::string toString() const override { return std::to_string(value); }
    std::string toLaTeX() const override { return toString(); }

    bool isPositive() const override { return value >= 0; }
    bool isZero() const override { return value == 0; }
    bool isNegative() const override { return value <= 0; }

    bool isStrictlyPositive() const { return value > 0; }
    bool isStrictlyNegative() const { return value < 0; }

    bool isEven() const override;
    bool isOdd() const override;

    Expression *_opposite() const override { return new Real(-value); }
    Expression *_differentiated(Unknown unknown) const override { return new Real(0); }
    virtual Expression *_absoluteValue() const override;

    Real operator=(double value) const { return Real(value); }
};

#endif /* REAL_HPP */
