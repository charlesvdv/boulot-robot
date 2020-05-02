#pragma once

namespace pathplanning::geometry {

    class Point {
    public:
        Point(double x, double y);

        bool operator==(const Point& other) const;

        double euclidian_distance(const Point& other) const;

        double get_x() const;
        double get_y() const;
    private:
        double x;
        double y;
    };

}