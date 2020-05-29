#include <catch2/catch.hpp>
#include <path-planning/map.hpp>
#include <path-planning/obstacle.hpp>
#include <vector>

using namespace pathplanning;

TEST_CASE("Test map functionalities") {
    SECTION("Test map with simple obstacle is created properly") {
        std::unique_ptr<map::Obstacle> rect_obstacle =
            map::Obstacle::make_rectangle(geometry::Point(40, 40), geometry::Point(60, 60));

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = {std::move(rect_obstacle)};
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(10, 10)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(35, 35)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(39, 39)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(61, 39)));

        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 59)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(50, 50)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 41)));
    }

    SECTION("Test multiple rectangular obstacles") {
        std::unique_ptr<map::Obstacle> obstacle_center =
            map::Obstacle::make_rectangle(geometry::Point(40, 40), geometry::Point(60, 60));
        std::unique_ptr<map::Obstacle> obstacle_corner0 =
            map::Obstacle::make_rectangle(geometry::Point(-25, -25), geometry::Point(25, 25));
        std::unique_ptr<map::Obstacle> obstacle_corner1 =
            map::Obstacle::make_rectangle(geometry::Point(75, 75), geometry::Point(125, 125));
        std::unique_ptr<map::Obstacle> obstacle_corner2 =
            map::Obstacle::make_rectangle(geometry::Point(25, 75), geometry::Point(-25, 125));
        std::unique_ptr<map::Obstacle> obstacle_corner3 =
            map::Obstacle::make_rectangle(geometry::Point(75, 25), geometry::Point(125, -25));

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = {std::move(obstacle_center),
            std::move(obstacle_corner0), std::move(obstacle_corner1), std::move(obstacle_corner2),
            std::move(obstacle_corner3)};
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE(map->is_point_in_obstacle(geometry::Point(10, 10)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(24.99, 24.99)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(0, 0)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(100, 100)));

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(35, 35)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(70, 80)));
    }

    SECTION("Test overlapping obstacles") {
        std::unique_ptr<map::Obstacle> rect_obstacle =
            map::Obstacle::make_rectangle(geometry::Point(40, 40), geometry::Point(60, 60));
        std::unique_ptr<map::Obstacle> overlapping_obstacle =
            map::Obstacle::make_rectangle(geometry::Point(20, 20), geometry::Point(50, 50));

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = {
            std::move(rect_obstacle), std::move(overlapping_obstacle)};
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(10, 10)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(61, 39)));

        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 59)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(50, 50)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(41, 41)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(35, 35)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(39, 39)));
    }

    SECTION("Test with circular obstacle") {
        std::unique_ptr<map::Obstacle> obstacle_circle = map::Obstacle::make_circle(geometry::Point(60, 60), 20);

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = {std::move(obstacle_circle)};
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE(map->is_point_in_obstacle(geometry::Point(60, 60)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(70, 70)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(50, 43)));

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(20, 50)));
    }

    SECTION("Test multiple obstacles of different shapes") {
        std::unique_ptr<map::Obstacle> obstacle_center =
            map::Obstacle::make_rectangle(geometry::Point(40, 40), geometry::Point(60, 60));
        std::unique_ptr<map::Obstacle> obstacle_corner0 =
            map::Obstacle::make_rectangle(geometry::Point(-25, -25), geometry::Point(25, 25));
        std::unique_ptr<map::Obstacle> obstacle_corner1 =
            map::Obstacle::make_rectangle(geometry::Point(75, 75), geometry::Point(125, 125));
        std::unique_ptr<map::Obstacle> obstacle_corner2 =
            map::Obstacle::make_rectangle(geometry::Point(25, 75), geometry::Point(-25, 125));
        std::unique_ptr<map::Obstacle> obstacle_corner3 =
            map::Obstacle::make_rectangle(geometry::Point(75, 25), geometry::Point(125, -25));
        std::unique_ptr<map::Obstacle> obstacle_circle = map::Obstacle::make_circle(geometry::Point(60, 60), 20);

        map::MapDimension dimension(100, 100);
        std::vector<std::shared_ptr<map::Obstacle>> obstacles = {
            std::move(obstacle_center),
            std::move(obstacle_corner0),
            std::move(obstacle_corner1),
            std::move(obstacle_corner2),
            std::move(obstacle_corner3),
            std::move(obstacle_circle),
        };
        std::unique_ptr<map::Map> map = map::Map::make(dimension, obstacles);

        REQUIRE(map->is_point_in_obstacle(geometry::Point(10, 10)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(24.99, 24.99)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(0, 0)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(100, 100)));
        REQUIRE(map->is_point_in_obstacle(geometry::Point(70, 70)));

        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(35, 35)));
        REQUIRE_FALSE(map->is_point_in_obstacle(geometry::Point(70, 80)));
    }
}