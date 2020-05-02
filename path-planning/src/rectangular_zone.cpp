#include <algorithm>

#include <path-planning/zone.hpp>

namespace pathplanning::geometry {

    RectangularZone::RectangularZone(const Point& point, const Point& opposite):
        point(point), opposite(opposite) {}

    double RectangularZone::get_left_line() const {
        return std::min(point.get_x(), opposite.get_x());
    }

    double RectangularZone::get_right_line() const {
        return std::max(point.get_x(), opposite.get_x());
    }

    double RectangularZone::get_bottom_line() const {
        return std::min(point.get_y(), opposite.get_y());
    }

    double RectangularZone::get_top_line() const {
        return std::max(point.get_y(), opposite.get_y());
    }

}