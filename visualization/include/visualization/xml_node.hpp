#pragma once

#include <vector>
#include <utility>
#include <string>

namespace visualization::render {

    class XMLNode {
    public:
        class Builder;

        auto to_string() const -> const std::string;
    private: 
        XMLNode(const std::string& tag, const std::vector<std::pair<std::string, std::string>>& attributes);

        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

    class XMLNode::Builder {
    public: 
        Builder(const std::string& tag);

        auto with_attribute(const std::string& name, const std::string& value) -> Builder&;
        
        auto build() const -> XMLNode;
    private: 
        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

}

