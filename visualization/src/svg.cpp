#include <visualization/svg.hpp>

namespace visualization::render {

    SVGDimension::SVGDimension(double height, double width):
        height(height), width(width) {}

    double SVGDimension::get_width() const {
        return width;
    }

    double SVGDimension::get_height() const {
        return height;
    }

    SVGRender::SVGRender(const std::string name, const SVGDimension& dimension):
        name(name), dimension(dimension) {}

    SVGRender::~SVGRender() {}

    void SVGRender::add_rectangle(const geometry::Rectangle& rectangle) {
        XMLNode node = XMLNode::Builder{}.has_tag("rect")
            .with_attribute("x", std::to_string(rectangle.get_center().get_x()))
            .with_attribute("y", std::to_string(rectangle.get_center().get_y()))
            .with_attribute("width", std::to_string(rectangle.get_width()))
            .with_attribute("height", std::to_string(rectangle.get_height()))
            .build();
        
        nodes.push_back(node);
    }

    void SVGRender::add_circle(const geometry::Circle& circle) {
        XMLNode node = XMLNode::Builder{}.has_tag("circle")
            .with_attribute("cx", std::to_string(circle.get_center().get_x()))
            .with_attribute("cy", std::to_string(circle.get_center().get_y()))
            .with_attribute("r", std::to_string(circle.get_radius()))
            .build();
        
        nodes.push_back(node);
    }

    const std::string SVGRender::build_node(const XMLNode& node) const {
        std::stringstream svg_node;

        svg_node << "\t<" << node.get_tag();
        std::vector<std::pair<std::string, std::string>> attributes = node.get_attributes();
        for(std::vector<std::pair<std::string, std::string>>::const_iterator it = attributes.begin(); it != attributes.end(); it++){
            svg_node << " "<< it->first << "=\"" << it->second <<"\"";
        }
        svg_node << "/>\n";

        return svg_node.str();
    }
    
    const std::string SVGRender::render() const {
        std::stringstream svg_built;

        svg_built << "<svg width=\"" << dimension.get_width() << "\" height=\"" << dimension.get_height() << "\">\n";
        for(std::vector<int>::size_type i = 0; i != nodes.size(); i++) {
            svg_built << build_node(nodes[i]);
        }
        svg_built << "</svg>";

        return svg_built.str();
    }

}