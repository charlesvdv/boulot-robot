#pragma once

#include <string>

#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

namespace visualization::render {

    class Renderer {
        virtual void add_line(const geometry::Line& line) = 0;
        virtual void add_rectangle(const geometry::Rectangle& rectangle) = 0;
        virtual void add_circle(const geometry::Circle& circle) = 0;
        virtual std::string render() const = 0;
    };
    
}