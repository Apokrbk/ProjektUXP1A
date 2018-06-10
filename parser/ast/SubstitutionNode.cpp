//
// Created by marcin on 09.06.18.
//

#include "SubstitutionNode.h"

SubstitutionNode::SubstitutionNode(Token token): token(token) {

}

SubstitutionNode::~SubstitutionNode() {

}

std::string SubstitutionNode::toString() {
    return "<SubstitutionNode + " + token.getRepr() + ">";
}
