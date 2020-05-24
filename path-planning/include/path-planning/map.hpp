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

        auto get_length() const -> double;
        auto get_width() const -> double;
        auto get_precision() const -> double;

    private:
        double length;
        double width;
        double precision;
    };

    class Map {
    public:
        virtual ~Map() = default;

        static auto make(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles) -> std::unique_ptr<Map>;

        virtual auto is_point_in_obstacle(const geometry::Point& point) const -> bool = 0;
    };

}