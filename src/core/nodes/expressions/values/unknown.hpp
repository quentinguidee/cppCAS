#ifndef UNKNOWN_HPP
#define UNKNOWN_HPP

#include "../expression.hpp"
#include "value.hpp"
#include "exceptions/todo.hpp"

class Unknown : public Value
{
private:
    const char symbol;

public:
    Unknown(const char symbol = 'x') : symbol(symbol) {}
    ~Unknown() {}

    char getSymbol() const { return symbol; }

    bool isPositive() const override { throw TODO(); }
    bool isZero() const override { throw TODO(); }
    bool isNegative() const override { throw TODO(); }

    bool isEven() const override { throw TODO(); }
    bool isOdd() const override { throw TODO(); }

    std::string toString() const override { return std::string(1, symbol); }
    std::string toLaTeX() const override { return std::string(1, symbol); }

    Expression *differentiated(Unknown &unknown) const override;

    Unknown operator=(char symbol) { return Unknown(symbol); }
    Unknown operator=(std::string symbol) { return Unknown(symbol[0]); }
};

#endif /* UNKNOWN_HPP */
