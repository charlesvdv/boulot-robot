#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Circle {
    public:
        Circle(const Point& center, double radius);

        auto get_radius() const -> double;
        auto get_center() const -> const Point&;
    private:
        Point center;
        double radius;
    };
    
}