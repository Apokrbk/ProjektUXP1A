//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_VARIDNODE_H
#define UNTITLED_VARIDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class VarIdNode: protected Node {

public:
    VarIdNode(Token token);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_VARIDNODE_H
