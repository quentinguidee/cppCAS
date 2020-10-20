#ifndef UNKNOWN_HPP
#define UNKNOWN_HPP

#include "../expression.hpp"
#include "exceptions/todo.hpp"
#include "value.hpp"

class Unknown : public Value
{
private:
    const std::string symbol;

public:
    Unknown(const std::string symbol = "x") : symbol(symbol) {}
    ~Unknown() {}

    std::string getSymbol() const { return symbol; }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override { return symbol; }
    std::string toLaTeX() const override { return symbol; }

    Expression *differentiated(Unknown &unknown) const override;

    Unknown operator=(std::string symbol) { return Unknown(symbol); }
};

#endif /* UNKNOWN_HPP */
