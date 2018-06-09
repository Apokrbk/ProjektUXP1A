//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_PROGRAMCALLNODE_H
#define UNTITLED_PROGRAMCALLNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class ProgramCallNode: protected Node {

public:
    ProgramCallNode(std::shared_ptr<NameNode> progname, std::vector<std::shared_ptr<Node>> args);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_PROGRAMCALLNODE_H
