#ifndef INFINITE_SET_HPP
#define INFINITE_SET_HPP

#include "set.hpp"

class InfiniteSet : public Set
{
private:
    std::string symbol;

public:
    InfiniteSet(std::string symbol);
    InfiniteSet(const InfiniteSet& set);
    ~InfiniteSet() {}

    Set* clone() const override { return new InfiniteSet(*this); }
    Set* simplified() const override { return clone(); }

    std::string toString() const override { return symbol; }
    std::string toLaTeX() const override { return symbol; }
};

#endif /* INFINITE_SET_HPP */
