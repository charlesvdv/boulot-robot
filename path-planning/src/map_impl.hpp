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

        static quadtree::Root<ZoneStatus> build_map(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles);
        static void add_obstacle_to_map(quadtree::Root<ZoneStatus>& root, std::shared_ptr<Obstacle> obstacle, double precision);
        static void obstacle_refinement(quadtree::Node<ZoneStatus>& node, std::shared_ptr<Obstacle> obstacle, double precision);
        static void base_case_obstacle_refinement(quadtree::Node<ZoneStatus>& node, std::shared_ptr<Obstacle> obstacle);
        static void recursive_case_obstacle_refinement(quadtree::Node<ZoneStatus>& node, std::shared_ptr<Obstacle> obstacle, double precision);

        quadtree::Root<ZoneStatus> map;
    };

}
