#include <io-interface/ultra_sonic_sensor.hpp>

namespace iointerface::sensor {

    UltraSonicSensor::UltraSonicSensor() {}

    double UltraSonicSensor::get_distance() const {
        return 10; // should come from the sensor itself
    }
}