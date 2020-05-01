#pragma once 

#include <path-planning/obstacle.hpp>

namespace pathplanning::map {

    class RectangleObstacle: public Obstacle {
    public:
        RectangleObstacle(const geometry::Point& point, const geometry::Point& opposite);

        SurfaceRelationship contains(const geometry::RectangularZone& area) const override;

    private:
        bool containsFully(const geometry::RectangularZone& area) const;
        bool overlap(const geometry::RectangularZone& area) const;

        double getLeftLine() const;
        double getRightLine() const;
        double getTopLine() const;
        double getBottomLine() const;

        const geometry::Point point;
        const geometry::Point opposite;
    };

}