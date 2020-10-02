#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <core/nodes/node.hpp>
#include <core/nodes/power.hpp>
#include <core/nodes/values/integer.hpp>

TEST_CASE("Tests started", "[TESTS]")
{
    Integer int1 = Integer(2);
    Integer int2 = Integer(3);
    REQUIRE(Power(&int1, &int2).ToString() == "2^3");
}
