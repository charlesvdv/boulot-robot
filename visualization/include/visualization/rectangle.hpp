#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Rectangle {

        public:
            Rectangle(double width, double height, const Point& center);

            double get_width() const;
            double get_height() const;
            Point get_center() const;

        private:
            double width;
            double height;
            const Point center;
    };
    
}