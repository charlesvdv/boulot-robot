#include "map_impl.hpp"

#include <stdexcept>
#include <utility>

namespace pathplanning::map {

    using QuadtreeRoot = quadtree::Root<ZoneStatus>;
    using QuadtreeNode = quadtree::Node<ZoneStatus>;
    using QuadtreeBranches = quadtree::Branches<ZoneStatus>;

    namespace {
        void unknown_state_error() {
            throw std::logic_error("Unknown state when building map");
        }
    }

    MapImpl::MapImpl(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles):
        map(build_map(dimension, obstacles)) {}

    auto MapImpl::is_point_in_obstacle(const geometry::Point& point) const -> bool {
        if (!is_point_in_map(point)) {
            throw std::logic_error("point not in map");
        }

        return is_point_in_obstacle_recursive(map, point);
    }

    auto MapImpl::is_point_in_obstacle_recursive(const QuadtreeNode& node, const geometry::Point& point) const -> bool {
        if (node.get_type() == quadtree::NodeType::LEAF) {
            return node.get_leaf_value() == ZoneStatus::OBSTACLE;
        }
        if (node.get_type() == quadtree::NodeType::BRANCH) {
            std::shared_ptr<QuadtreeBranches> branches = node.get_branches();
            const geometry::Point& splitting_node = branches->get_splitting_point();
            if (point.get_x() <= splitting_node.get_x() && point.get_y() >= splitting_node.get_y()) {
                return is_point_in_obstacle_recursive(branches->get_top_left_node(), point);
            }
            if (point.get_x() >= splitting_node.get_x() && point.get_y() >= splitting_node.get_y()) {
                return is_point_in_obstacle_recursive(branches->get_top_right_node(), point);
            }
            if (point.get_x() <= splitting_node.get_x() && point.get_y() <= splitting_node.get_y()) {
                return is_point_in_obstacle_recursive(branches->get_bottom_left_node(), point);
            }
            if (point.get_x() >= splitting_node.get_x() && point.get_y() <= splitting_node.get_y()) {
                return is_point_in_obstacle_recursive(branches->get_bottom_right_node(), point);
            }
        }

        throw std::logic_error("unkown node type");
    }

    auto MapImpl::is_point_in_map(const geometry::Point& point) const -> bool {
        const quadtree::BoundingBox& map_rect = map.get_bounding_box();
        if (point.get_x() < map_rect.get_left_line() || point.get_y() < map_rect.get_bottom_line()) {
            return false;
        }

        if (point.get_x() > map_rect.get_right_line() || point.get_y() > map_rect.get_top_line()) {
            return false;
        }

        return true;
    }

    auto MapImpl::build_map(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles)
        -> QuadtreeRoot {
        geometry::Point origin(0.0, 0.0);
        geometry::Point opposite(dimension.get_length(), dimension.get_width());
        QuadtreeRoot root(quadtree::BoundingBox(origin, opposite), ZoneStatus::FREE);

        for (const auto& obstacle: obstacles) {
            add_obstacle_to_map(root, obstacle, dimension.get_precision());
        }

        return root;
    }

    void MapImpl::add_obstacle_to_map(QuadtreeRoot& root, const std::shared_ptr<Obstacle>& obstacle, double precision) {
        obstacle_refinement(root, obstacle, precision);
    }

    void MapImpl::obstacle_refinement(QuadtreeNode& node, const std::shared_ptr<Obstacle>& obstacle, double precision) {
        if (node.get_bounding_box().get_area() < precision) {
            base_case_obstacle_refinement(node, obstacle);
            return;
        }

        recursive_case_obstacle_refinement(node, obstacle, precision);
    }

    void MapImpl::base_case_obstacle_refinement(QuadtreeNode& node, const std::shared_ptr<Obstacle>& obstacle) {
        SurfaceRelationship obstacle_relationship = obstacle->get_relation_with_zone(node.get_bounding_box());

        if (obstacle_relationship == SurfaceRelationship::DISJOINT) {
            return;
        } else if (obstacle_relationship == SurfaceRelationship::CONTAINS ||
                   obstacle_relationship == SurfaceRelationship::CONTAINED ||
                   obstacle_relationship == SurfaceRelationship::OVERLAP) {
            // If we overlap but we reached the end of the quadtree,
            // we set the zone as obstacle to avoid any issue.
            node.set_leaf_value(ZoneStatus::OBSTACLE);
        } else {
            unknown_state_error();
        }
    }

    void MapImpl::recursive_case_obstacle_refinement(
        QuadtreeNode& node, const std::shared_ptr<Obstacle>& obstacle, double precision) {
        SurfaceRelationship obstacle_relationship = obstacle->get_relation_with_zone(node.get_bounding_box());

        if (obstacle_relationship == SurfaceRelationship::DISJOINT) {
            return;
        } else if (obstacle_relationship == SurfaceRelationship::CONTAINS) {
            if (node.get_type() == quadtree::NodeType::LEAF) {
                node.set_leaf_value(ZoneStatus::OBSTACLE);
            } else if (node.get_type() == quadtree::NodeType::BRANCH) {
                // We can merge the branch and set everything as an obstacle as we don't care
                // about more information about the obstacle (yet)
                node.merge(ZoneStatus::OBSTACLE);
            } else {
                unknown_state_error();
            }
        } else if (obstacle_relationship == SurfaceRelationship::CONTAINED ||
                   obstacle_relationship == SurfaceRelationship::OVERLAP) {
            if (node.get_type() == quadtree::NodeType::LEAF) {
                // TODO(cvandevo): if obstacles are a bit smarter, the splitting point could be chosen more wisely
                //  and we could create an "unbalanced" quadtree.
                geometry::Point splitting_point = node.get_bounding_box().get_center();
                // By default, let's suppose the zone is free and the refinement will fill
                // if there is any obstacle.
                quadtree::SplittingNodeInfo splitting_info(splitting_point, ZoneStatus::FREE);
                node.split(splitting_info);
            } else if (node.get_type() == quadtree::NodeType::BRANCH) {
                // do nothing as we need to drill down more in the quadtree to see the value of the leaf node...
            } else {
                unknown_state_error();
            }

            std::shared_ptr<QuadtreeBranches> branches = node.get_branches();
            obstacle_refinement(branches->get_top_left_node(), obstacle, precision);
            obstacle_refinement(branches->get_top_right_node(), obstacle, precision);
            obstacle_refinement(branches->get_bottom_left_node(), obstacle, precision);
            obstacle_refinement(branches->get_bottom_right_node(), obstacle, precision);
        } else {
            unknown_state_error();
        }
    }

}