#include <catch2/catch.hpp>
#include <path-planning/obstacle.hpp>

namespace map = pathplanning::map;
namespace geo = pathplanning::geometry;

TEST_CASE("Verify circular obstacle contains method") {
    std::unique_ptr<map::Obstacle> circleObstacle = map::Obstacle::make_circle(geo::Point(10, 10), 5);

    SECTION("disjoint zone") {
        geo::StraightRectangle zone(geo::Point(0, 0), geo::Point(4, 4));
        REQUIRE(map::SurfaceRelationship::DISJOINT == circleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(16, 16), geo::Point(20, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == circleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(6, 14), geo::Point(0, 25));
        REQUIRE(map::SurfaceRelationship::DISJOINT == circleObstacle->get_relation_with_zone(zone));

        zone = geo::StraightRectangle(geo::Point(-5, -5), geo::Point(0, 5));
        REQUIRE(map::SurfaceRelationship::DISJOINT == circleObstacle->get_relation_with_zone(zone));
    }

    SECTION("obstacle containing zone") {
        geo::StraightRectangle zone(geo::Point(7, 7), geo::Point(13, 12));
        REQUIRE(map::SurfaceRelationship::CONTAINS == circleObstacle->get_relation_with_zone(zone));
    }

    SECTION("obstacle contained by zone") {
        geo::StraightRectangle zone = geo::StraightRectangle(geo::Point(0, 0), geo::Point(50, 50));
        REQUIRE(map::SurfaceRelationship::CONTAINED == circleObstacle->get_relation_with_zone(zone));
    }

    SECTION("when obstacle and zone are touching, it should be disjoint") {
        geo::StraightRectangle zone = geo::StraightRectangle(geo::Point(0, 0), geo::Point(5, 20));
        REQUIRE(map::SurfaceRelationship::DISJOINT == circleObstacle->get_relation_with_zone(zone));
    }

    SECTION("overlapping zone") {
        // Overlap coner zone
        geo::StraightRectangle zone(geo::Point(7, 11), geo::Point(0, 15));
        REQUIRE(map::SurfaceRelationship::OVERLAP == circleObstacle->get_relation_with_zone(zone));

        // Overlap without coner zone inside circle and line zone inside circle.
        zone = geo::StraightRectangle(geo::Point(0, 13), geo::Point(20, 7));
        REQUIRE(map::SurfaceRelationship::OVERLAP == circleObstacle->get_relation_with_zone(zone));

        // Overlap without coner inside circle and only one line zone inside circle.
        zone = geo::StraightRectangle(geo::Point(0, 16), geo::Point(20, 7));
        REQUIRE(map::SurfaceRelationship::OVERLAP == circleObstacle->get_relation_with_zone(zone));

        // One corner zone outside circle
        zone = geo::StraightRectangle(geo::Point(0, 14), geo::Point(10, 10));
        REQUIRE(map::SurfaceRelationship::OVERLAP == circleObstacle->get_relation_with_zone(zone));

        // Test negative value
        zone = geo::StraightRectangle(geo::Point(-1, 16), geo::Point(10, -5));
        REQUIRE(map::SurfaceRelationship::OVERLAP == circleObstacle->get_relation_with_zone(zone));
    }
}