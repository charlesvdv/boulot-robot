#include <stdexcept>

#include "quadtree.hpp"

namespace pathplanning::map {

    template<class T>
    QuadtreeNodeChildren<T>::QuadtreeNodeChildren(QuadtreeNodeChildren<T>&& top_right, QuadtreeNodeChildren<T>&& top_left,
        QuadtreeNodeChildren<T>&& bottom_left, QuadtreeNodeChildren<T>&& bottom_right): 
            top_right(top_right), top_left(top_left), bottom_left(bottom_left), bottom_right(bottom_right) {}


    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_top_right_node() const {
        return top_right;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_top_left_node() const {
        return top_left;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_bottom_left_node() const {
        return bottom_left;
    }

    template<class T>
    const QuadtreeNode<T>& QuadtreeNodeChildren<T>::get_bottom_right_node() const {
        return bottom_right;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_top_right(const QuadtreeNode<T> node) {
        top_right = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_top_left(const QuadtreeNode<T> node) {
        top_left = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_bottom_right(const QuadtreeNode<T> node) {
        bottom_right = node;
        return *this;
    }

    template<class T>
    typename QuadtreeNodeChildren<T>::Builder& QuadtreeNodeChildren<T>::Builder::with_bottom_left(const QuadtreeNode<T> node) {
        bottom_left = node;
        return *this;
    }

    template<class T>
    QuadtreeNodeChildren<T> QuadtreeNodeChildren<T>::Builder::build() const {
        if (!(top_right.has_value() && top_left.has_value() && bottom_left.has_value() && bottom_right.has_value())) {
            throw std::invalid_argument("QuadtreeNodeChildren::Builder must be filled completely");
        }

        return QuadtreeNodeChildren<T>(top_right, top_left, bottom_left, bottom_right);
    }

}