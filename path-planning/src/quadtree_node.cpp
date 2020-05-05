#include "quadtree.hpp"

namespace pathplanning::map {

    template<class T>
    QuadtreeNode<T> QuadtreeNode<T>::make_inner_node(const QuadtreeNodeChildren<T>& children, const geometry::StraightRectangle& zone) {
        return QuadtreeNode(children, zone);
    }

    template<class T>
    QuadtreeNode<T> QuadtreeNode<T>::make_edge_node(const T& value, const geometry::StraightRectangle& zone) {
        return QuadtreeNode(value, zone);
    }

    template<class T>
    QuadtreeNode<T>::QuadtreeNode(const QuadtreeNodeChildren<T>& children, const geometry::StraightRectangle& zone):
        value(children), zone(zone), value_type(Type::INNER) {}

    template<class T>
    QuadtreeNode<T>::QuadtreeNode(const T& value, const geometry::StraightRectangle& zone):
        value(value), value_type(Type::EDGE), zone(zone) {}

    template<class T>
    typename QuadtreeNode<T>::Type QuadtreeNode<T>::get_type() const {
        return value_type;
    }

    template<class T>
    const T& QuadtreeNode<T>::get_edge_value() const {
        return value.template get<T>();
    }

    template<class T>
    const QuadtreeNodeChildren<T>& QuadtreeNode<T>::get_children() const {
        return value.template get<QuadtreeNodeChildren<T>>();
    }

    template<class T>
    void QuadtreeNode<T>::split(const QuadtreeNodeChildren<T>& children) {
        value = children;
        value_type = Type::INNER;
    }

    template<class T>
    void QuadtreeNode<T>::merge(const T& value) {
        this->value = value;
        value_type = Type::EDGE;
    }
}