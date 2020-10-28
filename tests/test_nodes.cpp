#define CATCH_CONFIG_MAIN

// TODO: Remove the else statement.
#ifdef __APPLE__
#include <catch2/catch.hpp>
#else
#include "catch.hpp"
#endif

#include <core/nodes/expressions/absolute_value.hpp>
#include <core/nodes/expressions/addition.hpp>
#include <core/nodes/expressions/cos.hpp>
#include <core/nodes/expressions/differential.hpp>
#include <core/nodes/expressions/division.hpp>
#include <core/nodes/expressions/integral.hpp>
#include <core/nodes/expressions/multiplication.hpp>
#include <core/nodes/expressions/opposite.hpp>
#include <core/nodes/expressions/power.hpp>
#include <core/nodes/expressions/sin.hpp>
#include <core/nodes/expressions/tan.hpp>
#include <core/nodes/expressions/values/complex.hpp>
#include <core/nodes/expressions/values/imaginary.hpp>
#include <core/nodes/expressions/values/integer.hpp>
#include <core/nodes/expressions/values/unknown.hpp>
#include <core/nodes/node.hpp>
#include <parser/lexer.hpp>
#include <parser/parse_tree.hpp>
#include <parser/parser.hpp>

TEST_CASE("Integer", "[CORE]")
{
    Integer int1 = 3;
    Integer int2 = -2;

    REQUIRE(int1.isPositive() == true);
    REQUIRE(int1.isStrictlyPositive() == true);
    REQUIRE(int1.isZero() == false);
    REQUIRE(int1.isStrictlyNegative() == false);
    REQUIRE(int1.isNegative() == false);
    REQUIRE(int1.isEven() == false);
    REQUIRE(int1.isOdd() == true);

    REQUIRE(int2.isPositive() == false);
    REQUIRE(int2.isStrictlyPositive() == false);
    REQUIRE(int2.isZero() == false);
    REQUIRE(int2.isStrictlyNegative() == true);
    REQUIRE(int2.isNegative() == true);
    REQUIRE(int2.isEven() == true);
    REQUIRE(int2.isOdd() == false);

    REQUIRE(int1.opposite()->toString() == "-3");

    REQUIRE(int1.absoluteValue()->toString() == "3");
    REQUIRE(int2.absoluteValue()->toString() == "2");
}

TEST_CASE("Real", "[CORE]")
{
    Real real1 = 3.7;
    Real real2 = -2.3;

    REQUIRE(real1.isPositive() == true);
    REQUIRE(real1.isStrictlyPositive() == true);
    REQUIRE(real1.isZero() == false);
    REQUIRE(real1.isStrictlyNegative() == false);
    REQUIRE(real1.isNegative() == false);
    REQUIRE(real1.isEven() == false);
    REQUIRE(real1.isOdd() == false);

    REQUIRE(real2.isPositive() == false);
    REQUIRE(real2.isStrictlyPositive() == false);
    REQUIRE(real2.isZero() == false);
    REQUIRE(real2.isStrictlyNegative() == true);
    REQUIRE(real2.isNegative() == true);
    REQUIRE(real2.isEven() == false);
    REQUIRE(real2.isOdd() == false);

    REQUIRE(real1.opposite()->toString() == "-3.700000");

    REQUIRE(real1.absoluteValue()->toString() == "3.700000");
    REQUIRE(real2.absoluteValue()->toString() == "2.300000");
}

TEST_CASE("Complex", "[CORE]")
{
    Real re(3);
    Imaginary im(re);
    Complex complex(re, im);

    REQUIRE(complex.toString() == "3.000000+3.000000i");
    REQUIRE(complex.toLaTeX() == "3.000000+3.000000i");

    REQUIRE(complex.conjuguated().toString() == "3.000000-3.000000i");
    REQUIRE(complex.modulus()->toString() == "3.000000^2+3.000000^2^1/2");
}

TEST_CASE("Power", "[CORE]")
{
    Integer int1 = 2;
    Integer int2 = 3;
    Power power(int1, int2);

    REQUIRE(power.toString() == "2^3");
    REQUIRE(power.toLaTeX() == "{2}^{3}");
    // TODO: REQUIRE(power.isEven() == true);
    REQUIRE(power.isOdd() == false);
    REQUIRE(power.isPositive() == true);
    REQUIRE(power.isStrictlyPositive() == true);
    REQUIRE(power.isZero() == false);
    REQUIRE(power.isStrictlyNegative() == false);
    REQUIRE(power.isNegative() == false);

    REQUIRE(power.opposite()->toString() == "-2^3");

    REQUIRE(power.absoluteValue()->toString() == "2^3");
}

TEST_CASE("Absolute value", "[CORE]")
{
    Integer int1 = -3;
    AbsoluteValue abs(int1);

    REQUIRE(abs.toString() == "|-3|");
    REQUIRE(abs.toLaTeX() == "\\left\\mid-3\\right\\mid");
    REQUIRE(abs.isPositive() == true);
    REQUIRE(abs.isStrictlyPositive() == true);
    REQUIRE(abs.isZero() == false);
    REQUIRE(abs.isStrictlyNegative() == false);
    REQUIRE(abs.isNegative() == false);
    REQUIRE(abs.isEven() == false);
    REQUIRE(abs.isOdd() == true);

    REQUIRE(abs.opposite()->toString() == "-3");
    REQUIRE(abs.absoluteValue()->toString() == "|-3|");
}

