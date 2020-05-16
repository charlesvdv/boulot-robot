#include <catch2/catch.hpp>
#include <vector> 

#include <path-planning/map.hpp>
#include <path-planning/obstacle.hpp>

using namespace pathplanning;

TEST_CASE("Test map functionalities") {
    SECTION("Test map with simple obstacle is created properly") {
        std::unique_ptr<map::Obstacle> rect_obstacle = 
            map::Obstacle::make_rectangle(geometry::Point(40, 40), geometry::Point(60, 60));

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = { std::move(rect_obstacle) };
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(10, 10)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(35, 35)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(39, 39)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(61, 39)));

        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 59)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(50, 50)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 41)));
    }
}