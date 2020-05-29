#pragma once

namespace visualization::geometry {

    class Point {
    public:
        Point(double x, double y);

        auto get_x() const -> double;
        auto get_y() const -> double;

    private:
        double x;
        double y;
    };

}