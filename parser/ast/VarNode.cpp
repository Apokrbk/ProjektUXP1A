//
// Created by marcin on 09.06.18.
//

#include "VarNode.h"

VarNode::VarNode(Token token): token(token) {

}

VarNode::~VarNode() {

}

std::string VarNode::toString() {
    return std::__cxx11::string();
}

void VarNode::execute() {
    Node::execute();
}
