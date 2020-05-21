#include <visualization/rectangle.hpp>

namespace visualization::geometry {

    Rectangle::Rectangle(double width, double height, const Point& center):
        width(width), height(height), center(center) {
    }

    double Rectangle::get_width() const {
        return width;
    }

    double Rectangle::get_height() const {
        return height;
    }

    const Point& Rectangle::get_center() const {
        return center;
    }
}