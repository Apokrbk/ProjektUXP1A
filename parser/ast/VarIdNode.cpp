//
// Created by marcin on 09.06.18.
//

#include "VarIdNode.h"

VarIdNode::VarIdNode(Token token): token(token) {

}

VarIdNode::~VarIdNode() {

}

std::string VarIdNode::toString() {
    return std::__cxx11::string();
}

void VarIdNode::execute() {
    Node::execute();
}
