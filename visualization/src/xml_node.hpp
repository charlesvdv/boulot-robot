#pragma once

#include <string>
#include <utility>
#include <vector>

namespace visualization::render {

    class XMLNode {
    public:
        class Builder;

        auto to_string() const -> const std::string;

    private:
        XMLNode(std::string&& tag, std::vector<std::pair<std::string, std::string>>&& attributes);

        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

    class XMLNode::Builder {
    public:
        Builder(std::string tag);

        auto with_attribute(const std::string& name, const std::string& value) -> Builder&;

        auto build() -> XMLNode;

    private:
        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

}
