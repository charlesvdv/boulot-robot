#pragma once

#include <io-interface/ultra_sonic_sensor.hpp>

namespace robotlib::proximity_handler {

    using namespace iointerface::sensor;

    class ProximityHandler {
    public: 
        ProximityHandler(const UltraSonicSensor& us_sensor, const double min_distance);
        bool is_too_close() const;

    private: 
        const double min_distance;
        const UltraSonicSensor us_sensor;
    };

}