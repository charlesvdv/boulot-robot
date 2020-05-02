#pragma once

#include <optional>
#include <variant>

#include <path-planning/zone.hpp>

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

        static QuadtreeNode<T> make_inner_node(const QuadtreeNodeChildren<T>& children, const geometry::RectangularZone& zone);
        static QuadtreeNode<T> make_edge_node(const T& value, const geometry::RectangularZone& zone);

        Type get_type() const;
        const T& get_edge_value() const;
        const QuadtreeNodeChildren<T>& get_children() const;

        void split(const QuadtreeNodeChildren<T>& children);
        void merge(const T& value);

    private:
        QuadtreeNode(const QuadtreeNodeChildren<T>& children, const geometry::RectangularZone& zone);
        QuadtreeNode(const T& value, const geometry::RectangularZone& zone);

        geometry::RectangularZone zone;
        Type value_type;
        std::variant<QuadtreeNodeChildren<T>, T> value; 
    };


    template<class T>
    class QuadtreeNodeChildren {
    public:
        class Builder;

        const QuadtreeNode<T>& get_north_west_node() const;
        const QuadtreeNode<T>& get_north_east_node() const;
        const QuadtreeNode<T>& get_south_east_node() const;
        const QuadtreeNode<T>& get_south_west_node() const;

    private:
        QuadtreeNodeChildren(QuadtreeNodeChildren<T>&& north_west, QuadtreeNodeChildren<T>&& north_east,
            QuadtreeNodeChildren<T>&& south_east, QuadtreeNodeChildren<T>&& south_west);

        QuadtreeNode<T> north_west;
        QuadtreeNode<T> north_east;
        QuadtreeNode<T> south_east;
        QuadtreeNode<T> south_west;
    };

    template<class T>
    class QuadtreeNodeChildren<T>::Builder {
    public:
        Builder& with_north_west(const QuadtreeNode<T> node);
        Builder& with_north_east(const QuadtreeNode<T> node);
        Builder& with_south_west(const QuadtreeNode<T> node);
        Builder& with_south_east(const QuadtreeNode<T> node);

        QuadtreeNodeChildren<T> build() const;

    private:
        std::optional<QuadtreeNode<T>> north_west;
        std::optional<QuadtreeNode<T>> north_east;
        std::optional<QuadtreeNode<T>> south_east;
        std::optional<QuadtreeNode<T>> south_west;
    };

}