//
// Created by marcin on 05.06.18.
//

#include <vector>
#include "Parser.h"
#include "ast/SubstitutionNode.h"
#include "ast/QuotedNode.h"
#include "ast/BinaryOpNode.h"
#include "ast/ExportNode.h"
#include "ast/NameNode.h"
#include "ast/VarNode.h"
#include "ast/VarIdNode.h"
#include "ast/FilenameNode.h"
#include "ast/ProgramCallNode.h"


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

    node = parseNameStatement();
    if (node != nullptr)
        return node;

    node = parseVar();
    if (node != nullptr)
        return node;


    return nullptr;

}

std::shared_ptr<Node> Parser::parseCompoundStatement() {
    std::shared_ptr<Node> node;
    Token token = currentToken;
    eat(Token::TokenType::STRING);
    node = parseProgramCall(std::make_shared<NameNode>(token));
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
            node = std::make_shared<BinaryOpNode>(node, tokenOp, parseFileName());
        }
    }

    return node;

}

std::shared_ptr<Node> Parser::parseExportStatement() {
    if(currentToken.getType() != Token::TokenType::EXPORT)
        return nullptr;
    eat(Token::TokenType::EXPORT);
    Token token = currentToken;
    auto node = parseVarId();
    if(node == nullptr)
        throw std::runtime_error("Syntax error");

    return std::make_shared<ExportNode>(token);
}

std::shared_ptr<Node> Parser::parseVarId() {
    if(currentToken.getType() != Token::TokenType::IDENTIFIER)
        return nullptr;
    eat(Token::TokenType::IDENTIFIER);
    Token token = currentToken;
    return std::make_shared<VarIdNode>(token);
}


std::shared_ptr<Node> Parser::parseVar() {
    if(currentToken.getType() != Token::TokenType::DOLLARSIGN)
        return nullptr;
    eat(Token::TokenType::DOLLARSIGN);
    if(currentToken.getType() != Token::TokenType::IDENTIFIER)
        return nullptr;
    eat(Token::TokenType::IDENTIFIER);
    Token token = currentToken;
    return std::make_shared<VarNode>(token);
}

std::shared_ptr<Node> Parser::parseVarAssign(std::shared_ptr<VarIdNode> toBeAssigned) {
    Token op = currentToken;
    eat(Token::TokenType::EQ);
    if(currentToken.getType() == Token::TokenType::STRING || currentToken.getType() == Token::TokenType::IDENTIFIER){
        return std::make_shared<BinaryOpNode>(toBeAssigned, op, std::make_shared<NameNode>(currentToken));
    }
    else{
        throw std::runtime_error("Syntax error");
    }

}

std::shared_ptr<Node> Parser::parseFileName() {
    if(currentToken.getType() != Token::TokenType::STRING)
        return nullptr;
    eat(Token::TokenType::STRING);
    Token token = currentToken;
    return std::make_shared<FilenameNode>(token);
}

std::shared_ptr<Node> Parser::parseNameStatement() {
    if(currentToken.getType() == Token::TokenType::STRING){
        Token token = currentToken;
        eat(Token::TokenType::STRING);
        return parseProgramCall(std::make_shared<NameNode>(token));
    }

    if(currentToken.getType() == Token::TokenType::IDENTIFIER){
        Token token = currentToken;
        eat(Token::TokenType::IDENTIFIER);
        if(currentToken.getType() == Token::TokenType::EQ)
            return parseVarAssign(std::make_shared<VarIdNode>(token));
        else
            return parseProgramCall(std::make_shared<NameNode>(token));
    }
}

std::shared_ptr<Node> Parser::parseProgramCall(std::shared_ptr<NameNode> progname) {

    std::vector<std::shared_ptr<Node>> args;
    while(currentToken.getType() != Token::TokenType::PIPE || currentToken.getType() != Token::TokenType::STREAM || currentToken.getType() != Token::TokenType::END){
        if(currentToken.getType() == Token::TokenType::DOLLARSIGN){
            args.push_back(parseVar());
        }
        else if(currentToken.getType() == Token::TokenType::STRING){
            args.push_back(parseName());
        }
        else{
            throw std::runtime_error("Syntax error");
        }
    }
    return std::make_shared<ProgramCallNode>(progname, args);
}

std::shared_ptr<Node> Parser::parseName() {
    if(currentToken.getType() != Token::TokenType::STRING)
        return nullptr;
    else
        return std::make_shared<NameNode>(currentToken);

}

std::shared_ptr<Node> Parser::parseQuotedStatement() {
    if (currentToken.getType() != Token::TokenType::QUOTE)
        return nullptr;

    eat(Token::TokenType::QUOTE);
    std::shared_ptr<QuotedNode> node = parseStatement();
    eat(Token::TokenType::QUOTE);

    return node;
}








