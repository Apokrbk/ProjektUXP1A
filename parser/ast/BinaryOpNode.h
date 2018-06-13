#ifndef UNTITLED_BINARYOPNODE_H
#define UNTITLED_BINARYOPNODE_H


#include <memory>
#include "../../lexer/Token.h"
#include "Node.h"
#include <iostream>


class BinaryOpNode: public Node {

public:
    BinaryOpNode(std::shared_ptr<Node> left, Token token, std::shared_ptr<Node> right);
    ~BinaryOpNode();
    std::string toString();

    std::string execute(Memory *memory);

private:
    Token token;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

};


#endif //UNTITLED_BINARYOPNODE_H
