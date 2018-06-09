#ifndef UNTITLED_FILENAMENODE_H
#define UNTITLED_FILENAMENODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class FilenameNode: protected Node {

public:
    FilenameNode(Token token);

    std::string toString();

    void execute();

private:
    Token token;
};


#endif //UNTITLED_FILENAMENODE_H