TEST_CASE("Opposite", "[CORE]")
{
    Integer int1 = -2;
    Integer int2 = 3;
    Opposite opposite(int1);
    Opposite opposite2(int2);
    Unknown x{};

    REQUIRE(opposite.toString() == "--2");
    REQUIRE(opposite.toLaTeX() == "--2");
    REQUIRE(opposite.isPositive() == true);
    REQUIRE(opposite.isStrictlyPositive() == true);
    REQUIRE(opposite.isZero() == false);
    REQUIRE(opposite.isStrictlyNegative() == false);
    REQUIRE(opposite.isNegative() == false);
    REQUIRE(opposite.isEven() == true);
    REQUIRE(opposite.isOdd() == false);

    REQUIRE(opposite.opposite()->toString() == "-2");

    REQUIRE(opposite.absoluteValue()->toString() == "--2");
    REQUIRE(opposite2.absoluteValue()->toString() == "3");

    REQUIRE(opposite.differentiated(x)->toString() == "-0");
}

TEST_CASE("Sin", "[CORE]")
{
    Integer int1 = 1;
    Sin sin(int1);
    Unknown x{};

    REQUIRE(sin.toString() == "sin(1)");
    REQUIRE(sin.toLaTeX() == "\\sin{(1)}");

    REQUIRE(sin.differentiated(x)->toString() == "0*cos(1)");
}

TEST_CASE("Cos", "[CORE]")
{
    Integer int1 = 1;
    Cos cos(int1);
    Unknown x{};

    REQUIRE(cos.toString() == "cos(1)");
    REQUIRE(cos.toLaTeX() == "\\cos{(1)}");

    REQUIRE(cos.differentiated(x)->toString() == "0*-sin(1)");
}

TEST_CASE("Tan", "[CORE]")
{
    Integer int1 = 1;
    Tan tan(int1);
    Unknown x{};

    REQUIRE(tan.toString() == "tan(1)");
    REQUIRE(tan.toLaTeX() == "\\tan{(1)}");

    REQUIRE(tan.differentiated(x)->toString() == "d/dx(sin(1)/cos(1))");
}

TEST_CASE("Division", "[CORE]")
{
    Integer int1 = 2;
    Integer int2 = -3;
    Division division(int1, int2);

    REQUIRE(division.toString() == "2/-3");
    REQUIRE(division.toLaTeX() == "\\frac{2}{-3}");
    REQUIRE(division.isPositive() == false);
    REQUIRE(division.isZero() == false);
    REQUIRE(division.isNegative() == true);
}

TEST_CASE("Multiplication", "[CORE]")
{
    Integer int1 = 1;
    Integer int2 = 2;
    Multiplication multiplication{int1, int2, int1};

    REQUIRE(multiplication.toString() == "1*2*1");
    REQUIRE(multiplication.toLaTeX() == "1\\cdot 2\\cdot 1");
}

TEST_CASE("Addition", "[CORE]")
{
    Integer int1 = 1;
    Integer int2 = 2;
    Addition addition{int1, int2, int1};

    REQUIRE(addition.toString() == "1+2+1");
    REQUIRE(addition.toLaTeX() == "1+2+1");
}

TEST_CASE("Unknown", "[CORE]")
{
    Unknown x{};
    Unknown y("y");

    REQUIRE(x.toString() == "x");
    REQUIRE(y.toString() == "y");

    REQUIRE(x.differentiated(x)->toString() == "1");
    REQUIRE(x.differentiated(y)->toString() == "0");

    REQUIRE(x.integrated(x)->toString() == "x^2/2");
    REQUIRE(x.integrated(y)->toString() == "∫x dy");
}

TEST_CASE("Differential", "[CORE]")
{
    Unknown x{};
    Differential differential(x, x);

    REQUIRE(differential.toString() == "d/dx(x)");
    REQUIRE(differential.toLaTeX() == "\\frac{d}{dx}\\left(x\\right)");
}

TEST_CASE("Integral", "[CORE]")
{
    Unknown x{};
    Integral integral(x, x);

    REQUIRE(integral.toString() == "∫x dx");
    REQUIRE(integral.toLaTeX() == "\\int{x dx}");
}

TEST_CASE("Lexer", "[PARSER]")
{
    std::vector<Token> tokens;

    tokens = Lexer::execute("2.3+1");
    REQUIRE(Lexer::tokensToString(tokens) == "[(12, '2.3'), (0, '+'), (11, '1'), ]");

    tokens = Lexer::execute("abs(x)");
    REQUIRE(Lexer::tokensToString(tokens) == "[(13, 'abs'), (5, '('), (15, 'x'), (6, ')'), ]");
}

TEST_CASE("Parser", "[PARSER]")
{
    std::vector<Token> tokens;

    tokens = Lexer::execute("3+4*1+5");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(Lexer::tokensToString(tokens) == "[(11, '3'), (11, '4'), (11, '1'), (2, '*'), (0, '+'), (11, '5'), (0, '+'), ]");

    tokens = Lexer::execute("sin(7/3*2)+2+3");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(Lexer::tokensToString(tokens) == "[(11, '7'), (11, '3'), (3, '/'), (11, '2'), (2, '*'), (13, 'sin'), (11, '2'), (0, '+'), (11, '3'), (0, '+'), ]");
}

TEST_CASE("Parse Tree", "[PARSER]")
{
    std::vector<Token> tokens;

    tokens = Lexer::execute("3+2/4+5");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(ParseTree(tokens).getExpression().toString() == "3+2/4+5");

    tokens = Lexer::execute("(3/2)*(4/2)");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(ParseTree(tokens).getExpression().toString() == "3/2*4/2");

    tokens = Lexer::execute("abs(2+3)");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(ParseTree(tokens).getExpression().toString() == "|2+3|");

    tokens = Lexer::execute("sin(x)");
    tokens = Parser::reorderTokens(tokens);
    REQUIRE(ParseTree(tokens).getExpression().toString() == "sin(x)");
}
