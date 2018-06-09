//
// Created by marcin on 09.06.18.
//

#include "ProgramCallNode.h"

ProgramCallNode::ProgramCallNode(std::shared_ptr <Node> progname, std::vector <std::shared_ptr<Node>> args) {

}

ProgramCallNode::~ProgramCallNode() {

}

std::string ProgramCallNode::toString() {
    std::string result=progname->toString();
    result += " ARGS: ";
    for(auto arg : args){
        result += arg->toString();
    }
    return result;
}

void ProgramCallNode::execute() {
    Node::execute();
}
