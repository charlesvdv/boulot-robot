#pragma once

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>

namespace pathplanning::map {

    class CircleObstacle: public Obstacle {
    public:
        CircleObstacle(const geometry::Point& center, double radius);

        SurfaceRelationship contains(const geometry::RectangularZone& zone) const override;

    private:
        bool contains_fully(const geometry::RectangularZone& zone) const;
        bool overlap(const geometry::RectangularZone& zone) const;

        bool contains_point(const geometry::Point& point) const;

        const geometry::Point center;
        double radius;
    };
}