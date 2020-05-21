#include <visualization/xml_node.hpp>

#include <sstream>

namespace visualization::render {

    XMLNode::XMLNode(const std::string tag, const std::vector<std::pair<std::string, std::string>> attributes):
        tag(tag), attributes(attributes) {
        
        build_node();
    }
    
    XMLNode::Builder::Builder(const std::string tag): 
        tag(tag) {}

    XMLNode::Builder& XMLNode::Builder::with_attribute(const std::string name, const std::string value) {
        std::pair <std::string, std::string> attribute(name, value);
        attributes.push_back(attribute);
        return *this;
    }

    XMLNode XMLNode::Builder::build() const {
        return XMLNode(tag, attributes);
    }

    void const XMLNode::build_node() {
        std::stringstream node_builder;

        node_builder << "\t<" << tag;
        for(std::vector<std::pair<std::string, std::string>>::const_iterator it = attributes.begin(); it != attributes.end(); it++){
            node_builder << " "<< it->first << "=\"" << it->second <<"\"";
        }
        node_builder << "/>\n";

        node = node_builder.str();
    }

    const std::string& XMLNode::get_node() const {
        return node;
    }
}