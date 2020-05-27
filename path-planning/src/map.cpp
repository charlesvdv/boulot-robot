#include "map_impl.hpp"

#include <memory>
#include <path-planning/map.hpp>

namespace pathplanning::map {

    auto Map::make(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles)
            -> std::unique_ptr<Map> {
        return std::make_unique<MapImpl>(dimension, obstacles);
    }

    MapDimension::MapDimension(double length, double width):
        length(length), width(width), precision(DEFAULT_PRECISION) {}

    void MapDimension::set_precision(double precision) {
        this->precision = precision;
    }

    auto MapDimension::get_length() const -> double {
        return length;
    }

    auto MapDimension::get_width() const -> double {
        return width;
    }

    auto MapDimension::get_precision() const -> double {
        return precision;
    }
}
