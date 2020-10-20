#ifndef PARSE_TREE_HPP
#define PARSE_TREE_HPP

#include <vector>

#include "../core/nodes/expressions/expression.hpp"
#include "token.hpp"

class ParseTree
{
public:
    class Node
    {
    private:
        Token token;
        std::vector<Node> children;
        Expression *expression = nullptr;

    public:
        Node(Token token) : token(token) {}
        ~Node() {}

        void push(Node child) { children.push_back(child); }
        std::string toString(int level = 0) const;

        Expression &getExpression();
        Expression &getExpression(int childId) { return children[childId].getExpression(); }

        Token &getToken() { return token; }
        Node &getChild(int i) { return children[i]; }
    };

private:
    std::vector<Token> tokens;
    Node *node = nullptr;

public:
    ParseTree(std::vector<Token> tokens);
    ~ParseTree() {}

    std::string toString() const { return node->toString(); }
    Expression &getExpression() { return node->getExpression(); }
};

#endif /* PARSE_TREE_HPP */
