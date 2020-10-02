#ifndef POWER_HPP
#define POWER_HPP

#include "node.hpp"

class Power : public Node
{
private:
    Node *base;
    Node *power;

public:
    Power(Node *base, Node *power);
    ~Power();
    std::string ToString();
    std::string ToLaTeX();
};

#endif /* POWER_HPP */