#ifndef PARSE_TREE_HPP
#define PARSE_TREE_HPP

#include <vector>

#include "token.hpp"

class ParseTree
{
public:
    class Node
    {
    private:
        Token token;
        std::vector<Node> children;

    public:
        Node(Token token) : token(token) {}
        ~Node() {}

        void push(Node child) { children.push_back(child); }
        std::string toString(int level = 0) const;
    };

private:
    std::vector<Token> tokens;
    Node *node = nullptr;

public:
    ParseTree(std::vector<Token> tokens);
    ~ParseTree() {}

    std::string toString() const { return node->toString(); };
};

#endif /* PARSE_TREE_HPP */
