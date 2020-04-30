#pragma once 

#include "obstacle.hpp"

namespace pathmapping::map {

    class RectangleObstacle: public Obstacle {
    public:
        RectangleObstacle(const geometry::Point& a, const geometry::Point& b);

        ContainedInfo containsZone(const geometry::RectangularZone& area) const override;

    private:
        const geometry::Point a;
        const geometry::Point b;
    };

}