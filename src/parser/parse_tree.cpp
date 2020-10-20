#include "parse_tree.hpp"

#include <iostream>
#include <functional>
#include <string>

#include "parser.hpp"
#include "lexer.hpp"

#include "../core/nodes/expressions/addition.hpp"
#include "../core/nodes/expressions/multiplication.hpp"
#include "../core/nodes/expressions/division.hpp"
#include "../core/nodes/expressions/values/integer.hpp"

ParseTree::ParseTree(std::vector<Token> tokens)
{
    std::vector<std::reference_wrapper<Node>> stack{};
    for (Token &token : tokens)
    {
        if (token.getType() == TokenType::digit)
        {
            Node *node = new Node(token);
            stack.push_back(std::ref(*node));
        }
        else if (Parser::isOperator(token))
        {
            Node *node = new Node(token);
            node->push(stack.back().get());
            stack.pop_back();
            node->push(stack.back().get());
            stack.pop_back();
            stack.push_back(std::ref(*node));
        }
        else // 1 argument
        {
            Node *node = new Node(token);
            node->push(stack.back().get());
            stack.pop_back();
            stack.push_back(std::ref(*node));
        }
    }
    this->tokens = tokens;
    this->node = &stack.back().get();
}

std::string ParseTree::Node::toString(int level) const
{
    std::string output = "\n";
    for (int i = 0; i < level; i++)
    {
        output += '\t';
    }
    output += token.toString();
    for (Node node : children)
    {
        output += node.toString(level + 1);
    }
    return output;
}

Expression &ParseTree::Node::getExpression()
{
    if (expression != nullptr)
    {
        return *expression;
    }
    switch (token.getType())
    {
    case TokenType::plus:
        expression = new Addition({children[1].getExpression(), children[0].getExpression()});
        break;
    case TokenType::star:
        expression = new Multiplication({children[1].getExpression(), children[0].getExpression()});
        break;
    case TokenType::slash:
        expression = new Division(children[1].getExpression(), children[0].getExpression());
        break;
    case TokenType::digit:
        expression = new Integer(std::atoi(token.getValue().c_str()));
        break;
    default:
        break;
    }
    return *expression;
}
