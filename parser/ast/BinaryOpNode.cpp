//
// Created by marcin on 09.06.18.
//

#include "BinaryOpNode.h"

BinaryOpNode::BinaryOpNode(std::shared_ptr <Node> leftN, Token token, std::shared_ptr <Node> rightN): token(token), left(leftN), right(rightN) {
}

BinaryOpNode::~BinaryOpNode() {

}

std::string BinaryOpNode::toString() {
    return "<BinaryOpNode: " + left->toString() + " " + token.getRepr() + " " + right->toString() + ">";
}

void BinaryOpNode::execute() {
    Node::execute();
}
