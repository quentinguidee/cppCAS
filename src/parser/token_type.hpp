#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

#include <functional>

enum class TokenType
{
    plus,
    minus,
    star,
    slash,
    hat,

    leftparenthesis,
    rightparenthesis,

    leftbrace,
    rightbrace,

    leftbracket,
    rightbracket,

    integer,
    real,

    alpha,
    dot,

    symbol,

    error,
};

#endif /* TOKEN_TYPE_HPP */
