#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "value.hpp"

class Integer : public Value
{
private:
    int value;

public:
    Integer(int value);
    ~Integer();
    std::string ToString();
    std::string ToLaTeX();
};

#endif /* INTEGER_HPP */