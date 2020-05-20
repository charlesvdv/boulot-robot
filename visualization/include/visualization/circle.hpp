#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Circle {

        public:
            Circle(const Point& center, double radius);

            double get_radius() const;
            Point get_center() const;

        private:
            const Point center;
            double radius;
    };
    
}