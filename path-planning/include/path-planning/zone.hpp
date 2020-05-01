#pragma once

#include <utility>

#include "point.hpp"

namespace pathplanning::geometry {

    class RectangularZone {
    public:
        RectangularZone(const Point& point, const Point& opposite);

        double getLeftLine() const;
        double getRightLine() const;
        double getTopLine() const;
        double getBottomLine() const;

    private:
        Point point;
        Point opposite;
    };

}