#define CATCH_CONFIG_MAIN

// TODO: Remove the else statement.
#ifdef __APPLE__
#include <catch2/catch.hpp>
#else
#include "catch.hpp"
#endif

#include <core/nodes/node.hpp>

#include <core/nodes/expressions/absolute_value.hpp>
#include <core/nodes/expressions/cos.hpp>
#include <core/nodes/expressions/division.hpp>
#include <core/nodes/expressions/multiplication.hpp>
#include <core/nodes/expressions/opposite.hpp>
#include <core/nodes/expressions/power.hpp>
#include <core/nodes/expressions/sin.hpp>
#include <core/nodes/expressions/tan.hpp>

#include <core/nodes/expressions/values/integer.hpp>

TEST_CASE("Integer", "[CORE]")
{
    Integer int1 = Integer(3);
    Integer int2 = Integer(-2);

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

TEST_CASE("Power", "[CORE]")
{
    Integer int1 = Integer(2);
    Integer int2 = Integer(3);
    Power power = Power(int1, int2);

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
    Integer int1 = Integer(-3);
    AbsoluteValue abs = AbsoluteValue(int1);

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
    Integer int1 = Integer(-2);
    Integer int2 = Integer(3);
    Opposite opposite = Opposite(int1);
    Opposite opposite2 = Opposite(int2);

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
}

TEST_CASE("Sin", "[CORE]")
{
    Integer int1 = Integer(1);
    Sin sin = Sin(int1);
    REQUIRE(sin.toString() == "sin(1)");
    REQUIRE(sin.toLaTeX() == "\\sin{(1)}");
}

TEST_CASE("Cos", "[CORE]")
{
    Integer int1 = Integer(1);
    Cos cos = Cos(int1);
    REQUIRE(cos.toString() == "cos(1)");
    REQUIRE(cos.toLaTeX() == "\\cos{(1)}");
}

TEST_CASE("Tan", "[CORE]")
{
    Integer int1 = Integer(1);
    Tan tan = Tan(int1);
    REQUIRE(tan.toString() == "tan(1)");
    REQUIRE(tan.toLaTeX() == "\\tan{(1)}");
}

TEST_CASE("Division", "[CORE]")
{
    Integer int1 = Integer(2);
    Integer int2 = Integer(-3);
    Division division = Division(int1, int2);

    REQUIRE(division.toString() == "2/-3");
    REQUIRE(division.toLaTeX() == "\\frac{2}{-3}");
    REQUIRE(division.isPositive() == false);
    REQUIRE(division.isZero() == false);
    REQUIRE(division.isNegative() == true);
}

TEST_CASE("Multiplication", "[CORE]")
{
    Integer int1 = Integer(1);
    Integer int2 = Integer(2);
    Multiplication multiplication = Multiplication({int1, int2, int1});

    REQUIRE(multiplication.toString() == "1*2*1");
    REQUIRE(multiplication.toLaTeX() == "1\\cdot 2\\cdot 1");
}
