#include <robotlib/proximity_handler.hpp>

namespace robotlib::proximity_handler {

    Proximity_handler::Proximity_handler(double min_distance):
        min_distance(min_distance) {}

    bool Proximity_handler::isTooClose() {
        double distance = 10; // should be returned by the actual sensor

        if (distance > min_distance) {
            return true;
        }

        return false;
    }
}