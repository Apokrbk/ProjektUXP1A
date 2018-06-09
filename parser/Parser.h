//
// Created by marcin on 05.06.18.
//

#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H


#include <memory>
#include "../lexer/Lexer.h"
#include "ast/Node.h"

class Parser {

public:
    Parser(Lexer& lexer);
    std::shared_ptr<Node> parseStatement();
    std::shared_ptr<Node> parseSubstitution();
    std::shared_ptr<Node> parseShellStatement();
    std::shared_ptr<Node> parseBasicStatement();
    std::shared_ptr<Node> parseCompoundStatement();
    std::shared_ptr<Node> parseExportStatement();
    std::shared_ptr<Node> parseVarAssign();
    std::shared_ptr<Node> parseProgramCall();
    std::shared_ptr<Node> parseVar();
    std::shared_ptr<Node> parseQuotedStatement();
    std::shared_ptr<Node> parseName();
    std::shared_ptr<Node> parseArgs();
    std::shared_ptr<Node> parseOpPipe();
    std::shared_ptr<Node> parseOpRedirect();


private:
    Lexer lexer;
    Token currentToken;
    void eat(Token::TokenType type);
};


#endif //UNTITLED_PARSER_H
