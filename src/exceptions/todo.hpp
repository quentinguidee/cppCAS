#ifndef NOT_IMPLEMENTED_HPP
#define NOT_IMPLEMENTED_HPP

#include <stdexcept>

class TODO : public std::exception
{
private:
    std::string message;

public:
    TODO(const char *message = "Not implemented.") {}
    const char *what() const noexcept
    {
        return message.c_str();
    }
};

#endif /* NOT_IMPLEMENTED_HPP */
