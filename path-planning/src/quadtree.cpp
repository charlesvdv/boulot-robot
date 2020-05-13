#include <stdexcept>

#include "quadtree.hpp"

namespace pathplanning::quadtree {

    BoundingBox::BoundingBox(geometry::Point point, geometry::Point opposite):
        StraightRectangle(point, opposite) {}

}