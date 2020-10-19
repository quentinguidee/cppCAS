#include "parser.hpp"

std::vector<Token> Parser::reorderTokens(std::vector<Token> &tokens)
{
    std::vector<Token> output;
    std::vector<Token> stack;

    for (int i = 0; i < tokens.size(); i++)
    {
        Token token = tokens[i];
        if (token.getType() == TokenType::digit)
        {
            output.push_back(token);
        }
        else if (token.getType() == TokenType::alpha)
        {
            stack.push_back(token);
        }
        else if (isOperator(token))
        {
            while (
                stack.size() != 0 && isOperator(stack.back()) &&
                (precedenceOf(stack.back()) > precedenceOf(token) ||
                 precedenceOf(stack.back()) == precedenceOf(token) &&
                     associativityOf(token) == Associativity::left) &&
                stack.back().getType() != TokenType::leftparenthesis)
            {
                output.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(token);
        }
        else if (token.getType() == TokenType::leftparenthesis)
        {
            stack.push_back(token);
        }
        else if (token.getType() == TokenType::rightparenthesis)
        {
            while (stack.back().getType() != TokenType::leftparenthesis)
            {
                output.push_back(stack.back());
                stack.pop_back();
                // TODO: if stack.size() == 0 => mismatched parenthesis
            }
            if (stack.back().getType() == TokenType::leftparenthesis)
            {
                stack.pop_back();
            }
        }
        else
        {
            throw std::exception();
        }
    }

    while (stack.size() != 0)
    {
        output.push_back(stack.back());
        stack.pop_back();
    }

    return output;
}

int Parser::precedenceOf(Token token)
{
    for (Operation operation : operations)
    {
        if (operation.type == token.getType())
        {
            return operation.precedence;
        }
    }
    throw std::exception();
}

Parser::Associativity Parser::associativityOf(Token token)
{
    for (Operation operation : operations)
    {
        if (operation.type == token.getType())
        {
            return operation.associativity;
        }
    }
    throw std::exception();
}

bool Parser::isOperator(Token token)
{
    TokenType type = token.getType();
    return type == TokenType::plus ||
           type == TokenType::minus ||
           type == TokenType::star ||
           type == TokenType::slash ||
           type == TokenType::hat;
}
