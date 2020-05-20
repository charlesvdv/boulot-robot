#include <visualization/xml_node.hpp>

namespace visualization::render {

    XMLNode::XMLNode(const std::string tag, const std::vector<std::pair<std::string, std::string>> attributes):
        tag(tag), attributes(attributes) {}
    
    XMLNode::Builder& XMLNode::Builder::has_tag(const std::string name) {
        tag = name;
        return *this;
    }

    XMLNode::Builder& XMLNode::Builder::with_attribute(const std::string name, const std::string value) {
        std::pair <std::string, std::string> attribute(name, value);
        attributes.push_back(attribute);
        return *this;
    }

    XMLNode XMLNode::Builder::build() const {
        return XMLNode(tag, attributes);
    }

    const std::string XMLNode::get_tag() const {
        return tag;
    }

    const std::vector<std::pair<std::string, std::string>> XMLNode::get_attributes() const {
        return attributes;
    }
}