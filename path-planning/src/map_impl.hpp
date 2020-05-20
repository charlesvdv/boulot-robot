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

        auto is_point_in_obstacle(const geometry::Point& point) const -> bool override;

    private:
        auto is_point_in_map(const geometry::Point& point) const -> bool;
        auto is_point_in_obstacle_recursive(const quadtree::Node<ZoneStatus>& node, const geometry::Point& point) const -> bool;

        static auto build_map(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles) -> quadtree::Root<ZoneStatus>;
        static void add_obstacle_to_map(quadtree::Root<ZoneStatus>& root, const std::shared_ptr<Obstacle>& obstacle, double precision);
        static void obstacle_refinement(quadtree::Node<ZoneStatus>& node, const std::shared_ptr<Obstacle>& obstacle, double precision);
        static void base_case_obstacle_refinement(quadtree::Node<ZoneStatus>& node, const std::shared_ptr<Obstacle>& obstacle);
        static void recursive_case_obstacle_refinement(quadtree::Node<ZoneStatus>& node, const std::shared_ptr<Obstacle>& obstacle, double precision);

        quadtree::Root<ZoneStatus> map;
    };

}
