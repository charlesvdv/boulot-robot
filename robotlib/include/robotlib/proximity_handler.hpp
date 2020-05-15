#pragma once

#include <io-interface/ultra_sonic_sensor.hpp>

namespace robotlib::proximity_handler {

    class ProximityHandler {
    public: 
        ProximityHandler(const double min_distance);
        bool is_too_close() const;

    private: 
        double min_distance;
    };

}