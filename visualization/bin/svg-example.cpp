#include <fstream>
#include <visualization/circle.hpp>
#include <visualization/line.hpp>
#include <visualization/rectangle.hpp>
#include <visualization/renderer.hpp>

using namespace visualization;

int
    main() {
    std::unique_ptr<render::Renderer> svg_content = render::Renderer::make_svg_renderer("test", 100, 100);

    geometry::Point start = geometry::Point(80, 80);
    geometry::Point end = geometry::Point(90, 90);
    geometry::Line line = geometry::Line(start, end);
    svg_content->add_line(line);

    geometry::Point center1 = geometry::Point(10, 10);
    geometry::Rectangle renctangle1 = geometry::Rectangle(20, 20, center1);
    svg_content->add_rectangle(renctangle1);

    geometry::Point center2 = geometry::Point(50, 50);
    geometry::Circle circle1 = geometry::Circle(center2, 5);
    svg_content->add_circle(circle1);

    std::ofstream output("test.svg");
    output << svg_content->render();
    output.close();
}