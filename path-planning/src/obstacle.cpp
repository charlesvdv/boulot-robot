#include <path-planning/obstacle.hpp>
#include "obstacle_rectangle.hpp"
#include "obstacle_circle.hpp"

namespace pathplanning::map {

    auto Obstacle::make_rectangle(const geometry::Point& point, const geometry::Point& opposite) -> std::unique_ptr<Obstacle> {
        return std::make_unique<RectangleObstacle>(point, opposite);
    }

    auto Obstacle::make_circle(const geometry::Point& center, double radius) -> std::unique_ptr<Obstacle> {
        return std::make_unique<CircleObstacle>(center, radius);
    }

}
