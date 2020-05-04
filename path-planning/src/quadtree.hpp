#pragma once

#include <optional>
#include <memory>
#include <stdexcept>

#include <path-planning/point.hpp>
#include <path-planning/shape.hpp>

namespace pathplanning::quadtree {

    enum class NodeType {
            BRANCH,
            LEAF,
    };

    class BoundingBox: public geometry::StraightRectangle {
    public:
        BoundingBox(geometry::Point point, geometry::Point opposite);
    };

    // SplittingNodeInfo represents the data needed to split a quadtree node 
    // to four branches. 
    template<class T>
    class SplittingNodeInfo {
    public:
        SplittingNodeInfo(const geometry::Point& splitting_point):
            splitting_point(splitting_point) {}

        SplittingNodeInfo(const geometry::Point& splitting_point, const T& value):
            splitting_point(splitting_point), top_left_value(value), top_right_value(value),
            bottom_left_value(value), bottom_right_value(value) {}

        SplittingNodeInfo& with_top_left_value(const T& value) {
            top_left_value = value;
            return *this;
        }

        SplittingNodeInfo& with_top_right_value(const T& value) {
            top_right_value = value;
            return *this;
        }

        SplittingNodeInfo& with_bottom_left_value(const T& value) {
            bottom_left_value = value;
            return *this;
        }

        SplittingNodeInfo& with_bottom_right_value(const T& value) {
            bottom_right_value = value;
            return *this;
        }

        const geometry::Point& get_splitting_point() const {
            return splitting_point;
        }

        const T& get_top_left_value() const {
            validate();
            return *top_left_value;
        }

        const T& get_top_right_value() const {
            validate();
            return *top_right_value;
        }

        const T& get_bottom_left_value() const {
            validate();
            return *bottom_left_value;
        }

        const T& get_bottom_right_value() const {
            validate();
            return *bottom_right_value;
        }
    
    private:
        void validate() const {
            if (!(top_right_value.has_value() && top_left_value.has_value() 
                    && bottom_left_value.has_value() && bottom_right_value.has_value())) {
                throw std::invalid_argument("Branches::Builder must be filled completely");
            }

        }

        geometry::Point splitting_point;
        std::optional<T> top_right_value;
        std::optional<T> top_left_value;
        std::optional<T> bottom_left_value;
        std::optional<T> bottom_right_value;
    };

    template<class T> 
    class Branches; 

    // `Node` represents a bounded rectangular region in the quadtree.
    // The node can either be a branch (i.e. it contains other nodes) or 
    // a leaf (i.e. it contains the region value `T`).
    template<class T>
    class Node {
    public:
        NodeType get_type() const {
            if (value.has_value()) {
                return NodeType::LEAF;
            }
            return NodeType::BRANCH;
        }

        std::shared_ptr<Branches<T>> get_branches() const {
            if (get_type() != NodeType::BRANCH) {
                throw std::logic_error("Can not get tree branches when node is not a branch");
            }
            return branches;
        }

        const T& get_leaf_value() const {
            if (get_type() != NodeType::LEAF) {
                throw std::logic_error("Can not get leaf value when node is not a leaf");
            }
            return *value;
        }

        void set_leaf_value(const T& value) {
            if (get_type() != NodeType::LEAF) {
                throw std::logic_error("Can not set leaf value when node is not a leaf");
            }
            this->value = value;
        }

        const BoundingBox& get_bounding_box() const {
            return bounding_box;
        }

        void split(const SplittingNodeInfo<T>& splitting_info) {
            if (get_type() == NodeType::BRANCH) {
                throw std::logic_error("Can not split a branch node");
            }

            value = std::nullopt;
            branches = build_branches_for_split(splitting_info);
        }

        void merge(const T& value) {
            if (get_type() == NodeType::LEAF) {
                throw std::logic_error("Can not merge a leaf node");
            }

            this->value = value;
            branches = nullptr;
        }

    protected:
        Node(const BoundingBox& bounding_box, const T& value):
            bounding_box(bounding_box), value(value), branches(nullptr) {}

    private:
        std::shared_ptr<Branches<T>> build_branches_for_split(const SplittingNodeInfo<T>& info) const {
            geometry::Point split_point = info.get_splitting_point();
            Node<T> top_left(BoundingBox(split_point, bounding_box.get_top_left_corner()), info.get_top_left_value());
            Node<T> top_right(BoundingBox(split_point, bounding_box.get_top_right_corner()), info.get_top_right_value());
            Node<T> bottom_left(BoundingBox(split_point, bounding_box.get_bottom_left_corner()), info.get_bottom_left_value());
            Node<T> bottom_right(BoundingBox(split_point, bounding_box.get_bottom_right_corner()), info.get_bottom_right_value());

            // std::make_shared don't work with friend class so we need to create the pointer ourself and wrap the 
            // pointer manually in std::shared_ptr. It should be safe though as the quadtree::Branches constructor does not 
            // throw any exception. 
            return std::shared_ptr<Branches<T>>(new Branches<T>(top_right, top_left, bottom_left, bottom_right));
        }

        std::shared_ptr<Branches<T>> branches;
        std::optional<T> value;
        BoundingBox bounding_box;
    };

    template<class T>
    class Root: public Node<T> {
    public:
        Root(const BoundingBox& bounding_box, const T& value):
            Node<T>(bounding_box, value) {}
    };

    template<class T>
    class Branches {
    public:
        const Node<T>& get_top_right_node() const {
            return top_right;
        }

        Node<T>& get_top_right_node() {
            return top_right;
        }

        const Node<T>& get_top_left_node() const {
            return top_left;
        }

        Node<T>& get_top_left_node() {
            return top_left;
        }

        const Node<T>& get_bottom_left_node() const {
            return bottom_left;
        }

        Node<T>& get_bottom_left_node() {
            return bottom_left;
        }

        const Node<T>& get_bottom_right_node() const {
            return bottom_right;
        }

        Node<T>& get_bottom_right_node() {
            return bottom_right;
        }

        geometry::Point get_splitting_point() const {
            return top_left.get_bounding_box().get_bottom_right_corner();
        }

    private:
        Branches(const Node<T>& top_right, const Node<T>& top_left,
            const Node<T>& bottom_left, const Node<T>& bottom_right):
                top_right(top_right), top_left(top_left), bottom_left(bottom_left), 
                bottom_right(bottom_right) {}

        Node<T> top_left;
        Node<T> top_right;
        Node<T> bottom_left;
        Node<T> bottom_right;

        friend class Node<T>;
    };
}