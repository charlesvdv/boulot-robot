#pragma once

#include <memory>

#include "point.hpp"
#include "zone.hpp"

namespace pathplanning::map {

    enum class SurfaceRelationship {
        // Two surfaces are overlapping each other
        OVERLAP, 
        // Two surfaces are not touching each other
        DISJOINT,
        // A surface contains the others.
        CONTAINS,
    };

    class Obstacle {
    public:
        static std::unique_ptr<Obstacle> make_rectangle(const geometry::Point& point, const geometry::Point& opposite);
        static std::unique_ptr<Obstacle> make_circle(const geometry::Point& center, double radius);

        virtual ~Obstacle();

        // Check whether the obstacle contains a given rectangular zone.
        virtual SurfaceRelationship contains(const geometry::RectangularZone& area) const = 0;
    };

}