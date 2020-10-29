#include "infinite_set.hpp"

InfiniteSet::InfiniteSet(std::string symbol) :
    symbol(symbol)
{
}

InfiniteSet::InfiniteSet(const InfiniteSet& set) :
    symbol(set.symbol)
{
}
