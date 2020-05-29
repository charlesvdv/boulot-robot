#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Rectangle {
    public:
        Rectangle(double width, double height, const Point& center);

        auto get_width() const -> double;
        auto get_height() const -> double;
        auto get_center() const -> const Point&;

    private:
        double width;
        double height;
        Point center;
    };

}