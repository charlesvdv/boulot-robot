#pragma once

namespace iointerface::sensor {

    class UltraSonicSensor {
    public:
        UltraSonicSensor();
        auto get_distance() const -> double;
    };

}