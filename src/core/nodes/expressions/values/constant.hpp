#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <map>
#include <string>

#include "real.hpp"
#include "value.hpp"

class Constant : public Value
{
private:
    std::string symbol;

public:
    const std::map<std::string, double> constants = {
        {"e", M_E},
        {"π", M_PI},
        {"pi", M_PI},
    };

    Constant(std::string symbol);
    Constant(const Constant &constant);
    ~Constant() {}

    Expression *clone() const override { return new Constant(*this); }

    double getValue() const { return constants.at(symbol); }
    Real asReal() const { return Real(getValue()); }

    bool isPositive() const override { return asReal().isPositive(); }
    bool isZero() const override { return asReal().isZero(); }
    bool isNegative() const override { return asReal().isNegative(); }

    bool isOne() const override { return asReal().isOne(); }

    bool isOdd() const override { return asReal().isOdd(); }
    bool isEven() const override { return asReal().isEven(); }

    std::string toString() const override { return symbol; }
    std::string toLaTeX() const override { return symbol; }
};

#endif /* CONSTANT_HPP */
