//
// Created by marcin on 09.06.18.
//

#include <fstream>
#include <thread>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "BinaryOpNode.h"
#include "VarIdNode.h"
#include "NameNode.h"
#include "ProgramCallNode.h"
#include "FilenameNode.h"
#include "../../exception/ParserException.h"

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
    }else if(token.getType() == Token::TokenType::PIPE){
        int READ = 0;
        int WRITE = 1;

        int fds1[2];

        pipe(fds1);
        if (fork()==0) {
            // Close unnecessary pipe's end
            close(fds1[READ]);

            // Redirect stdout to pipe
            dup2(fds1[1],1 ); close(fds1[1]);

            // Execute first program
            std::static_pointer_cast<ProgramCallNode>(left)->execute(memory);
            exit(0);
        }
        if (fork()==0){
            // Close unnecessary pipe's end
            close(fds1[WRITE]);
            // Pipe input to stdin
            dup2(fds1[0],0); close(fds1[0]);
            // Execute second program
            std::static_pointer_cast<ProgramCallNode>(right)->execute(memory);
            exit(0);
        }
        sleep(1);
    }

    return "";
}
