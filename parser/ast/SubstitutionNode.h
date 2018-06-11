//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_COMMANDNODE_H
#define UNTITLED_COMMANDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class SubstitutionNode: public Node {

public:
    SubstitutionNode(Token token);
    ~SubstitutionNode();

    std::string toString();

    std::string execute(Memory *memory);

private:
    Token token;
};


#endif //UNTITLED_COMMANDNODE_H
