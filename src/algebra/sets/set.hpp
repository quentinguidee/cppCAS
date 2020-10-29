#ifndef SET_HPP
#define SET_HPP

#include "core/nodes/node.hpp"

class Set : public Node
{
private:
public:
    Set() {}
    ~Set() {}

    virtual Set* clone() const = 0;
    virtual Set* simplified() const = 0;
};

#endif /* SET_HPP */
