#include <algorithm>
#include "obstacle_rectangle.hpp"

namespace pathplanning::map {

    RectangleObstacle::RectangleObstacle(const geometry::Point& point, const geometry::Point& opposite):
        point(point), opposite(opposite) {}

    SurfaceRelationship RectangleObstacle::contains(const geometry::RectangularZone& zone) const {
        if (containsFully(zone)) {
            return SurfaceRelationship::CONTAINS;
        } else if (overlap(zone)) {
            return SurfaceRelationship::OVERLAP;
        }
        return SurfaceRelationship::DISJOINT;
    }

    bool RectangleObstacle::containsFully(const geometry::RectangularZone& zone) const {
        if (getLeftLine() < zone.getLeftLine() && getRightLine() > zone.getRightLine() &&
                getBottomLine() < zone.getBottomLine() && getTopLine() > zone.getTopLine()) {
            return true;
        }
        return false;
    }

    bool RectangleObstacle::overlap(const geometry::RectangularZone& zone) const {
        if (getRightLine() < zone.getLeftLine() || getLeftLine() > zone.getRightLine()) {
            // If x coordinates don't cross, it's impossible to have an overlap
            return false;
        }
        if (getTopLine() < zone.getBottomLine() || getBottomLine() > zone.getTopLine()) {
            // If y coordinates don't cross, it's impossible to have an overlap
            return false;
        }
        return true;
    }

    double RectangleObstacle::getLeftLine() const {
        return std::min(point.getX(), opposite.getX());
    }

    double RectangleObstacle::getRightLine() const {
        return std::max(point.getX(), opposite.getX());
    }

    double RectangleObstacle::getBottomLine() const {
        return std::min(point.getY(), opposite.getY());
    }

    double RectangleObstacle::getTopLine() const {
        return std::max(point.getY(), opposite.getY());
    }
}
