#include "svg_renderer.hpp"

#include <visualization/renderer.hpp>

namespace visualization::render {
    auto Renderer::make_svg_renderer(const std::string& name, double width, double height)
        -> std::unique_ptr<Renderer> {
        return std::make_unique<SVGRenderer>(name, width, height);
    }
}