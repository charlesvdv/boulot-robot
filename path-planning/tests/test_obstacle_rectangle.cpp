#include <catch2/catch.hpp>

#include <path-planning/obstacle.hpp>

namespace map = pathplanning::map;
namespace geo = pathplanning::geometry;

TEST_CASE("Verify rectangle obstacle contains method") {
    std::unique_ptr<map::Obstacle>  rectangleObstacle = map::Obstacle::make_rectangle(geo::Point(10, 10), geo::Point(20, 20));

    SECTION("disjoint zone") {
        geo::StraightRectangle zone(geo::Point(0, 0), geo::Point(5, 5));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(0, -10), geo::Point(5, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(25, -10), geo::Point(30, 0));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(25, -10), geo::Point(30, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->get_relation_with_zone(zone));
    }

    SECTION("obstacle containing zone") {
        geo::StraightRectangle zone(geo::Point(11, 12), geo::Point(17, 16));
        REQUIRE(map::SurfaceRelationship::CONTAINS == rectangleObstacle->get_relation_with_zone(zone));
    }

    SECTION("obstacle contained by zone") {
        geo::StraightRectangle zone = geo::StraightRectangle(geo::Point(0, 0), geo::Point(50, 50));
        REQUIRE(map::SurfaceRelationship::CONTAINED == rectangleObstacle->get_relation_with_zone(zone));
    }

    SECTION("overlapping zone") {
        geo::StraightRectangle zone(geo::Point(0, 0), geo::Point(15, 15));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(11, 11), geo::Point(15, 25));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(15, 15), geo::Point(25, 25));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(15, 15), geo::Point(25, -10));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->get_relation_with_zone(zone));
    }
}