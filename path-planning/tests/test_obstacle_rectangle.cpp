#include <catch2/catch.hpp>

#include <path-planning/obstacle.hpp>

namespace map = pathplanning::map;
namespace geo = pathplanning::geometry;

TEST_CASE("Verify rectangle obstacle contains method") {
    std::unique_ptr<map::Obstacle>  rectangleObstacle = map::Obstacle::make_rectangle(geo::Point(10, 10), geo::Point(20, 20));

    SECTION("disjoint area") {
        geo::RectangularZone zone(geo::Point(0, 0), geo::Point(5, 5));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(0, -10), geo::Point(5, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(25, -10), geo::Point(30, 0));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(25, -10), geo::Point(30, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == rectangleObstacle->contains(zone));
    }

    SECTION("full containing area") {
        geo::RectangularZone zone(geo::Point(11, 12), geo::Point(17, 16));
        REQUIRE(map::SurfaceRelationship::CONTAINS == rectangleObstacle->contains(zone));
    }

    SECTION("overlapping area") {
        geo::RectangularZone zone(geo::Point(0, 0), geo::Point(15, 15));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(0, 0), geo::Point(50, 50));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(11, 11), geo::Point(15, 25));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(15, 15), geo::Point(25, 25));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->contains(zone));

        zone = geo::RectangularZone(geo::Point(15, 15), geo::Point(25, -10));
        REQUIRE(map::SurfaceRelationship::OVERLAP == rectangleObstacle->contains(zone));
    }
}