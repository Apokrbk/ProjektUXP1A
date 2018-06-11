//
// Created by marcin on 09.06.18.
//

#include "NameNode.h"

NameNode::NameNode(Token token): token(token) {

}

NameNode::~NameNode() {

}

std::string NameNode::toString() {
    return "<NameNode " + token.getRepr() + ">";
}

void NameNode::execute() {
    Node::execute();
}

Token NameNode::getToken() {
    return token;
}
