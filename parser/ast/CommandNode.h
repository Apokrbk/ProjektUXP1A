//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_COMMANDNODE_H
#define UNTITLED_COMMANDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class CommandNode: protected Node {

public:
    CommandNode(Token token);

    std::string getRepr();
private:
    Token token;
};


#endif //UNTITLED_COMMANDNODE_H
