//
// Created by marcin on 09.06.18.
//

#include "FilenameNode.h"

FilenameNode::FilenameNode(Token token): token(token) {

}

FilenameNode::~FilenameNode() {

}

std::string FilenameNode::toString() {
    return "<FilenameNode " + token.getRepr() + ">";
}

std::string FilenameNode::execute() {
    return Node::execute();
}
