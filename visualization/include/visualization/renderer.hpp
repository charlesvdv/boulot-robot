#pragma once

#include <memory>
#include <string>

#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace visualization::render {

    class Renderer {
    public:
        static auto make_svg_renderer(const std::string& name, double width, double height) -> std::unique_ptr<Renderer>;

        virtual ~Renderer() = default;

        virtual void add_line(const geometry::Line& line) = 0;
        virtual void add_rectangle(const geometry::Rectangle& rectangle) = 0;
        virtual void add_circle(const geometry::Circle& circle) = 0;
        virtual auto render() const -> std::string = 0;
    };
    
}