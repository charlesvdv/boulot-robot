#pragma once

#include <obstacle.hpp>
#include <point.hpp>

namespace pathmapping::map {

    class CircleObstacle: public Obstacle {
    public:
        CircleObstacle(const geometry::Point& center, double radius);

        ContainedInfo containsZone(const geometry::RectangularZone& area) const override;
    private:
        const geometry::Point center;
        double radius;
    };

}