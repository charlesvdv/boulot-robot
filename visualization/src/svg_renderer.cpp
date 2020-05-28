#include "svg_renderer.hpp"

#include <sstream>
#include <utility>

namespace visualization::render {

    SVGRenderer::SVGRenderer(std::string name, double width, double height):
        name(std::move(name)), width(width), height(height) {}

    void SVGRenderer::add_line(const geometry::Line& line) {
        XMLNode node = XMLNode::Builder("line")
                           .with_attribute("x1", std::to_string(line.get_start().get_x()))
                           .with_attribute("y1", std::to_string(line.get_start().get_y()))
                           .with_attribute("x2", std::to_string(line.get_end().get_x()))
                           .with_attribute("y2", std::to_string(line.get_end().get_y()))
                           .with_attribute("stroke", "black")
                           .build();

        nodes.push_back(node);
    }

    void SVGRenderer::add_rectangle(const geometry::Rectangle& rectangle) {
        XMLNode node = XMLNode::Builder("rect")
                           .with_attribute("x", std::to_string(rectangle.get_center().get_x()))
                           .with_attribute("y", std::to_string(rectangle.get_center().get_y()))
                           .with_attribute("width", std::to_string(rectangle.get_width()))
                           .with_attribute("height", std::to_string(rectangle.get_height()))
                           .build();

        nodes.push_back(node);
    }

    void SVGRenderer::add_circle(const geometry::Circle& circle) {
        XMLNode node = XMLNode::Builder("circle")
                           .with_attribute("cx", std::to_string(circle.get_center().get_x()))
                           .with_attribute("cy", std::to_string(circle.get_center().get_y()))
                           .with_attribute("r", std::to_string(circle.get_radius()))
                           .build();

        nodes.push_back(node);
    }

    auto SVGRenderer::render() const -> std::string {
        std::stringstream svg_built;

        svg_built << "<svg width=\"" << width << "\" height=\"" << height << "\">\n";
        for (std::vector<int>::size_type i = 0; i != nodes.size(); i++) {
            svg_built << nodes[i].to_string();
        }
        svg_built << "</svg>";

        return svg_built.str();
    }
}