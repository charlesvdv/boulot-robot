#pragma once

#include <optional>
#include <variant>

#include <path-planning/shape.hpp>

namespace pathplanning::map {

    template<class T>
    class QuadtreeNodeChildren;

    template<class T>
    class QuadtreeNode {
    public:
        enum class Type {
            INNER,
            EDGE,
        };

        static QuadtreeNode<T> make_inner_node(const QuadtreeNodeChildren<T>& children, const geometry::StraightRectangle& zone);
        static QuadtreeNode<T> make_edge_node(const T& value, const geometry::StraightRectangle& zone);

        Type get_type() const;
        const T& get_edge_value() const;
        const QuadtreeNodeChildren<T>& get_children() const;

        void split(const QuadtreeNodeChildren<T>& children);
        void merge(const T& value);

    private:
        QuadtreeNode(const QuadtreeNodeChildren<T>& children, const geometry::StraightRectangle& zone);
        QuadtreeNode(const T& value, const geometry::StraightRectangle& zone);

        geometry::StraightRectangle zone;
        Type value_type;
        std::variant<QuadtreeNodeChildren<T>, T> value; 
    };


    template<class T>
    class QuadtreeNodeChildren {
    public:
        class Builder;

        const QuadtreeNode<T>& get_top_right_node() const;
        const QuadtreeNode<T>& get_top_left_node() const;
        const QuadtreeNode<T>& get_bottom_left_node() const;
        const QuadtreeNode<T>& get_bottom_right_node() const;

    private:
        QuadtreeNodeChildren(QuadtreeNodeChildren<T>&& top_right, QuadtreeNodeChildren<T>&& top_left,
            QuadtreeNodeChildren<T>&& bottom_left, QuadtreeNodeChildren<T>&& bottom_right);

        QuadtreeNode<T> top_right;
        QuadtreeNode<T> top_left;
        QuadtreeNode<T> bottom_left;
        QuadtreeNode<T> bottom_right;
    };

    template<class T>
    class QuadtreeNodeChildren<T>::Builder {
    public:
        Builder& with_top_right(const QuadtreeNode<T> node);
        Builder& with_top_left(const QuadtreeNode<T> node);
        Builder& with_bottom_right(const QuadtreeNode<T> node);
        Builder& with_bottom_left(const QuadtreeNode<T> node);

        QuadtreeNodeChildren<T> build() const;

    private:
        std::optional<QuadtreeNode<T>> top_right;
        std::optional<QuadtreeNode<T>> top_left;
        std::optional<QuadtreeNode<T>> bottom_left;
        std::optional<QuadtreeNode<T>> bottom_right;
    };

}