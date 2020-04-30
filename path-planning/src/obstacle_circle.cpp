#include "obstacle_circle.hpp"


namespace pathmapping::map {

    CircleObstacle::CircleObstacle(const geometry::Point& center, double radius):
        center(center), radius(radius) {}

    ContainedInfo CircleObstacle::containsZone(const geometry::RectangularZone& area) const {
        // TODO
        return ContainedInfo::NOT;
    }
}
