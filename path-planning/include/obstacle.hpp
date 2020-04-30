#pragma once

#include <memory>

#include "point.hpp"
#include "zone.hpp"

namespace pathmapping::map {

    enum class ContainedInfo {
        // Contained fully
        FULL,
        // Not contained
        NOT,
        // Partially contained
        PARTIAL,
    };

    class Obstacle {
    public:
        static std::unique_ptr<Obstacle> make_rectangle(const geometry::Point& lhs, const geometry::Point& rhs);
        static std::unique_ptr<Obstacle> make_circle(const geometry::Point& center, double radius);

        // Check whether the obstacle contains a given rectangular zone.
        // The zone can be either contained fully, not or only partial.
        virtual ContainedInfo containsZone(const geometry::RectangularZone& area) const = 0;
    };

}