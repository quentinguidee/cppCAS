#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>

#include "token.hpp"
#include "token_type.hpp"

class Lexer
{
private:
    static TokenType getTypeOf(char character);
    static std::string scanDigit(std::string input, int &i);
    static std::string scanAlpha(std::string input, int &i);

public:
    static std::vector<Token> execute(std::string input);
    static std::string tokensToString(std::vector<Token> tokens);
};

#endif /* LEXER_HPP */
