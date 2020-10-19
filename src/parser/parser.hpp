#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>

#include "token.hpp"

class Parser
{
private:
    enum Associativity
    {
        left,
        right
    };

    typedef struct Operation
    {
        TokenType type;
        int precedence;
        Associativity associativity;
    } Operation;

    static constexpr Operation operations[5]{
        {TokenType::plus, 0, Associativity::left},
        {TokenType::minus, 0, Associativity::left},
        {TokenType::star, 1, Associativity::left},
        {TokenType::slash, 1, Associativity::left},
        {TokenType::hat, 2, Associativity::right},
    };

public:
    static std::vector<Token> reorderTokens(std::vector<Token> &tokens);
    static int precedenceOf(Token type);
    static Associativity associativityOf(Token type);
    static bool isOperator(Token token);
};

#endif /* PARSER_HPP */
