#include <cmath>

#include <path-planning/point.hpp>
#include <path-planning/math_utils.hpp>

namespace pathplanning::geometry {

    Point::Point(double x, double y):
        x(x), y(y) {}

    bool Point::operator==(const Point& other) const {
        return math::almost_equal(x, other.x) && math::almost_equal(y, other.y);
    }

    double Point::euclidian_distance(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

}
