#pragma once

#include "point.hpp"
#include "shape.hpp"

#include <memory>

namespace pathplanning::map {

    enum class SurfaceRelationship {
        OVERLAP,
        DISJOINT,
        CONTAINS,
        CONTAINED,
    };

    class Obstacle {
    public:
        static auto make_rectangle(const geometry::Point& point, const geometry::Point& opposite)
            -> std::unique_ptr<Obstacle>;
        static auto make_circle(const geometry::Point& center, double radius) -> std::unique_ptr<Obstacle>;

        virtual ~Obstacle() = default;

        // Check the obstacle relationship with a given zone
        //  - OVERLAP: the obstacle overlap with the given zone
        //  - DISJOINT: the obstacle does have any contact with the zone
        //  - CONTAINS: the obstacle contains the zone
        //  - CONTAINED: the obstacle is contained in the zone
        // If the obstacle is touching the zone only by a point or a line, the obstacle
        //  is considered DISJOINT from the zone.
        virtual auto get_relation_with_zone(const geometry::StraightRectangle& rectangle) const
            -> SurfaceRelationship = 0;
    };

}