#include <visualization/point.hpp>

namespace visualization::geometry {

    Point::Point(double x, double y):
        x(x), y(y) {}

    double Point::get_x() const {
        return x;
    }

    double Point::get_y() const {
        return y;
    }
}
