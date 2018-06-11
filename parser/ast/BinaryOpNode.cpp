//
// Created by marcin on 09.06.18.
//

#include <fstream>
#include "BinaryOpNode.h"
#include "VarIdNode.h"
#include "NameNode.h"
#include "ProgramCallNode.h"
#include "FilenameNode.h"

BinaryOpNode::BinaryOpNode(std::shared_ptr <Node> leftN, Token token, std::shared_ptr <Node> rightN): token(token), left(leftN), right(rightN) {
}

BinaryOpNode::~BinaryOpNode() {

}

std::string BinaryOpNode::toString() {
    return "<BinaryOpNode: " + left->toString() + " " + token.getRepr() + " " + right->toString() + ">";
}

std::string BinaryOpNode::execute(Memory *memory) {
    if(token.getType() == Token::TokenType::EQ)
        memory->putSymbol(std::static_pointer_cast<VarIdNode>(left)->getToken().getTokenData(), Symbol(std::static_pointer_cast<NameNode>(right)->getToken().getTokenData()));
    else if(token.getType() == Token::TokenType::STREAM){
        std::string programValue = left->execute(memory);
        std::string filename = memory->getPwd() + "/" + std::static_pointer_cast<FilenameNode>(right)->getToken().getTokenData();
        std::ofstream o(filename.c_str());
        o<<programValue;
        o.close();
    }

    return "";
}
