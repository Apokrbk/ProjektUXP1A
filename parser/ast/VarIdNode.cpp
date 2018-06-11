//
// Created by marcin on 09.06.18.
//

#include <iostream>
#include "VarIdNode.h"

VarIdNode::VarIdNode(Token token): token(token) {

}

VarIdNode::~VarIdNode() {

}

std::string VarIdNode::toString() {
    return "<VarIdNode: " + token.getRepr() + ">";
}

std::string VarIdNode::execute(Memory *memory) {

}

Token VarIdNode::getToken()  {
    return token;
}
