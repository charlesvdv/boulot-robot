#include <io-interface/ultra-sonic-sensor.hpp>

namespace iointerface::sensor {

    UltraSonicSensor::UltraSonicSensor() = default;

    auto UltraSonicSensor::get_distance() const -> double {
        return 10; // should come from the sensor itself
    }
}