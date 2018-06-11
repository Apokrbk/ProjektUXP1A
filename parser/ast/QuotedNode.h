//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_QUOTEDNODE_H
#define UNTITLED_QUOTEDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class QuotedNode: public Node {

public:
    QuotedNode(Token token);
    ~QuotedNode();

    std::string toString();

    std::string execute(Memory *memory);

private:
    Token token;
};


#endif //UNTITLED_QUOTEDNODE_H
