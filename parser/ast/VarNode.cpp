//
// Created by marcin on 09.06.18.
//

#include "VarNode.h"

VarNode::VarNode(Token token): token(token) {

}

VarNode::~VarNode() {

}

std::string VarNode::toString() {
    return "<VarNode " + token.getRepr() + ">";
}

void VarNode::execute() {
    Node::execute();
}
