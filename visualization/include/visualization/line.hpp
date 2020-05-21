#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Line {
    public:
        Line(const Point& start, const Point& end);

        const Point& get_start() const;
        const Point& get_end() const;
    private:
        const Point start;
        const Point end;
    };
    
}