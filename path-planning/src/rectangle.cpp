#include <algorithm>
#include <stdexcept>

#include <path-planning/shape.hpp>

#include "math_utils.hpp"

namespace pathplanning::geometry {

    StraightRectangle::StraightRectangle(const Point& corner, const Point& opposite_corner):
        bottom_left_corner(std::min(corner.get_x(), opposite_corner.get_x()), 
            std::min(corner.get_y(), opposite_corner.get_y())), 
        top_right_corner(std::max(corner.get_x(), opposite_corner.get_x()), 
                std::max(corner.get_y(), opposite_corner.get_y())) {
        // Just make sure we have a rectangle and not a line..
        if (math::almost_equal(corner.get_x(), opposite_corner.get_x()) || 
                math::almost_equal(corner.get_y(), opposite_corner.get_y())) {
            throw std::invalid_argument("not a rectangle");
        }
    }

    double StraightRectangle::get_left_line() const {
        return bottom_left_corner.get_x();
    }

    double StraightRectangle::get_right_line() const {
        return top_right_corner.get_x();
    }

    double StraightRectangle::get_bottom_line() const {
        return bottom_left_corner.get_y();
    }

    double StraightRectangle::get_top_line() const {
        return top_right_corner.get_y();
    }

    Point StraightRectangle::get_top_left_corner() const {
        return Point(get_left_line(), get_top_line());
    }

    Point StraightRectangle::get_top_right_corner() const {
        return top_right_corner;
    }

    Point StraightRectangle::get_bottom_left_corner() const {
        return bottom_left_corner;
    }

    Point StraightRectangle::get_bottom_right_corner() const {
        return Point(get_right_line(), get_bottom_line());
    }

    double StraightRectangle::get_width() const {
        return std::abs(get_right_line() - get_left_line());
    }

    double StraightRectangle::get_height() const {
        return std::abs(get_top_line() - get_bottom_line());
    }

    Point StraightRectangle::get_center() const {
        double x = (get_right_line() + get_left_line())/2;
        double y = (get_top_line() + get_bottom_line())/2;
        return Point(x, y);
    }
}