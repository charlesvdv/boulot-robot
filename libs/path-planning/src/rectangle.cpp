#include "math-utils.hpp"

#include <algorithm>
#include <path-planning/shape.hpp>
#include <stdexcept>

namespace pathplanning::geometry {

    StraightRectangle::StraightRectangle(const Point& corner, const Point& opposite_corner):
        bottom_left_corner(
            std::min(corner.get_x(), opposite_corner.get_x()), std::min(corner.get_y(), opposite_corner.get_y())),
        top_right_corner(
            std::max(corner.get_x(), opposite_corner.get_x()), std::max(corner.get_y(), opposite_corner.get_y())) {
        // Just make sure we have a rectangle and not a line..
        if (math::almost_equal(corner.get_x(), opposite_corner.get_x()) ||
            math::almost_equal(corner.get_y(), opposite_corner.get_y())) {
            throw std::invalid_argument("not a rectangle");
        }
    }

    auto StraightRectangle::get_left_line() const -> double {
        return bottom_left_corner.get_x();
    }

    auto StraightRectangle::get_right_line() const -> double {
        return top_right_corner.get_x();
    }

    auto StraightRectangle::get_bottom_line() const -> double {
        return bottom_left_corner.get_y();
    }

    auto StraightRectangle::get_top_line() const -> double {
        return top_right_corner.get_y();
    }

    auto StraightRectangle::get_top_left_corner() const -> Point {
        return Point(get_left_line(), get_top_line());
    }

    auto StraightRectangle::get_top_right_corner() const -> Point {
        return top_right_corner;
    }

    auto StraightRectangle::get_bottom_left_corner() const -> Point {
        return bottom_left_corner;
    }

    auto StraightRectangle::get_bottom_right_corner() const -> Point {
        return Point(get_right_line(), get_bottom_line());
    }

    auto StraightRectangle::get_width() const -> double {
        return std::abs(get_right_line() - get_left_line());
    }

    auto StraightRectangle::get_height() const -> double {
        return std::abs(get_top_line() - get_bottom_line());
    }

    auto StraightRectangle::get_center() const -> Point {
        double x = (get_right_line() + get_left_line()) / 2;
        double y = (get_top_line() + get_bottom_line()) / 2;
        return Point(x, y);
    }

    auto StraightRectangle::get_area() const -> double {
        return get_width() * get_height();
    }
}