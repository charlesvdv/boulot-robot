#pragma once

#include <path-planning/map.hpp>

#include "quadtree.hpp"

namespace pathplanning::map {

    enum class ZoneStatus {
        OBSTACLE,
        FREE,
    };

    class MapImpl: public Map {
    public:
        MapImpl(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles);

        bool is_point_in_obstacle(const geometry::Point& point) const override;

    private:
        bool is_point_in_map(const geometry::Point& point) const;
        bool is_point_in_obstacle_recursive(const quadtree::Node<ZoneStatus>& node, const geometry::Point& point) const;

        quadtree::Root<ZoneStatus> map;
    };

}
