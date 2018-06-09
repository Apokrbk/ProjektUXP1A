//
// Created by marcin on 09.06.18.
//

#include "ProgramCallNode.h"

ProgramCallNode::ProgramCallNode(std::shared_ptr <Node> progname, std::vector <std::shared_ptr<Node>> args) {

}

ProgramCallNode::~ProgramCallNode() {

}

std::string ProgramCallNode::toString() {
    return std::__cxx11::string();
}

void ProgramCallNode::execute() {
    Node::execute();
}
