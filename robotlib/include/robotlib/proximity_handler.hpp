#pragma once

#include <io-interface/ultra_sonic_sensor.hpp>

namespace robotlib::proximity_handler {

    class ProximityHandler {
    public: 
        ProximityHandler(double min_distance);
        bool isTooClose();

    private: 
        double min_distance;
    };

}