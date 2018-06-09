//
// Created by marcin on 09.06.18.
//

#import "ExportNode.h"

ExportNode::ExportNode(Token token): token(token) {

}

ExportNode::~ExportNode() {

}

std::string ExportNode::toString() {
    return std::__cxx11::string();
}

void ExportNode::execute() {
    Node::execute();
}
