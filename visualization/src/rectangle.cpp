#include <visualization/rectangle.hpp>

namespace visualization::geometry {

    Rectangle::Rectangle(double width, double height, const Point& center):
        width(width), height(height), center(center) {
    }

    auto Rectangle::get_width() const -> double {
        return width;
    }

    auto Rectangle::get_height() const -> double {
        return height;
    }

    auto Rectangle::get_center() const -> const Point& {
        return center;
    }
}