#pragma once

namespace visualization::geometry {

    class Point {
    public:
        Point(double x, double y);

        double get_x() const;
        double get_y() const;

    private:
        double x;
        double y;
    };
    
} 