#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <core/nodes/node.hpp>
#include <core/nodes/expressions/power.hpp>
#include <core/nodes/expressions/values/integer.hpp>

TEST_CASE("Power", "[CORE]")
{
    Integer int1 = Integer(2);
    Integer int2 = Integer(3);
    Power power = Power(int1, int2);
    REQUIRE(power.ToString() == "2^3");
    REQUIRE(power.ToLaTeX() == "{2}^{3}");
}
