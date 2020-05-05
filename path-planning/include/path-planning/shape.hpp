#pragma once

#include <utility>

#include "point.hpp"

namespace pathplanning::geometry {

    class StraightRectangle {
    public:
        StraightRectangle(const Point& corner, const Point& opposite_corner);

        double get_left_line() const;
        double get_right_line() const;
        double get_top_line() const;
        double get_bottom_line() const;

        Point get_top_left_corner() const;
        Point get_top_right_corner() const;
        Point get_bottom_left_corner() const;
        Point get_bottom_right_corner() const;

        double get_width() const;
        double get_height() const;
        
        Point get_center() const;

    private:
        Point bottom_left_corner;
        Point top_right_corner;
};  
    

}