#pragma once

#include <vector>
#include <utility>
#include <string>

namespace visualization::render {

    class XMLNode {
    public:
        class Builder;

        const std::string to_string() const;
    private: 
        XMLNode(const std::string tag, const std::vector<std::pair<std::string, std::string>> attributes);

        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

    class XMLNode::Builder {
    public: 
        Builder(const std::string tag);

        Builder& with_attribute(const std::string name, const std::string value);
        
        XMLNode build() const;
    private: 
        std::string tag;
        std::vector<std::pair<std::string, std::string>> attributes;
    };

}

