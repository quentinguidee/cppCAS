#include "constant.hpp"

Constant::Constant(std::string symbol) :
    symbol(symbol)
{
}

Constant::Constant(const Constant &constant) :
    symbol(constant.symbol)
{
}
