//
// Created by marcin on 05.06.18.
//

#include "Parser.h"
#include "ast/CommandNode.h"


Parser::Parser(Lexer& lexer): lexer(lexer), currentToken(lexer.getNextToken()){
}

std::shared_ptr<CommandNode> Parser::parseCommand() {
    auto token = lexer.getNextToken();
    if (token.getType() == Token::TokenType::END)
        return nullptr;
    return std::make_shared<CommandNode>(token);
}

void Parser::eat() {
    currentToken = lexer.getNextToken();
}
