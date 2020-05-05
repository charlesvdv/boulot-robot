#pragma once

#include <memory>

#include "point.hpp"
#include "shape.hpp"

namespace pathplanning::map {

    enum class SurfaceRelationship {
        OVERLAP, 
        DISJOINT,
        CONTAINS,
        CONTAINED,
    };

    class Obstacle {
    public:
        static std::unique_ptr<Obstacle> make_rectangle(const geometry::Point& point, const geometry::Point& opposite);
        static std::unique_ptr<Obstacle> make_circle(const geometry::Point& center, double radius);

        virtual ~Obstacle();

        // Check the obstacle relationship with a given zone
        //  - OVERLAP: the obstacle overlap with the given zone
        //  - DISJOINT: the obstacle does have any contact with the zone
        //  - CONTAINS: the obstacle contains the zone
        //  - CONTAINED: the obstacle is contained in the zone
        virtual SurfaceRelationship get_relation_with_zone(const geometry::StraightRectangle& rectangle) const = 0;
    };

}