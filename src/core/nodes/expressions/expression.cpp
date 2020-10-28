#include "expression.hpp"

#include "absolute_value.hpp"
#include "assert.h"
#include "differential.hpp"
#include "integral.hpp"
#include "modulus.hpp"
#include "opposite.hpp"
#include "parser/lexer.hpp"
#include "parser/parse_tree.hpp"
#include "parser/parser.hpp"
#include "power.hpp"
#include "values/unknown.hpp"

Expression* Expression::from(std::string expression)
{
    std::vector<Token> tokens;
    tokens = Lexer::execute(expression);
    tokens = Parser::reorderTokens(tokens);
    return &ParseTree(tokens).getExpression();
}

Expression* Expression::opposite() const
{
    return Expression::_opposite()->simplified();
}

Expression* Expression::absoluteValue() const
{
    return Expression::_absoluteValue()->simplified();
}

Expression* Expression::differentiated(Unknown unknown) const
{
    return Expression::_differentiated(unknown)->simplified();
}

Expression* Expression::integrated(Unknown unknown) const
{
    return Expression::_integrated(unknown)->simplified();
}

Expression* Expression::modulus() const
{
    return Expression::_modulus()->simplified();
}

Expression* Expression::power(Expression& power) const
{
    return Expression::_power(power)->simplified();
}

Expression* Expression::_opposite() const
{
    return new Opposite(*clone());
}

Expression* Expression::_absoluteValue() const
{
    return new AbsoluteValue(*clone());
}

Expression* Expression::_differentiated(Unknown unknown) const
{
    return new Differential(*clone(), unknown);
}

Expression* Expression::_integrated(Unknown unknown) const
{
    return new Integral(*clone(), unknown);
}

Expression* Expression::_modulus() const
{
    return new Modulus(*clone());
}

Expression* Expression::_power(Expression& power) const
{
    return new Power(*clone(), power);
}
