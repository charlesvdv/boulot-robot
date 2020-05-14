#pragma once

#include <memory>
#include <vector>

#include "point.hpp"
#include "obstacle.hpp"

namespace pathplanning::map {

    class MapDimension {
    public:
        constexpr static double DEFAULT_PRECISION = 2.0;

        MapDimension(double length, double width);

        void set_precision(double precision);

        double get_length() const;
        double get_width() const;
        double get_precision() const;

    private:
        double length;
        double width;
        double precision;
    };

    class Map {
    public:
        virtual ~Map();

        static std::unique_ptr<Map> make(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles);

        virtual bool is_point_in_obstacle(const geometry::Point& point) const = 0;
    };

}