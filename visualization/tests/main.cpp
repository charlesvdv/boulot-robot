#include <visualization/rectangle.hpp>
#include <visualization/circle.hpp>
#include <visualization/svg.hpp>
#include <fstream>

using namespace visualization;

int main() {
    //Temporary
    render::SVGDimension dimension = render::SVGDimension(100, 100);
    render::SVGRender svg_content = render::SVGRender("test", dimension);

    geometry::Point center1 = geometry::Point(10, 10);
    geometry::Rectangle renctangle1 = geometry::Rectangle(20, 20, center1);
    svg_content.add_rectangle(renctangle1);

    geometry::Point center2 = geometry::Point(50,50);
    geometry::Circle circle1 = geometry::Circle(center2, 5);
    svg_content.add_circle(circle1);

    std::ofstream output("test.svg");
    output << svg_content.render();
    output.close();
}