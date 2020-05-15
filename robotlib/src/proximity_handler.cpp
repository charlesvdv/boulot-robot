#include <robotlib/proximity_handler.hpp>

namespace robotlib::proximity_handler {

    ProximityHandler::ProximityHandler(UltraSonicSensor us_sensor, const double min_distance):
        us_sensor(us_sensor), min_distance(min_distance) {}

    bool ProximityHandler::is_too_close() const {
        const double distance = us_sensor.get_distance();

        if (distance > min_distance) {
            return true;
        }

        return false;
    }
}