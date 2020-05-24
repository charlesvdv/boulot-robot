#include <io-interface/ultra_sonic_sensor.hpp>

namespace iointerface::sensor {

    UltraSonicSensor::UltraSonicSensor() = default;

    auto UltraSonicSensor::get_distance() const -> double {
        return 10; // should come from the sensor itself
    }
}