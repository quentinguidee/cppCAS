#ifndef TOKEN_TYPE_HPP
#define TOKEN_TYPE_HPP

enum class TokenType
{
    plus,
    minus,
    star,
    slash,

    leftparenthesis,
    rightparenthesis,

    leftbrace,
    rightbrace,

    leftbracket,
    rightbracket,

    digit,
    alpha,
    dot,

    error,
};

#endif /* TOKEN_TYPE_HPP */