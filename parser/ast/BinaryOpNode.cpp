//
// Created by marcin on 09.06.18.
//

#include "BinaryOpNode.h"

BinaryOpNode::BinaryOpNode(std::shared_ptr <Node> left, Token token, std::shared_ptr <Node> right): token(token) {
}

BinaryOpNode::~BinaryOpNode() {

}

std::string BinaryOpNode::toString() {
    return std::__cxx11::string();
}

void BinaryOpNode::execute() {
    Node::execute();
}
