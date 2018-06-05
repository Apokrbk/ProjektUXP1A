//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


#include <string>

class Node {

public:
    enum NodeType {
        COMMAND
    };

    virtual std::string toString() = 0;
    virtual void execute();

protected:
    NodeType nodeType;
};


#endif //UNTITLED_NODE_H
