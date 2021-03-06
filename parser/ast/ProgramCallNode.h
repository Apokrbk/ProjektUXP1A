//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_PROGRAMCALLNODE_H
#define UNTITLED_PROGRAMCALLNODE_H


#include <memory>
#include <vector>
#include <iostream>
#include <unistd.h>
#include "../../lexer/Token.h"
#include "Node.h"

class ProgramCallNode: public Node {

public:
    ProgramCallNode(std::shared_ptr<Node> progname, std::vector<std::shared_ptr<Node>> args);
    ~ProgramCallNode();
    std::string toString();

    std::string execute(Memory *memory);
    void add_argument(std::shared_ptr<Node>);

private:
    std::shared_ptr<Node> progname;
    std::vector<std::shared_ptr<Node>> args;

};


#endif //UNTITLED_PROGRAMCALLNODE_H
