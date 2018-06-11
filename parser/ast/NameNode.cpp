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

std::string NameNode::execute(Memory *memory) {
    return token.getTokenData();
}

Token NameNode::getToken() {
    return token;
}
