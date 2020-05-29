#pragma once

#include "point.hpp"

#include <utility>

namespace pathplanning::geometry {

    class StraightRectangle {
    public:
        StraightRectangle(const Point& corner, const Point& opposite_corner);

        auto get_left_line() const -> double;
        auto get_right_line() const -> double;
        auto get_top_line() const -> double;
        auto get_bottom_line() const -> double;

        auto get_top_left_corner() const -> Point;
        auto get_top_right_corner() const -> Point;
        auto get_bottom_left_corner() const -> Point;
        auto get_bottom_right_corner() const -> Point;

        auto get_width() const -> double;
        auto get_height() const -> double;

        auto get_center() const -> Point;

        auto get_area() const -> double;

    private:
        Point bottom_left_corner;
        Point top_right_corner;
    };

}