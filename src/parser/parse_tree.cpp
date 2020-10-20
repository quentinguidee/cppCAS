#include "parse_tree.hpp"

#include <iostream>
#include <functional>

#include "parser.hpp"
#include "lexer.hpp"

ParseTree::ParseTree(std::vector<Token> tokens)
{
    std::cout << Lexer::tokensToString(tokens) << std::endl;
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
