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

        geometry::Point get_top_left_coner() const;
        geometry::Point get_top_right_coner() const;
        geometry::Point get_bottom_left_coner() const;
        geometry::Point get_bottom_right_corner() const;

        double get_width() const;
        double get_height() const;
        
        geometry::Point get_center() const;

    private:
        Point point;
        Point opposite;
    };

}