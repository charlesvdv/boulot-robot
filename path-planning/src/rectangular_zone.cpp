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

    geometry::Point RectangularZone::get_top_left_coner() const {
        return geometry::Point(get_left_line(), get_top_line());
    }
    geometry::Point RectangularZone::get_top_right_coner() const {
        return geometry::Point(get_right_line(), get_top_line());
    }

    geometry::Point RectangularZone::get_bottom_left_coner() const {
        return geometry::Point(get_left_line(), get_bottom_line());
    }

    geometry::Point RectangularZone::get_bottom_right_corner() const {
        return geometry::Point(get_right_line(), get_bottom_line());
    }

    double RectangularZone::get_width() const {
        return std::abs(get_right_line() - get_left_line());
    }

    double RectangularZone::get_height() const {
        return std::abs(get_top_line() - get_bottom_line());
    }

    geometry::Point RectangularZone::get_center() const {
        double x = (get_right_line() + get_left_line())/2;
        double y = (get_top_line() + get_bottom_line())/2;
        return geometry::Point(x, y);
    }
}