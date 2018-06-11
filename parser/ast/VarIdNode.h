//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_VARIDNODE_H
#define UNTITLED_VARIDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class VarIdNode: public Node {

public:
    VarIdNode(Token token);
    ~VarIdNode();

    Token getToken();

    std::string toString();

    void execute(Memory *memory);

private:
    Token token;
};


#endif //UNTITLED_VARIDNODE_H
