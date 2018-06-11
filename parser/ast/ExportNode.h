#ifndef UNTITLED_EXPORTNODE_H
#define UNTITLED_EXPORTNODE_H


#include "../../lexer/Token.h"
#include "Node.h"

class ExportNode: public Node {

public:
    ExportNode(Token token);
    ~ExportNode();

    std::string toString();

    std::string execute(Memory *memory);

private:
    Token token;
};


#endif //UNTITLED_EXPORTNODE_H
