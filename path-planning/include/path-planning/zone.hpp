#pragma once

#include <utility>

#include "point.hpp"

namespace pathplanning::geometry {

    class RectangularZone {
    public:
        RectangularZone(const Point& point, const Point& opposite);

        double get_left_line() const;
        double get_right_line() const;
        double get_top_line() const;
        double get_bottom_line() const;

    private:
        Point point;
        Point opposite;
    };

}