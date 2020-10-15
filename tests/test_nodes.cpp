#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <core/nodes/node.hpp>

#include <core/nodes/expressions/absolute_value.hpp>
#include <core/nodes/expressions/opposite.hpp>
#include <core/nodes/expressions/power.hpp>

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
}

TEST_CASE("Opposite", "[CORE]")
{
    Integer int1 = Integer(-2);
    Opposite opposite = Opposite(int1);

    REQUIRE(opposite.toString() == "--2");
    REQUIRE(opposite.toLaTeX() == "--2");
    REQUIRE(opposite.isPositive() == true);
    REQUIRE(opposite.isStrictlyPositive() == true);
    REQUIRE(opposite.isZero() == false);
    REQUIRE(opposite.isStrictlyNegative() == false);
    REQUIRE(opposite.isNegative() == false);
    REQUIRE(opposite.isEven() == true);
    REQUIRE(opposite.isOdd() == false);
}
