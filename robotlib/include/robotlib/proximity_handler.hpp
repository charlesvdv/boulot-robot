#pragma once

#include <io-interface/ultra_sonic_sensor.hpp>

namespace robotlib::proximity_handler {

    class Proximity_handler {
    public: 
        Proximity_handler(double min_distance);
        bool isTooClose();

    private: 
        double min_distance;
    };

}