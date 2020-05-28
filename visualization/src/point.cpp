#include <visualization/point.hpp>

namespace visualization::geometry {

    Point::Point(double x, double y): x(x), y(y) {}

    auto Point::get_x() const -> double {
        return x;
    }

    auto Point::get_y() const -> double {
        return y;
    }
}
