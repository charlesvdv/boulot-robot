#include <visualization/xml_node.hpp>

#include <sstream>

namespace visualization::render {

    XMLNode::XMLNode(const std::string& tag, const std::vector<std::pair<std::string, std::string>>& attributes):
        tag(tag), attributes(attributes) {}
    
    XMLNode::Builder::Builder(const std::string& tag): 
        tag(tag) {}

    auto XMLNode::Builder::with_attribute(const std::string& name, const std::string& value) -> XMLNode::Builder& {
        std::pair <std::string, std::string> attribute(name, value);
        attributes.push_back(attribute);
        return *this;
    }

    auto XMLNode::Builder::build() const -> XMLNode {
        return XMLNode(tag, attributes);
    }

    auto XMLNode::to_string() const -> const std::string {
        std::stringstream node_builder;

        node_builder << "\t<" << tag;
        for(const auto & attribute : attributes){
            node_builder << " "<< attribute.first << "=\"" << attribute.second <<"\"";
        }
        node_builder << "/>\n";

        return node_builder.str();
    }
}