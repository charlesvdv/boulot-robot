#pragma once

namespace pathplanning::geometry {

    class Point {
    public:
        Point(double x, double y);

        auto operator==(const Point& other) const -> bool;

        auto euclidian_distance(const Point& other) const -> double;

        auto get_x() const -> double;
        auto get_y() const -> double;

    private:
        double x;
        double y;
    };

}