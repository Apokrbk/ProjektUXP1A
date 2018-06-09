//
// Created by marcin on 05.06.18.
//

#include "Parser.h"
#include "ast/SubstitutionNode.h"
#include "ast/BinaryOpNode.h"
#include "ast/ExportNode.h"


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

std::shared_ptr<Node> Parser::parseBasicStatement() {
    std::shared_ptr<Node> node;

    node = parseQuotedStatement();
    if (node != nullptr)
        return node;

    node = parseVarAssign();
    if (node != nullptr)
        return node;

    node = parseVar();
    if (node != nullptr)
        return node;

    node = parseProgramCall();
    if (node != nullptr)
        return node;

    return nullptr;

}

std::shared_ptr<Node> Parser::parseCompoundStatement() {
    std::shared_ptr<Node> node;

    node = parseProgramCall();
    if (node == nullptr)
        return nullptr;

    while(currentToken.getType() == Token::TokenType::PIPE || currentToken.getType() == Token::TokenType::STREAM){
        if(currentToken.getType() == Token::TokenType::PIPE){
            Token tokenOp = currentToken;
            eat(Token::TokenType::PIPE);
            node = std::make_shared<BinaryOpNode>(node, tokenOp, parseCompoundStatement());
        } else {
            Token tokenOp = currentToken;
            eat(Token::TokenType::STREAM);
            node = std::make_shared<BinaryOpNode>(node, tokenOp, parseName());
        }
    }

    return node;

}

std::shared_ptr<Node> Parser::parseExportStatement() {
    if(currentToken.getType() != Token::TokenType::EXPORT)
        return nullptr;
    eat(Token::TokenType::EXPORT);
    Token token = currentToken;

    auto node = parseName();
    if(node == nullptr)
        throw std::runtime_error("Syntax error");

    return std::make_shared<ExportNode>(token);
}







