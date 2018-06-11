#ifndef UNTITLED_FILENAMENODE_H
#define UNTITLED_FILENAMENODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class FilenameNode: public Node {

public:
    FilenameNode(Token token);
    ~FilenameNode();

    std::string toString();

    std::string execute(Memory *memory);

private:
    Token token;
};


#endif //UNTITLED_FILENAMENODE_H
