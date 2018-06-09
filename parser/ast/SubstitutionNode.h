//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_COMMANDNODE_H
#define UNTITLED_COMMANDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class SubstitutionNode: protected Node {

public:
    SubstitutionNode(Token token);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_COMMANDNODE_H
