#include <robotlib/proximity_handler.hpp>

namespace robotlib::proximity_handler {

    ProximityHandler::ProximityHandler(double min_distance):
        min_distance(min_distance) {}

    bool ProximityHandler::isTooClose() {
        double distance = 10; // should be returned by the actual sensor

        if (distance > min_distance) {
            return true;
        }

        return false;
    }
}