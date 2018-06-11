//
// Created by marcin on 09.06.18.
//

#include <iostream>
#include "VarNode.h"

VarNode::VarNode(Token token): token(token) {

}

VarNode::~VarNode() {

}

std::string VarNode::toString() {
    return "<VarNode " + token.getRepr() + ">";
}

std::string VarNode::execute(Memory *memory) {
    Symbol symbol = memory->getSymbol(token.getTokenData());
    if(symbol.getValue().empty())
        return "No such variable";
    else
        return symbol.getValue();
}
