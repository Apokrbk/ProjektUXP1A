#ifndef UNTITLED_NAMENODE_H
#define UNTITLED_NAMENODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class NameNode: protected Node {

public:
    NameNode(Token token);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_NAMENODE_H
