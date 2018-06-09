//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_QUOTEDNODE_H
#define UNTITLED_QUOTEDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class QuotedNode: protected Node {

public:
    QuotedNode(Token token);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_QUOTEDNODE_H
