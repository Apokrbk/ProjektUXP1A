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

void VarNode::execute(Memory *memory) {
    Symbol symbol = memory->getSymbol(token.getTokenData());
    if(symbol.getValue().empty())
        std::cout<<"No such variable"<<std::endl;
    else
        std::cout<<symbol.getValue()<<std::endl;
}
