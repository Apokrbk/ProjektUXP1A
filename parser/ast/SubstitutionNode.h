//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_COMMANDNODE_H
#define UNTITLED_COMMANDNODE_H


#include "../../lexer/Token.h"
#include "Node.h"
#include "ProgramCallNode.h"

class SubstitutionNode: public Node {

public:
    SubstitutionNode(std::shared_ptr<Node> programCallNode);
    ~SubstitutionNode();

    std::string toString();

    std::string execute(Memory *memory);

private:
    std::shared_ptr<Node> programCallNode;
};


#endif //UNTITLED_COMMANDNODE_H
