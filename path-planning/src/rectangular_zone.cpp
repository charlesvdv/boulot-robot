#include <algorithm>

#include <path-planning/zone.hpp>

namespace pathplanning::geometry {

    RectangularZone::RectangularZone(const Point& point, const Point& opposite):
        point(point), opposite(opposite) {}

    double RectangularZone::getLeftLine() const {
        return std::min(point.getX(), opposite.getX());
    }

    double RectangularZone::getRightLine() const {
        return std::max(point.getX(), opposite.getX());
    }

    double RectangularZone::getBottomLine() const {
        return std::min(point.getY(), opposite.getY());
    }

    double RectangularZone::getTopLine() const {
        return std::max(point.getY(), opposite.getY());
    }

}