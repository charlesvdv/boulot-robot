#include <visualization/line.hpp>

namespace visualization::geometry {

    Line::Line(const Point& start, const Point& end):
        start(start), end(end) {
    }

    const Point& Line::get_start() const {
        return start;
    }
    
    const Point& Line::get_end() const {
        return end;
    }
}