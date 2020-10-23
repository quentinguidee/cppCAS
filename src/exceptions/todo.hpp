#ifndef NOT_IMPLEMENTED_HPP
#define NOT_IMPLEMENTED_HPP

#include <stdexcept>

class TODO : public std::logic_error
{
public:
    TODO() : std::logic_error("Not implemented") {}
};

#endif /* NOT_IMPLEMENTED_HPP */
