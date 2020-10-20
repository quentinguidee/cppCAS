#ifndef TOKENS_LIBRARY_HPP
#define TOKENS_LIBRARY_HPP

#include <functional>
#include <map>

#include "../core/nodes/expressions/expression.hpp"
#include "parse_tree.hpp"
#include "token_type.hpp"

extern std::map<std::string, std::function<Expression *(ParseTree::Node &)>> functions;
extern std::map<TokenType, std::function<Expression *(ParseTree::Node &)>> tokensLibrary;

#endif /* TOKENS_LIBRARY_HPP */
