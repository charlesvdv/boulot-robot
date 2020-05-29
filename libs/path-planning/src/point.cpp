#include "math-utils.hpp"

#include <cmath>
#include <path-planning/point.hpp>

namespace pathplanning::geometry {

    Point::Point(double x, double y): x(x), y(y) {}

    auto Point::operator==(const Point& other) const -> bool {
        return math::almost_equal(x, other.x) && math::almost_equal(y, other.y);
    }

    auto Point::euclidian_distance(const Point& other) const -> double {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    auto Point::get_x() const -> double {
        return x;
    }

    auto Point::get_y() const -> double {
        return y;
    }

}
