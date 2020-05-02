#include "obstacle_circle.hpp"

#include <cmath>

namespace pathplanning::map {

    CircleObstacle::CircleObstacle(const geometry::Point& center, double radius):
        center(center), radius(radius) {}

    SurfaceRelationship CircleObstacle::contains(const geometry::RectangularZone& zone) const {
        if (contains_fully(zone)) {
            return SurfaceRelationship::CONTAINS;
        } else if (overlap(zone)) {
            return SurfaceRelationship::OVERLAP;
        }
        return SurfaceRelationship::DISJOINT;
    }

    bool CircleObstacle::contains_fully(const geometry::RectangularZone& zone) const {
        if (contains_point(zone.get_bottom_left_coner()) && 
                contains_point(zone.get_top_left_coner()) &&
                contains_point(zone.get_bottom_right_corner()) &&
                contains_point(zone.get_top_right_coner())) {
            return true;
        }
        return false;
    }

    // Circle completly inside zone is considered in overlap.
    // According to https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
    bool CircleObstacle::overlap(const geometry::RectangularZone& zone) const {
        double distance_x = std::abs(center.get_x() - zone.get_center().get_x());
        double distance_y = std::abs(center.get_y() - zone.get_center().get_y());

        if (distance_x > (zone.get_width()/2 + radius)) { 
            return false; 
        }
        if (distance_y > (zone.get_height()/2 + radius)) { 
            return false; 
        }

        if (distance_x <= (zone.get_width()/2)) { 
            return true; 
        } 
        if (distance_y <= (zone.get_height()/2)) { 
            return true; 
        }

        geometry::Point half_zone(zone.get_width()/2, zone.get_height()/2);
        if (std::pow(distance_x - half_zone.get_x(), 2) + std::pow(distance_y - half_zone.get_y(), 2) <= std::pow(radius, 2)) {
            return true;
        }
        return false;
    }

    bool CircleObstacle::contains_point(const geometry::Point& point) const {
        if (std::pow(center.get_x() - point.get_x(), 2) + std::pow(center.get_y() - point.get_y(), 2) > std::pow(radius, 2)) {
            return false;
        }
        return true;
    }
}
