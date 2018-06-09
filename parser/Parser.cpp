//
// Created by marcin on 05.06.18.
//

#include "Parser.h"
#include "ast/SubstitutionNode.h"


Parser::Parser(Lexer& lexer): lexer(lexer), currentToken(lexer.getNextToken()){
}


void Parser::eat(Token::TokenType type) {
    if (currentToken.getType() == type)
        throw std::runtime_error("Syntax error");
    currentToken = lexer.getNextToken();
}

std::shared_ptr<Node> Parser::parseStatement() {
    std::shared_ptr<Node> node;

    node = parseSubstitution();
    if (node != nullptr)
        return node;

    node = parseShellStatement();
    if (node != nullptr)
        return node;

    return nullptr;
}

std::shared_ptr<Node> Parser::parseSubstitution() {
    if (currentToken.getType() != Token::TokenType::QUOTE_REVERSED)
        return nullptr;

    eat(Token::TokenType::QUOTE_REVERSED);
    std::shared_ptr<SubstitutionNode> node = parseStatement();
    eat(Token::TokenType::QUOTE_REVERSED);

    return node;
}

std::shared_ptr<Node> Parser::parseShellStatement() {
    std::shared_ptr<Node> node;

    node = parseBasicStatement();
    if (node != nullptr)
        return node;

    node = parseCompoundStatement();
    if (node != nullptr)
        return node;

    node = parseExportStatement();
    if (node != nullptr)
        return node;

    return nullptr;
}





