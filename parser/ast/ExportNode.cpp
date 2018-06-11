//
// Created by marcin on 09.06.18.
//

#import "ExportNode.h"

ExportNode::ExportNode(Token token): token(token) {

}

ExportNode::~ExportNode() {

}

std::string ExportNode::toString() {
    return "<ExportNode " + token.getRepr() + ">";
}

std::string ExportNode::execute(Memory *memory) {
    return "";
}
