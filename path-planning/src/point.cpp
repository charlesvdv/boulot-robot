#include "point.hpp"

namespace pathmapping::geometry {

    Point::Point(double x, double y):
        x(x), y(y) {}

    double Point::getX() const {
        return x;
    }

    double Point::getY() const {
        return y;
    }

}
