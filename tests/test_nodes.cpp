#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <core/nodes/node.hpp>

#include <core/nodes/expressions/absolute_value.hpp>
#include <core/nodes/expressions/opposite.hpp>
#include <core/nodes/expressions/power.hpp>

#include <core/nodes/expressions/values/integer.hpp>

TEST_CASE("Power", "[CORE]")
{
    Integer int1 = Integer(2);
    Integer int2 = Integer(3);
    Power power = Power(int1, int2);
    REQUIRE(power.toString() == "2^3");
    REQUIRE(power.toLaTeX() == "{2}^{3}");
}

TEST_CASE("Absolute value", "[CORE]")
{
    Integer int1 = Integer(-3);
    AbsoluteValue abs = AbsoluteValue(int1);
    REQUIRE(abs.toString() == "|-3|");
    REQUIRE(abs.toLaTeX() == "\\left\\mid-3\\right\\mid");
}

TEST_CASE("Opposite", "[CORE]")
{
    Integer int1 = Integer(-2);
    Opposite opposite = Opposite(int1);
    REQUIRE(opposite.toString() == "--2");
    REQUIRE(opposite.toLaTeX() == "--2");
}
