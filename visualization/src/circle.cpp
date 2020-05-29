#include <visualization/circle.hpp>

namespace visualization::geometry {

    Circle::Circle(const Point& center, double radius): center(center), radius(radius) {}

    auto Circle::get_radius() const -> double {
        return radius;
    }

    auto Circle::get_center() const -> const Point& {
        return center;
    }
}