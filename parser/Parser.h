//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H


#include <memory>
#include "../lexer/Lexer.h"
#include "ast/Node.h"
#include "ast/CommandNode.h"

class Parser {

public:
    Parser(Lexer lexer);
    std::shared_ptr<CommandNode> parseCommand();

private:
    Lexer lexer;
    Token currentToken;
    void eat();
};


#endif //UNTITLED_PARSER_H
