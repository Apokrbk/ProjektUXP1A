//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_VARASSIGNNODE_H
#define UNTITLED_VARASSIGNNODE_H


#include <memory>
#include "../../lexer/Token.h"
#include "Node.h"

class VarAssignNode: public Node {

public:
    VarAssignNode(std::shared_ptr<Node> toBeAssigned, std::shared_ptr<Node> toAssign);
    ~VarAssignNode();
    std::string toString();

    void execute();

};


#endif //UNTITLED_VARASSIGNNODE_H
