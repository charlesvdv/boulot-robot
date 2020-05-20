#pragma once

#include "rectangle.hpp"
#include "circle.hpp"

namespace visualization::render {

    class Render {
        virtual void add_rectangle(const geometry::Rectangle& rectangle) = 0;
        virtual void add_circle(const geometry::Circle& circle) = 0;
    };
    
}