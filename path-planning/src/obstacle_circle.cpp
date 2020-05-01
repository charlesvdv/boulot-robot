#include "obstacle_circle.hpp"


namespace pathplanning::map {

    CircleObstacle::CircleObstacle(const geometry::Point& center, double radius):
        center(center), radius(radius) {}

    SurfaceRelationship CircleObstacle::contains(const geometry::RectangularZone& area) const {
        // TODO
        return SurfaceRelationship::DISJOINT;
    }
}
