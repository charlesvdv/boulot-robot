#pragma once

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>

namespace pathplanning::map {

    class CircleObstacle: public Obstacle {
    public:
        CircleObstacle(const geometry::Point& center, double radius);

        auto get_relation_with_zone(const geometry::StraightRectangle& rectangle) const -> SurfaceRelationship override;

    private:
        auto contains(const geometry::StraightRectangle& rectangle) const -> bool;
        auto contained(const geometry::StraightRectangle& rectangle) const -> bool;
        auto overlap(const geometry::StraightRectangle& rectangle) const -> bool;

        auto contains_point(const geometry::Point& point) const -> bool;

        const geometry::Point center;
        double radius;
    };
    
}