#pragma once

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>

namespace pathplanning::map {

    class CircleObstacle: public Obstacle {
    public:
        CircleObstacle(const geometry::Point& center, double radius);

        SurfaceRelationship contains(const geometry::RectangularZone& area) const override;

    private:
        const geometry::Point center;
        double radius;
    };

}