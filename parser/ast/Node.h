//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


#include <string>
#include "../../Memory.h"

class Node {

public:
    Node();
    virtual ~Node();
    enum NodeType {
        COMMAND
    };

    virtual std::string toString() = 0;
    virtual std::string execute(Memory *memory);
    virtual std::string execute();

protected:
    NodeType nodeType;
};


#endif //UNTITLED_NODE_H
