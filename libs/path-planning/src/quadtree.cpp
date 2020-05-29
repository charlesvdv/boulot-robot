#include "quadtree.hpp"

#include <stdexcept>

namespace pathplanning::quadtree {

    BoundingBox::BoundingBox(geometry::Point point, geometry::Point opposite): StraightRectangle(point, opposite) {}

}