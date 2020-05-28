#include <visualization/line.hpp>

namespace visualization::geometry {

    Line::Line(const Point& start, const Point& end): start(start), end(end) {}

    auto Line::get_start() const -> const Point& {
        return start;
    }

    auto Line::get_end() const -> const Point& {
        return end;
    }
}