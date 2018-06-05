//
// Created by marcin on 05.06.18.
//

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include "CommandNode.h"

CommandNode::CommandNode(Token token): token(token) {
    nodeType = Node::NodeType::COMMAND;
}

std::string CommandNode::getRepr() {
    return token.getRepr();
}

void CommandNode::execute() {
    if(token.getType()==Token::TokenType::PWD){
        uid_t uid = geteuid();
        struct passwd *pw = getpwuid(uid);
        if(pw){
            std::cout<< pw->pw_dir << std::endl;
        }
    }
}
