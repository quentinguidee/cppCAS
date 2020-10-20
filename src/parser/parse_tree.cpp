#include "parse_tree.hpp"

#include <functional>
#include <iostream>
#include <string>

#include "../core/nodes/expressions/addition.hpp"
#include "../core/nodes/expressions/division.hpp"
#include "../core/nodes/expressions/multiplication.hpp"
#include "../core/nodes/expressions/values/integer.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "tokens_library.hpp"

ParseTree::ParseTree(std::vector<Token> tokens)
{
    std::vector<std::reference_wrapper<Node>> stack{};
    for (Token &token : tokens)
    {
        if (token.getType() == TokenType::digit || token.getType() == TokenType::symbol)
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
        else  // 1 argument
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
    return *tokensLibrary[token.getType()](*this);
}
