#include <path-planning/obstacle.hpp>
#include "obstacle_rectangle.hpp"
#include "obstacle_circle.hpp"

namespace pathplanning::map {

    std::unique_ptr<Obstacle> Obstacle::make_rectangle(const geometry::Point& point, const geometry::Point& opposite) {
        return std::make_unique<RectangleObstacle>(point, opposite);
    }

    std::unique_ptr<Obstacle> Obstacle::make_circle(const geometry::Point& center, double radius) {
        return std::make_unique<CircleObstacle>(center, radius);
    }

}
