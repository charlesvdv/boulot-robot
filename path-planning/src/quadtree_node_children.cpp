#include <stdexcept>

#include "quadtree.hpp"

namespace pathplanning::map {

    template<class T>
    QuadtreeNodeChildren<T>::QuadtreeNodeChildren(QuadtreeNodeChildren<T>&& north_west, QuadtreeNodeChildren<T>&& north_east,
        QuadtreeNodeChildren<T>&& south_east, QuadtreeNodeChildren<T>&& south_west): 
            north_west(north_west), north_east(north_east), south_east(south_east), south_west(south_west) {}


    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_north_west_node() const {
        return north_west;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_north_east_node() const {
        return north_east;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_south_east_node() const {
        return south_east;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_south_west_node() const {
        return south_west;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_north_west(const QuadtreeNode<T> node) {
        north_west = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_north_east(const QuadtreeNode<T> node) {
        north_east = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_south_west(const QuadtreeNode<T> node) {
        south_west = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_south_east(const QuadtreeNode<T> node) {
        south_east = node;
        return *this;
    }

    template<class T>
    QuadtreeNodeChildren<T> QuadtreeNodeChildren<T>::Builder::build() const {
        if (!(north_west.has_value() && north_east.has_value() && south_east.has_value() && south_west.has_value())) {
            throw std::invalid_argument("QuadtreeNodeChildren::Builder must be filled completely");
        }

        return QuadtreeNodeChildren<T>(north_west, north_east, south_east, south_west);
    }

}