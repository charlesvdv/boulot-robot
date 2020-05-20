#include <visualization/circle.hpp>

namespace visualization::geometry {

    Circle::Circle(const Point& center, double radius):
        center(center), radius(radius) {
    }

    double Circle::get_radius() const {
        return radius;
    }
    
    Point Circle::get_center() const {
        return center;
    }
}