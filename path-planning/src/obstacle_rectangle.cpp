#include <algorithm>
#include "obstacle_rectangle.hpp"

namespace pathplanning::map {

    RectangleObstacle::RectangleObstacle(const geometry::Point& point, const geometry::Point& opposite):
        point(point), opposite(opposite) {}

    SurfaceRelationship RectangleObstacle::contains(const geometry::RectangularZone& zone) const {
        if (contains_fully(zone)) {
            return SurfaceRelationship::CONTAINS;
        } else if (overlap(zone)) {
            return SurfaceRelationship::OVERLAP;
        }
        return SurfaceRelationship::DISJOINT;
    }

    bool RectangleObstacle::contains_fully(const geometry::RectangularZone& zone) const {
        if (get_left_line() < zone.get_left_line() && get_right_line() > zone.get_right_line() &&
                get_bottom_line() < zone.get_bottom_line() && get_top_line() > zone.get_top_line()) {
            return true;
        }
        return false;
    }

    bool RectangleObstacle::overlap(const geometry::RectangularZone& zone) const {
        if (get_right_line() < zone.get_left_line() || get_left_line() > zone.get_right_line()) {
            // If x coordinates don't cross, it's impossible to have an overlap
            return false;
        }
        if (get_top_line() < zone.get_bottom_line() || get_bottom_line() > zone.get_top_line()) {
            // If y coordinates don't cross, it's impossible to have an overlap
            return false;
        }
        return true;
    }

    double RectangleObstacle::get_left_line() const {
        return std::min(point.get_x(), opposite.get_x());
    }

    double RectangleObstacle::get_right_line() const {
        return std::max(point.get_x(), opposite.get_x());
    }

    double RectangleObstacle::get_bottom_line() const {
        return std::min(point.get_y(), opposite.get_y());
    }

    double RectangleObstacle::get_top_line() const {
        return std::max(point.get_y(), opposite.get_y());
    }
}
