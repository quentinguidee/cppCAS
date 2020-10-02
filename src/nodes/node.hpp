#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node
{
private:
public:
    Node();
    ~Node();
    virtual std::string ToString() = 0;
    virtual std::string ToLaTeX() = 0;
};

#endif /* NODE_HPP */
