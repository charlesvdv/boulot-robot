#pragma once

#include <memory>
#include <vector>

#include "point.hpp"
#include "obstacle.hpp"

namespace pathmapping::map {

class Map {
public:
    static std::unique_ptr<Map> make_rectangular(const geometry::Point& p, std::vector<std::unique_ptr<Obstacle>> obstacles);
};

}