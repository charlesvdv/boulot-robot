#pragma once

#include "point.hpp"

namespace visualization::geometry {

    class Line {
    public:
        Line(const Point& start, const Point& end);

        auto get_start() const -> const Point&;
        auto get_end() const -> const Point&;

    private:
        const Point start;
        const Point end;
    };

}