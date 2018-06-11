#ifndef UNTITLED_NAMENODE_H
#define UNTITLED_NAMENODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class NameNode: public Node {

public:
    NameNode(Token token);
    ~NameNode();

    std::string toString();

    std::string execute(Memory *memory);
    Token getToken();
private:
    Token token;
};


#endif //UNTITLED_NAMENODE_H
