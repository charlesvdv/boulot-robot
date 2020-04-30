#include "obstacle.hpp"
#include "obstacle_rectangle.hpp"
#include "obstacle_circle.hpp"

namespace pathmapping::map {

    std::unique_ptr<Obstacle> Obstacle::make_rectangle(const geometry::Point& lhs, const geometry::Point& rhs) {
        return std::make_unique<RectangleObstacle>(lhs, rhs);
    }

    std::unique_ptr<Obstacle> Obstacle::make_circle(const geometry::Point& center, double radius) {
        return std::make_unique<CircleObstacle>(center, radius);
    }

}
