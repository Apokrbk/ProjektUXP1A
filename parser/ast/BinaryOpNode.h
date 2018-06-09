#ifndef UNTITLED_BINARYOPNODE_H
#define UNTITLED_BINARYOPNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class BinaryOpNode: protected Node {

public:
    BinaryOpNode(std::shared_ptr<Node> left, Token token, std::shared_ptr<Node> right);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_BINARYOPNODE_H
