//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_PROGRAMCALLNODE_H
#define UNTITLED_PROGRAMCALLNODE_H


#include <memory>
#include <vector>
#include "../../lexer/Token.h"
#include "Node.h"

class ProgramCallNode: public Node {

public:
    ProgramCallNode(std::shared_ptr<Node> progname, std::vector<std::shared_ptr<Node>> args);
    ~ProgramCallNode();
    std::string toString();

    void execute();
private:
    std::shared_ptr<Node> progname;
    std::vector<std::shared_ptr<Node>> args;
    void pwd();
    void cd();
    void ls();
};


#endif //UNTITLED_PROGRAMCALLNODE_H
