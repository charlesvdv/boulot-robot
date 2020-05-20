#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "render.hpp"
#include "xml_node.hpp"

namespace visualization::render {

    class SVGDimension {
    public:
        SVGDimension(double width, double height);

        double get_width() const;
        double get_height() const;

    private: 
        double width;
        double height;
    };

    class SVGRender: public Render {
    public:
        virtual ~SVGRender();

        SVGRender(const std::string name, const SVGDimension& dimension);

        void add_rectangle(const geometry::Rectangle& rectangle) override;
        void add_circle(const geometry::Circle& circle) override;

        const std::string render() const;
    
    private:
        const SVGDimension dimension;
        const std::string name;

        std::vector<XMLNode> nodes;
        const std::string build_node(const XMLNode& node) const;
    };

}