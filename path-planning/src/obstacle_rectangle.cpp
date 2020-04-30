#include "obstacle_rectangle.hpp"

namespace pathmapping::map {

    RectangleObstacle::RectangleObstacle(const geometry::Point& a, const geometry::Point& b):
        a(a), b(b) {}

    ContainedInfo RectangleObstacle::containsZone(const geometry::RectangularZone& area) const {
        return ContainedInfo::NOT;
    }

}
