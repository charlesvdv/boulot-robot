#include "quadtree.hpp"

#include <catch2/catch.hpp>

using namespace pathplanning;
namespace geo = pathplanning::geometry;

class TestData {
public:
    bool flag;

    TestData(bool flag): flag(flag) {}
};

TEST_CASE("Test basic quadtree feature") {
    quadtree::BoundingBox bounding_box(geo::Point(0, 0), geo::Point(200, 200));

    SECTION("Split node") {
        quadtree::Root<TestData> root(bounding_box, TestData(false));
        REQUIRE(root.get_type() == quadtree::NodeType::LEAF);

        quadtree::SplittingNodeInfo<TestData> split_info = quadtree::SplittingNodeInfo<TestData>(geo::Point(100, 100))
                                                               .with_top_left_value(TestData(true))
                                                               .with_top_right_value(TestData(true))
                                                               .with_bottom_left_value(TestData(false))
                                                               .with_bottom_right_value(TestData(false));

        root.split(split_info);
        REQUIRE(root.get_type() == quadtree::NodeType::BRANCH);

        REQUIRE(root.get_branches()->get_top_left_node().get_type() == quadtree::NodeType::LEAF);
        REQUIRE(root.get_branches()->get_top_right_node().get_type() == quadtree::NodeType::LEAF);
        REQUIRE(root.get_branches()->get_bottom_left_node().get_type() == quadtree::NodeType::LEAF);
        REQUIRE(root.get_branches()->get_bottom_right_node().get_type() == quadtree::NodeType::LEAF);

        REQUIRE(root.get_branches()->get_top_left_node().get_leaf_value().flag == true);
        REQUIRE(root.get_branches()->get_top_right_node().get_leaf_value().flag == true);
        REQUIRE(root.get_branches()->get_bottom_left_node().get_leaf_value().flag == false);
        REQUIRE(root.get_branches()->get_bottom_right_node().get_leaf_value().flag == false);
    }

    SECTION("Merge node") {
        quadtree::Root<TestData> root(bounding_box, TestData(false));
        REQUIRE(root.get_type() == quadtree::NodeType::LEAF);
        REQUIRE(root.get_leaf_value().flag == false);

        quadtree::SplittingNodeInfo<TestData> split_info = quadtree::SplittingNodeInfo<TestData>(geo::Point(100, 100))
                                                               .with_top_left_value(TestData(true))
                                                               .with_top_right_value(TestData(true))
                                                               .with_bottom_left_value(TestData(false))
                                                               .with_bottom_right_value(TestData(false));

        root.split(split_info);
        REQUIRE(root.get_type() == quadtree::NodeType::BRANCH);

        root.merge(TestData(true));
        REQUIRE(root.get_type() == quadtree::NodeType::LEAF);
        REQUIRE(root.get_leaf_value().flag == true);
    }
}