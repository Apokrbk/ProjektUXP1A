//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_VARNODE_H
#define UNTITLED_VARNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class VarNode: public Node {

public:
    VarNode(Token token);
    ~VarNode();
    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_VARNODE_H
