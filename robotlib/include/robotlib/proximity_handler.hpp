#pragma once

#include <io-interface/ultra_sonic_sensor.hpp>

using namespace iointerface::sensor;

namespace robotlib::proximity_handler {

    class ProximityHandler {
    public: 
        ProximityHandler(UltraSonicSensor us_sensor, const double min_distance);
        bool is_too_close() const;

    private: 
        double min_distance;
        UltraSonicSensor us_sensor;
    };

}