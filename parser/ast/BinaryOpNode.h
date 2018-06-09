#ifndef UNTITLED_BINARYOPNODE_H
#define UNTITLED_BINARYOPNODE_H


#include <memory>
#include "../../lexer/Token.h"
#include "Node.h"

class BinaryOpNode: public Node {

public:
    BinaryOpNode(std::shared_ptr<Node> left, Token token, std::shared_ptr<Node> right);
    ~BinaryOpNode();
    std::string toString();

    void execute();

private:
    Token token;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
};


#endif //UNTITLED_BINARYOPNODE_H
