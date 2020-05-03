#pragma once 

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>

namespace pathplanning::map {

    class RectangleObstacle: public Obstacle {
    public:
        RectangleObstacle(const geometry::Point& point, const geometry::Point& opposite);

        SurfaceRelationship contains(const geometry::RectangularZone& zone) const override;

    private:
        bool contains_fully(const geometry::RectangularZone& area) const;
        bool overlap(const geometry::RectangularZone& area) const;

        double get_left_line() const;
        double get_right_line() const;
        double get_top_line() const;
        double get_bottom_line() const;

        const geometry::Point point;
        const geometry::Point opposite;
    };

}