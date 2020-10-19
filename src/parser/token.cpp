#include "token.hpp"

std::ostream &operator<<(std::ostream &others, const Token &token)
{
    others << token.getValue();
    return others;
}

std::string Token::toString() const
{
    return "(" + std::to_string(static_cast<int>(type)) + ", '" + value + "')";
}
