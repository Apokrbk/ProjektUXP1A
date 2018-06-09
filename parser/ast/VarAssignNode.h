//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_VARASSIGNNODE_H
#define UNTITLED_VARASSIGNNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class VarAssignNode: protected Node {

public:
    VarAssignNode(Node toBeAssigned, Node toAssign);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_VARASSIGNNODE_H
