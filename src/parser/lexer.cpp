#include "lexer.hpp"

#include "tokens_library.hpp"

std::vector<Token> Lexer::execute(std::string input)
{
    std::vector<Token> tokens{};
    for (int i = 0; i < input.size(); i++)
    {
        char character = input[i];
        TokenType type;
        std::string value;
        if (isdigit(character))
        {
            std::pair<TokenType, std::string> p = scanDigit(input, i);
            type = p.first;
            value = p.second;
        }
        else if (isalpha(character))
        {
            value = scanAlpha(input, i);
            type = functions.count(value) == 1 ? TokenType::alpha : TokenType::symbol;
        }
        else
        {
            value = character;
            type = getTypeOf(character);
        }
        tokens.push_back(Token(type, value));
    }
    return tokens;
}

std::string Lexer::tokensToString(std::vector<Token> tokens)
{
    std::string output = "[";
    for (Token token : tokens)
    {
        output += token.toString() + ", ";
    }
    return output + "]";
}

// TODO: Merge scanDigit and scanAlpha.
std::pair<TokenType, std::string> Lexer::scanDigit(std::string input, int &i)
{
    std::string number = std::string(1, input[i]);
    TokenType type = TokenType::integer;
    char next = input[i + 1];
    int end = input.size();
    while (isdigit(next) || next == '.' || next == ',')
    {
        if (next == '.' || next == ',')
        {
            type = TokenType::real;
        }
        number += next;
        if (i + 1 >= end)
        {
            break;
        }
        i++;
        next = input[i + 1];
    }
    return std::pair<TokenType, std::string>(type, number);
}

std::string Lexer::scanAlpha(std::string input, int &i)
{
    std::string string = std::string(1, input[i]);
    char next = input[i + 1];
    int end = input.size();
    while (isalpha(next))
    {
        string += next;
        if (i + 1 >= end)
            return string;
        i++;
        next = input[i + 1];
    }
    return string;
}

TokenType Lexer::getTypeOf(char character)
{
    switch (character)
    {
        case '+': return TokenType::plus;
        case '-': return TokenType::minus;
        case '*': return TokenType::star;
        case '/': return TokenType::slash;
        case '^': return TokenType::hat;
        case '.': return TokenType::dot;
        case '(': return TokenType::leftparenthesis;
        case ')': return TokenType::rightparenthesis;
        case '{': return TokenType::leftbrace;
        case '}': return TokenType::rightbrace;
        case '[': return TokenType::leftbracket;
        case ']': return TokenType::rightbracket;
        default: return TokenType::error;
    }
}
