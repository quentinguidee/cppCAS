#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node
{
private:
public:
    Node() {}
    ~Node() {}
    virtual std::string toString() = 0;
    virtual std::string toLaTeX() = 0;
};

#endif /* NODE_HPP */
