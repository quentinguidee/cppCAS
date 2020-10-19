#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

#include "token_type.hpp"

class Token
{
private:
    TokenType type;
    std::string value;

public:
    Token(TokenType type, std::string value) : type(type), value(value) {}
    TokenType getType() const { return type; }
    std::string getValue() const { return value; }
    std::string toString() const;
};

#endif /* TOKEN_HPP */
