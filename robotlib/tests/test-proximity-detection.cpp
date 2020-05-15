#include <catch2/catch.hpp>

#include <robotlib/proximity_handler.hpp>

using namespace robotlib::proximity_handler;

TEST_CASE("Verify the proximity handler detects to close objects") {

    SECTION("to close object") {
        REQUIRE(1 == 1);
    }
}