#pragma once

#include <memory>
#include <vector>

#include "point.hpp"
#include "obstacle.hpp"

namespace pathplanning::map {

class Map {
public:
    static std::unique_ptr<Map> make_rectangular(double lenght, double height, std::vector<std::unique_ptr<Obstacle>> obstacles);
};

}