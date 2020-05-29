#include <catch2/catch.hpp>
#include <robotlib/proximity_handler.hpp>

using namespace iointerface::sensor;
using namespace robotlib::proximity_handler;

TEST_CASE("Verify the proximity handler detects to close objects") {
    const double min_distance = 20;
    UltraSonicSensor us_sensor;
    ProximityHandler proximity_handler(us_sensor, min_distance);

    SECTION("far enough from any object") {
        REQUIRE(false == proximity_handler.is_too_close());
    }
}