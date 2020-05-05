#pragma once 

#include <path-planning/obstacle.hpp>
#include <path-planning/point.hpp>
#include <path-planning/shape.hpp>

namespace pathplanning::map {

    class RectangleObstacle: public Obstacle, private geometry::StraightRectangle {
    public:
        RectangleObstacle(const geometry::Point& corner, const geometry::Point& opposite_corner);

        SurfaceRelationship get_relation_with_zone(const geometry::StraightRectangle& rectangle) const override;

    private:
        bool contains(const geometry::StraightRectangle& rectangle) const;
        bool contained(const geometry::StraightRectangle& rectangle) const;
        bool overlap(const geometry::StraightRectangle& rectangle) const;
    };

}