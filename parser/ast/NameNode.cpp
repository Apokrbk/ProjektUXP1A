//
// Created by marcin on 09.06.18.
//

#include "NameNode.h"

NameNode::NameNode(Token token): token(token) {

}

NameNode::~NameNode() {

}

std::string NameNode::toString() {
    return std::__cxx11::string();
}

void NameNode::execute() {
    Node::execute();
}
