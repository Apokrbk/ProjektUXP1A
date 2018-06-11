//
// Created by marcin on 09.06.18.
//

#include "QuotedNode.h"

QuotedNode::QuotedNode(Token token): token(token) {

}

QuotedNode::~QuotedNode() {

}

std::string QuotedNode::toString() {
    return "<QuotedNode + " + token.getRepr() + ">";
}

std::string QuotedNode::execute(Memory *memory) {
    return "";
}
