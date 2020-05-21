#pragma once

#include <string>
#include <vector>

#include "render.hpp"
#include "xml_node.hpp"

namespace visualization::render {

    class SVGRenderer: public Renderer {
    public:
        SVGRenderer(const std::string name, double width, double height);

        void add_line(const geometry::Line& line) override;
        void add_rectangle(const geometry::Rectangle& rectangle) override;
        void add_circle(const geometry::Circle& circle) override;

        std::string render() const override;
    private:
        double width;
        double height;
        const std::string name;

        std::vector<XMLNode> nodes;
    };

}