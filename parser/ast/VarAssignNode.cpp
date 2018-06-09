//
// Created by marcin on 09.06.18.
//

#include "VarAssignNode.h"

VarAssignNode::VarAssignNode(std::shared_ptr<Node> toBeAssigned, std::shared_ptr<Node> toAssign) {

}

VarAssignNode::~VarAssignNode() {

}

std::string VarAssignNode::toString() {
    return std::__cxx11::string();
}

void VarAssignNode::execute() {
    Node::execute();
}
