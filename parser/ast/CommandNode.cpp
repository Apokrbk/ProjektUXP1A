//
// Created by marcin on 05.06.18.
//

#include "CommandNode.h"

CommandNode::CommandNode(Token token): token(token) {
    nodeType = Node::NodeType::COMMAND;
}

std::string CommandNode::toString() {
    return token.getRepr();
}
