#pragma once

namespace iointerface::sensor {

    class UltraSonicSensor {
    public:
        UltraSonicSensor();
        double get_distance() const;
    };

}