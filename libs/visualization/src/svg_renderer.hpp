#pragma once

#include "xml_node.hpp"

#include <string>
#include <vector>
#include <visualization/renderer.hpp>

namespace visualization::render {

    class SVGRenderer: public Renderer {
    public:
        SVGRenderer(std::string name, double width, double height);

        void add_line(const geometry::Line& line) override;
        void add_rectangle(const geometry::Rectangle& rectangle) override;
        void add_circle(const geometry::Circle& circle) override;

        auto render() const -> std::string override;

    private:
        double width;
        double height;
        const std::string name;

        std::vector<XMLNode> nodes;
    };

}