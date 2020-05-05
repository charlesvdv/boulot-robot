#pragma once

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>

namespace pathplanning::map {

    class CircleObstacle: public Obstacle {
    public:
        CircleObstacle(const geometry::Point& center, double radius);

        SurfaceRelationship get_relation_with_zone(const geometry::StraightRectangle& rectangle) const override;

    private:
        bool contains(const geometry::StraightRectangle& rectangle) const;
        bool contained(const geometry::StraightRectangle& rectangle) const;
        bool overlap(const geometry::StraightRectangle& rectangle) const;

        bool contains_point(const geometry::Point& point) const;

        const geometry::Point center;
        double radius;
    };
}