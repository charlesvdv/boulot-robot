#include <memory>
#include <path-planning/map.hpp>

#include "map_impl.hpp"

namespace pathplanning::map {

    Map::~Map() {}

    std::unique_ptr<Map> Map::make(const MapDimension& dimension, const std::vector<std::shared_ptr<Obstacle>>& obstacles) {
        return std::make_unique<MapImpl>(dimension, obstacles);
    }

    MapDimension::MapDimension(double length, double width):
        length(length), width(width), precision(DEFAULT_PRECISION) {}

    void MapDimension::set_precision(double precision) {
        this->precision = precision;
    }

    double MapDimension::get_length() const {
        return length;
    }

    double MapDimension::get_width() const {
        return width;
    }

    double MapDimension::get_precision() const {
        return precision;
    }
}
