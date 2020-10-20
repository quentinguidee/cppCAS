#include "tokens_library.hpp"

#include "../core/nodes/expressions/absolute_value.hpp"
#include "../core/nodes/expressions/addition.hpp"
#include "../core/nodes/expressions/cos.hpp"
#include "../core/nodes/expressions/differential.hpp"
#include "../core/nodes/expressions/division.hpp"
#include "../core/nodes/expressions/expression.hpp"
#include "../core/nodes/expressions/multiplication.hpp"
#include "../core/nodes/expressions/opposite.hpp"
#include "../core/nodes/expressions/power.hpp"
#include "../core/nodes/expressions/sin.hpp"
#include "../core/nodes/expressions/tan.hpp"
#include "../core/nodes/expressions/values/integer.hpp"
#include "../core/nodes/expressions/values/unknown.hpp"
#include "parse_tree.hpp"
#include "token_type.hpp"

// clang-format off

std::map<std::string, std::function<Expression *(ParseTree::Node &)>> functions{
    {"sin",             [](ParseTree::Node &node) -> Expression * { return new Sin              (node.getExpression(0)); }},
    {"cos",             [](ParseTree::Node &node) -> Expression * { return new Cos              (node.getExpression(0)); }},
    {"tan",             [](ParseTree::Node &node) -> Expression * { return new Tan              (node.getExpression(0)); }},
    {"opposite",        [](ParseTree::Node &node) -> Expression * { return new Opposite         (node.getExpression(0)); }},
    {"diff",            [](ParseTree::Node &node) -> Expression * { return new Differential     (node.getExpression(0), *new Unknown()); }},
    {"abs",             [](ParseTree::Node &node) -> Expression * { return new AbsoluteValue    (node.getExpression(0)); }},
};

std::map<TokenType, std::function<Expression *(ParseTree::Node &)>> tokensLibrary{
    {TokenType::plus,   [](ParseTree::Node &node) -> Expression * { return new Addition         {node.getExpression(1), node.getExpression(0)}; }},
    {TokenType::star,   [](ParseTree::Node &node) -> Expression * { return new Multiplication   {node.getExpression(1), node.getExpression(0)}; }},
    {TokenType::slash,  [](ParseTree::Node &node) -> Expression * { return new Division         (node.getExpression(1), node.getExpression(0)); }},
    {TokenType::hat,    [](ParseTree::Node &node) -> Expression * { return new Power            (node.getExpression(1), node.getExpression(0)); }},
    {TokenType::digit,  [](ParseTree::Node &node) -> Expression * { return new Integer          (std::atoi(node.getToken().getValue().c_str())); }},
    {TokenType::symbol, [](ParseTree::Node &node) -> Expression * { return new Unknown          (node.getToken().getValue().c_str()); }},
    {TokenType::alpha,  [](ParseTree::Node &node) -> Expression * { return functions            [node.getToken().getValue()](node); }},
};

// clang-format on
