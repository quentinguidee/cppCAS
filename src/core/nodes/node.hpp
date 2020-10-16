#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node
{
private:
public:
    Node() {}
    ~Node() {}
    virtual std::string toString() const = 0;
    virtual std::string toLaTeX() const = 0;
};

#endif /* NODE_HPP */
